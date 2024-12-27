/*
 * 1014. Best Sightseeing Pair
 *
 * You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
 * The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
 * Return the maximum score of a pair of sightseeing spots.
 *
 * Example 1:
 * Input: values = [8,1,5,2,6]
 * Output: 11
 * Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 *
 * Example 2:
 * Input: values = [1,2]
 * Output: 2
 *
 * Constraints:
 * 2 <= values.length <= 5 * 10^4
 * 1 <= values[i] <= 1000
 */

// Approach 1 (Brute Force TLE 48/55): For each j, we look back at all previous i values (0 to j-1) to find max(values[i] + i) and combine it with (values[j] - j) to get max score.
// TC: O(n²) since for each element j we iterate back through up to j-1 elements.
// SC: O(1) as we only use a few variables regardless of input size.
class Solution {
public:
   int maxScoreSightseeingPair(vector<int>& values){
      int n      = values.size();
      int result = 0;

      // Iterate through all possible j values (second spot in the pair)
      for (int j = 1; j < n; j++) {
         int maxVal = 0;

         // For each j, look back at all possible i values (first spot)
         // to find the maximum value of (values[i] + i)
         for (int i = j - 1; i >= 0; i--) {
            // For each pair (i,j), the score formula can be rewritten as:
            // (values[i] + i) + (values[j] - j)
            // So we find the maximum of (values[i] + i) for all i < j
            maxVal = max(maxVal, values[i] + i);
         }

         // Calculate the final score for current j by adding (values[j] - j)
         // Update the result if this score is higher than previous maximum
         result = max(result, maxVal + values[j] - j);
      }
      return result;
   }
};

// Approach 2: Precompute max(values[i] + i) for all positions using prefix array, then iterate once more to find best pair by combining each (values[j] - j) with precomputed max up to j-1.
// TC: O(n) since we have two linear iterations - one to build vec array and one to compute final result.
// SC: O(n) for the extra vector vec that stores precomputed maximums.
class Solution {
public:
   int maxScoreSightseeingPair(vector<int>& values){
      int n = values.size();

      // vec[i] stores the maximum value of (values[k] + k) for all k from 0 to i
      vector<int> vec(n, 0);

      vec[0] = values[0] + 0;   // Initialize first value

      // For each index i, calculate max of (previous max, current value + index)
      for (int i = 1; i < n; i++) {
         vec[i] = max(vec[i - 1], values[i] + i);
      }

      int result = 0;
      // For each j starting from index 1, find maximum score
      for (int j = 1; j < n; j++) {
         // x = values[j] - j part of the score formula
         int x = values[j] - j;
         // y = maximum of (values[i] + i) for all i < j, which we stored in vec[j-1]
         int y = vec[j - 1];

         // Update result if current score is higher
         result = max(result, x + y);
      }
      return result;
   }
};

// Approach 3: Use a single variable to track max(values[i] + i) seen so far and combine it with (values[j] - j) at each position j to find maximum score
// TC: O(n) since we do a single pass through the array with constant time operations at each step
// SC: O(1) as we only use a few variables regardless of input size
class Solution {
public:
   int maxScoreSightseeingPair(vector<int>& values){
      int n = values.size();

      // Keep track of maximum (values[i] + i) seen so far
      // Initialize with first value plus its index
      int max_till_now = values[0] + 0;

      int result = 0;

      // For each position j starting from index 1
      for (int j = 1; j < n; j++) {
         // Current position's (values[j] - j) part of score formula
         int x = values[j] - j;
         // Maximum of (values[i] + i) seen so far for i < j
         int y = max_till_now;

         // Update result if current score is higher
         result = max(result, x + y);

         // Update maximum (values[i] + i) seen so far including current position
         max_till_now = max(max_till_now, values[j] + j);
      }
      return result;
   }
};

// Approach 4: Use priority queue to track max(values[i] + i) seen so far and combine it with (values[j] - j) at each position j to find maximum score
// TC: O(nlogn) since for each element we perform a priority queue push operation which takes O(logn) time
// SC: O(n) for storing up to n elements in the priority queue
class Solution {
public:
   int maxScoreSightseeingPair(vector<int>& values){
      int n = values.size();

      // Use priority queue to keep track of maximum (values[i] + i) seen so far
      priority_queue<int> pq;

      // Initialize with first value plus its index
      pq.push(values[0] + 0);

      int result = 0;
      // For each position j
      for (int j = 1; j < n; j++) {
         // Get maximum score by combining:
         // - Maximum (values[i] + i) from previous positions (from pq)
         // - Current position's (values[j] - j)
         result = max(result, pq.top() + (values[j] - j));
         // Add current position's (values[j] + j) to queue for future positions
         pq.push(values[j] + j);
      }
      return result;
   }
};
