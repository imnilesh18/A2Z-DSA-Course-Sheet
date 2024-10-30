/*
 * 300. Longest Increasing Subsequence
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
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
 */

// T.C : O(n²)
// S.C : O(n)
class Solution {
public:
   int lengthOfLIS(vector<int>& nums){
      int n = nums.size();

      vector<int> t(n, 1);

      int maxLIS = 1;

      for (int i = 0; i < n; i++) {
         for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
               t[i]   = max(t[i], t[j] + 1);
               maxLIS = max(maxLIS, t[i]);
            }
         }
      }
      return maxLIS;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   int lengthOfLIS(vector<int>& nums){
      int n = nums.size();

      // Vector t holds the length of the longest increasing subsequence up to each index
      vector<int> t(n, 1);

      // Variable to track the maximum length of LIS found so far
      int maxLIS = 1;

      // Iterate over each element as the end element of a subsequence
      for (int i = 0; i < n; i++) {
         // Check all previous elements to see if they can form an increasing subsequence with nums[i]
         for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {     // Condition for increasing subsequence
               // Update t[i] to the longest subsequence length ending at index i
               t[i] = max(t[i], t[j] + 1);
               // Update maxLIS with the largest subsequence length found so far
               maxLIS = max(maxLIS, t[i]);
            }
         }
      }
      return maxLIS;   // Return the maximum length of increasing subsequence found
   }
};
