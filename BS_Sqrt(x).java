class Solution {
    public int mySqrt(int n) {
        long low = 0, high = n, ans = 1;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int) high;
    }
}