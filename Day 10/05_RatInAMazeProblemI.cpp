// Problem Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
 * Rat in a Maze Problem - I
 *
 * Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 * Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.
 * Examples:
 * Input: mat[][] = [[1, 0, 0, 0],
 *              [1, 1, 0, 1],
 *              [1, 1, 0, 0],
 *              [0, 1, 1, 1]]
 * Output: DDRDRR DRDDRR
 * Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
 *
 * Input: mat[][] = [[1, 0],
 *              [1, 0]]
 * Output: -1
 * Explanation: No path exists and destination cell is blocked.
 * Expected Time Complexity: O(3n^2)
 * Expected Auxiliary Space: O(l * x)
 * Here l = length of the path, x = number of paths.
 *
 * Constraints:
 * 2 ≤ n ≤ 5
 * 0 ≤ mat[i][j] ≤ 1
 */

//T.C : O(3^(n^2))
//S.C : O(L * X) - L = Length of path, X = number of paths
class Solution {
public:
   vector<string> result;

   void solve(int i, int j, vector<vector<int> >&mat, int n, string&temp){
      if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) {
         return;
      }

      if (i == n - 1 && j == n - 1) {
         result.push_back(temp);
         return;
      }

      mat[i][j] = 0;

      // L, R, D, U
      temp.push_back('D');
      solve(i + 1, j, mat, n, temp);
      temp.pop_back();

      temp.push_back('R');
      solve(i, j + 1, mat, n, temp);
      temp.pop_back();

      temp.push_back('U');
      solve(i - 1, j, mat, n, temp);
      temp.pop_back();

      temp.push_back('L');
      solve(i, j - 1, mat, n, temp);
      temp.pop_back();

      mat[i][j] = 1;
   }

   vector<string> findPath(vector<vector<int> >&mat){
      int n = mat.size();

      string temp = "";

      solve(0, 0, mat, n, temp);

      return result;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   // Vector to store all valid paths from source (0,0) to destination (n-1,n-1)
   vector<string> result;

   /* Recursive function to find all possible paths
    * Parameters:
    * i, j: Current position of rat in the maze
    * mat: The maze matrix (1: valid cell, 0: blocked cell)
    * n: Size of maze (n x n)
    * temp: Current path being explored (stored as string of moves)
    */
   void solve(int i, int j, vector<vector<int> >&mat, int n, string&temp){
      // Base cases:
      // 1. If current position is out of bounds
      // 2. If current cell is blocked (0)
      // 3. If current cell is already visited (marked as 0)
      if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) {
         return;
      }

      // If reached destination, add current path to result
      if (i == n - 1 && j == n - 1) {
         result.push_back(temp);
         return;
      }

      // Mark current cell as visited by setting it to 0
      // This prevents the path from visiting the same cell multiple times
      mat[i][j] = 0;

      // Try all possible movements from current cell
      // For each direction:
      // 1. Add the direction to current path
      // 2. Recursively explore that direction
      // 3. Backtrack by removing the direction from path

      // Try moving DOWN
      temp.push_back('D');
      solve(i + 1, j, mat, n, temp);
      temp.pop_back();

      // Try moving RIGHT
      temp.push_back('R');
      solve(i, j + 1, mat, n, temp);
      temp.pop_back();

      // Try moving UP
      temp.push_back('U');
      solve(i - 1, j, mat, n, temp);
      temp.pop_back();

      // Try moving LEFT
      temp.push_back('L');
      solve(i, j - 1, mat, n, temp);
      temp.pop_back();

      // Backtrack: restore the current cell to 1 for other possible paths
      mat[i][j] = 1;
   }

   /* Main function to find all possible paths in the maze
    * Returns vector of strings where each string represents a valid path
    */
   vector<string> findPath(vector<vector<int> >&mat){
      int    n    = mat.size();
      string temp = "";    // Temporary string to store current path

      solve(0, 0, mat, n, temp);
      return result;
   }
};

/*
 * Time Complexity: O(3^(n^2))
 * - At each cell, we can move in 3 directions (not counting the direction we came from)
 * - The maximum possible path length is n^2 (visiting all cells)
 * - Therefore, at each step we have 3 choices, and this can happen n^2 times
 *
 * Space Complexity: O(L * X)
 * Where:
 * - L = Length of each path (maximum can be n^2)
 * - X = Number of possible paths
 * - This space is used to store all valid paths in the result vector
 *
 * Additional Space:
 * - Recursion stack space: O(n^2) in worst case
 * - Input matrix modification: O(1) as we modify in place
 */
