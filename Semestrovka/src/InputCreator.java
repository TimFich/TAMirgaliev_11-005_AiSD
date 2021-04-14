import java.io.*;

public class InputCreator {
    public static final int NUMBER_OF_SETS = 100;


    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("semestrInput.txt");

        OutputStream os = new FileOutputStream(file);
        PrintWriter pw = new PrintWriter(os);

        for (int i = 1; i <= NUMBER_OF_SETS; i++) {
            for (int j = 0; j <= i*100; j++) {
                int a = (int) (Math.random() * 10);
                pw.print(a+" ");
            }
            pw.println();
        }
    }
}



