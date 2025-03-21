/*
 * 213. House Robber II
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 *
 * Example 1:
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 *
 * Example 2:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 3:
 * Input: nums = [1,2,3]
 * Output: 3
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 */

// Approach: Use recursion with memoization to solve the circular house robber problem by splitting it into two linear subproblems—one excluding the last house (indices 0 to n-2) and one excluding the first house (indices 1 to n-1)—and then taking the maximum of both.
// Time Complexity: O(n) per subproblem, since each house is processed once due to memoization.
// Space Complexity: O(n) for each memoization vector and recursion stack space.
class Solution {
public:
    // Helper function to calculate maximum loot in a linear segment from index 'idx' to 'end' using recursion with memoization.
    int solve(vector<int>& nums, int idx, int end, vector<int>& t) {
        if (idx > end) {
            return 0;
        }
        if (t[idx] != -1) {        // if already computed, return the stored result
            return t[idx];
        }
        int take = nums[idx] + solve(nums, idx + 2, end, t); // option: take current house and skip next
        int skip = solve(nums, idx + 1, end, t);             // option: skip current house

        return t[idx] = max(take, skip);                     // memoize and return the maximum loot from index idx
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];      // Only one house, so return its value.
        }

        // Create separate memoization vectors for the two cases.
        vector<int> t1(n, -1), t2(n, -1);
        // Case 1: Exclude the last house (consider houses from index 0 to n-2)
        int case1 = solve(nums, 0, n - 2, t1);
        // Case 2: Exclude the first house (consider houses from index 1 to n-1)
        int case2 = solve(nums, 1, n - 1, t2);

        return max(case1, case2);
    }
};

/*
 * Dry Run
 * Example: nums = [2, 3, 2]
 * Case 1: Solve for indices [0, 1] (exclude last house)
 *  - solve(nums, 0, 1, memo1):
 *       idx = 0 -> take = 2 + solve(nums, 2, 1, memo1) = 2 + 0 = 2; skip = solve(nums, 1, 1, memo1)
 *       idx = 1 -> take = 3 + solve(nums, 3, 1, memo1) = 3 + 0 = 3; skip = solve(nums, 2, 1, memo1) = 0
 *       => solve(nums, 1, 1, memo1) returns max(3, 0) = 3
 *       => solve(nums, 0, 1, memo1) returns max(2, 3) = 3
 *  - Case 1 Result = 3
 * Case 2: Solve for indices [1, 2] (exclude first house)
 *  - solve(nums, 1, 2, memo2):
 *       idx = 1 -> take = 3 + solve(nums, 3, 2, memo2) = 3 + 0 = 3; skip = solve(nums, 2, 2, memo2)
 *       idx = 2 -> take = 2 + solve(nums, 4, 2, memo2) = 2 + 0 = 2; skip = solve(nums, 3, 2, memo2) = 0
 *       => solve(nums, 2, 2, memo2) returns max(2, 0) = 2
 *       => solve(nums, 1, 2, memo2) returns max(3, 2) = 3
 *  - Case 2 Result = 3
 * Final Answer: max(3, 3) = 3
 */
