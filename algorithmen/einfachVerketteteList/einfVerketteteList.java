public class einfVerketteteList {
    class ListElement {

        ListElement next;
        int value;

    }

    ListElement root;
    // ListElement last;

    void add(int v) {
        ListElement newListElement = new ListElement();
        newListElement.value = v;
        if (isEmpty()) {
            root = newListElement;
            // last = newListElement;
        } else {
            // last.next = newListElement;
            // last = newListElement;
            ListElement current = root;
            while (current.next != null) {
                current = current.next;
            }

            current.next = newListElement;
        }

    }

    boolean isEmpty() {
        // boolean empty = false;
        // if(root == null){
        // empty = true;
        // }

        return root == null;
    }
}
