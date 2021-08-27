import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String readLine() {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
            }
            return line;
        }

    }

    public static Boolean check(ArrayList<Long> temp, int pos) {
        long sum = 0;
        for (int i = 0; i <= pos; i++)
            sum += temp.get(i);
        for (int i = pos + 1; i < temp.size(); i++) {
            if (temp.get(i) > sum)
                return false;
            sum += temp.get(i);
        }
        return true;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        while (t != 0) {
            t--;
            int n = fs.nextInt();
            ArrayList<Long> arr = new ArrayList<Long>();
            for (int i = 0; i < n; i++) {
                Long key;
                key = fs.nextLong();
                arr.add(key);
            }
            ArrayList<Long> temp = arr;
            Collections.sort(temp);
            int low = -1, high = n - 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (check(temp, mid))
                    high = mid;
                else
                    low = mid + 1;
            }
            ArrayList<Integer> ans = new ArrayList<>();
            for (int i = 0; i < arr.size(); i++) {
                if (arr.get(i) >= temp.get(low))
                    ans.add(i);
            }
            System.out.println(ans.size());
            for (int i : ans)
                System.out.print(i + 1 + " ");
            System.out.println();

        }
    }
}