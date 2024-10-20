/*
 * 219. Contains Duplicate II
 * 
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 */

// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (mp.containsKey(nums[i]) &&
                    Math.abs(mp.get(nums[i]) - i) <= k) {
                return true;
            } else {
                mp.put(nums[i], i);
            }
        }
        return false;
    }
}

// Code with comments for better understanding:
// T.C : O(n)
// S.C : O(n)

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // Create a HashMap to store each number and its most recent index
        HashMap<Integer, Integer> mp = new HashMap<>();

        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            // Check if the current number is already in the HashMap
            if (mp.containsKey(nums[i])) {
                // If it exists, check if the difference between indices is <= k
                if (Math.abs(mp.get(nums[i]) - i) <= k) {
                    // If the condition is met, return true
                    return true;
                }
            }
            // Otherwise, update the HashMap with the current index for the number
            mp.put(nums[i], i);
        }
        // If no such pair is found, return false
        return false;
    }
}
