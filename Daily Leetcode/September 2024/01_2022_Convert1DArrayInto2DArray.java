/*
 * 2022. Convert 1D Array Into 2D Array
 * 
 * You are given a 0-indexed 1-dimensional (1D) integer array original, and two
 * integers, m and n. You are tasked with creating a 2-dimensional (2D) array
 * with m rows and n columns using all the elements from original.
 * The elements from indices 0 to n - 1 (inclusive) of original should form the
 * first row of the constructed 2D array, the elements from indices n to 2 * n -
 * 1 (inclusive) should form the second row of the constructed 2D array, and so
 * on.
 * Return an m x n 2D array constructed according to the above procedure, or an
 * empty 2D array if it is impossible.
 * 
 * Example 1:
 * Input: original = [1,2,3,4], m = 2, n = 2
 * Output: [[1,2],[3,4]]
 * Explanation: The constructed 2D array should contain 2 rows and 2 columns.
 * The first group of n=2 elements in original, [1,2], becomes the first row in
 * the constructed 2D array.
 * The second group of n=2 elements in original, [3,4], becomes the second row
 * in the constructed 2D array.
 * 
 * Example 2:
 * Input: original = [1,2,3], m = 1, n = 3
 * Output: [[1,2,3]]
 * Explanation: The constructed 2D array should contain 1 row and 3 columns.
 * Put all three elements in original into the first row of the constructed 2D
 * array.
 * 
 * Example 3:
 * Input: original = [1,2], m = 1, n = 1
 * Output: []
 * Explanation: There are 2 elements in original.
 * It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D
 * array.
 * 
 * Constraints:
 * 1 <= original.length <= 5 * 104
 * 1 <= original[i] <= 105
 * 1 <= m, n <= 4 * 104
 * 
 */

// Second Approach:
/*
 * Time Complexity: O(m * n) - We iterate over all m * n elements of the original array once.
 * Space Complexity: O(m * n) - We create a 2D array of size m * n.
*/

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if the size of the original array matches the total elements required
        // for m x n
        if (original.length != m * n) {
            // If not, return an empty 2D array
            return new int[0][0];
        }

        // Initialize the 2D array with the specified dimensions m x n
        int[][] result = new int[m][n];

        // Loop through each element of the original array
        for (int i = 0; i < original.length; i++) {
            // Calculate the row index in the 2D array
            int row = i / n;
            // Calculate the column index in the 2D array
            int col = i % n;

            // Assign the current element from the original array to the 2D array
            result[row][col] = original[i];
        }

        // Return the filled 2D array
        return result;
    }
}

// First Approach:
/*
 * Time Complexity: O(m * n) - We iterate over all m * n elements once to fill
 * the 2D array.
 * Space Complexity: O(m * n) - We create a 2D array of size m * n.
 */

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Initialize the 2D array with the specified dimensions m x n
        int result[][] = new int[m][n];

        // Check if the size of the original array matches the total elements required
        // for m x n
        if (original.length != m * n) {
            // If not, return an empty 2D array
            return new int[0][0];
        }

        // Index to keep track of elements in the original array
        int idx = 0;

        // Loop through each row of the 2D array
        for (int i = 0; i < m; i++) {
            // Loop through each column of the 2D array
            for (int j = 0; j < n; j++) {
                // Assign the current element from the original array to the 2D array
                result[i][j] = original[idx];
                // Move to the next element in the original array
                idx++;
            }
        }

        // Return the filled 2D array
        return result;
    }
}
