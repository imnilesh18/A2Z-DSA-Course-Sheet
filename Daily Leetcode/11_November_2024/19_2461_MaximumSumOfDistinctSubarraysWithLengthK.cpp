/*
 * 2461. Maximum Sum of Distinct Subarrays With Length K
 *
 * You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
 * The length of the subarray is k, and
 * All the elements of the subarray are distinct.
 * Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Example 1:
 * Input: nums = [1,5,4,2,9,9,9], k = 3
 * Output: 15
 * Explanation: The subarrays of nums with length 3 are:
 * - [1,5,4] which meets the requirements and has a sum of 10.
 * - [5,4,2] which meets the requirements and has a sum of 11.
 * - [4,2,9] which meets the requirements and has a sum of 15.
 * - [2,9,9] which does not meet the requirements because the element 9 is repeated.
 * - [9,9,9] which does not meet the requirements because the element 9 is repeated.
 * We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
 *
 * Example 2:
 * Input: nums = [4,4,4], k = 3
 * Output: 0
 * Explanation: The subarrays of nums with length 3 are:
 * - [4,4,4] which does not meet the requirements because the element 4 is repeated.
 * We return 0 because no subarrays meet the conditions.
 *
 * Constraints:
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 */

//Approach (Using classic sliding window template + using set/map to keep distinct element)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
   long long maximumSubarraySum(vector<int>& nums, int k){
      int                i = 0, j = 0;
      long long          result        = 0;
      long long          currWindowSum = 0;
      unordered_set<int> st;

      while (j < nums.size()) {
         // Adjust the window if nums[j] is already in the set
         while (st.count(nums[j])) {
            currWindowSum -= nums[i];
            st.erase(nums[i]);
            i++;
         }

         currWindowSum += nums[j];
         st.insert(nums[j]);

         // Check if the window size is equal to k
         if (j - i + 1 == k) {
            result = max(result, currWindowSum);

            // Shrink the window from the left
            currWindowSum -= nums[i];
            st.erase(nums[i]);
            i++;
         }

         j++;
      }

      return result;
   }
};
