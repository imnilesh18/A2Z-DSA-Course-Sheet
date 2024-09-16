/*
 * 539. Minimum Time Difference
 * 
 * Given a list of 24-hour clock time points in "HH:MM" format, return the
 * minimum minutes difference between any two time-points in the list.
 * 
 * Example 1:
 * Input: timePoints = ["23:59","00:00"]
 * Output: 1
 * 
 * Example 2:
 * Input: timePoints = ["00:00","23:59","00:00"]
 * Output: 0
 * 
 * Constraints:
 * 2 <= timePoints.length <= 2 * 104
 * timePoints[i] is in the format "HH:MM".
 */

//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(nlogn)
//S.C : O(n)
//NOTE - You can use Bucket sort because input (miniutes) will always be between [0, 1439]
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        int[] minutes = new int[n];

        // Convert timePoints to minutes
        for (int i = 0; i < n; i++) {
            String time = timePoints.get(i);
            String[] parts = time.split(":");

            int hours = Integer.parseInt(parts[0]);
            int mins = Integer.parseInt(parts[1]);

            minutes[i] = hours * 60 + mins;
        }

        // Sort the minutes array
        Arrays.sort(minutes);

        // Initialize result with the maximum possible value
        int result = Integer.MAX_VALUE;

        // Find the minimum difference between adjacent times
        for (int i = 1; i < n; i++) {
            result = Math.min(result, minutes[i] - minutes[i - 1]);
        }

        // Check the circular case (between the first and last times)
        result = Math.min(result, (24 * 60 - minutes[n - 1]) + minutes[0]);

        return result;
    }
}