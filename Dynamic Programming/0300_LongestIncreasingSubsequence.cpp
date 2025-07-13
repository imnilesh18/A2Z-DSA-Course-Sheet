/*
 * LeetCode Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
 * GfG Link: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
 *
 * 300. Longest Increasing Subsequence
 *
 * Medium
 *
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 *
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 * Constraints:
 * * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 */

/************************************************************ C++ ************************************************/

// Approach 1: Recursion with memoization exploring “take”/“not take” choices at each index to compute LIS length.
// Time Complexity: O(n²) due to O(n²) DP states over (i, prev) and O(1) work per state.
// Space Complexity: O(n²) for the DP table plus O(n) recursion stack.
class Solution {
public:

    // helper function: returns LIS length starting at index i with previous taken index prev
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        // base case: reached end of array
        if (i >= n) {
            return 0;
        }

        // if we have a previous index and already computed this state, reuse it
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }

        int take = 0;
        // option 1: take nums[i] if it's greater than nums[prev] (or if no prev)
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        // option 2: skip nums[i]
        int not_take = solve(i + 1, prev, nums, dp);

        // store result if there's a valid prev to index into dp
        if (prev != -1) {
            dp[i][prev] = max(take, not_take);
        }

        return max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][prev] stores answer for solve(i, prev); prev = -1 is handled separately
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};

/*
 *
 * Dry Run
 *
 * Example: nums = [10, 9, 2, 5]
 *
 * solve(0, -1):
 *   take = 1 + solve(1, 0)      // take 10
 *   not_take = solve(1, -1)     // skip 10
 *
 *   solve(1, 0):
 *     nums[1]=9 <= nums[0]=10 → can't take
 *     take=0
 *     not_take = solve(2, 0)
 *
 *   solve(2, 0):
 *     nums[2]=2 <= nums[0]=10 → can't take
 *     take=0
 *     not_take = solve(3, 0)
 *
 *   solve(3, 0):
 *     nums[3]=5 <= nums[0]=10 → can't take
 *     take=0
 *     not_take = solve(4, 0) = 0
 *     return 0
 *
 *   so solve(2,0)=0, solve(1,0)=0 → take branch at root = 1 + 0 = 1
 *
 *   solve(1, -1):
 *     take = 1 + solve(2, 1)    // take 9
 *     not_take = solve(2, -1)   // skip 9
 *
 *   solve(2, 1):
 *     nums[2]=2 <= nums[1]=9 → take=0
 *     not_take = solve(3, 1)
 *
 *   solve(3, 1):
 *     nums[3]=5 <= nums[1]=9 → take=0
 *     not_take = solve(4, 1)=0
 *     return 0
 *
 *   so solve(2,1)=0 → solve(1,-1).take = 1
 *   solve(2, -1):
 *     take = 1 + solve(3, 2)    // take 2
 *     not_take = solve(3, -1)
 *
 *   solve(3, 2):
 *     nums[3]=5 > nums[2]=2 → take = 1 + solve(4, 3) = 1
 *     not_take = solve(4, 2) = 0
 *     return 1
 *
 *   solve(3, -1):
 *     take = 1 + solve(4, 3) = 1
 *     not_take = solve(4, -1) = 0
 *     return 1
 *
 *   so solve(2,-1) = max(1 + 1, 1) = 2
 *
 *   solve(1,-1) = max(1, 2) = 2
 *
 * solve(0,-1) = max(1, 2) = 2 → LIS length = 2 (subsequence [2,5])
 */

// Approach 2: Bottom‑up dynamic programming where dp[i] stores the length of the LIS ending at i.
// Time Complexity: O(n²) due to the nested loops over i and j.
// Space Complexity: O(n) for the dp array.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int         n = nums.size();
        vector<int> dp(n, 1);          // dp[i] = LIS ending at i (min length 1)
        int         maxLIS = 1;        // track overall maximum

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // if nums[j] can precede nums[i], extend the subsequence
                if (nums[j] < nums[i]) {
                    dp[i]  = max(dp[i], dp[j] + 1);
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};

/*
 *
 * Dry Run
 *
 * Example: nums = [10, 9, 2, 5]
 *
 * Initialize dp = [1,1,1,1], maxLIS = 1
 *
 * i = 0:
 *   no j < 0 → dp stays [1,1,1,1], maxLIS = 1
 *
 * i = 1:
 *   j = 0: nums[0]=10 ≥ nums[1]=9 → skip
 *   dp = [1,1,1,1], maxLIS = 1
 *
 * i = 2:
 *   j = 0: 10 ≥ 2 → skip
 *   j = 1: 9 ≥ 2 → skip
 *   dp = [1,1,1,1], maxLIS = 1
 *
 * i = 3:
 *   j = 0: 10 ≥ 5 → skip
 *   j = 1: 9 ≥ 5 → skip
 *   j = 2: 2 < 5 → dp[3] = max(1, dp[2]+1)=2; maxLIS=2
 *   dp = [1,1,1,2], maxLIS = 2
 *
 * Return 2 → LIS length = 2 (subsequence [2,5])
 */

/************************************************************ JAVA ************************************************/

