/*
 * 624. Maximum Distance in Arrays
 * 
 * You are given m arrays, where each array is sorted in ascending order.
 * You can pick up two integers from two different arrays (each array picks one)
 * and calculate the distance. We define the distance between two integers a and
 * b to be their absolute difference |a - b|.
 * Return the maximum distance.
 * 
 * Example 1:
 * Input: arrays = [[1,2,3],[4,5],[1,2,3]]
 * Output: 4
 * Explanation: One way to reach the maximum distance 4 is to pick 1 in the
 * first or third array and pick 5 in the second array.
 * 
 * Example 2:
 * Input: arrays = [[1],[1]]
 * Output: 0
 */

class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int MIN = arrays.get(0).get(0);
        int MAX = arrays.get(0).get(arrays.get(0).size() - 1);

        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int currMin = arrays.get(i).get(0);
            int currMax = arrays.get(i).get(arrays.get(i).size() - 1);

            result = Math.max(result, Math.max(Math.abs(currMin - MAX), Math.abs(currMax - MIN)));

            MAX = Math.max(MAX, currMax);
            MIN = Math.min(MIN, currMin);
        }
        return result;
    }
}
