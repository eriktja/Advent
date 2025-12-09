package Eight;

import java.util.ArrayList;

public class Junction {
    public int id;
    public int x;
    public int y;
    public int z;

    public Junction root = this;
    public ArrayList<Junction> children = new ArrayList<Junction>();

    public Junction(int id, String coordinates) {
        this.id = id;
        String[] c = coordinates.split(",");
        this.x = Integer.parseInt(c[0].trim());
        this.y = Integer.parseInt(c[1].trim());
        this.z = Integer.parseInt(c[2].trim());
    }

    public long Compare(Junction other) {
        long dx = this.x - other.x;
        long dy = this.y - other.y;
        long dz = this.z - other.z;
        return dx*dx + dy*dy + dz*dz;
    }
}
