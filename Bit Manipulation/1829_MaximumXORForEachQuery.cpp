/*
 * 1829. Maximum XOR for Each Query
 *
 * You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want to perform the following query n times:
 * Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
 * Remove the last element from the current array nums.
 * Return an array answer, where answer[i] is the answer to the ith query.
 *
 * Example 1:
 * Input: nums = [0,1,1,3], maximumBit = 2
 * Output: [0,3,2,3]
 * Explanation: The queries are answered as follows:
 * 1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
 * 2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
 * 3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
 * 4th query: nums = [0], k = 3 since 0 XOR 3 = 3.
 *
 * Example 2:
 * Input: nums = [2,3,4,7], maximumBit = 3
 * Output: [5,2,6,5]
 * Explanation: The queries are answered as follows:
 * 1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
 * 2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
 * 3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
 * 4th query: nums = [2], k = 5 since 2 XOR 5 = 7.
 *
 * Example 3:
 * Input: nums = [0,1,2,2,5,7], maximumBit = 3
 * Output: [4,3,6,4,6,7]
 *
 * Constraints:
 * nums.length == n
 * 1 <= n <= 105
 * 1 <= maximumBit <= 20
 * 0 <= nums[i] < 2maximumBit
 * nums​​​ is sorted in ascending order.
 */

// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   vector<int> getMaximumXor(vector<int>& nums, int maximumBit){
      int         n = nums.size();
      vector<int> result(n);

      // Step 1 : Find the total XOR
      int XOR = 0;

      for (int i = 0; i < n; i++) {
         XOR ^= nums[i];
      }

      // To find flip, first find the mask having all bits set to 1
      int mask = ((1 << maximumBit) - 1); // 2^n - 1

      for (int i = 0; i < n; i++) {
         int k = XOR ^ mask;    // This will give me the flipped value of XOR i.e my best k
         result[i] = k;

         XOR = (XOR ^ nums[n - i - 1]);
      }

      return result;
   }
};

// Code with comments for better understanding:

// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   vector<int> getMaximumXor(vector<int>& nums, int maximumBit){
      int         n = nums.size();
      vector<int> result(n);

      // Step 1: Find the cumulative XOR of all elements in nums
      int XOR = 0;

      for (int i = 0; i < n; i++) {
         XOR ^= nums[i];  // Accumulate XOR of all elements
      }

      // Step 2: Create a mask with all bits set to 1 within the range defined by maximumBit
      // This mask will help us flip bits to maximize XOR for each query
      int mask = ((1 << maximumBit) - 1);

      // Step 3: Answer each query by finding the optimal k and updating the XOR
      for (int i = 0; i < n; i++) {
         // Find k such that XOR ^ k is maximized, which is achieved by XORing with mask
         int k = XOR ^ mask; // This will give the maximum XOR with current XOR value
         result[i] = k;      // Store the result for the current query

         // Update XOR by removing the last element in the current nums array
         XOR ^= nums[n - i - 1];  // Update XOR by removing the last element from XOR
      }

      return result;
   }
};
