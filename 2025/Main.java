import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import Five.Five;
import Four.Four;


public class Main {
    public static void main(){
        ArrayList<String> data = readFromFile("Five/input.txt");
        //ArrayList<String> data = readFromFile("Five/testInput.txt");
        long result = Five.Work(data);

        System.out.printf("ANSWER: %d\n", result);

        long expect = 14;
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