public class Main {

    static Stack sampleStack = new Stack();

    public static void main(String[] args) {
        createSampleStack();
        sampleStack.printStackTopToBottom();
    }

    static void createSampleStack() {
        sampleStack.push(4);
        sampleStack.push(3);
        sampleStack.push(2);
        sampleStack.push(1);

    }

}
