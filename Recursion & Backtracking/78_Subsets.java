/*
 * 78. Subsets
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * Constraints:
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 */

class Solution {
    void solve(int[] nums, int index, List<List<Integer>> result, List<Integer> temp) {
        if (index == nums.length) {
            result.add(new ArrayList<>(temp));
            return;
        }

        temp.add(nums[index]);
        solve(nums, index + 1, result, temp);

        temp.remove(temp.size() - 1);
        solve(nums, index + 1, result, temp);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        solve(nums, 0, result, temp);
        return result;
    }
}

// Code with comments for better undertstanding:
class Solution {

    // Recursive helper function to generate all subsets
    void solve(int[] nums, int index, List<List<Integer>> result, List<Integer> temp) {
        // Base case: when index reaches the end of the array, add the current subset (temp) to the result
        if (index == nums.length) {
            result.add(new ArrayList<>(temp));  // Create a new list and add it to result to avoid modifying temp later
            return;
        }

        // Include the current element in the subset and recursively move to the next element
        // Include
        temp.add(nums[index]);
        solve(nums, index + 1, result, temp);

        // Backtrack: remove the last added element and explore the subset without the current element
        // Not Include
        temp.remove(temp.size() - 1);
        solve(nums, index + 1, result, temp);
    }

    // Function to return all subsets of the given array
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();  // To store all subsets
        List<Integer> temp = new ArrayList<>();          // Temporary list to build individual subsets

        // Call the recursive function starting with index 0
        solve(nums, 0, result, temp);
        return result;  // Return the final list of all subsets
    }
}
