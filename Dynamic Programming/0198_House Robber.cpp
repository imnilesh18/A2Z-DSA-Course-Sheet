/*
 * 198. House Robber
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 */

// Approach: Use recursion with memoization (top-down dynamic programming) to decide at each house whether to rob it or skip it, ensuring adjacent houses are not robbed.
// Time Complexity: O(n) - Each house is computed once due to memoization.
// Space Complexity: O(n) - For the recursion stack and the memoization array.
class Solution {
public:
    int t[101];     // memoization array to store maximum loot from index i onward

    int solve(vector<int>& nums, int n, int idx) {
        if (idx >= n) {     // base case: if index exceeds number of houses, return 0
            return 0;
        }

        if (t[idx] != -1) {     // if result for index idx is already computed, return it
            return t[idx];
        }

        // Option 1: Rob the current house and then skip the next one (move idx by 2)
        int take = nums[idx] + solve(nums, n, idx + 2);
        // Option 2: Skip the current house and check the next one (move idx by 1)
        int skip = solve(nums, n, idx + 1);

        // Store and return the maximum loot achievable from index idx
        return t[idx] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(t, -1, sizeof(t));     // initialize memoization array with -1
        return solve(nums, n, 0);     // start from the first house
    }
};

/*
 * Dry Run:
 * Input:
 * nums = [2, 7, 9, 3, 1]
 *
 * Step-by-step execution:
 * solve(nums, 5, 0):
 *  - Option 1 (take house 0): 2 + solve(nums, 5, 2)
 *    solve(nums, 5, 2):
 *      - Option 1 (take house 2): 9 + solve(nums, 5, 4)
 *        solve(nums, 5, 4):
 *          - Option 1 (take house 4): 1 + solve(nums, 5, 6) → 1 + 0 = 1
 *          - Option 2 (skip house 4): solve(nums, 5, 5) → 0
 *          → Maximum at idx 4: max(1, 0) = 1
 *      - Option 2 (skip house 2): solve(nums, 5, 3)
 *        solve(nums, 5, 3):
 *          - Option 1 (take house 3): 3 + solve(nums, 5, 5) → 3 + 0 = 3
 *          - Option 2 (skip house 3): solve(nums, 5, 4) → already computed as 1
 *          → Maximum at idx 3: max(3, 1) = 3
 *      → Maximum at idx 2: max(9+1, 3) = max(10, 3) = 10
 *  - Option 2 (skip house 0): solve(nums, 5, 1)
 *    solve(nums, 5, 1):
 *      - Option 1 (take house 1): 7 + solve(nums, 5, 3) → 7 + 3 = 10
 *      - Option 2 (skip house 1): solve(nums, 5, 2) → already computed as 10
 *      → Maximum at idx 1: max(10, 10) = 10
 *
 * Final Calculation at idx 0: max(2+10, 10) = max(12, 10) = 12
 *
 * Output:
 * 12
 */
