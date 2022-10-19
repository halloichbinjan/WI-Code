public class Stack {

    class StackElement {
        StackElement next;
        StackElement previous;
        int value;
    }

    StackElement top;

    boolean isEmpty() {
        boolean empty = false;
        if (top == null)
            empty = true;
        return empty;
    }

    void push(int v) {
        StackElement newStackElement = new StackElement();
        newStackElement.value = v;

        if (isEmpty())
            top = newStackElement;
        else {
            top.next = newStackElement;
            newStackElement.previous = top;
            top = newStackElement;

        }
    }

    void pop() {
        if (!isEmpty()) {
            top.previous.next = null;
            top = top.previous;
        }
    }

    void printStackReverse() {
        StackElement current = top;
        while (current != null) {
            System.out.println(current.value);
            current = current.previous;
        }
    }
}