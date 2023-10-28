public class Solution {
        public static int calcGCD(int n, int m){
                while (n != 0) {
                        int r = m % n;
                        m = n;
                        n = r;
                }
                return m;
        }
}