// Approach 1: Recursion with memoization exploring “take”/“not take” choices at each index to compute LIS length.
// Time Complexity: O(n²) due to O(n²) DP states over (i, prev) and O(1) work per state.
// Space Complexity: O(n²) for the DP table plus O(n) recursion stack.
class Solution {
    // helper function: returns LIS length starting at index i with previous taken index prev
    private int solve(int i, int prev, int[] nums, int[][] dp) {
        int n = nums.length;

        // base case: reached end of array
        if (i >= n) {
            return 0;
        }
        // if we have a previous index and already computed this state, reuse it
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }

        int take = 0;
        // option 1: take nums[i] if it's greater than nums[prev] (or if no prev)
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        // option 2: skip nums[i]
        int notTake = solve(i + 1, prev, nums, dp);

        int result = Math.max(take, notTake);
        // store result if there's a valid prev to index into dp
        if (prev != -1) {
            dp[i][prev] = result;
        }
        return result;
    }
    
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        // dp[i][prev] stores answer for solve(i, prev); prev = -1 handled separately
        int[][] dp = new int[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, -1, nums, dp);
    }
}

/*
 *
 * Dry Run
 *
 * Example: nums = [10, 9, 2, 5]
 *
 * solve(0, -1, nums, dp):
 *   take = 1 + solve(1, 0, nums, dp)      // take 10
 *   notTake = solve(1, -1, nums, dp)      // skip 10
 *
 *   solve(1, 0, nums, dp):
 *     nums[1]=9 <= nums[0]=10 → can't take => take=0
 *     notTake = solve(2, 0, nums, dp)
 *
 *   solve(2, 0, nums, dp):
 *     nums[2]=2 <= nums[0]=10 → take=0
 *     notTake = solve(3, 0, nums, dp)
 *
 *   solve(3, 0, nums, dp):
 *     nums[3]=5 <= nums[0]=10 → take=0
 *     notTake = solve(4, 0, nums, dp) = 0
 *     return 0
 *
 *   so solve(2,0)=0, solve(1,0)=0 → root.take = 1 + 0 = 1
 *
 *   solve(1, -1, nums, dp):
 *     take = 1 + solve(2, 1, nums, dp)    // take 9
 *     notTake = solve(2, -1, nums, dp)    // skip 9
 *
 *   solve(2, 1, nums, dp):
 *     nums[2]=2 <= nums[1]=9 → take=0
 *     notTake = solve(3, 1, nums, dp)
 *
 *   solve(3, 1, nums, dp):
 *     nums[3]=5 <= nums[1]=9 → take=0
 *     notTake = solve(4, 1, nums, dp)=0
 *     return 0
 *
 *   so solve(2,1)=0 → solve(1,-1).take = 1
 *   solve(2, -1, nums, dp):
 *     take = 1 + solve(3, 2, nums, dp)    // take 2
 *     notTake = solve(3, -1, nums, dp)
 *
 *   solve(3, 2, nums, dp):
 *     nums[3]=5 > nums[2]=2 → take = 1 + solve(4, 3, nums, dp) = 1
 *     notTake = solve(4, 2, nums, dp) = 0
 *     return 1
 *
 *   solve(3, -1, nums, dp):
 *     take = 1 + solve(4, 3, nums, dp) = 1
 *     notTake = solve(4, -1, nums, dp) = 0
 *     return 1
 *
 *   so solve(2,-1) = max(1 + 1, 1) = 2
 *
 *   solve(1,-1) = max(1, 2) = 2
 *
 * solve(0,-1) = max(1, 2) = 2 → LIS length = 2 (subsequence [2,5])
 */

// Approach 2: Bottom‑up dynamic programming where dp[i] stores the length of the LIS ending at i.
// Time Complexity: O(n²) due to the nested loops over i and j.
// Space Complexity: O(n) for the dp array.
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];

        Arrays.fill(dp, 1);           // dp[i] = LIS ending at i (min length 1)
        int maxLIS = 1;               // track overall maximum

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // if nums[j] can precede nums[i], extend the subsequence
                if (nums[j] < nums[i]) {
                    dp[i]  = Math.max(dp[i], dp[j] + 1);
                    maxLIS = Math.max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
}

/*
 *
 * Dry Run
 *
 * Example: nums = [10, 9, 2, 5]
 *
 * Initialize dp = [1,1,1,1], maxLIS = 1
 *
 * i = 0:
 *   no j < 0 → dp stays [1,1,1,1], maxLIS = 1
 *
 * i = 1:
 *   j = 0: nums[0]=10 ≥ nums[1]=9 → skip
 *   dp = [1,1,1,1], maxLIS = 1
 *
 * i = 2:
 *   j = 0: 10 ≥ 2 → skip
 *   j = 1: 9 ≥ 2 → skip
 *   dp = [1,1,1,1], maxLIS = 1
 *
 * i = 3:
 *   j = 0: 10 ≥ 5 → skip
 *   j = 1: 9 ≥ 5 → skip
 *   j = 2: 2 < 5 → dp[3] = max(1, dp[2]+1)=2; maxLIS=2
 *   dp = [1,1,1,2], maxLIS = 2
 *
 * Return 2 → LIS length = 2 (subsequence [2,5])
 */
