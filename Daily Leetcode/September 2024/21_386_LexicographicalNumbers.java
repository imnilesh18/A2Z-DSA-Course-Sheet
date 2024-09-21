/*
 * 386. Lexicographical Numbers
 * 
 * Given an integer n, return all the numbers in the range [1, n] sorted in
 * lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.
 * 
 * Example 1:
 * Input: n = 13
 * Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
 * 
 * Example 2:
 * Input: n = 2
 * Output: [1,2]
 * 
 * Constraints:
 * 1 <= n <= 5 * 104
 */

// In mathematics, the lexicographic or lexicographical order (also known as
// lexical order, or dictionary order) is a generalization of the alphabetical
// order of the dictionaries to sequences of ordered symbols or, more generally,
// of elements of a totally ordered set. [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Approach (Simple Recursion - DFS)
// T.C : O(n) - We visit each number (1 to n) only once.
// S.C : O(d) - where d is the number of digits in n, i.e., log10(n)
class Solution {

    // This helper function recursively explores numbers in lexical order.
    // It starts with the current number 'curr' and adds it to the result list.
    // Then, it attempts to append digits (0 to 9) to 'curr', forming new numbers.
    // The recursion stops when the new number exceeds 'n'.
    void solve(int curr, int n, List<Integer> result) {
        // Base condition: If the current number exceeds n, stop recursion
        if (curr > n) {
            return;
        }

        // Add the current number to the result list
        result.add(curr);

        // Try appending digits 0 to 9 to the current number to generate new numbers
        for (int append = 0; append <= 9; append++) {
            // Generate the new number by appending the current digit to the current number
            int newNum = (curr * 10) + append;

            // If the newly formed number exceeds 'n', stop further exploration
            if (newNum > n) {
                return;
            }

            // Recursively call 'solve' with the new number
            solve(newNum, n, result);
        }
    }

    // Main function to return numbers in lexical order from 1 to n
    public List<Integer> lexicalOrder(int n) {
        // Initialize a result list to store numbers in lexical order
        List<Integer> result = new ArrayList<>();

        // Start with the numbers from 1 to 9 (as the lexical order starts from 1)
        for (int startNum = 1; startNum <= 9; startNum++) {
            // Call the recursive function to explore numbers starting with 'startNum'
            solve(startNum, n, result);
        }

        // Return the final list of numbers in lexical order
        return result;
    }
}
