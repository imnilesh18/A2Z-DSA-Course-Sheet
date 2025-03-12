/*
 * 746. Min Cost Climbing Stairs
 *
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 *
 * Example 1:
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 *
 * Example 2:
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 *
 * Constraints:
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 */

// Approach 1: Top-Down Recursive with Memoization
// Time Complexity: O(n) because each index is computed only once due to memoization
// Space Complexity: O(n) due to recursion stack and memoization array
class Solution {
public:
    int t[1001];      // Memoization array of size 1001 (since cost.length <= 1000)

    // Recursive helper function to compute minimum cost from current index.
    int solve(int idx, vector<int>& cost) {
        // Base case: if index is beyond the last step, no cost is incurred.
        if (idx >= cost.size()) {
            return 0;
        }
        // Return the pre-computed result if available.
        if (t[idx] != -1) {
            return t[idx];
        }
        // Option 1: Take one step from the current index.
        int oneStep = cost[idx] + solve(idx + 1, cost);
        // Option 2: Take two steps from the current index.
        int twoSteps = cost[idx] + solve(idx + 2, cost);
        // Store and return the minimum cost between both options.
        return t[idx] = min(oneStep, twoSteps);
    }
    // Main function to compute the minimum cost to reach the top.
    // You can start from either index 0 or index 1.
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));      // Initialize memoization array with -1.
        return min(solve(0, cost), solve(1, cost));
    }
};

/*
 * Dry Run:
 * For cost = [10, 15, 20]
 * - Starting at index 1 directly yields: cost[1] = 15.
 * - Starting at index 0:
 *  cost[0] = 10 + min(solve(1), solve(2))
 *  - solve(1) = 15 + min(solve(2), solve(3))
 *  - solve(2) = 20 + min(solve(3), solve(4)) = 20 + 0 = 20  (since solve(3) returns 0)
 *  - Thus, solve(1) = 15 + min(20, 0) = 15
 *  - So, cost starting at index 0 becomes 10 + 15 = 25.
 * - Final answer = min(25, 15) = 15.
 */

// Approach 2: Bottom-Up Dynamic Programming (In-Place)
// Time Complexity: O(n) because we iterate over the array once
// Space Complexity: O(1) as we update the input array in-place
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // If there are only two steps, return the minimum cost of the two.
        if (n == 2) {
            return min(cost[0], cost[1]);
        }
        // Update each step's cost to be the minimum total cost to reach that step.
        for (int i = 2; i < n; i++) {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
        }
        // The final answer is the minimum cost between the last step and the second last step.
        return min(cost[n - 1], cost[n - 2]);
    }
};

/*
 * Dry Run:
 * For cost = [10, 15, 20]
 * - For i = 2:
 *  cost[2] = 20 + min(cost[1], cost[0]) = 20 + min(15, 10) = 20 + 10 = 30.
 *  Updated cost array becomes: [10, 15, 30].
 * - Final answer = min(cost[2], cost[1]) = min(30, 15) = 15.
 */
