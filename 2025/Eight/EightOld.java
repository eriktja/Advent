package Eight;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class EightOld {
    public static long Work(ArrayList<String> input){
       long result = part1(input, 10);

       return result;
    }

    public static long part1(ArrayList<String> input, int n){
        ArrayList<Junction> junctions = new ArrayList<>();

        for (int i = 0; i < input.size(); i++) {
            String s =  input.get(i);
            junctions.add(new Junction(i, s));
        }

        HashMap<Integer, Circuits> circuits = new HashMap<>();
        ArrayList<Connection> connections = new ArrayList<>();

        for (int i = 0; i < junctions.size(); i++) {
            for (int j = i + 1; j < junctions.size(); j++) {
                Junction j1 = junctions.get(i);
                Junction j2 = junctions.get(j);

                long distance = j1.distance(j2);

                connections.add(new Connection(j1, j2, distance));

            }
        }

        connections.sort((a,b) -> Math.toIntExact((a.distance - b.distance)));


        for (int i = 0; i < n; i++) {
            Connection c = connections.get(i);
            Junction j1 = c.j1;
            Junction root = findRoot(j1);
            Junction j2 = c.j2;
            Junction root2 = findRoot(j2);

            if (circuits.containsKey(root.id)) {
                HashSet<Integer> root2Children = new HashSet<>();
                root2Children.add(root2.id);
                if (circuits.containsKey(root2.id)) {
                   root2Children.addAll(circuits.get(root2.id).junctions);
                   circuits.remove(root2.id);
                }

                circuits.get(root.id).junctions.addAll(root2Children);
            }
            else {
                HashSet<Integer> set = new HashSet<>();
               set.add(j1.id);
               set.add(j2.id);
               circuits.put(root.id, new Circuits(root.id, set));
            }


        }

        return 0L;
    }

    public static long first(ArrayList<String> input, int n) {
        long result = 0;

        ArrayList<Junction> junctions = new ArrayList<>();

        for (int i = 0; i < input.size(); i++) {
            String s =  input.get(i);
            junctions.add(new Junction(i, s));
        }

        ArrayList<Pairs> pairs = new ArrayList<>();
        HashMap<Integer, Junction> startJunctions = new HashMap<>();

        for (int iter = 0; iter < n; iter++) {
            long minDiff = Long.MAX_VALUE;
            Junction bestJ1 = null;
            Junction bestJ2 = null;


            for (int i = 0; i < junctions.size(); i++) {
                for (int j = i + 1; j < junctions.size(); j++) {
                    Junction j1 = junctions.get(i);
                    Junction j2 = junctions.get(j);

                     if (findRoot(j1).id == findRoot(j2).id) continue;


                    if (j1.id == j2.id) continue;

                    long diff = j1.distance(j2);

                    if (diff < minDiff) {
                        bestJ1 = j1;
                        bestJ2 = j2;
                        minDiff = diff;
                    }
                }
            }

            if (bestJ1 == null) continue;

            Junction rootJ1 = findRoot(bestJ1);
            Junction rootJ2 = findRoot(bestJ2);

            if (rootJ1.id == rootJ2.id) continue;

            var p = new Pairs(bestJ1.id, bestJ2.id);
            pairs.add(p);


            int oldrootJ2 = rootJ2.id;
            rootJ2.root = rootJ1;
            rootJ1.children.add(rootJ2);

            if (!startJunctions.containsKey(rootJ1.id)) {
                startJunctions.put(rootJ1.id, rootJ1);
            }

            if (oldrootJ2 != rootJ1.id) {
                startJunctions.remove(oldrootJ2);
            }
        }


        for (Junction j1 : startJunctions.values()) {
            printAll(j1, 1);
        }
        result = count(startJunctions);

        return result;
    }

    public static void printAll(Junction j, int depth) {
        for (int i = 0; i < depth; i++) {
            System.out.print("-");
        }
        System.out.println(j.id);
        for (Junction j2 : j.children) {
            printAll(j2, depth+1);
        }
    }

    public static Junction findRoot(Junction j) {
        if (j.root != j)
            j.root = findRoot(j.root);
        return j.root;
    }

    public static long countNodes(Junction j) {
        if (j.children.isEmpty()) return 1;
        long result = 1;
        for (Junction child : j.children) {
            result += countNodes(child);
        }
        return result;
    }

    public static long count(HashMap<Integer, Junction> junctionMap) {
        long l1 = 1;
        long l2 = 1;
        long l3 = 1;

        for (Junction j : junctionMap.values()) {
            long c = countNodes(j);
            if (c > l1) {
                l3 = l2;
                l2 = l1;
                l1 = c;
            }
            else if (c > l2) {
                l3 = l2;
                l2 = c;
            }
            else if (c > l3) {
                l3 = c;
            }
        }

        return l1 * l2 * l3;
    }
}