/*
 * 485. Max Consecutive Ones
 * 
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array.
 * 
 * Example 1:
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s. The maximum number of consecutive 1s is 3.
 * 
 * Example 2:
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 */
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCount = 0; // To keep track of the maximum length of consecutive 1s found
        int count = 0; // To count the current length of consecutive 1s

        // Iterate through each element in the array
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) { // Check if the current element is 1
                count++; // Increment the count of consecutive 1s
                maxCount = Math.max(maxCount, count); // Update maxCount if current count is higher
            } else {
                count = 0; // Reset count if the current element is not 1
            }
        }

        // Return the maximum length of consecutive 1s found
        return maxCount;
    }
}
