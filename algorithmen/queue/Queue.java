public class Queue {

    QueueElement root;

    public class QueueElement {
        int value;
        QueueElement next;
    }

    boolean isEmpty() {
        boolean empty = false;
        if (root == null)
            empty = true;
        return empty;
    }

    void offer(int v) {
        QueueElement newQueueElement = new QueueElement();
        newQueueElement.value = v;

        if (isEmpty())
            root = newQueueElement;
        else {
            QueueElement current = root;
            while (current.next != null)
                current = current.next;
            current.next = newQueueElement;
        }
    }

    void poll() {
        if (!isEmpty())
            root = root.next;
    }

    void printQueue() {
        QueueElement current = root;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }
}
