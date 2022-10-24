public class Queue {

    QueueElement root;

    public class QueueElement {
        int value;
        QueueElement next;
    }

    boolean isEmpty() {
        return root == null;
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

    int poll() {
        if (!isEmpty()) {
            int res = root.value;
            if (root.next != null)
                root = root.next;
            else
                root = null;

            return res;
        } else {
            return -1;
        }
    }

    void printQueue() {
        QueueElement current = root;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }
}
