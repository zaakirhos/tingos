/*
 * Swarthmore College, CS 31
 * Copyright (c) 2021 Swarthmore College Computer Science Department,
 * Swarthmore PA, Professors Tia Newhall, Andrew Danner, and Kevin Webb
 */

/* Zakir Hossain, Natnicha Sukprawit
  April 11, 2021

  This program implements the Conways Game of Life in a torus.

  Conways Game of Life:
    A cellular automata game in which each cell's new state depend on the 
    states of its neighbors. The cell state in this game is depicted with
    0 (alive) or 1 (death)
    The next generation of the game is determined by the previous
    generation

    The following rules of CGL are used for this program:
    1. For a cell that is alive (1):
      1. Each cell with one or no neighbors dies, as if by solitude
      2. Each cell with four or more neighbors dies, as if by overpopulation.
      3. Each cell with two or three neighbors survives.

    2. For a cell that is death (0):
      1. Each cell with three neighbors becomes populated.

  The program uses a number of builtin C header files to 
  achieve this goal, i.e. time.h.
  Many functions are defined and implemented to carry out the 
  necessary computation for this game, i.e. play_gol().
  The program allows user to give a text files that contains the initial
  configuration of the game:
    1. size of the board (rows x columns) = # of cells
    2. The number of rounds to play 
    3. The number of initial cells alive
    4. The coordinates of these alive cells 
  It also enables the user to enter an output bit to indicate whether
  it should display an animation while the game is played out.
  Depending on the output bit, the program plays the game and 
  displays the appropriate information of the game, including the 
  time took for the game to complete with the given rounds


 */

/*
 * To run:
 * ./gol file1.txt  0  # run with config file file1.txt, do not print board
 * ./gol file1.txt  1  # run with config file file1.txt, ascii animation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

/****************** Definitions **********************/
/* Two possible modes in which the GOL simulation can run */
#define OUTPUT_NONE   0   // with no animation
#define OUTPUT_ASCII  1   // with ascii animation

/* Used to slow down animation run modes: usleep(SLEEP_USECS);
 * Change this value to make theh animation run faster or slower
 */
//#define SLEEP_USECS  1000000
#define SLEEP_USECS    100000

/* A global variable to keep track of the number of live cells in the
 * world (this is the ONLY global variable you may use in your program)
 */
static int total_live = 0;
// semaphore
static pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
// barrier
static pthread_barrier_t my_barrier;
static pthread_cond_t cv1, cv2;

static int tc = -1;

struct gol_data_per_par{
  int starting_row;
  int starting_col;
  int ending_row;
  int ending_col;
  int cwl; //Column Work Length;
  int rwl; //row work length
  // int output_mode;
  int initialLiveCells;
  double totalRunTime;
  int eachParIndex; //Index of each partition created. 
};

/* This struct represents all the data you need to keep track of your GOL
 * simulation.  Rather than passing individual arguments into each function,
 * we'll pass in everything in just one of these structs.
 * this is passed to play_gol, the main gol playing loop
 *
 * NOTE: You will need to use the provided fields here, but you'll also
 *       need to add additional fields. (note the nice field comments!)
 * NOTE: DO NOT CHANGE THE NAME OF THIS STRUCT!!!!
 */
struct gol_data {

   // NOTE: DO NOT CHANGE the names of these 4 fields (but USE them)
   int rows;  // the row dimension
   int cols;  // the column dimension
   int iters; // number of iterations to run the gol simulation
   int output_mode; // set to:  OUTPUT_NONE, or OUTPUT_ASCII
   int* currentGen; // The current generation of cells.
   // The next generation of cells, will be produced based on 
   // the current generation cell
   int* nextGen; 
   //The number of live cells in the initial generation
   int initialLiveCells;
   double totalRunTime; // Total running time to complete the game

   // Static data to be used for threads
    int num_threads; //number of threads tbe run
    int par_type; // Type of partition (col or row wise)
    int print_par; //Should each partition be printed (1 for print, 0 for no)
    pthread_t *tids;
    int my_tids[num_threads];
    struct gol_data_per_par *partitions;
};

/****************** Function Prototypes **********************/
/* the main gol game playing loop (prototype must match this) */
void *play_gol(void *args);
/* init gol data from the input file and run mode cmdline args */
int init_game_data_from_args(struct gol_data *data, char *argv[]);

