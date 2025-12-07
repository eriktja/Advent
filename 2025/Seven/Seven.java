package Seven;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;


public class Seven {
    public static long Work(ArrayList<String> input){
       long result = 0;
       
       result = second(input);

       return result;
    }


    public static long first(List<String> input) {
        long result = 1;

        HashSet<Integer> beams = new HashSet<>();

        for (int i = 0; i < input.size(); i++) {
            String s = input.get(i);
            if (i == 0) {
                int index = s.indexOf("S");
                beams.add(index);
                continue;
            }

            ArrayList<Integer> splitters = new ArrayList<>();

            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c == '^') {
                    splitters.add(j);
                }
            }

            if (splitters.size() > 0) {

                for (int splitter : splitters) {
                    for (int j = 0; j < beams.size(); j++) {
                        if (!beams.contains(splitter)) continue;

                        Optional<Integer> beamOpt = beams.stream().filter(b -> b == splitter).findFirst();

                        if (!beams.remove(splitter)) continue;

                        int beam = beamOpt.get();

                        if (splitter == beam) {
                            beams.add(beam - 1);
                            beams.add(beam + 1);
                            result++;
                        }
                    }
                }
            }
        }


        return result;

    }

    public static long second(List<String> input) {
        long result = 0;

        HashMap<Integer, Long> timelines = new HashMap<>();

        for (int i = 0; i < input.size(); i++) {
            String s = input.get(i);
            if (i == 0) {
                int index = s.indexOf("S");
                timelines.put(index, 1L);
                continue;
            }

            ArrayList<Integer> splitters = new ArrayList<>();

            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c == '^') {
                    splitters.add(j);
                }
            }

            
            for (int splitter : splitters) {
                if (!timelines.containsKey(splitter)) continue;

                long timelineCount = timelines.remove(splitter);

                updateTimeline(timelines, splitter - 1, timelineCount);
                updateTimeline(timelines, splitter + 1, timelineCount);
            }
        }

        for (var v : timelines.values()) {
            result += v;
        }

        return result;
    }

    private static void updateTimeline(HashMap<Integer, Long> map, int index, long count) {
        if (map.containsKey(index)) {
            long c = map.remove(index);
            map.put(index, count + c);
        } else {
            map.put(index, count);
        }
    }
}