public class Main {

    static Queue sampleQueue = new Queue();

    public static void main(String[] args) {
        createSampleQueue();
        sampleQueue.printQueue();
    }

    static void createSampleQueue() {
        sampleQueue.offer(1);
        sampleQueue.offer(2);
        sampleQueue.offer(3);
        sampleQueue.offer(4);
    }
}
