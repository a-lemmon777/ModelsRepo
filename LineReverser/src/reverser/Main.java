package reverser;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        System.out.println("Press <enter> when you're ready to run.");
        System.in.read();
        
        String fileName = args[0];
        LineReverser.reverseLines(fileName);
    }
}
