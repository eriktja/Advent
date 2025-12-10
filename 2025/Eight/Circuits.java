package Eight;

import java.util.ArrayList;

public class Circuits {
    public String id;
    public ArrayList<Junction> junctions = new ArrayList<Junction>();

    public Circuits(String id, ArrayList<Junction> junctions) {
        this.id = id;
        this.junctions = junctions;
    }
}
