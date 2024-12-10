/*
 * 435. Non-overlapping Intervals
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 *
 * Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
 *
 * Example 1:
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 *
 * Example 2:
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
 *
 * Example 3:
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 *
 * Constraints:
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 */

// Approach 1: Sorting
// T.C: O(nlogn) + O(n) ~ O(n)
// S.C: O(1)
class Solution {
public:
   int eraseOverlapIntervals(vector<vector<int> >& intervals){
      sort(begin(intervals), end(intervals));

      int n     = intervals.size();
      int i     = 0;
      int j     = 1;
      int count = 0;

      while (j < n) {
         vector<int> curr_interval = intervals[i];
         vector<int> next_interval = intervals[j];

         int cs = curr_interval[0];
         int ce = curr_interval[1];

         int ns = next_interval[0];
         int ne = next_interval[1];

         if (ce <= ns) {
            i = j;
            j++;
         } else if (ce <= ne) {
            j++;
            count++;
         } else if (ce > ne) {
            i = j;
            j++;
            count++;
         }
      }
      return count;
   }
};

// Approach 2: Sorting and using last interval (same but different implementation)
// T.C: O(nlogn) + O(n) ~ O(n)
// S.C: O(1)
class Solution {
public:
   int eraseOverlapIntervals(vector<vector<int> >&intervals){
      // Sort intervals based on their start times
      sort(begin(intervals), end(intervals));

      int         count = 0;                // Counter for the number of intervals to remove
      int         n     = intervals.size(); // Total number of intervals
      int         i     = 1;                // Pointer to iterate through intervals
      vector<int> L     = intervals[0];     // L represents the last interval in the non-overlapping set

      while (i < n) {
         int curr_end   = intervals[i][1]; // End of the current interval
         int curr_start = intervals[i][0]; // Start of the current interval
         int last_end   = L[1];            // End of the last interval in the non-overlapping set

         if (curr_start >= last_end) {
            // No overlap with the last interval
            // Update the last interval to the current interval
            L = intervals[i];
            i++;
         } else if (curr_end >= last_end) {
            // Overlap, but the current interval's end is beyond or equal to the last interval's end
            // Remove the current interval (increment count)
            count++;
            i++;
         } else if (curr_end < last_end) {
            // Overlap, and the current interval ends earlier than the last interval
            // Remove the last interval by updating L to the current interval
            count++;
            L = intervals[i];
            i++;
         }
      }
      return count;   // Return the total number of intervals removed
   }
};
