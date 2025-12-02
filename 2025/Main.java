import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import Two.Two;


public class Main {
    public static void main(String[] args){
        var data = readFromFile("solutionTwo/input.txt");
        // var data = readFromFile("solutionTwo/testInput.txt");
        int result = Two.Work(data);

        System.out.printf("ANSWER: %d\n", result);
    }


    private static ArrayList<String> readFromFile(String path) {
        File myObj = new File(path);
        ArrayList<String> data = new ArrayList<String>();
        // try-with-resources: Scanner will be closed automatically
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