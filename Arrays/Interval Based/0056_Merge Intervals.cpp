/*
 * 56. Merge Intervals
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 *
 * Example 1:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 *
 * Example 2:
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * Constraints:
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 */

// Approach: Sort intervals by starting time, then iterate and merge overlapping intervals.
// Time Complexity: O(n log n) due to sorting.
// Space Complexity: O(n) for storing the merged intervals.
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        int n = intervals.size();

        // Sorting intervals based on start times
        sort(begin(intervals), end(intervals));

        vector<vector<int> > result;
        // Initialize result with the first interval
        result.push_back(intervals[0]);

        // Iterate over the remaining intervals
        for (int i = 1; i < n; i++) {
            // If the current interval overlaps with the last interval in result
            if (intervals[i][0] <= result.back()[1]) {
                // Merge by updating the end of the last interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap; add the current interval to result
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

/*
 * Dry Run:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Step 1: Sort intervals -> [[1,3],[2,6],[8,10],[15,18]]
 * Step 2: Initialize result = [[1,3]]
 * Step 3: i = 1, Compare [2,6] with result.back() = [1,3]
 *      Since 2 <= 3, merge -> result becomes [[1,6]]
 * Step 4: i = 2, Compare [8,10] with result.back() = [1,6]
 *      Since 8 > 6, add [8,10] to result -> result becomes [[1,6], [8,10]]
 * Step 5: i = 3, Compare [15,18] with result.back() = [8,10]
 *      Since 15 > 10, add [15,18] to result -> result becomes [[1,6], [8,10], [15,18]]
 * Final Output: [[1,6],[8,10],[15,18]]
 */
