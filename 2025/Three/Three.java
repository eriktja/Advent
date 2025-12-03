package Three;

import java.util.ArrayList;

public class Three {
    public static long Work(ArrayList<String> input){
       long result = 0;
       
       for (var i = 0; i < input.size(); i++) {
        long tmp = second(input.get(i));
        result += tmp;
       }
       
       return result;
    }

    public static int first(String batteries) {
        int result = 0;
        
        int firstIndex = 0;
        int secondIndex = 1;

        int firstValue = 0;
        for (var i = 0; i < batteries.length()-1; i++) {
            int checkValue = Integer.parseInt(batteries.substring(i, i+1));

            if (firstValue < checkValue) {
                firstIndex = i;
                firstValue = checkValue;
            }
        }

        int secondValue = 0;
        for (var i = firstIndex + 1; i < batteries.length(); i++) {
            int checkValue = Integer.parseInt(batteries.substring(i, i+1));

            if (secondValue < checkValue) {
                secondIndex = i;
                secondValue = checkValue;
            }
        }
        
        

        return firstValue * 10 + secondValue;
    }

    public static long second(String batteries) {
        long result = 0;

        int n = 12;

        int[] numbers = new int[n];

        int lastIndex = 0;
        for (int j = 0; j < n; j++) {
            for (int i = lastIndex; i < batteries.length(); i++) {
                int checkValue = Integer.parseInt(batteries.substring(i, i+1));
                
                if (numbers[j] < checkValue) {
                    numbers[j] = checkValue;
                    lastIndex = i + 1;
                }

                int current = i;
                int lastIndexCheck = batteries.length() - n + j;
                if (current >= lastIndexCheck) {
                    break;
                }
                
            }
        }


        for (int i = 0; i < n; i++) {
            long multiplier = (long)Math.pow(10, n - i - 1); 
            result += numbers[i] * multiplier;
        }

        return result;
    }
}