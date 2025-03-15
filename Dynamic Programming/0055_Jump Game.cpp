/*
 * 55. Jump Game
 *
 * You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 *
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 */

// Approach 1: Use recursion with memoization (top-down dynamic programming) to explore every possible jump and store intermediate results.
// Time Complexity: O(n * max_jump) in the worst-case scenario, but memoization significantly reduces redundant computations.
// Space Complexity: O(n) due to recursion stack and memoization array.
class Solution {
public:
    int t[10001];     // memoization array: t[i] stores whether index i can lead to the last index (true/false)

    bool solve(vector<int>& nums, int n, int idx) {
        // Base case: if we have reached the last index, return true.
        if (idx == n - 1) {
            return true;
        }

        // If the result for the current index has been computed before, return it.
        if (t[idx] != -1) {
            return t[idx];
        }

        // Try every jump possible from the current index.
        for (int i = 1; i <= nums[idx]; i++) {
            // If a jump leads to a successful path, mark this index as true and return.
            if (solve(nums, n, idx + i) == true) {
                return t[idx] = true;
            }
        }

        // If no jump leads to the last index, mark this index as false and return.
        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // Initialize the memoization array with -1 (indicating uncomputed states).
        memset(t, -1, sizeof(t));
        // Start the recursion from index 0.
        return solve(nums, n, 0);
    }
};

/*
 * Dry Run:
 * Input: nums = [2, 3, 1, 1, 4]
 *
 * - Start at index 0, value = 2. Possible jumps: to index 1 and index 2.
 * - Jump to index 1, value = 3. Possible jumps: to index 2, 3, and 4.
 *  - Jump to index 4 from index 1: index 4 is the last index, so return true.
 * - The recursive call returns true at index 1, so index 0 also returns true.
 * - Final output: true
 */

// Approach 2 (Bottom Up): Dynamic programming using tabulation to track reachable indices.
// Time Complexity: O(n^2) in the worst-case scenario due to the nested loops.
// Space Complexity: O(n) for the boolean array used to record reachability.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int          n = nums.size();
        vector<bool> t(n, false); // t[i] = true means index i is reachable; false means it is not reachable.

        t[0] = true;              // Starting at index 0 is always reachable.

        // Iterate over each index from 1 to n-1 to determine if it's reachable.
        for (int i = 1; i < n; i++) {
            // Check all previous indices to see if any can jump to i.
            for (int j = i - 1; j >= 0; j--) {
                // If index j is reachable and can jump to index i, mark i as reachable.
                if (t[j] && j + nums[j] >= i) {
                    t[i] = true;
                    break;     // No need to check further if index i is already marked reachable.
                }
            }
        }

        // Return true if the last index is reachable.
        return t[n - 1];
    }
};

/*
 * Dry Run:
 * Input: nums = [2, 3, 1, 1, 4]
 *
 * - Start: t[0] = true (index 0 is reachable).
 * - For i = 1:
 *  Check j = 0: Since t[0] is true and 0 + nums[0] (0+2 = 2) >= 1, set t[1] = true.
 * - For i = 2:
 *  Check j = 1: t[1] is true and 1 + nums[1] (1+3 = 4) >= 2, set t[2] = true.
 * - For i = 3:
 *  Check j = 2: t[2] is true and 2 + nums[2] (2+1 = 3) >= 3, set t[3] = true.
 * - For i = 4:
 *  Check j = 3: t[3] is true and 3 + nums[3] (3+1 = 4) >= 4, set t[4] = true.
 * - Final output: true (last index is reachable)
 */

// Approach 3: Greedy algorithm; iterate through the array, updating the maximum reachable index at each step, and check if the current index is reachable.
// Time Complexity: O(n) because the array is traversed only once.
// Space Complexity: O(1) as no extra space is used apart from variables.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n            = nums.size();
        int maxReachable = 0;     // tracks the farthest index we can reach

        // Iterate through the array to update maxReachable
        for (int i = 0; i < n; i++) {
            // If current index is greater than the maximum reachable index, then it is not reachable.
            if (i > maxReachable) {
                return false;
            }
            // Update maxReachable if jumping from index i reaches further.
            maxReachable = max(maxReachable, i + nums[i]);
        }

        return true;     // if loop completes, the last index is reachable
    }
};

/*
 * Dry Run:
 * Input: nums = [2, 3, 1, 1, 4]
 *
 * - Initialize maxReachable = 0.
 * - i = 0:
 *  - Condition: 0 <= maxReachable (0) holds.
 *  - Update maxReachable = max(0, 0 + 2) = 2.
 * - i = 1:
 *  - Condition: 1 <= maxReachable (2) holds.
 *  - Update maxReachable = max(2, 1 + 3) = 4.
 * - i = 2:
 *  - Condition: 2 <= maxReachable (4) holds.
 *  - Update maxReachable = max(4, 2 + 1) = 4.
 * - i = 3:
 *  - Condition: 3 <= maxReachable (4) holds.
 *  - Update maxReachable = max(4, 3 + 1) = 4.
 * - i = 4:
 *  - Condition: 4 <= maxReachable (4) holds.
 *  - Update maxReachable = max(4, 4 + 4) = 8.
 * - End of loop: All indices are reachable, so return true.
 */
