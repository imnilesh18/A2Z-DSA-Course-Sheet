/*
 * 947. Most Stones Removed with Same Row or Column
 * 
 * On a 2D plane, we place n stones at some integer coordinate points. Each
 * coordinate point may have at most one stone.
 * A stone can be removed if it shares either the same row or the same column as
 * another stone that has not been removed.
 * Given an array stones of length n where stones[i] = [xi, yi] represents the
 * location of the ith stone, return the largest possible number of stones that
 * can be removed.
 * 
 * Example 1:
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * Explanation: One way to remove 5 stones is as follows:
 * 1. Remove stone [2,2] because it shares the same row as [2,1].
 * 2. Remove stone [2,1] because it shares the same column as [0,1].
 * 3. Remove stone [1,2] because it shares the same row as [1,0].
 * 4. Remove stone [1,0] because it shares the same column as [0,0].
 * 5. Remove stone [0,1] because it shares the same row as [0,0].
 * Stone [0,0] cannot be removed since it does not share a row/column with
 * another stone still on the plane.
 * 
 * Example 2:
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * Explanation: One way to make 3 moves is as follows:
 * 1. Remove stone [2,2] because it shares the same row as [2,0].
 * 2. Remove stone [2,0] because it shares the same column as [0,0].
 * 3. Remove stone [0,2] because it shares the same row as [0,0].
 * Stones [0,0] and [1,1] cannot be removed since they do not share a row/column
 * with another stone still on the plane.
 * 
 * Example 3:
 * Input: stones = [[0,0]]
 * Output: 0
 * Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 * 
 * 
 * Constraints:
 * 1 <= stones.length <= 1000
 * 0 <= xi, yi <= 104
 * No two stones are at the same coordinate point.
 */

class Solution {

    // Helper method to perform Depth-First Search (DFS) from a given index
    void dfs(int[][] stones, int index, boolean[] visited) {
        // Mark the current stone as visited
        visited[index] = true;

        // Iterate through all stones to find connected stones
        for (int i = 0; i < stones.length; i++) {
            int row = stones[index][0]; // Get the row of the current stone
            int col = stones[index][1]; // Get the column of the current stone

            // If the stone at index i has not been visited and shares the same row or
            // column,
            // then it is connected, so we perform DFS on that stone
            if ((visited[i] == false) && (stones[i][0] == row || stones[i][1] == col)) {
                dfs(stones, i, visited); // Recursive DFS call for the connected stone
            }
        }
    }

    // Main method to determine the maximum number of stones that can be removed
    public int removeStones(int[][] stones) {
        int n = stones.length; // Number of stones

        boolean[] visited = new boolean[n]; // Array to keep track of visited stones
        int groups = 0; // Counter for the number of connected groups of stones

        // Iterate through each stone
        for (int i = 0; i < n; i++) {
            // If the current stone is already visited, skip it
            if (visited[i] == true) {
                continue;
            }
            // Perform DFS to find all stones in the same connected group
            dfs(stones, i, visited);
            groups++; // Increment the group count
        }

        // The result is the total stones minus the number of groups
        // because each group can leave one stone unremoved
        return (n - groups);
    }
}
