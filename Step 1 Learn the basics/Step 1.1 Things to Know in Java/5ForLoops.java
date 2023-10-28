import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result = fibo(n);
        System.out.println(result);
    }

    public static int fibo(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        } else {
            int fiboN = 0;
            int first = 1;
            int second = 1;

            for (int i = 3; i <= n; i++) {
                fiboN = first + second;
                second = first;
                first = fiboN;
            }

            return fiboN;
        }
    }
}
