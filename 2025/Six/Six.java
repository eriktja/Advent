package Six;
import java.util.ArrayList;
import java.util.List;

public class Six {
    public static long Work(ArrayList<String> input){
       long result = second(input);

       
       return result;
    }

    private static long first(ArrayList<String> input){
        ArrayList<ArrayList<String>> matrix = buildMatrix(input);
        long result = 0;
        for (ArrayList<String> col : matrix) {
            String operator = col.getLast();
            long sum = 0;

            result += sum(col.subList(0, col.size() - 1), operator);
        }

        return result;
    }

    private static long second(ArrayList<String> input){
        long result = 0;

        int longest = findLongest(input);

        ArrayList<String> nums = new ArrayList<>();
        for (int i = longest -1; i >= 0; i--) {
            String a = "";
            for (int j = 0; j < input.size(); j++) {
                String s = input.get(j);

                if (s.length() > i) {
                    char c = s.charAt(i);
                    
                    a = a + String.format("%c",c);
                }
            }
            nums.add(a);

            if (a.contains("*") || a.contains("+")) {
                result +=calculate(nums);
                nums.clear();
            }

        }
        
        return result;
    }

    private static long calculate(List<String> nums) {
        long result = 0;

        var s = nums.getLast();
        char operator = s.charAt(s.length() - 1);

        for (int i = 0; i < nums.size(); i++) {
            String n = nums.get(i).trim();
            
            if (n.length() == 0) continue;

            if (i == nums.size() - 1) {
                n = n.substring(0, n.length() - 1);
            }

            long num = Long.parseLong(n.trim());

            if (operator == '*') {
                if (result == 0) result = 1;
                result *= num;
            }
            else {
                result += num;
            }
        }

        return result;
    }

    private static int findLongest(List<String> input) {
        int longest = 0;

        for (String s : input) {
            if (s.length() > longest) {
                longest = s.length();
            }
        }

        return longest;
    }

    private static long sum(List<String> input, String operator){
        long result = 0;
        if (operator.equals("+")) {
            for (String s :  input) {
                result += Integer.parseInt(s);
            }
        }
        else if (operator.equals("*")) {
            result = 1;
            for (String s :  input) {
                result *= Integer.parseInt(s);
            }
        }
        else {
            System.out.println("ILLEGAL OPERATOR");
        }

            return result;
    }

    private static ArrayList<ArrayList<String>> buildMatrix(ArrayList<String> input){
        ArrayList<ArrayList<String>> matrix = new ArrayList<>();

        for (String s : input) {
            String[] columnData =  s.trim().split("\\s+");
            for (int i = 0; i < columnData.length; i++) {
                if (matrix.size() <= i) {
                    matrix.add(new ArrayList<>());
                }

                var column = matrix.get(i);

                column.add(columnData[i]);
            }
        }

        return matrix;
    }
}