/* print board to the terminal (for OUTPUT_ASCII mode) */
void print_board(struct gol_data *data, int round);
//malloc pointers and initializes their values
void mallocGensAndInit(struct gol_data *data);
//Make a cell alive
void reviveCellAt(struct gol_data *data, int row_index, int col_index);
//Finds the state of a cell
int cellStateAt(struct gol_data *data, int row_index, int col_index);
//Counts all alive cells
void countTotalLiveCells(struct gol_data *data);
//Counts all neighbors
int countNeighbors(struct gol_data *data, int row_index, int col_index);
//Reset one generation with another generation
void copyGeneration(struct gol_data *data);
//Multiple purposes: count, clear, print, sleep
void animate(struct gol_data *data, int round);
void partition(struct gol_data *data);
void printPartition(struct gol_data *data);
void play_parallely(struct gol_data *data);
/**********************************************************/
int main(int argc, char *argv[]) {

  int ret;
  struct gol_data data;
  double secs;


  /* check number of command line arguments */
  if (argc < 6) {
    printf("usage: ./gol <infile> <0|1>\n");
    printf("(0: with no visi, 1: with ascii visi)\n");
    exit(1);
  }

  /* Initialize game state (all fields in data) from information
   * read from input file */
  ret = init_game_data_from_args(&data, argv);
  partition(&data);
  if(ret != 0) {
    printf("Error init'ing with file %s, mode %s\n", argv[1], argv[2]);
    exit(1);
  }
  data.output_mode = atoi(argv[2]);
  /* Invoke play_gol in different ways based on the run mode */
  if(data.output_mode == OUTPUT_NONE) {  // run with no animation
    play_parallely(&data);
  }
  else { // run with ascii animation
    play_parallely(&data);

    // clear the previous print_board output from the terminal:
    // (NOTE: you can comment out this line while debugging)
    if(system("clear")) { perror("clear"); exit(1); }

    // NOTE: DO NOT modify this call to print_board at the end
    //       (its for grading)
    printf("Final Board (same as round %d) \n", data.iters);
    print_board(&data, data.iters);
  }

  secs = data.totalRunTime;

  /* Print the total runtime, in seconds. */
  // NOTE: do not modify these calls to fprintf
  fprintf(stdout, "Total time: %0.3f seconds\n", secs);
  fprintf(stdout, "Number of live cells after %d rounds: %d\n\n",
      data.iters, total_live);


  //Freeing the pointers allocated via the call of init_game_data_from_args()
  free(data.currentGen);
  free(data.nextGen);
  free(data.partitions);
  free(data.tids);
  data.currentGen = NULL;
  data.nextGen = NULL;
  data.partitions = NULL;
  data.tids = NULL;


  return 0;
}
/**********************************************************/

/* initialize the gol game state from command line arguments
 *       argv[1]: name of file to read game config state from
 *       argv[2]: run mode value
 * data: pointer to gol_data struct to initialize
 * argv: command line args
 *       argv[1]: name of file to read game config state from
 *       argv[2]: run mode
 * returns: 0 on success, 1 on error
 */
int init_game_data_from_args(struct gol_data *data, char *argv[]) {

    int ret;
    int i, row_index, col_index;
    data->num_threads = atoi(argv[3]);
    data->par_type = atoi(argv[4]); // Type of partition (col or row wise)
    data->print_par = atoi(argv[5]); //Should each partition be printed (1 for print, 0 for no)
    FILE *infile;  // a file pointer is not a pointer like pointers to other
                 // C types: dereferencing it doesn't make any sense

    // (1) open the file for reading and check that open succeeded
    //     (the file name is passed as command line arg)
    infile = fopen(argv[1], "r");
    if (infile == NULL) {
          printf("Error: file open %s\n", argv[1]);
    }
      ret = fscanf(infile, "%d", &(data->rows));
    if(ret ==1){
        ret = fscanf(infile, "%d", &(data->cols));
    }
    if(ret ==1){
        ret = fscanf(infile, "%d", &(data->iters));
    }
    if(ret ==1){
        ret = fscanf(infile, "%d", &(data->initialLiveCells));
    }
    mallocGensAndInit(data);

    ret = fscanf(infile, "%d%d", &row_index, &col_index); //Is the coordinate format row col
    reviveCellAt(data, row_index, col_index);

    i = 0;
    while (i < data->initialLiveCells-1 && ret==2){
      ret = fscanf(infile, "%d%d", &row_index, &col_index);
      reviveCellAt(data, row_index, col_index);
      i++;
    }

    return 0;
}
/*
Allocated two pointer fields (currentGen, nextGen), 
each having size to hold rows*cols integers.
Then it fills each pointer's slots (cells) with zeroes. 

data:pointer to a struct gol_data that contains the pointer fields currentGen
      and nextGen pointer fields
 */
