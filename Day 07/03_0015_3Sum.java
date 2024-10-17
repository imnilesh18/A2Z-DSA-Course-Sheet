/*
 * 15. 3Sum
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * Constraints:
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 */

// T.C : O(n²)
// S.C : O(1)

class Solution {
    void twoSum(int[] nums, int k, int target, List<List<Integer>> result) {
        int i = k;
        int j = nums.length - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                result.add(Arrays.asList(-target, nums[i], nums[j]));
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                i++;
                j--;
            }
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        // -4 -1 -1 0 1 2
        // n1 + n2 + n3 = 0
        // n2 + n3 = -n1;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int n1 = nums[i];
            twoSum(nums, i + 1, -n1, result);
        }
        return result;
    }
}

// Comments for better understanding:
// T.C : O(n²)
// S.C : O(1)

class Solution {
    // Helper function to find pairs of numbers in nums such that they add up to the
    // target
    void twoSum(int[] nums, int k, int target, List<List<Integer>> result) {
        int i = k; // Initialize i to the current index (start of two-sum search)
        int j = nums.length - 1; // Initialize j to the end of the array

        // While i is less than j, search for pairs
        while (i < j) {
            int sum = nums[i] + nums[j]; // Calculate the sum of nums[i] and nums[j]

            if (sum > target) {
                // If the sum is greater than the target, move the j pointer left
                j--;
            } else if (sum < target) {
                // If the sum is less than the target, move the i pointer right
                i++;
            } else {
                // If the sum equals the target, add the triplet to the result list
                result.add(Arrays.asList(-target, nums[i], nums[j]));

                // Skip duplicates for the i pointer
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }

                // Skip duplicates for the j pointer
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }

                // Move both pointers after finding a valid pair
                i++;
                j--;
            }
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>(); // To store the result triplets
        int n = nums.length; // Get the size of the input array
        Arrays.sort(nums); // Sort the array to simplify the search and avoid duplicates

        // Loop through the array to find the first element (n1) of the triplet
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element (n1)
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Move to the next element if it's a duplicate
            }

            int n1 = nums[i]; // Set n1 as the current element
            // Call twoSum to find pairs (n2, n3) such that n1 + n2 + n3 = 0
            twoSum(nums, i + 1, -n1, result); // n2 + n3 must equal -n1
        }
        return result; // Return the result list containing all unique triplets
    }
}
