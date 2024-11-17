/*
 * 209. Minimum Size Subarray Sum
 *
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 *
 * Example 1:
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 *
 * Example 2:
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 * Example 3:
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 * Constraints:
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 * Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
 */

// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums){
      int n = nums.size();

      int i = 0, j = 0;
      int minL = INT_MAX;

      int sum = 0;

      while (j < n) {
         sum += nums[j];

         while (sum >= target) {
            minL = min(minL, j - i + 1);

            sum -= nums[i];
            i++;
         }
         j++;
      }
      return minL == INT_MAX ? 0 : minL;
   }
};

// Code with comments for better understanding:

// T.C: O(n) - Linear time complexity as we traverse the array only once.
// S.C: O(1) - Constant space as no extra data structures are used.

class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums){
      int n = nums.size(); // Get the size of the input array.

      int i = 0, j = 0;    // Two pointers: 'i' is the start of the window, 'j' is the end.
      int minL = INT_MAX;  // Initialize the minimum length to the maximum possible value.

      int sum = 0;         // Variable to store the current sum of the window.

      // Iterate through the array with 'j' as the end pointer of the sliding window.
      while (j < n) {
         sum += nums[j]; // Add the current element to the window sum.

         // Shrink the window from the left as long as the sum is greater than or equal to the target.
         while (sum >= target) {
            // Update the minimum length of the window.
            minL = min(minL, j - i + 1);

            // Subtract the element at the start of the window and move the start pointer.
            sum -= nums[i];
            i++;
         }
         j++; // Expand the window by moving the end pointer.
      }

      // If no valid subarray was found, return 0. Otherwise, return the minimum length.
      return minL == INT_MAX ? 0 : minL;
   }
};

/*
 * Two Pointers (i, j):
 *
 * i is the start of the current window, and j is the end. This forms the sliding window.
 *
 * Sliding Window Expansion:
 * Add elements to sum by expanding the window (j++).
 *
 * Sliding Window Shrinking:
 * If sum >= target, shrink the window from the left by increasing i. During this process, check if the current window size is the smallest so far.
 *
 * Edge Case:
 * If no subarray meets the condition (sum >= target), return 0. Otherwise, return the smallest valid window size.
 *
 * This approach ensures linear traversal with optimal efficiency.
 */
