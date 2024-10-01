/*
 * 1497. Check If Array Pairs Are Divisible by k
 * 
 * Given an array of integers arr of even length n and an integer k.
 * We want to divide the array into exactly n / 2 pairs such that the sum of
 * each pair is divisible by k.
 * Return true If you can find a way to do that or false otherwise.
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
 * Output: true
 * Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
 * 
 * Example 2:
 * Input: arr = [1,2,3,4,5,6], k = 7
 * Output: true
 * Explanation: Pairs are (1,6),(2,5) and(3,4).
 * 
 * Example 3:
 * Input: arr = [1,2,3,4,5,6], k = 10
 * Output: false
 * Explanation: You can try all possible pairs to see that there is no way to
 * divide arr into 3 pairs each with sum divisible by 10.
 * 
 * Constraints:
 * arr.length == n
 * 1 <= n <= 10^5
 * n is even.
 * -10^9 <= arr[i] <= 10^9
 * 1 <= k <= 10^5
 */

//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] mpp = new int[k]; // Array to store remainders frequency

        // Calculate the remainder frequencies
        for (int num : arr) {
            int rem = ((num % k) + k) % k; // Handle negative remainders
            mpp[rem]++;
        }

        // Check if the frequency of numbers with 0 remainder is even
        if (mpp[0] % 2 != 0) {
            return false;
        }

        // Check if each remainder has a complement remainder with matching frequency
        for (int rem = 1; rem <= k / 2; rem++) {
            int counterHalf = k - rem;
            if (mpp[rem] != mpp[counterHalf]) {
                return false;
            }
        }

        return true;
    }
}
