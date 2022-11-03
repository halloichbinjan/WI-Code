public class Mergesort {
    static int[] arr = { 3, 2, 4, 5, 6, 7, 3, 2, 34, 5 };

    public static void main(String[] args) {
        mergesort(arr);
    }

    static void mergesort(int[] pArr) {
        msHelper(pArr, 0, pArr.length - 1);
    }

    static void msHelper(int[] pArr, int from, int to) {
        if (to - from <= 1) {
            return;
        }
        int middle = (from + to) / 2;
        msHelper(pArr, from, middle);
        msHelper(pArr, middle + 1, to);
    }
}