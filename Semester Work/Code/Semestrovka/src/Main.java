import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        File file = new File("semestrInput.txt");

        Scanner sc = new Scanner(file);

        long st;
        long addTime;
        long removeStart;
        long removeTime;
        long searchStart;
        long searchTime;


        for (int i = 1; i < InputCreator.NUMBER_OF_SETS; i++) {
            RedBlackTree redBlackTree = new RedBlackTree<>();
            ArrayList<Integer> list = new ArrayList<>();
            for (int j = 0; j < i * 100; j++) {
                list.add(sc.nextInt());
            }
            for (int j = 0; j < i * 100; j++) {
                redBlackTree.add(list.get(j));
            }

            st = System.nanoTime();
            redBlackTree.add(10);
            addTime = System.nanoTime() - st;

            searchStart = System.nanoTime();
            redBlackTree.contains(10);
            searchTime = System.nanoTime() - searchStart;

            removeStart = System.nanoTime();
            redBlackTree.remove(10);
            removeTime = System.nanoTime() - removeStart;
            System.out.println("'DATA': " + i * 100 + " 'Add Time': " + addTime + " 'Search Time':" + searchTime + " 'Remove Time': " + removeTime);


        }

    }
}
