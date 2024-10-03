/*
 * 90. Subsets II
 * 
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * Constraints:
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 */

class Solution {

    public void findSubsets(int ind, int[] nums, List<Integer> ds, List<List<Integer>> result) {
        result.add(new ArrayList<>(ds));
        for (int i = ind; i < nums.length; i++) {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.add(nums[i]);
            findSubsets(i + 1, nums, ds, result);
            ds.remove(ds.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        findSubsets(0, nums, new ArrayList<>(), result);
        return result;
    }
}

// Code with comments for bettert understanding:
class Solution {

    // Helper method to find all unique subsets
    public void findSubsets(int ind, int[] nums, List<Integer> ds, List<List<Integer>> result) {
        // Add the current subset (deep copy of the 'ds' list) to the result
        result.add(new ArrayList<>(ds));

        // Loop through the elements starting from index 'ind'
        for (int i = ind; i < nums.length; i++) {
            // Skip duplicates: if the current element is the same as the previous one,
            // continue
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            // Add the current element to the subset
            ds.add(nums[i]);

            // Recursively call the function with the next index
            findSubsets(i + 1, nums, ds, result);

            // Backtrack: remove the last element to explore other subsets
            ds.remove(ds.size() - 1);
        }
    }

    // Main method to return all unique subsets, including duplicates
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        // Sort the array to handle duplicates easily
        Arrays.sort(nums);

        // List to store all subsets
        List<List<Integer>> result = new ArrayList<>();

        // Start the recursion with an empty subset and index 0
        findSubsets(0, nums, new ArrayList<>(), result);

        // Return the final result containing all subsets
        return result;
    }
}
