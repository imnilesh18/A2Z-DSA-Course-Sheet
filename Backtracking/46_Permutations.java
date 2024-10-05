/*
 * 46. Permutations
 * 
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * 
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * Constraints:
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 */

class Solution {
    void solve(List<Integer> temp, int[] nums, int n, List<List<Integer>> result, HashSet<Integer> st) {
        if (temp.size() == n) {
            result.add(new ArrayList<>(temp));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!st.contains(nums[i])) {
                temp.add(nums[i]);
                st.add(nums[i]);

                solve(temp, nums, n, result, st);

                st.remove(nums[i]);
                temp.remove(temp.size() - 1);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length;
        List<List<Integer>> result = new ArrayList<>();
        HashSet<Integer> st = new HashSet<>();
        List<Integer> temp = new ArrayList<>();

        solve(temp, nums, n, result, st);

        return result;
    }
}

// Code with comments for better understanding:
class Solution {

    // Helper function to recursively generate permutations
    void solve(List<Integer> temp, int[] nums, int n, List<List<Integer>> result, HashSet<Integer> st) {

        // Base case: if the current permutation (temp) has reached the required length
        // (n), add it to the result
        if (temp.size() == n) {
            result.add(new ArrayList<>(temp)); // Add a copy of the current permutation to the result
            return;
        }

        // Loop through each element in nums to generate all possible permutations
        for (int i = 0; i < n; i++) {

            // Check if the current number (nums[i]) is already in the HashSet (i.e., has
            // been used in the current permutation)
            if (!st.contains(nums[i])) {

                // If nums[i] hasn't been used, add it to the current permutation (temp) and
                // mark it as used (add to HashSet)
                temp.add(nums[i]);
                st.add(nums[i]);

                // Recursively call the solve function to generate the next element of the
                // permutation
                solve(temp, nums, n, result, st);

                // Backtrack: remove the last added element from temp and mark it as unused
                // (remove from HashSet)
                st.remove(nums[i]); // Undo the mark to allow other permutations to use nums[i] later
                temp.remove(temp.size() - 1); // Remove the last element added to temp
            }
        }
    }

    // Main function to generate all permutations of the given array nums
    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length; // Get the length of the input array
        List<List<Integer>> result = new ArrayList<>(); // List to store all the permutations
        HashSet<Integer> st = new HashSet<>(); // HashSet to keep track of elements already used in the current
                                               // permutation
        List<Integer> temp = new ArrayList<>(); // Temporary list to build each permutation

        // Start the recursive process to generate permutations
        solve(temp, nums, n, result, st);

        // Return the final list of permutations
        return result;
    }
}
