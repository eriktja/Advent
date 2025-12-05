package Five;

import java.util.ArrayList;
import java.util.List;

public class Five {
    public static long Work(ArrayList<String> input){
       long result = 0;

        result = second(input);
       
       return result;
    }

    public static int first(ArrayList<String> input){
        int result = 0;
        ArrayList<Range> freshIds = new ArrayList<>();
        int splitIndex = input.indexOf("");

        // GET FRESH IDS
        for (int i = 0; i < splitIndex; i++){
            String[] idStartStop =  input.get(i).split("-");
            long start = Long.parseLong(idStartStop[0]);
            long stop = Long.parseLong(idStartStop[1]);

            freshIds.add(new Range(start, stop));

        }

        for (int i = splitIndex+1; i < input.size(); i++){
            long id =  Long.parseLong(input.get(i));
            if (freshIds.stream().anyMatch(r -> r.inRange(id))){
                result += 1;
            }
        }

        return result;
    }

    public static long second(ArrayList<String> input){
        long result = 0;
        ArrayList<Range> freshIds = new ArrayList<>();
        int splitIndex = input.indexOf("");

        // GET FRESH IDS
        for (int i = 0; i < splitIndex; i++){
            String[] idStartStop =  input.get(i).split("-");
            long start = Long.parseLong(idStartStop[0]);
            long stop = Long.parseLong(idStartStop[1]);

            freshIds.add(new Range(start, stop));
        }

        for (int i = 0; i < freshIds.size(); i++){
            Range range = freshIds.get(i);
            for (int j = i + 1; j < freshIds.size(); j++){
                Range comp = freshIds.get(j);
                if (range.isOverlapping(comp)){
                    var newStart = Math.min(range.start, comp.start);
                    var newStop = Math.max(range.end, comp.end);
                    freshIds.remove(j);
                    freshIds.remove(i);
                    freshIds.add(new Range(newStart, newStop));
                    i = 0;
                    break;
                }
            }
        }

        for (Range range : freshIds) {
            result += range.end - range.start + 1;
        }

        return result;
    }
}