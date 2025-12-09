package Nine;

public class Point {
    public int x;
    public int y;

    public Point(String s) {
        String[] sub =  s.split(",");
        x = Integer.parseInt(sub[0].trim());
        y = Integer.parseInt(sub[1].trim());
    }
}
