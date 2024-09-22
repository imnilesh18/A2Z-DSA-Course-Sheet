/*
 * 440. K-th Smallest in Lexicographical Order
 * 
 * Given two integers n and k, return the kth lexicographically smallest integer
 * in the range [1, n].
 * 
 * Example 1:
 * Input: n = 13, k = 2
 * Output: 10
 * Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6,
 * 7, 8, 9], so the second smallest number is 10.
 * 
 * Example 2:
 * Input: n = 1, k = 1
 * Output: 1
 * 
 * Constraints:
 * 1 <= k <= n <= 109
 */

// MLE:
class Solution {

    void solve(int curr, int n, List<Integer> result) {
        if (curr > n) {
            return;
        }

        result.add(curr);
        for (int append = 0; append <= 9; append++) {
            int newNum = (curr * 10) + append;
            if (newNum > n) {
                return;
            }
            solve(newNum, n, result);
        }
    }

    public int findKthNumber(int n, int k) {
        List<Integer> result = new ArrayList<>();
        for (int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, result);
        }
        return result.get(k - 1);
    }
}
