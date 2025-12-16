package Eleven;

import java.util.*;

public class Eleven {
    public static long Work(ArrayList<String> input){
       return second(input);
    }

    public static long first(ArrayList<String> input){
        var io = build(input);

        String start = "you";
        String end = "out";
        String current = start;

        long result = findOut(io, start, end, 0, new HashSet<>(), new HashSet<>());

        return result;
    }

    public static long second(ArrayList<String> input){
        HashMap<String, Set<String>> io = build(input);

        String start = "svr";
        String end = "out";

        var contacts = new HashSet<String>();
        contacts.add("dac");
        contacts.add("fft");
        long result = findOut(io, start, end, 0, contacts, new HashSet<>());

        return result;
    }

    private static long findOut(HashMap<String, Set<String>> io, String start, String end, long count, Set<String> contacts, Set<String> visited){
        Set<String> outs = io.get(start);

        if (outs == null){
            return count;
        }

        for (String s : outs) {
            if (visited.contains(s)) {
                //System.out.println("Visited " + s);
               continue;
            }
            visited.add(s);
            //System.out.println(visited.size() + " " + s);
            if (s.equals(end)){
                if (!contacts.isEmpty()){
                    visited.remove(s);
                    //System.out.println("FOUNT OUT TOO SOON");
                    return count;
                }
                //System.out.println("FOUND OUT");
                count++;
            }
            else if (contacts.remove(s)) {
                //System.out.println("REMOVE " + s);
                count = findOut(io, s, end, count, contacts, visited);
                contacts.add(s);
            }
            else {
                //System.out.println("CONTINUE: " + s);
                count = findOut(io, s, end, count, contacts, visited);
            }
            visited.remove(s);
        }
        return count;
    }

    private static HashMap<String, Set<String>> build(ArrayList<String> input){
        HashMap<String, Set<String>> io = new HashMap<>();

        for (String s : input) {
            String[] inputOutput =  s.split(":");
            String in = inputOutput[0];
            String[] out = inputOutput[1].trim().split(" ");

            Set<String> outSet = new HashSet<>(Arrays.asList(out));
            for (String string : out) {
                String st = string.trim();
                if (st.isEmpty()) continue;
                outSet.add(st);
            }

            io.put(in, outSet);
        }
        return io;
    }
}