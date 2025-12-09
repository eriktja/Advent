package Eight;

public class Pairs {
    public int a;
    public int b;

    public Pairs(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public boolean compare(Pairs o) {
        return this.a == o.a && this.b == o.b || this.a == o.b && this.b == o.a;
    }
}
