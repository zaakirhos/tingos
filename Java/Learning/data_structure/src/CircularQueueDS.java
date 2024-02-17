

public class CircularQueueDS {
    public static void main(String[] args) {

        CircularQueue q1 = new CircularQueue(10);

        for (int i = 1; i<=11; i++){
            q1.enqueue(i*i*i);
        }
        q1.printQueue();
        q1.enqueue(4353);
        System.out.println("sdgf dsgf");
        q1.printQueue();


    }
}

class CircularQueue{
    int maxSize;
    int size;
    int nextValidSlot;
    int [] queue;

    public CircularQueue(int maxSize) {
        this.maxSize = maxSize;
        queue = new int[maxSize];
        this.size = 0;
        this.nextValidSlot = 0;
    }

    public void enqueue(int val){

        queue[nextValidSlot] = val;
        nextValidSlot = (nextValidSlot + 1) % maxSize;
        if(size < maxSize){
            size++;
        }
    }

    public int getMaxSize() {
        return maxSize;
    }

    public int getSize() {
        return size;
    }

    public int getNextValidSlot() {
        return nextValidSlot;
    }

    public void printQueue(){
        int temp = nextValidSlot;
        int index = temp;
        for (int i = 0; i<size; i++){
            if (size== maxSize) {
                System.out.println(index + ": " + queue[temp] + " \n");
                temp = (temp + 1) % maxSize;
                index++;
            }else{
                System.out.println(i + ": " + queue[i] + " \n");
            }

        }
    }
}
