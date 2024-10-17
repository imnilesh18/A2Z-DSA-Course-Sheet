/*
 * 16. 3Sum Closest
 * 
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * Example 1:
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * Example 2:
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 * 
 * Constraints:
 * 3 <= nums.length <= 500
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 */

// T.C : O(n²)
// S.C : O(1)
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int closestSum = Integer.MAX_VALUE;

        Arrays.sort(nums);

        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];

                if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum > target) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return closestSum;
    }
}

// Code with comments for better understanding:
// T.C : O(n²)
// S.C : O(1)
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length; // Get the length of the input array
        int closestSum = Integer.MAX_VALUE; // Initialize the closest sum to a large value

        // Sort the array to apply two-pointer approach
        Arrays.sort(nums);

        // Loop through each number as the first element in the triplet
        for (int k = 0; k < n - 2; k++) { // We need at least 2 elements after the current element, hence n-2
            int i = k + 1; // Left pointer starts just after k
            int j = n - 1; // Right pointer starts at the end of the array

            // Use two-pointer technique to find the closest sum
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of three elements

                // Check if the current sum is closer to the target than the previous closest
                // sum
                if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                    closestSum = sum; // Update the closest sum if the current one is closer
                }

                // If the current sum is greater than the target, move the right pointer to the
                // left
                if (sum > target) {
                    j--;
                }
                // If the current sum is less than or equal to the target, move the left pointer
                // to the right
                else {
                    i++;
                }
            }
        }
        // Return the closest sum found
        return closestSum;
    }
}
