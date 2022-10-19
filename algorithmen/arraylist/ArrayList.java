public class ArrayList {
    // BB
    int[] list;

    void add(int value) {
        int[] newList = new int[this.list.length + 1];
        for (int i = 0; i < this.list.length; i++) {
            newList[i] = this.list[i];
        }
        newList[newList.length - 1] = value;
        this.list = newList;
    }

    boolean contains(int value) {
        for (int i = 0; i < this.list.length; i++) {
            if (this.list[i] == value) {
                return true;
            }
        }
        return false;
    }

    boolean isEmpty() {
        return this.list.length == 0;
    }

    void remove(int value) {
        if (this.contains(value)) {
            int[] minusList = new int[this.list.length - 1];
            boolean found = false;
            for (int i = 0; i < this.list.length; i++) {
                if (value == this.list[i]) {
                    found = true;
                }
                if (found) {
                    minusList[i - 1] = this.list[i];
                } else {
                    minusList[i] = this.list[i];
                }
            }

            this.list = minusList;
        }
    }
}
