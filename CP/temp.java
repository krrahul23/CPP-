import java.util.*;

public class temp {
    static class Edge implements Comparable<Edge> {
        int a, b, w;

        public Edge(int _a, int _b, int _w) {
            a = _a;
            b = _b;
            w = _w;
        }

        public int compareTo(Edge y) {
            return Integer.compare(w, y.w);
        }
    }

    public static void main(String[] args) {
        int a[] = { 1, 2, 3, 4 };
        System.out.println(a.length);
        a = Arrays.copyOf(a, 2);
        System.out.println(a.length);
        try {
            System.out.println(a[2]);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}