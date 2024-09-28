/*
 * Q2. Maximize the Total Height of Unique Towers
 * 5 pt.
 * 
 * You are given an array maximumHeight, where maximumHeight[i] denotes the
 * maximum height the ith tower can be assigned.
 * Your task is to assign a height to each tower so that:
 * The height of the ith tower is a positive integer and does not exceed
 * maximumHeight[i].
 * No two towers have the same height.
 * Return the maximum possible total sum of the tower heights. If it's not
 * possible to assign heights, return -1.
 * 
 * Example 1:
 * Input: maximumHeight = [2,3,4,3]
 * Output: 10
 * Explanation:
 * We can assign heights in the following way: [1, 2, 4, 3].
 * 
 * Example 2:
 * Input: maximumHeight = [15,10]
 * Output: 25
 * Explanation:
 * We can assign heights in the following way: [15, 10].
 * 
 * Example 3:
 * Input: maximumHeight = [2,2,1]
 * Output: -1
 * Explanation:
 * It's impossible to assign positive heights to each index so that no two
 * towers have the same height.
 * 
 * Constraints:
 * 1 <= maximumHeight.length <= 10^5
 * 1 <= maximumHeight[i] <= 10^9
 */

class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        long sum = 0;
        Integer[] maximumHeightObjects = Arrays.stream(maximumHeight).boxed().toArray(Integer[]::new);
        Arrays.sort(maximumHeightObjects, Collections.reverseOrder());
        maximumHeight = Arrays.stream(maximumHeightObjects).mapToInt(Integer::intValue).toArray();
        int currentHeight = maximumHeight[0] + 1;

        for (int height : maximumHeight) {
            currentHeight = Math.min(currentHeight - 1, height);
            if (currentHeight <= 0) {
                return -1;
            }
            sum += currentHeight;
        }
        return sum;
    }
}

// Comments for better understanding: 
class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        // Initialize sum to keep track of the total height
        long sum = 0;

        // Create an Integer array from the input int array for sorting
        Integer[] maximumHeightObjects = Arrays.stream(maximumHeight).boxed().toArray(Integer[]::new);
        // Sort the array in descending order
        Arrays.sort(maximumHeightObjects, Collections.reverseOrder());
        // Convert the sorted Integer array back to an int array
        maximumHeight = Arrays.stream(maximumHeightObjects).mapToInt(Integer::intValue).toArray();

        // Initialize currentHeight with the first element + 1
        int currentHeight = maximumHeight[0] + 1;

        // Loop through each height in the array
        for (int height : maximumHeight) {
            // Update currentHeight with the minimum of currentHeight - 1 and the current
            // height
            currentHeight = Math.min(currentHeight - 1, height);
            // Check if currentHeight becomes zero or negative, indicating an invalid state
            if (currentHeight <= 0) {
                return -1;
            }
            // Add currentHeight to the total sum
            sum += currentHeight;
        }

        // Return the calculated sum
        return sum;
    }
}
