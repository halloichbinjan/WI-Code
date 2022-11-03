public class Stack {

    class StackElement {
        StackElement next;
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

    int pop() {
        if (!isEmpty()) {
            int res = top.value;
            top = top.next;
            return res;
        } else {
            // Wenn Stack leer ist:
            return -1;
        }
    }

    void printStackTopToBottom() {
        StackElement current = top;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }
}