/*
 * 1. Two Sum
 * 
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Constraints:
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 */

// T.C: O(N), where N is the number of elements in the array
// S.C: O(N), because we're using a HashMap to store elements and their indices

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int remaining = target - nums[i];

            if (mp.containsKey(remaining)) {
                return new int[] { mp.get(remaining), i };
            }

            mp.put(nums[i], i);
        }
        return new int[] {};
    }
}

// Code with comments for better understanding:

// T.C: O(N), where N is the number of elements in the array
// S.C: O(N), because we're using a HashMap to store elements and their indices

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Get the total number of elements in the array
        int n = nums.length;

        // Initialize a HashMap to store the numbers as keys and their indices as values
        HashMap<Integer, Integer> mp = new HashMap<>();

        // Loop through each element in the array
        for (int i = 0; i < n; i++) {
            // Calculate the remaining value that would sum up to the target
            int remaining = target - nums[i];

            // Check if the remaining value exists in the HashMap
            // If it does, we've found the pair of indices that add up to the target
            if (mp.containsKey(remaining)) {
                // Return the indices of the two numbers that sum up to the target
                return new int[] { mp.get(remaining), i };
            }

            // If the remaining value is not found, store the current number and its index
            // in the HashMap
            mp.put(nums[i], i);
        }

        // If no pair is found (though the problem guarantees one solution), return an
        // empty array
        return new int[] {};
    }
}
