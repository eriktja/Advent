package Two;
import java.util.ArrayList;

public class Two {
    public static int Work(ArrayList<String> input){
        int result = 0;

        String data = input.get(0);

        String[] ranges = data.split(",");

        for (int i = 0; i < ranges.length; i++) {
            String[] range = ranges[i].split("-");
            long start = Long.parseLong(range[0]);
            long end = Long.parseLong(range[1]);

            System.out.printf("Start: %d\nEnd: %d", start, end);

            result += Do(start, end);
        }


        return result;
    }

    public static int Do(long start, long end) {
        int result = 0;


        return result;
    }
}