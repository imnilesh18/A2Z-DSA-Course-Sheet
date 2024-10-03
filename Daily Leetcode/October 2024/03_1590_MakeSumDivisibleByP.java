/*
 * 1590. Make Sum Divisible by P
 * 
 * Given an array of positive integers nums, remove the smallest subarray
 * (possibly empty) such that the sum of the remaining elements is divisible by
 * p. It is not allowed to remove the whole array.
 * Return the length of the smallest subarray that you need to remove, or -1 if
 * it's impossible.
 * A subarray is defined as a contiguous block of elements in the array.
 * 
 * Example 1:
 * Input: nums = [3,1,4,2], p = 6
 * Output: 1
 * Explanation: The sum of the elements in nums is 10, which is not divisible by
 * 6. We can remove the subarray [4], and the sum of the remaining elements is
 * 6, which is divisible by 6.
 * 
 * Example 2:
 * Input: nums = [6,3,5,2], p = 9
 * Output: 2
 * Explanation: We cannot remove a single element to get a sum divisible by 9.
 * The best way is to remove the subarray [5,2], leaving us with [6,3] with sum
 * 9.
 * 
 * Example 3:
 * Input: nums = [1,2,3], p = 3
 * Output: 0
 * Explanation: Here the sum is 6. which is already divisible by 3. Thus we do
 * not need to remove anything.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
 */

// Approach: (Using prefix sum modulo and storing in hashmap)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length; // Length of the array
        int sum = 0; // To store the sum of the array modulo p

        // Step 1: Calculate the total sum of the array modulo p
        for (int num : nums) {
            sum = (sum + num) % p; // Update the sum with modulo p to prevent overflow
        }

        // Step 2: Calculate the remainder (target) that needs to be removed to make the
        // sum divisible by p
        int target = sum % p;

        // Step 3: If the sum is already divisible by p, no need to remove any subarray,
        // return 0
        if (target == 0) {
            return 0;
        }

        // Step 4: Create a HashMap to store the prefix sum mod p and its index
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1); // Initialize with prefix sum 0 at index -1 for the edge case

        int curr = 0; // Variable to store the current prefix sum modulo p
        int result = n; // Variable to store the minimum length of subarray to remove, initialized to n
                        // (max length)

        // Step 5: Iterate through the array to find the smallest subarray that can be
        // removed
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p; // Calculate current prefix sum modulo p
            int prev = (curr - target + p) % p; // Calculate the required previous prefix sum mod p

            // Step 6: Check if this previous prefix sum has already been seen
            if (mp.containsKey(prev)) {
                // Update result with the minimum subarray length that needs to be removed
                result = Math.min(result, j - mp.get(prev));
            }

            // Step 7: Store the current prefix sum and its index in the map
            mp.put(curr, j);
        }

        // Step 8: If no valid subarray is found, return -1; otherwise, return the
        // minimum subarray length
        return result == n ? -1 : result;
    }
}

// My Approach but TLE:
class Solution {
    public int minSubarray(int[] nums, int p) {

        long sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if (sum % p == 0) {
            return 0;
        }

        int s1 = (int) sum;
        for (int i = 0; i < nums.length; i++) {
            if ((s1 - nums[i]) % p == 0) {
                return 1;
            }
        }

        int minCnt = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int crrcnt = 0;
            int s = (int) sum;
            for (int j = i; j < nums.length; j++) {

                s -= nums[j];
                crrcnt++;
                if (s == 0) {
                    continue;
                }
                if (s % p == 0) {
                    minCnt = Math.min(minCnt, crrcnt);
                }
            }
        }

        if (minCnt != Integer.MAX_VALUE) {
            return minCnt;
        }
        return -1;
    }
}