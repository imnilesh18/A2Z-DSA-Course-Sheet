/*
 * 1574. Shortest Subarray to be Removed to Make Array Sorted
 *
 * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
 * Return the length of the shortest subarray to remove.
 * A subarray is a contiguous subsequence of the array.
 *
 * Example 1:
 * Input: arr = [1,2,3,10,4,2,3,5]
 * Output: 3
 * Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
 * Another correct solution is to remove the subarray [3,10,4].
 *
 * Example 2:
 * Input: arr = [5,4,3,2,1]
 * Output: 4
 * Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
 *
 * Example 3:
 * Input: arr = [1,2,3]
 * Output: 0
 * Explanation: The array is already non-decreasing. We do not need to remove any elements.
 *
 * Constraints:
 * 1 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^9
 */

// Approach (simple two pointer approach)
// T.C : O(n) - We don't visit any element once inside the while loop
// S.C : O(1)
class Solution {
public:
   int findLengthOfShortestSubarray(vector<int>& arr){
      int n = arr.size();

      // Step 1: Find the jth pointer from the right side
      int j = n - 1;

      while (j > 0 && arr[j] >= arr[j - 1]) {
         j--;
      }

      int i      = 0;
      int result = j;   // We are removing all elements left to index j because index j to n - 1 are sorted

      // Step 2: Start finding correct i and j and find deleted elements = j - i - 1
      while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {
         // arr[j] < arr[i]
         while (j < n && arr[i] > arr[j]) {
            j++;
         }

         // We have found correct jth element such that arr[i] <= arr[j]
         result = min(result, j - i - 1);
         i++;
      }
      return result;
   }
};

// Code with comments for better understanding:

// Approach (simple two pointer approach)
// T.C : O(n) - We don't visit any element once inside the while loop
// S.C : O(1)
class Solution {
public:
   int findLengthOfShortestSubarray(vector<int>& arr){
      int n = arr.size();   // Length of the array

      // Step 1: Find the rightmost part of the array that is already sorted
      int j = n - 1;

      // Traverse from the end to find the first element where the order breaks
      while (j > 0 && arr[j] >= arr[j - 1]) {
         j--;    // Move `j` left until the array stops being non-decreasing
      }

      // If the entire array is already sorted, no subarray needs to be removed
      if (j == 0) {
         return 0;
      }

      // Initialize `result` with the length of the subarray to remove
      // Assume removing everything from the start up to `j` initially
      int i      = 0;
      int result = j;   // All elements left to index `j` are assumed to be removed

      // Step 2: Use two pointers `i` and `j` to find the minimal subarray to remove
      while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {
         // Ensure the left side (0 to i) remains sorted

         // Move `j` forward until `arr[i] <= arr[j]` to maintain sorted order
         while (j < n && arr[i] > arr[j]) {
            j++;
         }

         // Update the result to the minimum length of subarray to remove
         result = min(result, j - i - 1);
         i++;    // Increment `i` to consider a longer left sorted subarray
      }

      return result;   // Return the minimum length of subarray to remove
   }
};
