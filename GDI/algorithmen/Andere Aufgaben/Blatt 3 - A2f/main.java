public class main {
    static int[] arr = { 4, 3, 2, 1, 5, 3, 2, 8, 9 };

    public static void main(String[] args) {
        System.out.println(find(arr, 1));

    }

    // Eine for-Schleife die einfach einmal das Array durchgeht und checkt, ob der
    // Wert gefunden ist.
    // Einmal mit einer for-Schleife das Array durchgehen ist O(n)
    static int find(int[] pArr, int pValue) {
        for (int i = 0; i < pArr.length; i++) {
            if (pArr[i] == pValue)
                return i;
        }
        return -1;
    }
}