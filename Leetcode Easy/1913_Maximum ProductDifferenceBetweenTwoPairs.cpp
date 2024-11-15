/*
 * 1913. Maximum Product Difference Between Two Pairs
 *
 * The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
 * For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
 * Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
 * Return the maximum such product difference.
 *
 * Example 1:
 * Input: nums = [5,6,2,7,4]
 * Output: 34
 * Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
 * The product difference is (6 * 7) - (2 * 4) = 34.
 *
 * Example 2:
 * Input: nums = [4,2,5,9,7,4,8]
 * Output: 64
 * Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
 * The product difference is (9 * 8) - (2 * 4) = 64.
 *
 * Constraints:
 * 4 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 */

// Approach 1: via sorting
// T.C: O(nlogn)
// S.C: O(1)
class Solution {
public:
   int maxProductDifference(vector<int>& nums){
      int n = nums.size();

      sort(begin(nums), end(nums));
      return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
   }
};

// Approach 2:
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   int maxProductDifference(vector<int>& nums){
      int largest       = INT_MIN;
      int secondLargest = INT_MIN;

      int smallest       = INT_MAX;
      int secondSmallest = INT_MAX;

      for (int&num : nums) {
         // track largest and second largest
         if (num > largest) {
            secondLargest = largest;
            largest       = num;
         } else {
            secondLargest = max(secondLargest, num);
         }

         // track smallest and second smallest
         if (num < smallest) {
            secondSmallest = smallest;
            smallest       = num;
         } else {
            secondSmallest = min(secondSmallest, num);
         }
      }
      return (largest * secondLargest) - (smallest * secondSmallest);
   }
};

// Code with comments for better understanding:

// Approach 1: via sorting
// T.C: O(nlogn)
// S.C: O(1)
class Solution {
public:
   int maxProductDifference(vector<int>& nums){
      // Get the size of the array
      int n = nums.size();

      // Sort the array in ascending order
      sort(begin(nums), end(nums));

      // Calculate the product difference:
      // (largest * second largest) - (smallest * second smallest)
      // Since the array is sorted, the largest values are at the end,
      // and the smallest values are at the beginning.
      return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
   }
};

/*
 * Get the Size of the Array: int n = nums.size();
 * This retrieves the number of elements in the array, which helps identify the indices of the largest and smallest values after sorting.
 * Sort the Array: sort(begin(nums), end(nums));
 *
 * Sorting the array puts the smallest values at the beginning and the largest values at the end.
 * Calculate the Product Difference:
 *
 * nums[n - 1] and nums[n - 2] refer to the largest and second - largest elements.
 * nums[0] and nums[1] refer to the smallest and second - smallest elements.
 * The result is calculated as(largest pair product) - (smallest pair product) to maximize the product difference.
 */

// Approach 2:
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   int maxProductDifference(vector<int>& nums){
      // Initialize the largest and second-largest values to the smallest possible integer
      int largest       = INT_MIN;
      int secondLargest = INT_MIN;

      // Initialize the smallest and second-smallest values to the largest possible integer
      int smallest       = INT_MAX;
      int secondSmallest = INT_MAX;

      // Traverse through each number in the array
      for (int&num : nums) {
         // Check if the current number is greater than the current largest
         // If true, update secondLargest to largest and largest to the current number
         if (num > largest) {
            secondLargest = largest;
            largest       = num;
         } else {
            // If the current number is not the largest, check if it's larger than the secondLargest
            secondLargest = max(secondLargest, num);
         }

         // Check if the current number is smaller than the current smallest
         // If true, update secondSmallest to smallest and smallest to the current number
         if (num < smallest) {
            secondSmallest = smallest;
            smallest       = num;
         } else {
            // If the current number is not the smallest, check if it's smaller than the secondSmallest
            secondSmallest = min(secondSmallest, num);
         }
      }

      // Calculate and return the product difference between the two largest and two smallest numbers
      return (largest * secondLargest) - (smallest * secondSmallest);
   }
};

/*
 * Initialize Variables:
 * largest and secondLargest are initialized to INT_MIN to ensure that any number in nums will be larger, allowing us to update them as we find larger values.
 * smallest and secondSmallest are initialized to INT_MAX to ensure any number in nums will be smaller, allowing us to update them as we find smaller values.
 *
 * Loop Through Array:
 *
 * Find Largest and Second-Largest:
 * If num is greater than largest, we update secondLargest to hold the previous largest, then update largest to num.
 * Otherwise, we check if num is larger than secondLargest and update it if true.
 *
 * Find Smallest and Second-Smallest:
 * If num is smaller than smallest, we update secondSmallest to hold the previous smallest, then update smallest to num.
 * Otherwise, we check if num is smaller than secondSmallest and update it if true.
 *
 * Calculate Product Difference:
 * Return the product difference (largest * secondLargest) - (smallest * secondSmallest).*/
