/*
 * 79. Word Search
 *
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example 1:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 *
 * Example 2:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 *
 * Example 3:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 *
 * Constraints:
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * Follow up: Could you use search pruning to make your solution faster with a larger board?
 */

// Approach: Use DFS/backtracking from each cell that matches the first letter to search adjacent cells sequentially for the word.
// Time Complexity: O(m*n * 4^L) in the worst-case, where L is the length of the word.
// Space Complexity: O(L) due to recursion stack.
class Solution {
public:
   // Dimensions of the board
   int m, n;
   // Directions to move: down, up, right, left
   vector<vector<int> > directions{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

   // Helper function to perform DFS and search for the word starting at board[i][j]
   bool find(vector<vector<char> >& board, int i, int j, int idx, string& word) {
      // If we have matched the whole word, return true
      if (idx == word.length()) {
         return true;
      }

      // Check for out-of-bound indices or if the cell is already visited (marked with '$')
      if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
         return false;
      }

      // If the current cell does not match the current character in word, return false
      if (board[i][j] != word[idx]) {
         return false;
      }

      // Temporarily mark the current cell as visited
      char temp = board[i][j];
      board[i][j] = '$';

      // Explore all four possible directions
      for (auto&dir: directions) {
         int new_i = i + dir[0];
         int new_j = j + dir[1];

         // Recursively search for the next character
         if (find(board, new_i, new_j, idx + 1, word)) {
            return true;     // If found in any direction, return true
         }
      }

      // Backtrack: restore the original value of the cell
      board[i][j] = temp;
      return false;
   }

   // Main function to check if the word exists in the board
   bool exist(vector<vector<char> >& board, string word) {
      // Set board dimensions
      m = board.size();
      n = board[0].size();

      // Iterate over each cell in the board
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            // If the first character matches, start DFS from that cell
            if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
               return true;      // Return true if the word is found
            }
         }
      }
      // Return false if the word is not found in the board
      return false;
   }
};
