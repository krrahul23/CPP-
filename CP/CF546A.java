import java.io.*;
import java.util.*;

/**
 * Simple yet moderately fast I/O routines. Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 * Kattio-instance, otherwise, you may lose output.
 *
 * - The nextInt(), nextDouble(), and nextLong() methods will throw an exception
 * if there is no more data in the input.
 *
 * @author: Kattis
 */

public class CF546A {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        long k = io.nextLong();
        long n = io.nextLong();
        long w = io.nextLong();

        long sum = k * (w * (w + 1) / 2) - n;
        io.println(Math.max(0, sum));
        io.close(); // make sure to include this line -- closes io and flushes the output
    }
}

class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;

    // standard input
    public Kattio() {
        this(System.in, System.out);
    }

    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }

    // USACO-style file input
    public Kattio(String problemName) throws IOException {
        // super(new FileWriter(problemName + ".out"));
        // r = new BufferedReader(new FileReader(problemName + ".in"));
        super(new FileWriter("./output.txt"));
        r = new BufferedReader(new FileReader("./input.txt"));
    }

    // returns null if no more input
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {
        }
        return null;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}