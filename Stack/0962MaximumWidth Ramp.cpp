/*
 * 962. Maximum Width Ramp
 *
 * A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
 * Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
 *
 * Example 1:
 * Input: nums = [6,0,8,2,1,5]
 * Output: 4
 * Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
 *
 * Example 2:
 * Input: nums = [9,8,1,0,1,9,4,0,4,1]
 * Output: 7
 * Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 *
 * Constraints:
 * 2 <= nums.length <= 5 * 0^4
 * 0 <= nums[i] <= 5 * 10^4
 */
class Solution {
public:
   int maxWidthRamp(vector<int>& nums){
      int n = nums.size();

      stack<int> st;          // Store the indices of the elements

      for (int i = 0; i < n; i++) {
         if (st.empty() || nums[st.top()] >= nums[i]) {
            st.push(i);
         }
      }

      int ramp = 0;

      int j = n - 1;

      while (j >= 0) {
         while (!st.empty() && nums[st.top()] <= nums[j]) {
            int i = st.top();
            ramp = max(ramp, j - i);
            st.pop();
         }
         j--;
      }
      return ramp;
   }
};
