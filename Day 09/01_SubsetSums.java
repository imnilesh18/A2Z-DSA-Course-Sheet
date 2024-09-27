/*
 * Subset Sums
 * 
 * Given a list arr of n integers, return sums of all subsets in it. Output sums
 * can be printed in any order.
 * 
 * Examples:
 * Input: n = 2, arr[] = {2, 3}
 * Output: 0 2 3 5
 * Explanation: When no elements is taken then Sum = 0. When only 2 is taken
 * then Sum = 2. When only 3 is taken then Sum = 3. When element 2 and 3 are
 * taken then Sum = 2+3 = 5.
 * 
 * Example 2:
 * Input: n = 3, arr = {1, 2, 1}
 * Output: 0 1 1 2 2 3 3 4
 * 
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the
 * function subsetSums() which takes a list/vector and an integer n as an input
 * parameter and returns the list/vector of all the subset sums.
 * 
 * Expected Time Complexity: O(2n)
 * Expected Auxiliary Space: O(2n)
 * 
 * Constraints:
 * 1 <= n <= 15
 * 0 <= arr[i] <= 104
 */

//Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
//Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

class Solution {

    // Helper function to generate all possible subsets and their sums
    void subSet(int ind, int sum, ArrayList<Integer> arr, int n, ArrayList<Integer> result) {
        // Base case: if all elements are considered, add the current sum to the result
        // list
        if (ind == n) {
            result.add(sum);
            return;
        }
        // Recursive case: include the current element in the subset sum
        subSet(ind + 1, sum + arr.get(ind), arr, n, result);

        // Recursive case: exclude the current element from the subset sum
        subSet(ind + 1, sum, arr, n, result);
    }

    // Function to return all subset sums of the array
    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int n) {
        ArrayList<Integer> result = new ArrayList<>();
        // Start the recursive subset generation from index 0 with initial sum of 0
        subSet(0, 0, arr, n, result);
        // Sort the results (optional, depending on whether sorted order is required)
        Collections.sort(result);
        return result;
    }
}
