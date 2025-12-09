package Nine;

import java.util.ArrayList;

public class Nine {
    public static long Work(ArrayList<String> input){
       return first(input);
    }

    public static long first(ArrayList<String> input){
        ArrayList<Point>  points = new ArrayList<Point>();

        for (String s : input){
            points.add(new Point(s));
        }

        long largest = 0;

        for (int i = 0; i<points.size(); i++){
            for (int j = i+1; j<points.size(); j++){
                Point p1 = points.get(i);
                Point p2 = points.get(j);

                long area = area(p1, p2);
                if (area > largest){
                    //System.out.println("P1: X: " + p1.x + " Y: " + p1.y);
                    //System.out.println("P2: X: " + p2.x + " Y: " + p2.y);
                    //System.out.println("AREA: " + area);
                    largest = area;
                }
            }
        }

        return largest;
    }

    public static long area(Point p1,  Point p2){
        int x = Math.abs(p1.x - p2.x) + 1;
        int y = Math.abs(p1.y - p2.y) + 1;
        long area =  (long) x *y;
        //System.out.println("P1: X: " + p1.x + " Y: " + p1.y);
        //System.out.println("P2: X: " + p2.x + " Y: " + p2.y);
        //System.out.println("AREA: " + area);
        return area;
    }
}