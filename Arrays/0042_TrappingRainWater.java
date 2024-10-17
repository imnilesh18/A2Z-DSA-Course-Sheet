/*
 * 42. Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
 * are being trapped.
 * 
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * Constraints:
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 */

// T.C : O(n)
// S.C : O(n)
class Solution {
    public int trap(int[] height) {
        int n = height.length;

        int[] leftMax = new int[n];
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }

        int[] rightMax = new int[n];
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }

        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            int h = Math.min(leftMax[i], rightMax[i]) - height[i];
            waterTrapped += h;
        }
        return waterTrapped;
    }
}

// Code with comments for better understanding:
// T.C : O(n)
// S.C : O(n)

class Solution {
    public int trap(int[] height) {
        int n = height.length; // Get the total number of elements in the height array

        // Create an array to store the maximum height encountered from the left for
        // each position
        int[] leftMax = new int[n];
        leftMax[0] = height[0]; // The left max at index 0 is the height at index 0
        for (int i = 1; i < n; i++) {
            // For each index i, store the maximum of the current height and the max height
            // to the left
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }

        // Create an array to store the maximum height encountered from the right for
        // each position
        int[] rightMax = new int[n];
        rightMax[n - 1] = height[n - 1]; // The right max at the last index is the height at the last index
        for (int i = n - 2; i >= 0; i--) {
            // For each index i, store the maximum of the current height and the max height
            // to the right
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }

        // Calculate the total amount of water trapped
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            // The water trapped at each index is the difference between the smaller of the
            // left and right max heights and the current height
            int h = Math.min(leftMax[i], rightMax[i]) - height[i];
            waterTrapped += h; // Accumulate the total trapped water
        }

        return waterTrapped; // Return the total amount of water trapped
    }
}
