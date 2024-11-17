// Before solving this problem solve leetcode: 209. Minimum Size Subarray Sum

/*
 * 862. Shortest Subarray with Sum at Least K
 *
 * Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
 *
 * A subarray is a contiguous part of an array.
 *
 * Example 1:
 * Input: nums = [1], k = 1
 * Output: 1
 *
 * Example 2:
 * Input: nums = [1,2], k = 4
 * Output: -1
 *
 * Example 3:
 * Input: nums = [2,-1,2], k = 3
 * Output: 3
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= 10^9
 */


//Approach (Using sliding window + monotinic deque
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
   int shortestSubarray(vector<int>& nums, int K){
      int N = nums.size();

      deque<int>        deq;
      vector<long long> cumulativeSum(N, 0);    // This stores the cumulative sum

      int result = INT_MAX;
      int j      = 0;

      // Compute cumulative sum in the cumulativeSum array using while loop
      while (j < N) {
         if (j == 0) {
            cumulativeSum[j] = nums[j];
         }else{
            cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
         }

         // If the cumulative sum from the start to j is already >= K, update result
         if (cumulativeSum[j] >= K) {
            result = min(result, j + 1);
         }

         // Remove indices from the deque where the subarray sum is >= K
         while (!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= K) {
            result = min(result, j - deq.front()); // Calculate the length of the subarray
            deq.pop_front();                       // Remove the front index from the deque
         }

         // Maintain the monotonic property of the deque (increasing order of cumulative sums)
         while (!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]) {
            deq.pop_back();      // Remove indices that won't be useful
         }

         // Add the current index to the deque
         deq.push_back(j);

         j++;     // Increment j to move to the next index
      }

      // Return the result if we found a valid subarray, otherwise return -1
      return result == INT_MAX ? -1 : result;
   }
};
