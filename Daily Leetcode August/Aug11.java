/*
 * 1568. Minimum Number of Days to Disconnect Island
 * 
 * You are given an m x n binary grid grid where 1 represents land and 0
 * represents water. An island is a maximal 4-directionally (horizontal or
 * vertical) connected group of 1's.
 * The grid is said to be connected if we have exactly one island, otherwise is
 * said disconnected.
 * In one day, we are allowed to change any single land cell (1) into a water
 * cell (0).
 * Return the minimum number of days to disconnect the grid.
 * 
 * Example 1:
 * Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 2
 * Explanation: We need at least 2 days to get a disconnected grid.
 * Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
 * 
 * Example 2:
 * Input: grid = [[1,1]]
 * Output: 2
 * Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0
 * islands.
 */
class Solution {
    private final int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    private int m;
    private int n;

    private void DFS(int[][] matrix, int i, int j, boolean[][] visited) {
        if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || visited[i][j] || matrix[i][j] == 0)
            return;

        visited[i][j] = true; // mark visited

        for (int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            DFS(matrix, new_i, new_j, visited);
        }
    }

    private int numberOfIslandsDFS(int[][] grid) {
        boolean[][] visited = new boolean[m][n];
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) { // DFS
                    DFS(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }

    public int minDays(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int islands = numberOfIslandsDFS(grid);

        // Grid already disconnected
        if (islands > 1 || islands == 0) {
            return 0;
        } else {
            // Check for 1 move
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0; // mark visited

                        islands = numberOfIslandsDFS(grid);

                        grid[i][j] = 1; // unmark visited
                        if (islands > 1 || islands == 0) {
                            return 1;
                        }
                    }
                }
            }
        }

        return 2; // It's always possible to break an island with 2 moves
    }
}
