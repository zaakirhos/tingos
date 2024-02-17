## Compile C++ Codes
* 1. g++ foo.cpp (run ./a.out for output)
* 2. g++ -o 'filename' foo.cpp (run ./filename for output)
* 3. g++ -Wall -ansi -c -o 'filename' prog.cpp

### Stages:
* 1. Preprocess (-E foo.cpp to stop t)
* 2. Compile (-S foo.cpp to stop the process after this stage)
* 3. Assemble
* 4. Link

## Compile C
* 1. Same as above, just replace g++ with gcc

### Stop