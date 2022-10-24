public class Stack {

    class StackElement {
        StackElement next;
        // StackElement previous;
        int value;
    }

    StackElement top;

    boolean isEmpty() {
        return top == null;
    }

    void push(int v) {
        StackElement newStackElement = new StackElement();
        newStackElement.value = v;

        if (isEmpty())
            top = newStackElement;
        else {
            newStackElement.next = top;
            top = newStackElement;

        }
    }

    void pop() {
        if (!isEmpty()) {
            top = top.next;
        }
    }

    void printStackReverse() {
        StackElement current = top;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }
}