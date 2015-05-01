package reverser;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class LineReverser {

    private List<String> lines;
    private List<String> reversedLines;
    private String fileName;

    private LineReverser(String fileName) {
        this.fileName = fileName;
    }

    public static void reverseLines(String fileName) throws IOException {
        LineReverser reverser = new LineReverser(fileName);
        reverser.reverseLinez();
        reverser.saveToFile();
    }

    private void reverseLinez() throws FileNotFoundException {
        Scanner scanner = readLines();
        reversedLines = new LinkedList<String>();
        reverseLineList();
        scanner.close();
    }

    private Scanner readLines() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(fileName));
        lines = new LinkedList<String>();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            addLine(line);
        }
        return scanner;
    }

    private void addLine(String line) {
        lines.add(line);
    }

    private void reverseLineList() {
//    	for (int i = 0; i < lines.size(); i++) {
//    		moveLine(i);
//    	}
//        for (int i=lines.size(); i>0; --i) {
//            moveLine(i);
//        }
    	for (String line : lines) {
    		reversedLines.add(0, line);
    	}
    }

//    private void moveLine(int i) {
////    	reversedLines.add(lines.get(i));
////        reversedLines.add(lines.get(i-1));
//    }

    private void saveToFile() throws IOException {
        PrintWriter writer = new PrintWriter(new FileWriter(fileName + ".reversed"));
        for (String line : reversedLines) {
            writer.println(line);
        }
        writer.close();
    }

}
