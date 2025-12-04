package Four;

import java.util.ArrayList;

public class Four {
    public static int Work(ArrayList<String> input) {
        return second(input);
    }

    public static int first(ArrayList<String> data) {
        int result = 0;
        for (int y = 0; y < data.size(); y++) {
            String s = data.get(y);

            for (int x = 0; x < s.length(); x++) {

                int adjacentRollCount = 0;
                if (s.charAt(x) == '.') {
                    continue;
                }

                // top left
                if (spotHasRoll(data, x-1, y-1)) {
                    adjacentRollCount++;
                }

                // top
                if (spotHasRoll(data, x, y-1)) {
                    adjacentRollCount++;
                }

                // top right
                if (spotHasRoll(data, x+1, y-1)) {
                    adjacentRollCount++;
                }

                // right
                if (spotHasRoll(data, x+1, y)) {
                    adjacentRollCount++;
                }

                // bottom-right
                if (spotHasRoll(data, x+1, y+1)) {
                    adjacentRollCount++;
                }

                // bottom
                if (spotHasRoll(data, x, y+1)) {
                    adjacentRollCount++;
                }

                // bottom left
                if (spotHasRoll(data, x-1, y+1)) {
                    adjacentRollCount++;
                }

                // left
                if (spotHasRoll(data, x-1, y)) {
                    adjacentRollCount++;
                }

                if (adjacentRollCount < 4) {
                    s = replaceCharAtIndex(s, x, 'x');
                    data.set(y, s);
                    result++;
                }
            }
        }

        return result;
    }

    public static boolean spotHasRoll(ArrayList<String> data, int x, int y) {
        if (y >= 0 && y < data.size() && x >= 0 && x < data.get(y).length()) {
            String line = data.get(y);
            return line.charAt(x) != '.';
        }
        return false;
    }



    public static int second(ArrayList<String> data) {
        int result = 0;
        int prevResult = 0;

        do {
            prevResult = result;
            int a = first(data);
            result += a;
            cleanUpX(data);
        } while(result != prevResult);



        return result;
    }

    public static String replaceCharAtIndex(String input, int index, char ch) {
        return input.substring(0, index) + ch + input.substring(index + 1);
    }

    public static void cleanUpX(ArrayList<String> data) {
        for (int i = 0; i < data.size(); i++) {
            String s = data.get(i);
            s = s.replaceAll("x", ".");
            data.set(i, s);
        }
    }
}