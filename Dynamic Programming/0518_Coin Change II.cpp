/*
 * 518. Coin Change II
 *
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
 * You may assume that you have an infinite number of each kind of coin.
 * The answer is guaranteed to fit into a signed 32-bit integer.
 *
 * Example 1:
 * Input: amount = 5, coins = [1,2,5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 * Example 2:
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 * Example 3:
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 * Constraints:
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * All the values of coins are unique.
 * 0 <= amount <= 5000
 */

// Approach: Recursion with memoization; at each coin index, decide whether to include the coin (reuse allowed) or skip it.
// Time Complexity: O(n * amount) - each state (coin index, remaining amount) is computed only once.
// Space Complexity: O(n * amount) - for the memoization table and recursion stack.
class Solution {
public:
    int n;
    int t[301][5001];       // Memoization table: first dimension is 301 (max coins length 300 + 1), second dimension is 5001 (amount up to 5000)

    // Recursive helper function to count the number of ways to form the target sum
    int solve(int i, vector<int>& coins, int sum) {
        // If the remaining sum is 0, a valid combination is found.
        if (sum == 0) {
            return 1;
        }

        // If no coins are left to consider, return 0 as no valid combination can be formed.
        if (i == n) {
            return 0;
        }

        // Return the stored result if this state has already been computed.
        if (t[i][sum] != -1) {
            return t[i][sum];
        }

        // If the current coin's value is greater than the remaining sum, skip this coin.
        if (coins[i] > sum) {
            return t[i][sum] = solve(i + 1, coins, sum);
        }

        // Option 1: Include the current coin (stay at the same index since coins can be reused).
        int take = solve(i, coins, sum - coins[i]);
        // Option 2: Exclude the current coin and move to the next index.
        int skip = solve(i + 1, coins, sum);

        // Store and return the total number of combinations for this state.
        return t[i][sum] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));       // Initialize the memoization table with -1
        return solve(0, coins, amount);
    }
};

/*
 * Dry Run
 * Example: coins = [1, 2, 5], amount = 5
 * 1. Call change(5, [1,2,5]): n is set to 3 and memoization table t is initialized.
 * 2. Call solve(0, [1,2,5], 5):
 * - coins[0] = 1 is <= 5, so:
 *   a) take = solve(0, [1,2,5], 5 - 1) = solve(0, [1,2,5], 4)  // Include coin 1
 *   b) skip = solve(1, [1,2,5], 5)                               // Skip coin 1
 * 3. The recursion continues:
 * - For "take", coin 1 is repeatedly included until sum reduces to 0 (yielding one valid combination) or no valid combination is found.
 * - For "skip", the algorithm moves to the next coin and repeats the process.
 * 4. Valid combinations found include:
 * - [5]
 * - [2, 2, 1]
 * - [2, 1, 1, 1]
 * - [1, 1, 1, 1, 1]
 * 5. The total number of combinations returned is 4.
 */
