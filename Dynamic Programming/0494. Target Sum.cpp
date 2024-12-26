/*
 * 494. Target Sum
 *
 * You are given an integer array nums and an integer target.
 * You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
 * Return the number of different expressions that you can build, which evaluates to target.
 *
 * Example 1:
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 * Input: nums = [1], target = 1
 * Output: 1
 *
 * Constraints:
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 */

// Approach 1 (Brute Force): Use recursive backtracking to try both + and - signs for each number and count valid expressions
// TC: O(2^n) since we try 2 possibilities (+ or -) for each number, creating a binary tree of height n
// SC: O(n) due to recursion stack depth where n is the length of input array
class Solution {
public:
   // Parameters:
   // nums: input array of numbers
   // target: the target sum we want to achieve
   // i: current index in the array we're processing
   // currSum: running sum of the expression built so far
   int solve(vector<int>& nums, int target, int i, int currSum){
      // Base case: reached end of array
      if (i == nums.size()) {
         // If current sum equals target, we found a valid expression
         if (currSum == target) {
            return 1;
         } else {
            // Current sum doesn't equal target, not a valid expression
            return 0;
         }
      }

      // Recursive case: try both possibilities for current number
      // Option 1: Add current number (use + sign)
      int plus = solve(nums, target, i + 1, currSum + nums[i]);
      // Option 2: Subtract current number (use - sign)
      int minus = solve(nums, target, i + 1, currSum - nums[i]);

      // Return total number of valid expressions found
      // (sum of expressions starting with + and - for current number)
      return plus + minus;
   }

   // Parameters:
   // nums: input array of numbers
   // target: the target sum we want to achieve
   int findTargetSumWays(vector<int>& nums, int target){
      // Start recursion from index 0 with initial sum of 0
      return solve(nums, target, 0, 0);
   }
};

// Approach 2 (Normal Recursion & Memoization using unordered_map): Use recursive backtracking with memoization where key is combination of index and current sum to avoid recalculating same states
// TC: O(nsum) where n is length of array and sum is total of all numbers, as each state of (index, currentSum) is calculated only once
// SC: O(nsum) for storing results in map plus O(n) recursion stack, effectively O(n*sum)
class Solution {
public:
   // Parameters:
   // nums: input array of numbers
   // target: the target sum we want to achieve
   // i: current index in the array we're processing
   // currSum: running sum of the expression built so far
   // mp: map to store already computed results for (index, sum) pairs
   int solve(vector<int>& nums, int target, int i, int currSum, unordered_map<string, int>& mp){
      // Base case: reached end of array
      if (i == nums.size()) {
         if (currSum == target) {
            return 1;       // Found valid expression
         } else {
            return 0;       // Invalid expression
         }
      }

      // Create unique key from current state (index and sum)
      string key = to_string(i) + "_" + to_string(currSum);

      // If this state was already computed, return cached result
      if (mp.count(key)) {
         return mp[key];
      }

      // Recursive case: try both + and - for current number
      int plus  = solve(nums, target, i + 1, currSum + nums[i], mp);
      int minus = solve(nums, target, i + 1, currSum - nums[i], mp);

      // Cache and return result for current state
      return mp[key] = plus + minus;
   }

   int findTargetSumWays(vector<int>& nums, int target){
      // Map to store results of already computed states
      unordered_map<string, int> mp;

      return solve(nums, target, 0, 0, mp);
   }
};

// Approach 3 (Normal Recursion & Memoization using vector): Use recursive backtracking with 2D DP array memoization where indices are shifted by total sum S to handle negative sums
// TC: O(nsum) where n is array length and sum is total of all numbers, as each state is calculated only once using dp table
// SC: O(nsum) for 2D dp table of size n*(2S + 1) plus O(n) recursion stack, effectively O(nsum)
class Solution {
public:
   // S stores total sum of array, used for shifting index in dp table
   int S;

   // Parameters:
   // nums: input array of numbers
   // target: the target sum we want to achieve
   // i: current index in the array we're processing
   // currSum: running sum of the expression built so far
   // t: 2D DP table to store already computed results
   int solve(vector<int>& nums, int target, int i, int currSum, vector<vector<int> >& t){
      // Base case: reached end of array
      if (i == nums.size()) {
         if (currSum == target) {
            return 1;       // Found valid expression
         } else {
            return 0;       // Invalid expression
         }
      }

      // Check if current state was already computed
      // We add S to currSum to handle negative indices
      if (t[i][currSum + S] != -1) {
         return t[i][currSum + S];
      }

      // Recursive case: try both + and - for current number
      int plus  = solve(nums, target, i + 1, currSum + nums[i], t);
      int minus = solve(nums, target, i + 1, currSum - nums[i], t);

      // Store and return result in dp table
      return t[i][currSum + S] = plus + minus;
   }

   int findTargetSumWays(vector<int>& nums, int target){
      int n = nums.size();

      // Calculate total sum of array for dp table size
      S = accumulate(begin(nums), end(nums), 0);

      // Initialize dp table of size n x (2*S + 1)
      // +1 for handling 0 and 2*S to handle range -S to +S
      vector<vector<int> > t(n + 1, vector<int>(2 * S + 1, -1));

      return solve(nums, target, 0, 0, t);
   }
};
