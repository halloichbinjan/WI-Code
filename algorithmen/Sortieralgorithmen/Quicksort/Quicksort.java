public class Quicksort {
    static int[] arr = { 5, 100, 3, 3, 2, 1, 5, 6, 7, 8, 99, 3, 21, 23, 45, 56, 22, 11 };
    static int[] arr2 = { 1, 5, 3, 6, 12, 7, 9, 8 };

    public static void main(String[] args) {
        quicksort(arr);
        printArray();
    }

    static void quicksort(int[] pArr) {
        qsHelper(pArr, 0, arr.length - 1);
    }

    static void qsHelper(int[] pArr, int from, int to) {
        if (to - from <= 1) {
            return;
        }
        int pivot = pArr[to];
        int left = from;
        int right = to - 1;
        if (left >= right) {
            if (pArr[left] > pivot) {

                pArr[to] = pArr[left];
                pArr[left] = pivot;
            }
            return;

        }

        while (left < right) {
            for (; left < right && pArr[left] < pivot; left++)
                ;
            for (; right > left && pArr[right] >= pivot; right--)
                ;
            int value = pArr[left];
            pArr[left] = pArr[right];
            pArr[right] = value;
        }

        if (pArr[left] >= pivot) {
            pArr[to] = pArr[left];
            pArr[left] = pivot;
        } else {
            pArr[to] = pArr[left] + 1;
            pArr[left + 1] = pivot;
        }

        qsHelper(pArr, from, left - 1);
        qsHelper(pArr, left + 1, to);
    }

    static void printArray() {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}