void mallocGensAndInit(struct gol_data *data){
  int rows = data->rows;
  int cols = data->cols;
    int i, j;
  data->currentGen = malloc(sizeof(int) * rows*cols);
  data->nextGen = malloc(sizeof(int) * rows*cols);
  if(data->currentGen == NULL){
    printf("Malloc Failed");
    exit(1);
  }

  for (i = 0; i < rows; i++)
  {
    for ( j = 0; j < cols; j++)
    {
      data->currentGen[i*cols+j] = 0;
      data->nextGen[i*cols+j] = 0;
    }
  }
}

/*
Changes the state of the given cell of currentGen to 1, 
assumed the cell is initially 0.

data: pointer to a struct gol_data that contains the pointer field currentGen
row_index: the row index of the cell that changes to 1
col_index: the column index of the cell that changes to 1
 */
void reviveCellAt(struct gol_data *data, int row_index, int col_index){
  data->currentGen[row_index * data->cols + col_index] = 1;
}
/*
returns the state of the given cell of currentGen

data: pointer to a struct gol_data that contains the pointer field currentGen
row_index: the row index of the cell whose state will be return
col_index: the column index of the whose state will be return
return: the state (1 or 0)
 */
int cellStateAt(struct gol_data *data, int row_index, int col_index){
  int state = data->currentGen[row_index * data->cols + col_index];

  return state;
  
}

/*
Calculates the total number of live cells in currentGen.
Then it updates total_live by the number of live cells in currentGen.

data: pointer to a struct gol_data that contains the pointer field currentGen
 */
void countTotalLiveCells(struct gol_data *data){
  int i, j, state;

  for ( i = 0; i < data->rows; i++)
  {
    for ( j = 0; j < data->cols; j++)
    {
      state = cellStateAt(data, i, j);
      if (state == 1)
      {
        total_live++;
      }
    }
    
  }
}

/*
Counts the total (max 8) number of live neighbor cells
of the given cell of currentGen. 

data: pointer to a struct gol_data that contains the pointer field currentGen

row_index: the row index of the cell whose neighbors will be counted
col_index: the column index of the cell whose neighbors will be counted

Self (given cell ) is not identified as neighbor
 */
int countNeighbors(struct gol_data *data, int row_index, int col_index){
  int totalNeighbors = 0;
  int i, j, state;
  int neighborRowIndex;
  int neighborColIndex;

  for (i = -1; i <=1 ; i++)
  {
    for ( j = -1; j <= 1; j++)
    {
      neighborRowIndex = (row_index + i + data->rows) % data->rows;
      neighborColIndex = (col_index + j + data->cols) % data->cols;
      state = cellStateAt(data, neighborRowIndex, neighborColIndex);
      totalNeighbors += state;
    }
  }

  //Preventing self (given cell) from being counted as neighbor
  if (cellStateAt(data, row_index, col_index) == 1)
  {
    totalNeighbors -=1;
  }
  return totalNeighbors;
}

/*
Sets all the cells' state of the currentGen with all the cells' state 
of the nextGen.

data: pointer to a struct gol_data that contains the pointer 
      fields currentGen and nextGen
 */
void copyGeneration(struct gol_data *data){
  int i, j;

  for ( i = 0; i < data->rows; i++)
  {
    for ( j = 0; j < data->cols; j++)
    {
      data->currentGen[i*data->cols +j] = data->nextGen[i*data->cols +j];
    }
    
  }
}

/*
  if OUTPUT_ASCII=1:
    Counts the total live cells in currentGen by calling
    countTotalLiveCells().
    Clears any previous output in the terminal
    Prints the board by calling print_board()
    Then the program goes to sleep for 0.1 seconds
  Otherwise:
    Counts the total live cells in currentGen by calling
    countTotalLiveCells().

  data: pointer to a struct gol_data that contains the pointer field currentGen

*/
void animate(struct gol_data *data, int round){

  if (data->output_mode == OUTPUT_ASCII){
        pthread_mutex_lock(&my_mutex);
        total_live = 0;
        countTotalLiveCells(data);
        pthread_mutex_unlock(&my_mutex);
        
        system("clear");
        print_board(data, round);
        usleep(100000);
      }else{
        pthread_mutex_lock(&my_mutex);
        total_live = 0;
        countTotalLiveCells(data);
        pthread_mutex_unlock(&my_mutex);
      }
}

