/*
 * 2257. Count Unguarded Cells in the Grid
 *
 * You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
 *
 * A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
 *
 * Return the number of unoccupied cells that are not guarded.
 *
 * Example 1:
 * Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
 * Output: 7
 * Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
 * There are a total of 7 unguarded cells, so we return 7.
 *
 * Example 2:
 * Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
 * Output: 4
 * Explanation: The unguarded cells are shown in green in the above diagram.
 * There are a total of 4 unguarded cells, so we return 4.
 *
 * Constraints:
 * 1 <= m, n <= 10^5
 * 2 <= m * n <= 10^5
 * 1 <= guards.length, walls.length <= 5 * 10^4
 * 2 <= guards.length + walls.length <= m * n
 * guards[i].length == walls[j].length == 2
 * 0 <= rowi, rowj < m
 * 0 <= coli, colj < n
 * All the positions in guards and walls are unique.
 */

//Approach-2 (DFS)
//T.C : O(m*n + G*(m+n)), where G =  size of guards
//S.C : O(m*n), considering the size of grid we took
class Solution {
public:
   void dfs(vector<vector<int> >& grid, int row, int col, int rows, int cols, int direction){
      // Boundary check and skipping guarded or walled cells
      if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
         return;
      }

      // Mark the current cell as visited by a guard's line of sight
      grid[row][col] = 3;

      // Continue the DFS in the specified direction
      if (direction == 1) {        // UP
         dfs(grid, row - 1, col, rows, cols, direction);
      } else if (direction == 2) { // DOWN
         dfs(grid, row + 1, col, rows, cols, direction);
      } else if (direction == 3) { // LEFT
         dfs(grid, row, col - 1, rows, cols, direction);
      } else {                     // RIGHT
         dfs(grid, row, col + 1, rows, cols, direction);
      }
   }

   int countUnguarded(int rows, int cols, vector<vector<int> >& guards, vector<vector<int> >& walls){
      // Initialize the grid
      vector<vector<int> > grid(rows, vector<int>(cols, 0));

      // Mark guard positions
      for (const auto& guard : guards) {
         int i = guard[0];
         int j = guard[1];
         grid[i][j] = 1;    // Guard cell
      }

      // Mark wall positions
      for (const auto& wall : walls) {
         int i = wall[0];
         int j = wall[1];
         grid[i][j] = 2;    // Wall cell
      }

      // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
      for (const auto& guard : guards) {
         int guardRow = guard[0];
         int guardCol = guard[1];

         dfs(grid, guardRow - 1, guardCol, rows, cols, 1);    // UP
         dfs(grid, guardRow + 1, guardCol, rows, cols, 2);    // DOWN
         dfs(grid, guardRow, guardCol - 1, rows, cols, 3);    // LEFT
         dfs(grid, guardRow, guardCol + 1, rows, cols, 4);    // RIGHT
      }

      // Count unguarded cells
      int unguardedCount = 0;
      for (int row = 0; row < rows; ++row) {
         for (int col = 0; col < cols; ++col) {
            if (grid[row][col] == 0) {
               ++unguardedCount;
            }
         }
      }

      return unguardedCount;
   }
};
