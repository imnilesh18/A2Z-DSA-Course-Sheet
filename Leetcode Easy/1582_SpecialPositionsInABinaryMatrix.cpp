/*
 * 1582. Special Positions in a Binary Matrix
 *
 * Given an m x n binary matrix mat, return the number of special positions in mat.
 * A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
 *
 * Example 1:
 * Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
 * Output: 1
 * Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
 *
 * Example 2:
 * Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 *
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * mat[i][j] is either 0 or 1.
 */

// Approach-1 (Brute Force)
// T.C : O((m*n) (m+n))
// S.C : O(1)
class Solution {
public:
   int numSpecial(vector<vector<int> >& mat){
      int m      = mat.size();
      int n      = mat[0].size();
      int result = 0;

      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            if (mat[row][col] == 0) {
               continue;
            }

            bool special = true;
            // check column
            for (int r = 0; r < m; r++) {
               if (r != row && mat[r][col] == 1) {
                  special = false;
                  break;
               }
            }

            // check row
            for (int c = 0; c < n; c++) {
               if (c != col && mat[row][c] == 1) {
                  special = false;
                  break;
               }
            }

            if (special == true) {
               result++;
            }
         }
      }
      return result;
   }
};

// Approach-2 (Storing count of 1s in rows and cols)
// T.C : O(m*n)
// S.C : O(m+n)
class Solution {
public:
   int numSpecial(vector<vector<int> >& mat){
      int m = mat.size();
      int n = mat[0].size();

      vector<int> rowCount(m, 0);
      vector<int> colCount(n, 0);

      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            if (mat[row][col] == 1) {
               rowCount[row]++;
               colCount[col]++;
            }
         }
      }

      int result = 0;
      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            if (mat[row][col] == 0) {
               continue;
            }

            if (rowCount[row] == 1 && colCount[col] == 1) {
               result++;
            }
         }
      }
      return result;
   }
};

// Code with comments for better understanding:

// Approach-1 (Brute Force)
// T.C : O((m*n) (m+n))
// S.C : O(1)

/*
 * Problem: Special Positions in a Binary Matrix
 *
 * Goal: Find positions where:
 * 1. The element is 1
 * 2. All other elements in same row are 0
 * 3. All other elements in same column are 0
 *
 * Example matrix:
 * [1 0 0]
 * [0 0 1]  -> Here (1,2) is special because mat[1][2] = 1 and all other elements in row 1 and column 2 are 0
 * [1 0 0]
 */

class Solution {
public:
   int numSpecial(vector<vector<int> >& mat){
      // Get matrix dimensions
      int m      = mat.size();     // Number of rows
      int n      = mat[0].size();  // Number of columns
      int result = 0;              // Counter for special positions

      // Iterate through each position in matrix
      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            // Skip if current element is 0 (not a candidate for special position)
            if (mat[row][col] == 0) {
               continue;
            }

            // Assume current position is special until proven otherwise
            bool special = true;

            // Check current column for any other 1s
            // If found, position is not special
            for (int r = 0; r < m; r++) {
               if (r != row && mat[r][col] == 1) {
                  special = false;
                  break;        // Early termination if another 1 is found
               }
            }

            // If column check passed, check current row for any other 1s
            // If found, position is not special
            for (int c = 0; c < n; c++) {
               if (c != col && mat[row][c] == 1) {
                  special = false;
                  break;        // Early termination if another 1 is found
               }
            }

            // If position passed both row and column checks, it's special
            if (special == true) {
               result++;
            }
         }
      }

      return result;
   }
};

/*
 * Time Complexity Analysis:
 * - Outer nested loops: O(m * n) to visit each matrix position
 * - For each position with 1, we check its row O(n) and column O(m)
 * - Total: O(m * n * (m + n))
 *
 * Space Complexity: O(1)
 * - Only using constant extra space (few variables)
 *
 * Optimization notes:
 * 1. Early continue for 0 elements
 * 2. Early break when another 1 is found in row/column
 * 3. Only check row if column check passes
 *
 * Further optimization possible:
 * - Could precompute row and column sums
 * - Could use bit manipulation for faster checks
 */


// Approach-2 (Storing count of 1s in rows and cols)
// T.C : O(m*n)
// S.C : O(m+n)

/*
 * Intuition:
 * 1. For a position to be special (mat[i][j] = 1):
 *    - It should be the only 1 in its row
 *    - It should be the only 1 in its column
 *
 * 2. Instead of checking entire row/column each time:
 *    - We can precompute count of 1s in each row and column
 *    - Then for each 1, we just need to check if counts are 1
 */

class Solution {
public:
   int numSpecial(vector<vector<int> >& mat){
      int m = mat.size();      // Number of rows
      int n = mat[0].size();   // Number of columns

      // Arrays to store count of 1s in each row and column
      vector<int> rowCount(m, 0);   // rowCount[i] = number of 1s in row i
      vector<int> colCount(n, 0);   // colCount[j] = number of 1s in column j

      // First pass: Count number of 1s in each row and column
      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            if (mat[row][col] == 1) {
               rowCount[row]++;      // Increment count for this row
               colCount[col]++;      // Increment count for this column
            }
         }
      }

      int result = 0;   // Counter for special positions

      // Second pass: Check each position containing 1
      for (int row = 0; row < m; row++) {
         for (int col = 0; col < n; col++) {
            // Skip if current position is 0
            if (mat[row][col] == 0) {
               continue;
            }

            // Position is special if:
            // 1. Current element is 1 (already checked above)
            // 2. Its row has exactly one 1 (rowCount[row] == 1)
            // 3. Its column has exactly one 1 (colCount[col] == 1)
            if (rowCount[row] == 1 && colCount[col] == 1) {
               result++;
            }
         }
      }
      return result;
   }
};

/*
 * Time Complexity: O(m*n)
 * - First pass: O(m*n) to count 1s
 * - Second pass: O(m*n) to check each position
 * - Much better than previous O(m*n*(m+n)) approach
 *
 * Space Complexity: O(m+n)
 * - rowCount array: O(m)
 * - colCount array: O(n)
 *
 * Key Optimization:
 * Instead of checking entire row and column for each 1,
 * we precompute counts and use them for O(1) lookup
 */