/**********************************************************/
/* the gol application main loop function:
 *  runs rounds of GOL,
 *    * updates program state for next round (world and total_live)
 *    * performs any animation step based on the output/run mode
 *
 *   data: pointer to a struct gol_data  initialized with
 *         all GOL game playing state
 */
void partition(struct gol_data *data){
  data->partitions = malloc(data->num_threads * sizeof(struct gol_data_per_par));
  if (data->partitions == NULL)
  {
    printf("Initialization of partitions failed");
    exit(1);
  }
  
  int j = 0;
  int rows = data->rows;
  int cols = data->cols;
  int t = data->num_threads;

  if (t<=0)
  {
    printf("You entered %d threadn\n You must enter at least 1 thread", t);
    exit(1);
  }
  if (t > rows && data->par_type==0)
  {
    printf("You indicated to partition row wise, therefore thread number cannot be greater than row size. \nYou entered %d threads, but row size is %d", t, rows);
    exit(1);
  }
  if (t > rows && data->par_type==1)
  {
    printf("You indicated to partition column wise, therefore thread number cannot be greater than column size. \nYou entered %d threads, but column size is %d", t, cols);
    exit(1);
  }

  if(data->par_type==0){
    //row wise
    for (int i = 0; i < data->rows;)
    {
      data->partitions[j].starting_row = i;
      data->partitions[j].rwl = rows/t;
      i+=data->partitions[j].rwl;
      data->partitions[j].ending_row = i-1; //inclusive
      rows-=data->partitions[j].rwl;
      data->partitions[j].starting_col = 0;
      data->partitions[j].ending_col = cols-1;
      data->partitions[j].cwl = cols;
      data->partitions[j].eachParIndex = j;
      j++;
      t--;
      if (t==0){
          break;
        }
      
      
    }
  }else{
     for (int i = 0; i < data->cols;)
    {
      data->partitions[j].starting_col = i;
      data->partitions[j].cwl = cols/t;
      i+=data->partitions[j].cwl;
      data->partitions[j].ending_col = i-1; //inclusive
      cols-=data->partitions[j].cwl;
      data->partitions[j].starting_row = 0;
      data->partitions[j].ending_row = rows-1;
      data->partitions[j].rwl = rows;
      j++;
      data->partitions[j].eachParIndex = t;
      t--;
      if(t == 0){
        break;
      }
      
    }
  }

}
void play_parallely(struct gol_data *data){
  int i;
  int round=0; 
  int num_threads = data->num_threads;
  data->tids = (pthread_t *)malloc(sizeof(pthread_t)*data->num_threads);
    if(!data->tids) {
      perror("malloc pthread_t array");
      exit(1);
    }
      if (data->print_par)
  {
    printPartition(data);
    
  }
      //Time variables
  struct timeval startTime, endTime;
  int ret;
  double startedAt, endedAt;

  ret = gettimeofday(&startTime, NULL);
  if (ret != 0)
  {
    printf("An error has occurred in initializing the start time");
  }
  

//Render and print the initial configuration of the board if the mode is 1
  printf("Initial generation (round 0):\n");
  animate(data, round);

// initialize the barrier with the number of threads that will
  // synchronize on it:
  if(pthread_barrier_init(&my_barrier, 0, num_threads)) {
    printf("pthread_barrier_init error\n");
    exit(1);
  } 
  //Starting of the subsequent generations
  for ( round = 1; round <= data->iters; round++)
   {
     for (i=0; i < num_threads; i++) {
        // The third parameter is a function pointer, we pass
        // the name of a function with a matching prototype of
        // the parameter.  thread_create calls thread_hello via
        // the function ptr parameter.
        ret = pthread_create(&data->tids[i], 0, play_gol, data);
        
        if(ret) {
           perror("Error pthread_create\n");
           exit(1);
        }

        // try this call to pthread_create instead of the above
        // one. run a few times and see what happens to the value
        // passed in as the arg (do you understand what is going on?):
        //ret = pthread_create(&tids[i], 0, thread_hello, &i);

        
    }
    // wait for all worker threads to exit
    for (i=0; i < num_threads; i++) {
        pthread_join(data->tids[i], 0);
    }
     copyGeneration(data);
      animate(data, round);
      tc = -1;
   }
   pthread_barrier_destroy(&my_barrier);
   


     //Total time calculation.
  ret = gettimeofday(&endTime, NULL);
  startedAt = (double)startTime.tv_sec + (double)(startTime.tv_usec/1000000);
  endedAt = (double)endTime.tv_sec + (double)(endTime.tv_usec/1000000);
  data->totalRunTime = endedAt - startedAt;
}
void *play_gol(void *args) {
  struct gol_data *data = (struct gol_data *)args;

  int i, j, neighbors, state;
  int rows = data->rows;
  int cols = data->cols;
  int round = 0;


  pthread_mutex_lock(&my_mutex);
   tc += 1;
pthread_mutex_unlock(&my_mutex);
      for ( i = data->partitions[tc].starting_row; i < data->partitions[tc].ending_row; i++){
        for ( j = data->partitions[tc].starting_col; j < data->partitions[tc].ending_col; j++){

          // pthread_mutex_lock(&my_mutex);
          neighbors = countNeighbors(data, i, j);
      
          state = cellStateAt(data, i, j);
          
            if( state == 1){
              if (neighbors == 0 || neighbors == 1){
                data->nextGen[i*cols + j] = 0;
              }
              else if (neighbors >= 4){
                data->nextGen[i*cols + j] = 0;
              }
              else{
                data->nextGen[i * cols + j] = data->currentGen[i * cols + j];
              }
            }
            else{
              if (neighbors == 3){
                data->nextGen[i*cols + j] = 1;
              }
              else{
                data->nextGen[i * cols + j] = data->currentGen[i * cols + j];
              }
              
            }
            // pthread_mutex_unlock(&my_mutex);
        }
        
      }

  // printf("%d  ", tc);

      // copyGeneration(data);
    //   // animate(data, round);
    // }
// printf("%d", tc);
  // pthread_mutex_lock(&my_mutex);
  //  printf("%d  ", data->partitions[tc].starting_row);
  //  tc += 1;
  // //  printf("%d\n", tc);
  // pthread_mutex_unlock(&my_mutex);
  



  //Total time calculation.
  // ret = gettimeofday(&endTime, NULL);
  // startedAt = (double)startTime.tv_sec + (double)(startTime.tv_usec/1000000);
  // endedAt = (double)endTime.tv_sec + (double)(endTime.tv_usec/1000000);
  // data->totalRunTime = endedAt - startedAt;

  return NULL;

}

