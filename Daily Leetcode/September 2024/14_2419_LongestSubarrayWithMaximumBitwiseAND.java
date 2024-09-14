/*
 * 2419. Longest Subarray With Maximum Bitwise AND
 * 
 * You are given an integer array nums of size n.
 * Consider a non-empty subarray from nums that has the maximum possible bitwise
 * AND.
 * In other words, let k be the maximum value of the bitwise AND of any subarray
 * of nums. Then, only subarrays with a bitwise AND equal to k should be
 * considered.
 * Return the length of the longest such subarray.
 * The bitwise AND of an array is the bitwise AND of all the numbers in it.
 * A subarray is a contiguous sequence of elements within an array.
 * 
 * Example 1:
 * Input: nums = [1,2,3,3,2,2]
 * Output: 2
 * Explanation:
 * The maximum possible bitwise AND of a subarray is 3.
 * The longest subarray with that value is [3,3], so we return 2.
 * 
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: 1
 * Explanation:
 * The maximum possible bitwise AND of a subarray is 4.
 * The longest subarray with that value is [4], so we return 1.
 * 
 * Constraints:
 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 106
 */

// Time Complexity: O(n)
// Space Complexity: O(1)
//  Approach:
//  * - First, identify the maximum value present in the array.
//  * - Then, look for the longest contiguous subarray where all elements are equal to that maximum value.
//  * - This is because, for any subarray to have the maximum bitwise AND, it must contain the maximum value.
class Solution {
    public int longestSubarray(int[] nums) {
        // Initialize variables
        int maxVal = 0; // To store the maximum value in the array
        int result = 0; // To store the length of the longest subarray
        int streak = 0; // To track the current streak of maximum values

        // Iterate through the array
        for (int num : nums) {

            // If the current number is greater than the maximum value found so far
            if (num > maxVal) {
                maxVal = num; // Update maxVal to the new maximum value
                result = 0; // Reset the result since a new maximum is found
                streak = 0; // Reset the streak as we start counting for the new maxVal
            }

            // If the current number is equal to the maximum value
            if (num == maxVal) {
                streak++; // Increase the streak of consecutive maxVal occurrences
            } else {
                streak = 0; // Reset the streak if the current number is not equal to maxVal
            }

            // Update the result to store the maximum length of the subarray
            result = Math.max(result, streak);
        }

        // Return the length of the longest subarray with the maximum bitwise AND value
        return result;
    }
}