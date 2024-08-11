/*
 * 463. Island Perimeter
 * 
 * You are given row x col grid representing a map where grid[i][j] = 1
 * represents land and grid[i][j] = 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e., one
 * or more connected land cells).
 * The island doesn't have "lakes", meaning the water inside isn't connected to
 * the water around the island. One cell is a square with side length 1. The
 * grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * Example 1:
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 * Example 2:
 * Input: grid = [[1]]
 * Output: 4
 * 
 * Example 3:
 * Input: grid = [[1,0]]
 * Output: 4
 */

//Approach-3 (Iterative)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                if (i - 1 < 0 || grid[i - 1][j] == 0) // up
                    perimeter++;

                if (i + 1 >= m || grid[i + 1][j] == 0) // down
                    perimeter++;

                if (j - 1 < 0 || grid[i][j - 1] == 0) // left
                    perimeter++;

                if (j + 1 >= n || grid[i][j + 1] == 0) // right
                    perimeter++;
            }
        }

        return perimeter;
    }
}

// Approach-1 (DFS)
// T.C : O(m*n)
// S.C : O(1) Auxiliary Space
class Solution {
    int n;
    int m;
    int peri;

    void dfs(int[][] grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            peri++;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }

        grid[i][j] = -1; // mark visited

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    public int islandPerimeter(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        peri = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return peri;
                }
            }
        }
        return peri;
    }
}

// Approach-2 (BFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
    int m;
    int n;
    int[][] directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    int bfs(int[][] grid, int i, int j) {
        int perim = 0;

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { i, j });
        grid[i][j] = -1;

        while (!queue.isEmpty()) {
            int[] it = queue.poll();

            for (int[] dir : directions) {
                int i_ = it[0] + dir[0];
                int j_ = it[1] + dir[1];

                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                    perim++;
                else if (grid[i_][j_] == -1)
                    continue;
                else {
                    queue.offer(new int[] { i_, j_ });
                    grid[i_][j_] = -1;
                }
            }
        }

        return perim;
    }

    int islandPerimeter(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
            }
        }

        return -1;
    }
}