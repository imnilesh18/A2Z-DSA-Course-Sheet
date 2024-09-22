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

//T.C : O((logn)^2)
//S.C : O(log(n)) system resursion stack
class Solution {

    // Helper function to count how many numbers exist in the lexicographical range
    // [curr, next)
    int Count(long curr, long next, int n) {
        int countNum = 0; // Initialize counter

        // While current prefix is within the limit of n
        while (curr <= n) {
            // Add the number of valid numbers in this range
            countNum += (next - curr);

            // Move to the next level in lexicographical order by multiplying by 10
            curr *= 10;
            next *= 10;

            // Ensure 'next' doesn't exceed n + 1, as we only consider numbers <= n
            next = Math.min(next, (long) n + 1);
        }
        return countNum; // Return total count of numbers in this lexicographical range
    }

    // Main function to find the k-th smallest number in lexicographical order up to
    // n
    public int findKthNumber(int n, int k) {
        int curr = 1; // Start from the first number (lexicographically 1)
        k -= 1; // Since we're already at the first number, decrement k by 1

        // Loop until we find the k-th number
        while (k > 0) {
            // Count the numbers between curr and curr + 1 (i.e., the lexicographical
            // "siblings")
            int count = Count(curr, curr + 1, n);

            // If count is less than or equal to k, move to the next sibling
            if (count <= k) {
                curr++; // Move to the next sibling (curr + 1)
                k -= count; // Subtract the count from k
            } else {
                // If the k-th number is within the current range, go down one level
                // lexicographically
                curr *= 10; // Move to the next level (i.e., curr becomes curr * 10)
                k -= 1; // Subtract 1 from k because we're still counting the current number
            }
        }
        return curr; // Return the k-th smallest number
    }
}

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
