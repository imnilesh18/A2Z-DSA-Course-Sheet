/*
 * 3152. Special Array II
 *
 * An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
 * You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.
 * Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
 *
 * Example 1:
 * Input: nums = [3,4,1,2,6], queries = [[0,4]]
 * Output: [false]
 * Explanation:
 * The subarray is [3,4,1,2,6]. 2 and 6 are both even.
 *
 * Example 2:
 * Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
 * Output: [false,true]
 * Explanation:
 * The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
 * The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
 */

// Approach 1: Use a prefix sum array to count adjacent same-parity pairs and answer each query in O(1) by checking the count difference between indices.
// Time Complexity: O(n + q), where n is the length of nums and q is the number of queries (linear time preprocessing and constant time per query).
// Space Complexity: O(n), as extra space is used for the prefix sum array.
class Solution {
public:
   vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int> >& queries) {
      int n = nums.size();        // Number of elements in nums
      int m = queries.size();     // Number of queries

      // Create a prefix sum array to record the count of adjacent pairs with the same parity
      vector<int> cumSum(n, 0);

      cumSum[0] = 0;   // No adjacent pair for the first element

      // Build the prefix sum array: for each index, cumSum[i] holds the number of same-parity adjacent pairs from index 0 to i
      for (int i = 1; i < n; i++) {
         // If current element and previous element have the same parity, increment the count
         if (nums[i] % 2 == nums[i - 1] % 2) {
            cumSum[i] = cumSum[i - 1] + 1;
         } else {
            cumSum[i] = cumSum[i - 1];      // Otherwise, carry forward the count
         }
      }

      // Prepare the result vector to hold the boolean answer for each query
      vector<bool> result(m, false);
      int          i = 0; // Iterator for result index

      // Process each query
      for (vector<int>& query : queries) {
         int start = query[0];
         int end   = query[1];
         // If the difference in prefix sum between end and start is zero,
         // then there is no adjacent pair with the same parity in the subarray, hence it is special.
         if (cumSum[end] - cumSum[start] == 0) {
            result[i] = true;
         }
         i++;     // Move to the next result index
      }
      return result;
   }
};

