public class Solution {
        public static int[] generateFibonacciNumbers(int n) {
                int[] result = new int[n];
                generateFibonacci(0, n, result);
                return result;
        }

        public static void generateFibonacci(int i, int n, int[] result) {
                if (i >= n) {
                        return;
                }

                if (i <= 1) {
                        result[i] = i; // Set the first two Fibonacci numbers to 0 and 1
                } else {
                        result[i] = result[i - 1] + result[i - 2];
                }

                generateFibonacci(i + 1, n, result);
        }
}

// Other Solution without Recursion

/*
public class Solution {
    public static int[] generateFibonacciNumbers(int n) {
        int []fib = new int[n];  // Create a vector to store the Fibonacci numbers
        fib[0] = 0;          // First Fibonacci number
        if(n < 2)
            return fib;
        fib[1] = 1;          // Second Fibonacci number

        // Generate the Fibonacci numbers
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];  // Compute the next Fibonacci number
        }

        return fib;
    }
}

LeetCode Solution
class Solution {
    public int fib(int n) {
        if(n == 0){
            return 0;
        }

        if(n == 1 || n == 2){
            return 1;
        }

        return fib(n-1)+fib(n-2);

    }
}

*/
