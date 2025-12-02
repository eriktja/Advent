package One;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class One {
    public static int Work(ArrayList<String> input) {
        int result = 0;

        int value = 50;

        final String regex = "([L|R])([0-9]*)";

        Pattern pattern = Pattern.compile(regex);

        for (int i = 0; i < input.size(); i++) {
            String cmd = input.get(i);

            Matcher matcher = pattern.matcher(cmd);
            if (matcher.matches()) {
                String direction = matcher.group(1);
                int length = Integer.parseInt(matcher.group(2));

                if (direction.equals("L")) {
                    length *= -1;
                }

                if (length > 99 || length < -99) {
                    int rotation = length / 100;
                     result += Math.abs(rotation);
                    length = length % 100;
                }

                int prevValue = value;
                value += length;

                // System.out.printf("CUrrent value after %s : %d = %d\n", direction, length, value);

               
                if (value > 99) {
                    value -= 100;
                    if (prevValue != 0) result++;
                } else if (value < 0) {
                    value += 100;
                    if (prevValue != 0) result++;
                }
                else if (value == 0) {
                    result ++;
                }
                
                

                PrintValue("Value", value);
            }
        }
        

        return result;
    }

    private static void PrintValue(String text, int value) {
        System.out.printf("%s: %d\n",text.toUpperCase(), value);
    }
}
