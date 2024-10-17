/*
 * 11. Container With Most Water
 * 
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the ith line are (i, 0) and (i,
 * height[i]).
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 * 
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 * 
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
 * 
 * Constraints:
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 */

// T.C : O(n)
// S.C : O(1)
class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxWater = 0;

        int i = 0;
        int j = n - 1;
        while (i < j) {
            int w = j - i;
            int h = Math.min(height[i], height[j]);

            int area = w * h;

            maxWater = Math.max(maxWater, area);

            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maxWater;
    }
}

// Code with comments for better understanding:
// T.C : O(n)
// S.C : O(1)
class Solution {
    public int maxArea(int[] height) {
        int n = height.length; // Get the number of vertical lines
        int maxWater = 0; // Initialize variable to store the maximum water area

        int i = 0; // Start pointer at the leftmost line
        int j = n - 1; // End pointer at the rightmost line
        while (i < j) { // Loop until the two pointers meet
            int w = j - i; // Calculate the width of the container
            int h = Math.min(height[i], height[j]); // Find the height of the container

            int area = w * h; // Calculate the area (water capacity) of the current container

            maxWater = Math.max(maxWater, area); // Update the maximum area found so far

            // Move the pointer pointing to the shorter line
            if (height[i] > height[j]) {
                j--; // Move the end pointer left if the left line is taller
            } else {
                i++; // Move the start pointer right if the right line is taller or equal
            }
        }
        return maxWater; // Return the maximum area found
    }
}
