import java.util.Arrays;

class temp {
    public static void main(String[] args) {
        int[] arr = new int[2];
        arr[0] = 10;
        arr[1] = 3;
        Arrays.sort(arr);
        for (int i : arr)
            System.out.println(i);
    }
}