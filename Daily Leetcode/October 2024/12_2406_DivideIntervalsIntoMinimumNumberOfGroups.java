/*
 * 2406. Divide Intervals Into Minimum Number of Groups
 * 
 * You are given a 2D integer array intervals where intervals[i] = [lefti,
 * righti] represents the inclusive interval [lefti, righti].
 * You have to divide the intervals into one or more groups such that each
 * interval is in exactly one group, and no two intervals that are in the same
 * group intersect each other.
 * Return the minimum number of groups you need to make.
 * Two intervals intersect if there is at least one common number between them.
 * For example, the intervals [1, 5] and [5, 8] intersect.
 * 
 * Example 1:
 * Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
 * Output: 3
 * Explanation: We can divide the intervals into the following groups:
 * - Group 1: [1, 5], [6, 8].
 * - Group 2: [2, 3], [5, 10].
 * - Group 3: [1, 10].
 * It can be proven that it is not possible to divide the intervals into fewer
 * than 3 groups.
 * 
 * Example 2:
 * Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
 * Output: 1
 * Explanation: None of the intervals overlap, so we can put all of them in one
 * group.
 * 
 * Constraints:
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * 1 <= lefti <= righti <= 10^6
 */

//Approach (Simply sorting and using heap)
//T.C : O(nlogn)
//S.C : O(n)

class Solution {
    public int minGroups(int[][] intervals) {

        // Step 1: Get the number of intervals
        int n = intervals.length;

        // Step 2: Sort the intervals based on their start time
        // This helps us process intervals in a way where overlapping ones can be
        // managed
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // Step 3: Use a priority queue (min-heap) to track the end times of intervals
        // in each group
        // The priority queue helps efficiently manage when an interval ends
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Step 4: Iterate over the sorted intervals
        for (int[] interval : intervals) {
            int start = interval[0]; // Start of the current interval
            int end = interval[1]; // End of the current interval

            // Step 5: If the start of the current interval is greater than the earliest end
            // time in the queue,
            // it means the current interval can fit in the same group, so we remove the
            // earliest end time
            if (!pq.isEmpty() && start > pq.peek()) {
                pq.poll(); // Remove the interval that ended the earliest (non-overlapping)
            }

            // Step 6: Add the end time of the current interval to the queue
            // This signifies that this interval is now part of some group
            pq.offer(end);
        }

        // Step 7: The size of the priority queue represents the minimum number of
        // groups needed
        // because it tells us how many intervals are overlapping at the same time
        return pq.size();
    }
}