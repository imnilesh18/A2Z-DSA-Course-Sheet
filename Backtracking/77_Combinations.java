/*
 * 77. Combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to
 * be the same combination.
 * 
 * Example 2:
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 * 
 * Constraints:
 * 1 <= n <= 20
 * 1 <= k <= n
 */

class Solution {
    void solve(int start, List<Integer> temp, List<List<Integer>> result, int n, int k) {
        if (temp.size() == k) {
            result.add(new ArrayList<>(temp));
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.add(i);
            solve(i + 1, temp, result, n, k);
            temp.remove(temp.size() - 1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        solve(1, temp, result, n, k);
        return result;
    }
}

// Code with comments for better understanding:
class Solution {
    // This method performs backtracking to find all combinations
    void solve(int start, List<Integer> temp, List<List<Integer>> result, int n, int k) {
        // If the temporary list size equals k, we have a valid combination
        if (temp.size() == k) {
            // Add a copy of the current combination to the result list
            result.add(new ArrayList<>(temp));
            return; // Backtrack
        }

        // Iterate through the numbers starting from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            // Add the current number to the temporary combination
            temp.add(i);
            // Recursively call solve to continue building combinations
            solve(i + 1, temp, result, n, k);
            // Remove the last added number to backtrack and try the next number
            temp.remove(temp.size() - 1);
        }
    }

    // Main method to initiate the combination finding process
    public List<List<Integer>> combine(int n, int k) {
        // Result list to hold all the combinations
        List<List<Integer>> result = new ArrayList<>();
        // Temporary list to build each combination
        List<Integer> temp = new ArrayList<>();

        // Start the backtracking process from the first number (1)
        solve(1, temp, result, n, k);
        return result; // Return the complete list of combinations
    }
}
