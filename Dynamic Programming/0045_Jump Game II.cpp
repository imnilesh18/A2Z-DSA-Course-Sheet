/*
 * 45. Jump Game II
 *
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
 * Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
 * 0 <= j <= nums[i] and
 * i + j < n
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
 *
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * It's guaranteed that you can reach nums[n - 1].
 */

// Approach: Use recursion with memoization to explore each jump from the current index and cache results to avoid recomputation.
// Time Complexity: O(n^2) in the worst-case scenario, as each index may explore up to nums[idx] jumps.
// Space Complexity: O(n) due to the memoization array and recursion call stack.
class Solution {
public:
    // Recursive function to compute minimum jumps from index 'idx' to the end.
    int solve(vector<int>& nums, int n, int idx, vector<int>& t) {
        if (idx == n - 1) {    // Base case: reached the last index, no more jumps needed.
            return 0;
        }
        if (idx >= n) {    // If index goes out of bounds, return a large number.
            return INT_MAX;
        }
        if (t[idx] != -1) {    // Return cached result if available.
            return t[idx];
        }

        int minJump = INT_MAX;
        // Try all possible jump lengths from 1 to nums[idx]
        for (int i = 1; i <= nums[idx]; i++) {
            int res = solve(nums, n, idx + i, t);     // 'res' = minimum jumps from index (idx + i) to the end.
            if (res != INT_MAX) {                     // Only consider valid paths.
                minJump = min(minJump, 1 + res);      // Candidate = 1 (current jump) + res (jumps from next index).
            }
        }

        // Cache and return the computed minimum jumps for index 'idx'.
        return t[idx] = minJump;
    }
    int jump(vector<int>& nums) {
        int         n = nums.size();
        vector<int> t(n, -1);                  // Memoization array initialized with -1.
        int         ans = solve(nums, n, 0, t);

        return ans;     // Since it's guaranteed that nums[n-1] is reachable, no need for additional checks.
    }
};

/*
 * Dry Run
 * ---------
 * Input: nums = [2, 3, 1, 1, 4] with n = 5
 *
 * Step 1: Call solve(nums, 5, 0, t) at idx = 0, nums[0] = 2.
 *  - From idx 0, possible jumps:
 *       Jump 1: to idx = 1.
 *       Jump 2: to idx = 2.
 *
 * Step 2: For jump 1 from idx 0:
 *  Call solve(nums, 5, 1, t) at idx = 1, nums[1] = 3.
 *  - From idx 1, possible jumps:
 *       Jump 1: to idx = 2.
 *       Jump 2: to idx = 3.
 *       Jump 3: to idx = 4.
 *
 * Step 3: At idx 1:
 *  a) For jump 1:
 *       Call solve(nums, 5, 2, t) at idx = 2, nums[2] = 1.
 *       - From idx 2, only jump: to idx = 3.
 *       Call solve(nums, 5, 3, t) at idx = 3, nums[3] = 1.
 *       - From idx 3, only jump: to idx = 4.
 *       Call solve(nums, 5, 4, t) at idx = 4 → Base case reached, returns 0.
 *       Back at idx 3: Candidate = 1 + 0 = 1; so solve(nums, 5, 3, t) returns 1.
 *       Back at idx 2: Candidate = 1 + 1 = 2; so solve(nums, 5, 2, t) returns 2.
 *  b) For jump 2:
 *       Call solve(nums, 5, 3, t) at idx = 3, which returns 1 (as computed above).
 *       Candidate = 1 + 1 = 2.
 *  c) For jump 3:
 *       Call solve(nums, 5, 4, t) at idx = 4 → Base case, returns 0.
 *       Candidate = 1 + 0 = 1.
 *  - At idx 1, minimum candidate = min( (1+2)=3, (1+1)=2, (1+0)=1 ) = 1.
 *    So, solve(nums, 5, 1, t) returns 1.
 *
 * Step 4: For jump 2 from idx 0:
 *  Call solve(nums, 5, 2, t) at idx = 2, which returns 2.
 *  Candidate = 1 + 2 = 3.
 *
 * Step 5: At idx 0, minimum candidate = min( (1 + solve(idx 1)=1+1=2), (1 + solve(idx 2)=1+2=3) ) = 2.
 *  So, solve(nums, 5, 0, t) returns 2.
 *
 * Final Answer: 2 jumps are required to reach the last index.
*/