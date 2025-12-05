package Five;

public class Range {
    public long start;
    public long end;

    public Range(long start, long end){
        this.start = start;
        this.end = end;
    }

    public boolean inRange(long num) {
        return num >= start && num <= end;
    }

    public boolean isOverlapping(Range other){
        return  (start <= other.start && end >= other.start)
                ||
                (start <= other.end && end >= other.end)
                ||
                (start >= other.start && end <= other.end)
                ||
                (start <= other.start && end >= other.end);
    }
}
