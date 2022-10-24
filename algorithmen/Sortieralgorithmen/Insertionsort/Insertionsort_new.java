// Übungsblatt 4 - Aufgabe 1c)

public class Insertionsort_new {

    static int[] arr = { 3, 5, 6, 2, 9, 7 };

    public static void main(String[] args) {
        sort();
        printArray();
    }

    // ------------------------------------------------------------------------------------------------------------------------
    // Das ist die Methode, die den Insertionsort macht. Alles andere könnt ihr
    // ignorieren (das static davor auch)
    // ------------------------------------------------------------------------------------------------------------------------

    static void sort() {
        // Mit der ersten for-Schleife wird über das Array itereriert, sodass jeder Wert
        // an seine entsprechende (sortierte) Stelle im Array verschoben werden kann.
        for (int i = 1; i < arr.length; i++) {
            // Das aktuelle Element im Array ist das, welches in den nächsten Schritten
            // verschoben werden soll
            int elementToSort = arr[i];

            // Um die anderen Elemente entsprechend zu verschieben müssen wir uns den Wert
            // vom aktuellen i (also dem Index, dessen Element grade verschoben werden soll)
            // seperat speichern, um ihn verändern zu können, ohne dass das eigentliche i
            // und damit die Iteration durcheinander gerät.
            int j = i;

            // Mithilfe von j können wir nun verschieben.
            // Bedingungen in der Schleife:
            // 1.
            // Wenn j 0 wird sind wir ganz am Anfang vom Array und es kann nicht weiter
            // verglichen werden
            // Somit muss das Element dort eingefügt werden und ist dementsprechend das
            // kleinste im Array.
            // 2.
            // Es wird auch vergleichen, ob das zu sortierende Element kleiner ist, als das
            // vor (/"links") von ihm. Tritt das nicht mehr ein ist die Stelle gefunden,
            // an der es eingefügt werden muss und es die Schleife ist beendet.
            while (j > 0 && elementToSort < arr[j - 1]) {
                // Damit keine Elemente ersetzt werden, die noch benötigt werden, müssen alle
                // Elemente, mit denen hier verglichen werden und nach denen
                // entsprechend nicht eingefügt werden, einen Index nach rechts verschoben
                // werden.
                // Dafür setzen wir bevor wir weiter nach links / vorne iterieren das aktuelle
                // Element welches wir vergleichen auf das mit dem wir vergleichen
                // Das Element vor dem aktuellen existiert nun also doppelt, einmal an der
                // eigentlichen Stelle und zusätzlich an der atuellen Stelle (vom Element aus
                // gesehen 1 weiter rechts / hinten)
                // Dadurch, dass das nächste Element auch wieder einen nach rechts verschoben
                // wird usw. bis das aktuelle Element auf das zu sortierende Element gesetzt
                // wird,
                // haben wir temporär immer nur ein Element, welches kopiert ist, das es im
                // nächsten Durchlauf der while-Schleife immer wieder ersetzt wird.
                arr[j] = arr[j - 1];

                // Wir arbeiten uns solange nach links, bis wir die passende Stelle gefunden
                // haben. Daher das minus minus
                j--;
            }

            // Wir haben die passende Stelle gefunden und den dort aktuellen Wert bereits
            // nach rechts kopiert (genau wie alle vorher).
            // Wenn wir jetzt das aktuelle Element durch das zu sortierende ersetzen, sind
            // alle Elemente zwischen dieser Stelle und der Stelle an der wir
            // gestartet sind einen nach rechts verschoben worden und das Ausgangselement an
            // die richtige Stelle eingefügt worden.
            arr[j] = elementToSort;

        }
    }

    static void printArray() {
        int n = arr.length;
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
    }
}