/**********************************************************/
/* Print the board to the terminal.
 *   data: gol game specific data
 *   round: the current round number
 *
 */
void print_board(struct gol_data *data, int round) {


    int i, j;
    int state;

    /* Print the round number. */
    fprintf(stderr, "Round: %d\n", round);

    for (i = 0; i < data->rows; ++i) {
        for (j = 0; j < data->cols; ++j) {
            state = cellStateAt(data, i, j);
            if(state == 1){
              fprintf(stderr, " @");
            }else{
              fprintf(stderr, " .");
            }
                
        }
        fprintf(stderr, "\n");
    }

    /* Print the total number of live cells. */
    fprintf(stderr, "Live cells: %d\n\n", total_live);
}
void printPartition(struct gol_data *data){

  for (int i = 0; i < data->num_threads; i++)
  {
    printf("tid  %d: rows:  %d:%d (%d)  cols:  %d:%d (%d)\n",
          i, data->partitions[i].starting_row,data->partitions[i].ending_row, 
          data->partitions[i].rwl, data->partitions[i].starting_col,
          data->partitions[i].ending_col, data->partitions[i].cwl);
  }
  
}

// tid  0: rows:  0:99 (100) cols:  0:11 (12)
// tid  1: rows:  0:99 (100) cols: 12:22 (11)
// tid  2: rows:  0:99 (100) cols: 23:33 (11)
// tid  4: rows:  0:99 (100) cols: 45:55 (11)
// tid  3: rows:  0:99 (100) cols: 34:44 (11)
// tid  5: rows:  0:99 (100) cols: 56:66 (11)
// tid  6: rows:  0:99 (100) cols: 67:77 (11)
// tid  7: rows:  0:99 (100) cols: 78:88 (11)
// tid  8: rows:  0:99 (100) cols: 89:99 (11)