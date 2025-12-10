package Eight;

public class Connection {
    public Junction j1;
    public Junction j2;
    public long distance;

    public Connection(Junction j1, Junction j2, long distance) {
        this.j1 = j1;
        this.j2 = j2;
        this.distance = distance;
    }
}
