/*
 * 53. Maximum Subarray
 * (Solve 1749. Maximum Absolute Sum of Any Subarray)
 *
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 *
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 *
 * Example 2:
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 *
 * Example 3:
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

// Approach: Use Kadane's algorithm to track the maximum subarray sum by either starting a new subarray at the current element or continuing the existing subarray.
// TC: O(n) - The array is traversed once.
// SC: O(1) - Only constant extra space is used.
class Solution {
public:
   int maxSubArray(vector<int>& nums) {
      int n          = nums.size(); // Number of elements in the array
      int maxSum     = nums[0];     // Initialize global maximum with the first element
      int currSumMax = nums[0];     // Initialize current subarray sum with the first element

      for (int i = 1; i < n; i++) {
         // Update current subarray sum: either start a new subarray at nums[i] or extend the previous subarray
         currSumMax = max(nums[i], currSumMax + nums[i]);
         // Update global maximum sum if the current subarray sum is higher
         maxSum = max(maxSum, currSumMax);
      }
      return maxSum;
   }
};

/*
 * Dry Run
 * Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *
 * Initial:
 * maxSum = -2, currSumMax = -2
 *
 * Iteration 1 (nums[1] = 1):
 * currSumMax = max(1, (-2 + 1)) = 1
 * maxSum = max(-2, 1) = 1
 *
 * Iteration 2 (nums[2] = -3):
 * currSumMax = max(-3, (1 + (-3))) = -2
 * maxSum = max(1, -2) = 1
 *
 * Iteration 3 (nums[3] = 4):
 * currSumMax = max(4, (-2 + 4)) = 4
 * maxSum = max(1, 4) = 4
 *
 * Iteration 4 (nums[4] = -1):
 * currSumMax = max(-1, (4 + (-1))) = 3
 * maxSum = max(4, 3) = 4
 *
 * Iteration 5 (nums[5] = 2):
 * currSumMax = max(2, (3 + 2)) = 5
 * maxSum = max(4, 5) = 5
 *
 * Iteration 6 (nums[6] = 1):
 * currSumMax = max(1, (5 + 1)) = 6
 * maxSum = max(5, 6) = 6
 *
 * Iteration 7 (nums[7] = -5):
 * currSumMax = max(-5, (6 + (-5))) = 1
 * maxSum = max(6, 1) = 6
 *
 * Iteration 8 (nums[8] = 4):
 * currSumMax = max(4, (1 + 4)) = 5
 * maxSum = max(6, 5) = 6
 *
 * Final Answer: 6
 * End Dry Run
 */
