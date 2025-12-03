package Two;
import java.util.ArrayList;

public class Two {
    public static long Work(ArrayList<String> input){
        long result = 0;

        String data = input.get(0);

        String[] ranges = data.split(",");

        for (int i = 0; i < ranges.length; i++) {
            String[] range = ranges[i].split("-");
            long start = Long.parseLong(range[0]);
            long end = Long.parseLong(range[1]);

            // System.out.printf("Start: %d\nEnd: %d\n\n", start, end);

            result += Do(start, end);
        }


        return result;
    }

    public static long Do(long start, long end) {
        long result = 0;

        while (start <= end) {
            if (SecondCheck(start)) {
                result+=start;  
            }
            start++;
        }

        return result;
    }

    public static boolean FirstCheck(long number) {
        String textNumber = String.format("%d", number);
        int half = textNumber.length() / 2;
        String firstHalf = textNumber.substring(0, half);

        if (firstHalf.startsWith("0")) {
            return false;
        } 

        String secondHalf = textNumber.substring(half, textNumber.length());
        return firstHalf.equals(secondHalf);
    }

    public static boolean SecondCheck(long number) {
        String textNumber = String.format("%d", number);

        for (int i = 0; i < textNumber.length() / 2; i++) {
            
            String subString = textNumber.substring(0, i+1);
            int step = subString.length();
            
            for (int j = step; j < textNumber.length(); j += step) {
            
                String check = textNumber.substring(j, Math.min(j + step, textNumber.length()));
            
                if (!subString.equals(check)) {
                    break;
                }

                if (step + j == textNumber.length()) {
                    return true;
                }
            }
        }
        
        return false;
    }
}