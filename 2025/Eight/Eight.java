package Eight;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.function.BiConsumer;
import java.util.function.Function;

public class Eight {
    public static long Work(ArrayList<String> input) {
        return part1(input, 1000);
    }
    public static long part1(ArrayList<String> input, int n) {

        ArrayList<Junction> junctions = new ArrayList<>();
        for (int i = 0; i < input.size(); i++) {
            junctions.add(new Junction(i, input.get(i)));
        }

        int count = junctions.size();

        ArrayList<Connection> connections = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                Junction a = junctions.get(i);
                Junction b = junctions.get(j);
                long d = a.distance(b);
                connections.add(new Connection(a, b, d));
            }
        }

        connections.sort(Comparator.comparingLong(c -> c.distance));

        int[] parent = new int[count];
        int[] size = new int[count];

        for (int i = 0; i < count; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        Function<Integer, Integer> find = new Function<>() {
            @Override
            public Integer apply(Integer x) {
                if (parent[x] != x)
                    parent[x] = apply(parent[x]);
                return parent[x];
            }
        };

        BiConsumer<Integer, Integer> union = (a, b) -> {
            int ra = find.apply(a);
            int rb = find.apply(b);
            if (ra == rb) return;

            if (size[ra] < size[rb]) {
                parent[ra] = rb;
                size[rb] += size[ra];
            } else {
                parent[rb] = ra;
                size[ra] += size[rb];
            }
        };

        for (int i = 0; i < n; i++) {
            Connection c = connections.get(i);
            union.accept(c.j1.id, c.j2.id);
        }

        HashMap<Integer, Integer> groups = new HashMap<>();

        for (int i = 0; i < count; i++) {
            int r = find.apply(i);
            groups.put(r, groups.getOrDefault(r, 0) + 1);
        }

        ArrayList<Integer> sizes = new ArrayList<>(groups.values());
        sizes.sort(Comparator.reverseOrder());

        if (sizes.size() < 3)
            throw new RuntimeException("Less than three circuits!");

        long a = sizes.get(0);
        long b = sizes.get(1);
        long c = sizes.get(2);

        return a * b * c;
    }


}
