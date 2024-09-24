/*
 * 79. Word Search
 * 
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * Example 1:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * Example 2:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * Example 3:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * Constraints:
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 */

/*
Example:
Step 1: Start at 'A[0][0]' (First character matches 'A')
$ B C E
S F C S
A D E E

Step 2: Move right to 'B[0][1]' (Matches 'B')
$ $ C E
S F C S
A D E E

Step 3: Move right to 'C[0][2]' (Matches 'C')
$ $ $ E
S F C S
A D E E

Step 4: Move down to 'C[1][2]' (Matches 'C')
$ $ $ E
S F $ S
A D E E

Step 5: Move down to 'E[2][2]' (Matches 'E')
$ $ $ E
S F $ S
A D $ E

Step 6: Move left to 'D[2][1]' (Matches 'D')
$ $ $ E
S F $ S
A $ $ E

--- Backtracking starts ---

Restore 'D[2][1]'
$ $ $ E
S F $ S
A D $ E

Restore 'E[2][2]'
$ $ $ E
S F $ S
A D E E

Restore 'C[1][2]'
$ $ $ E
S F C S
A D E E

Restore 'C[0][2]'
$ $ C E
S F C S
A D E E

Restore 'B[0][1]'
$ B C E
S F C S
A D E E

Restore 'A[0][0]'
A B C E
S F C S
A D E E

*/

class Solution {
    int m, n; // Dimensions of the board
    int[][] directions = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } }; // Directions for moving: left, right, up, down

    // Recursive function to check if the word exists starting from position (i, j)
    boolean find(char[][] board, int i, int j, int idx, String word) {
        // Base case: if the index equals the length of the word, we have found the word
        if (idx == word.length()) {
            return true;
        }

        // Check if out of bounds or if the current cell is already visited ('$')
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$') {
            return false;
        }

        // If the current character does not match the word's character at index idx
        if (board[i][j] != word.charAt(idx)) {
            return false;
        }

        // Temporarily mark the cell as visited by setting it to '$'
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 possible directions (left, right, up, down)
        for (int[] dir : directions) {
            int new_i = i + dir[0]; // Calculate new row index
            int new_j = j + dir[1]; // Calculate new column index

            // Recursively check if the next character matches in the new direction
            if (find(board, new_i, new_j, idx + 1, word)) {
                return true;
            }
        }

        // Backtrack: restore the original character at board[i][j]
        board[i][j] = temp;
        return false;
    }

    // Main function to check if the word exists in the board
    public boolean exist(char[][] board, String word) {
        m = board.length; // Get number of rows
        n = board[0].length; // Get number of columns

        // Loop through each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the first character matches and find() returns true, word is found
                if (board[i][j] == word.charAt(0) && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        // If no match found after checking all cells, return false
        return false;
    }
}
