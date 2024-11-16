/*
 * 3254. Find the Power of K-Size Subarrays I
 *
 * You are given an array of integers nums of length n and a positive integer k.
 * The power of an array is defined as:
 * Its maximum element if all of its elements are consecutive and sorted in ascending order.
 * -1 otherwise.
 * You need to find the power of all subarrays of nums of size k.
 *
 * Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4,3,2,5], k = 3
 * Output: [3,4,-1,-1,-1]
 * Explanation:
 * There are 5 subarrays of nums of size 3:
 * [1, 2, 3] with the maximum element 3.
 * [2, 3, 4] with the maximum element 4.
 * [3, 4, 3] whose elements are not consecutive.
 * [4, 3, 2] whose elements are not sorted.
 * [3, 2, 5] whose elements are not consecutive.
 *
 * Example 2:
 * Input: nums = [2,2,2,2,2], k = 4
 * Output: [-1,-1]
 *
 * Example 3:
 * Input: nums = [3,2,3,2,3,2], k = 2
 * Output: [-1,3,-1,3,-1]
 *
 * Constraints:
 * 1 <= n == nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= n
 */

// Approach 1: (Using Sliding Window)
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   vector<int> resultsArray(vector<int>& nums, int k){
      int n = nums.size();

      vector<int> result(n - k + 1, -1);

      int count = 1;

      for (int i = 1; i < k; i++) {
         if (nums[i] == nums[i - 1] + 1) {
            count++;
         } else {
            count = 1;
         }
      }

      if (count == k) {
         result[0] = nums[k - 1];
      }

      int i = 1;
      int j = k;

      while (j < n) {
         if (nums[j] == nums[j - 1] + 1) {
            count++;
         } else {
            count = 1;
         }

         if (count >= k) {
            result[i] = nums[j];
         }

         i++;
         j++;
      }
      return result;
   }
};

// Approach 2 (Using Monotonic Deque)
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
   vector<int> resultsArray(vector<int>& nums, int k){
      int n = nums.size();

      deque<int>  deq;
      vector<int> result;

      for (int j = 0; j < n; j++) {
         if (deq.size() == k) {
            deq.pop_front();
         }

         if (!deq.empty() && deq.back() != nums[j] - 1) {
            deq.clear();
         }

         deq.push_back(nums[j]);

         if (j >= k - 1) {
            if (deq.size() == k) {
               result.push_back(deq.back());
            } else {
               result.push_back(-1);
            }
         }
      }
      return result;
   }
};

// Code with comments for better understanding:

// Approach 1: (Using Sliding Window)
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   vector<int> resultsArray(vector<int>& nums, int k){
      int n = nums.size();

      // Initialize the result array with -1 for all subarrays of size k.
      vector<int> result(n - k + 1, -1);

      int count = 1;   // This keeps track of the length of the current consecutive sequence.

      // Check the first k elements to see if they form a consecutive sequence.
      for (int i = 1; i < k; i++) {
         if (nums[i] == nums[i - 1] + 1) {
            count++;     // Increment count if the current element is consecutive to the previous one.
         } else {
            count = 1;   // Reset count if the sequence breaks.
         }
      }

      // If the first k elements form a consecutive sequence, set the result for the first subarray.
      if (count == k) {
         result[0] = nums[k - 1];    // The maximum element of a sorted subarray is the last element.
      }

      // Use a sliding window to check the remaining subarrays.
      int i = 1;   // Start index of the current subarray.
      int j = k;   // End index of the current subarray (1-indexed).

      while (j < n) {
         if (nums[j] == nums[j - 1] + 1) {
            count++;     // Increment count if the current element is consecutive to the previous one.
         } else {
            count = 1;   // Reset count if the sequence breaks.
         }

         // If the current window of size k forms a consecutive sequence, update the result.
         if (count >= k) {
            result[i] = nums[j];     // Maximum element in a valid k-sized subarray.
         }

         // Slide the window.
         i++;
         j++;
      }
      return result;   // Return the final results array.
   }
};

// Approach 2 (Using Monotonic Deque)
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
   vector<int> resultsArray(vector<int>& nums, int k){
      int n = nums.size(); // Length of the input array.

      deque<int>  deq;     // Deque to store elements of the current subarray.
      vector<int> result;  // Vector to store the power of each k-sized subarray.

      // Iterate through each element in the array.
      for (int j = 0; j < n; j++) {
         // Maintain the size of the deque to represent a window of size k.
         if (deq.size() == k) {
            deq.pop_front();     // Remove the oldest element if the deque is full.
         }

         // Check if the new element breaks the consecutive sequence.
         // If so, clear the deque to reset the sequence.
         if (!deq.empty() && deq.back() != nums[j] - 1) {
            deq.clear();     // Reset the deque if the current element is not consecutive.
         }

         // Add the current element to the deque.
         deq.push_back(nums[j]);

         // If the window has reached size k, calculate the power of the subarray.
         if (j >= k - 1) {
            if (deq.size() == k) {
               // If the deque contains a valid consecutive sequence, store the maximum element.
               result.push_back(deq.back());
            } else {
               // Otherwise, store -1 to indicate an invalid subarray.
               result.push_back(-1);
            }
         }
      }

      return result;   // Return the result array containing the power of each k-sized subarray.
   }
};
