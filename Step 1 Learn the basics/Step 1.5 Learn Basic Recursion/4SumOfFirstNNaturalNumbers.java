public class Solution {
        public static long sumFirstN(long n) {
                if (n == 1) {
                        return 1;
                } else {
                        return n + sumFirstN(n - 1);
                }
        }
}

//Other Solution 
// return  n * (n + 1) / 2;