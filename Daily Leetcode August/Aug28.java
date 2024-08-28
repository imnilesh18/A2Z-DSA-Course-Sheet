/*
 * 1905. Count Sub Islands
 * 
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's
 * (representing water) and 1's (representing land). An island is a group of 1's
 * connected 4-directionally (horizontal or vertical). Any cells outside of the
 * grid are considered water cells.
 * An island in grid2 is considered a sub-island if there is an island in grid1
 * that contains all the cells that make up this island in grid2.
 * Return the number of islands in grid2 that are considered sub-islands.
 * 
 * Example 1:
 * Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
 * grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * Output: 3
 * Explanation: In the picture above, the grid on the left is grid1 and the grid
 * on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are three sub-islands.
 * 
 * Example 2:
 * Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
 * grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * Output: 2
 * Explanation: In the picture above, the grid on the left is grid1 and the grid
 * on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are two sub-islands.
 * 
 * Constraints:
 * m == grid1.length == grid2.length
 * n == grid1[i].length == grid2[i].length
 * 1 <= m, n <= 500
 * grid1[i][j] and grid2[i][j] are either 0 or 1.
 */
class Solution {

    // Helper method to check if the current land in grid2 is a sub-island of grid1
    boolean checkSubIsland(int[][] grid1, int[][] grid2, int i, int j) {
        // Check if indices are out of bounds
        if (i < 0 || i >= grid1.length || j < 0 || j >= grid1[0].length) {
            return true; // Out of bounds, considered as true for the island check
        }

        // If the current cell in grid2 is not land (i.e., it's water or already
        // visited), return true
        if (grid2[i][j] != 1) {
            return true; // Non-land or already visited cell
        }

        // Mark the current cell in grid2 as visited
        grid2[i][j] = -1;

        // Check if the current cell in grid1 is land
        boolean result = (grid1[i][j] == 1);

        // Recursively check all four directions (down, up, right, left)
        result = result & checkSubIsland(grid1, grid2, i + 1, j); // Down
        result = result & checkSubIsland(grid1, grid2, i - 1, j); // Up
        result = result & checkSubIsland(grid1, grid2, i, j + 1); // Right
        result = result & checkSubIsland(grid1, grid2, i, j - 1); // Left

        return result; // Return the result of the sub-island check
    }

    // Main method to count the number of sub-islands
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int subIslands = 0; // Counter for sub-islands
        int m = grid2.length; // Number of rows in grid2
        int n = grid2[0].length; // Number of columns in grid2

        // Iterate through each cell in grid2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell in grid2 is land and is a sub-island of grid1
                if (grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)) {
                    subIslands++; // Increment the sub-island counter
                }
            }
        }
        return subIslands; // Return the total count of sub-islands
    }
}
