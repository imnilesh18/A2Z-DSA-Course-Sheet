public class Solution {
        public static int countDigits(int n) {
                int count = 0;
                int temp = n;
                while (temp > 0) {
                        int digit = temp % 10;
                        temp = temp / 10;

                        // Check if the current digit is not zero
                        //(because 980 zero will give ArithmeticException) and is a divisor of n.
                        if (digit != 0 && n % digit == 0) {
                                count += 1;
                        }
                }
                return count;
        }
}
