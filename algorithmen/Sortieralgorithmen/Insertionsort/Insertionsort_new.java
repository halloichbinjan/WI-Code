public class Insertionsort_new {
    static int[] arr = { 3, 5, 6, 2, 9, 7 };

    public static void main(String[] args) {
        sort();
        printArray();
    }

    static void sort() {
        for (int i = 1; i < arr.length; i++) {
            int elementToSort = arr[i];
            int j = i;

            while (j > 0 && elementToSort < arr[j - 1]) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = elementToSort;

        }
    }

    static void printArray() {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
    }
}
