/*
 * 1464. Maximum Product of Two Elements in an Array
 *
 * Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 *
 * Example 1:
 * Input: nums = [3,4,5,2]
 * Output: 12
 * Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
 *
 * Example 2:
 * Input: nums = [1,5,4,5]
 * Output: 16
 * Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
 *
 * Example 3:
 * Input: nums = [3,7]
 * Output: 12
 *
 * Constraints:
 * 2 <= nums.length <= 500
 * 1 <= nums[i] <= 10^3
 */

// Approach-1 (Keep finding the max current number)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   int maxProduct(vector<int>& nums){
      int n        = nums.size();
      int curr_max = nums[0];

      int result = 0;

      for (int i = 1; i < n; i++) {
         result = max(result, (nums[i] - 1) * (curr_max - 1));

         curr_max = max(curr_max, nums[i]);
      }
      return result;
   }
};

// Approach-2 (Find max and secondmax number)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   int maxProduct(vector<int>& nums){
      int largest       = 0;
      int secondLargest = 0;

      for (int&num : nums) {
         if (num > largest) {
            secondLargest = largest;
            largest       = num;
         } else {
            secondLargest = max(secondLargest, num);
         }
      }

      return (largest - 1) * (secondLargest - 1);
   }
};

// Codes with comment for better understanding:

// Approach-1: Single Pass with Running Maximum
// T.C : O(n)
// S.C : O(1)
// Intuition:
// - For each number, we want to pair it with the largest number we've seen so far
// - By keeping track of current maximum, we can calculate potential products as we go
// - This way we don't need to store all numbers or sort the array
class Solution {
public:
   int maxProduct(vector<int>& nums){
      int n = nums.size();
      // Initialize current_max with first number
      int curr_max = nums[0];

      // Initialize result to store maximum product
      int result = 0;

      // Iterate through array starting from second element
      for (int i = 1; i < n; i++) {
         // Calculate product between current number and largest seen so far
         // Subtract 1 from both numbers as per problem requirement
         result = max(result, (nums[i] - 1) * (curr_max - 1));

         // Update curr_max if we find a larger number
         curr_max = max(curr_max, nums[i]);
      }
      return result;
   }
};

// Approach-2: Track Two Largest Numbers
// T.C : O(n)
// S.C : O(1)
// Intuition:
// - The maximum product will always be from the two largest numbers
// - We can find these in a single pass without sorting
// - Keep track of largest and second largest numbers as we iterate
class Solution {
public:
   int maxProduct(vector<int>& nums){
      // Variables to keep track of two largest numbers
      int largest       = 0;
      int secondLargest = 0;

      // Iterate through all numbers
      for (int& num : nums) {
         if (num > largest) {
            // If we find a number larger than our current largest
            // Current largest becomes second largest
            secondLargest = largest;
            largest       = num;
         } else {
            // If number is not larger than largest
            // Check if it should be our second largest
            secondLargest = max(secondLargest, num);
         }
      }

      // Return product after subtracting 1 from both numbers
      return (largest - 1) * (secondLargest - 1);
   }
};
