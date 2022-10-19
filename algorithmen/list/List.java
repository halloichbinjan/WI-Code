public class List {

    class ListElement {

        ListElement previous;
        ListElement next;
        int value;

    }

    ListElement root;
    ListElement last;

    void add(int v) {
        ListElement newElement = new ListElement();
        newElement.value = v;

        // Wenn Liste leer ist wird neues Element eingefügt und wird erstes und letztes
        // Element.
        if (this.isEmpty()) {

            root = newElement;
            last = newElement;
            root.next = null;

            // Wenn Liste nicht leer ist wird neues Element ans Ende der Liste eingefügt und
            // wird somit letztes Element.
            // Das vorherige letzte Element wird das previous Element vom neuen Letzten.
        } else {
            newElement.previous = last;
            last.next = newElement;
            last = newElement;

        }
    }

    boolean contains(int v) {
        boolean contains = false;
        if (!this.isEmpty()) {
            ListElement current = root;
            while (current != null) {
                if (current.value == v) {
                    contains = true;
                    break;
                } else
                    current = current.next;
            }
        }

        return contains;

    }

    boolean isEmpty() {
        return root == null;
    }

    void remove(int v) {
        if (!this.isEmpty()) {

            ListElement current = root;

            while (current != null) {

                if (current.value == v) {
                    if (current == root) {
                        if (current.next != null) {
                            root = current.next;
                            current.next.previous = null;
                        } else {
                            root = null;
                            last = null;
                            current = null;
                        }

                    } else if (current == last) {

                        last = current.previous;
                        current.previous.next = null;

                    } else {
                        current.previous.next = current.next;
                        current.next.previous = current.previous;
                    }
                    break;
                } else {
                    if (current.next != null) {
                        current = current.next;
                    } else
                        current = null;
                }
            }
        } // Andernfalls kann kein Element removet werden, da die Liste leer ist
    }

    void printList() {
        ListElement current = root;
        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }

}