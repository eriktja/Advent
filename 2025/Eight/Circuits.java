package Eight;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Circuits {
    public int id;
    public Set<Integer> junctions = new HashSet<>();

    public Circuits(int id, Set<Integer> junctions) {
        this.id = id;
        this.junctions = junctions;
    }
}
