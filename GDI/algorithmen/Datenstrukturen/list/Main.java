
public class Main {

    static List sampleList = new List();

    public static void main(String[] args) {
        createSampleList();

        sampleList.printList();

    }

    static void createSampleList() {
        sampleList.add(1);
        sampleList.add(2);
        sampleList.add(7);
        sampleList.add(8);
    }

    // static void removeFromSampleList(){
    // // sampleList.remove(7);
    // }
}
