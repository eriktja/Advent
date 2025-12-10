import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import Eight.Eight;

public class Main {
    public static void main(){
        ArrayList<String> data = readFromFile("Eight/input.txt");
       // ArrayList<String> data = readFromFile("Eight/testInput.txt");

        //ArrayList<String> data = readFromFile("Nine/input.txt");
        //ArrayList<String> data = readFromFile("Nine/testInput.txt");

        long result = Eight.Work(data);
        //long result = Nine.Work(data);

        System.out.printf("ANSWER: %d\n", result);

        long expect = 50;
        System.out.printf("TEST: %s%n", result == expect ? "Passed" : "Failed");
    }


    private static ArrayList<String> readFromFile(String path) {
        File myObj = new File(path);
        ArrayList<String> data = new ArrayList<String>();

        try (Scanner myReader = new Scanner(myObj)) {
            while (myReader.hasNextLine()) {
                data.add(myReader.nextLine());
            }


        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        return data;
    }
}