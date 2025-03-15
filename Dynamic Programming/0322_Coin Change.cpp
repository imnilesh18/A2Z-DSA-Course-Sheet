/*
 * 322. Coin Change
 *
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by ny combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Example 1:
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 * Constraints:
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 */

// Approach: Use recursion with memoization (top-down DP) to decide whether to take a coin (unlimited supply) or skip it.
// Time Complexity: O(n * amount) since each state (index, current sum) is computed once.
// Space Complexity: O(n * amount) for the memoization table and recursion call stack.
class Solution {
public:
    int n;
    vector<vector<int> > t;      // Memoization table: dimensions [n][amount+1]

    int solve(int idx, vector<int>& coins, int sum, int curr) {
        // If current sum equals target sum, no more coins are needed.
        if (curr == sum) {
            return 0;
        }
        // If current sum exceeds target sum, this path is invalid.
        if (curr > sum) {
            return INT_MAX;
        }
        // If we have exhausted all coins, return a large value (failure).
        if (idx >= coins.size()) {
            return INT_MAX;
        }
        // If the state (idx, curr) is already computed, return its value.
        if (t[idx][curr] != -1) {
            return t[idx][curr];
        }
        int takeRes;
        // Check to prevent overflow or exceeding sum:
        // If adding coins[idx] to curr would exceed sum, set takeRes to INT_MAX.
        if (curr > sum - coins[idx]) {
            takeRes = INT_MAX;
        } else {
            // Recursively try taking the coin at index 'idx'
            takeRes = solve(idx, coins, sum, curr + coins[idx]);
        }
        // If taking the coin yields a valid solution, add 1 coin; otherwise, keep it INT_MAX.
        int take = (takeRes == INT_MAX) ? INT_MAX : 1 + takeRes;
        // Recursively try skipping the coin at index 'idx' and moving to the next coin.
        int skip = solve(idx + 1, coins, sum, curr);
        // Store the minimum result between taking or skipping the coin.
        return t[idx][curr] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        // Initialize memoization table with -1 (uncomputed states)
        t.assign(n, vector<int>(amount + 1, -1));
        // Start recursion from index 0 and current sum 0.
        int result = solve(0, coins, amount, 0);
        // If result is INT_MAX, it means it's impossible to form the amount.
        return (result == INT_MAX) ? -1 : result;
    }
};

/*
 * Dry Run
 * Input: coins[] = [25, 10, 5], sum = 30
 * Steps:
 * 1. Start at idx = 0, curr = 0.
 * - Option: take coin 25 -> new state (0, 25).
 * Check: if (0 > 30 - 25) → (0 > 5) is false, so recursion proceeds.
 * 2. At state (0, 25):
 * - Taking coin 25 again:
 * Check: if (25 > 30 - 25) → (25 > 5) is true, so takeRes = INT_MAX.
 * - Skipping coin 25:
 * Move to idx = 1, state remains (1, 25).
 * 3. At state (1, 25):
 * - Taking coin 10:
 * Check: if (25 > 30 - 10) → (25 > 20) is true, so takeRes = INT_MAX.
 * - Skipping coin 10:
 * Move to idx = 2, state remains (2, 25).
 * 4. At state (2, 25):
 * - Taking coin 5:
 * Check: if (25 > 30 - 5) → (25 > 25) is false, so new state becomes (2, 30) and returns 0.
 * - Skipping coin 5:
 * Move to idx = 3, which is invalid, returns INT_MAX.
 * - Minimum coins at (2,25) = 1 (by taking coin 5).
 * 5. Backtracking to state (0,25):
 * - Minimum = min(1 + result from taking, result from skipping) = 2.
 * Final Output: 2 coins are needed.
 */
