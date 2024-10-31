/*
 * 867. Transpose Matrix
 *
 * Given a 2D integer array matrix, return the transpose of matrix.
 * The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
 *
 * Example 1:
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 *
 * Example 2:
 * Input: matrix = [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 *
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * -10^9 <= matrix[i][j] <= 10^9
 */

class Solution {
public:
   vector<vector<int> > transpose(vector<vector<int> >& matrix){
      int m = matrix.size();
      int n = matrix[0].size();

      vector<vector<int> > result(n, vector<int>(m));  // n*m

      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
         }
      }
      return result;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   vector<vector<int> > transpose(vector<vector<int> >& matrix){
      // Get dimensions of input matrix
      int m = matrix.size();     // number of rows
      int n = matrix[0].size();  // number of columns

      // Create result matrix with swapped dimensions
      // Original matrix: m x n
      // Transposed matrix: n x m
      // Initialize with zeros
      vector<vector<int> > result(n, vector<int>(m));

      // Traverse input matrix
      // For each element matrix[i][j]
      // Put it at result[j][i]
      for (int i = 0; i < m; i++) {
         for (int j = 0; j < n; j++) {
            // Key operation: swap indices i and j
            // Element at row i, col j in original
            // Goes to row j, col i in transpose
            result[j][i] = matrix[i][j];
         }
      }
      return result;
   }
};

/*
 * Intuition:
 * 1. Transpose means flipping matrix over its main diagonal
 * 2. Each element at position (i,j) moves to position (j,i)
 *
 * Example:
 * Original matrix:
 * [1 2 3]
 * [4 5 6]
 *
 * Transposed matrix:
 * [1 4]
 * [2 5]
 * [3 6]
 *
 * Key Points:
 * 1. Dimensions get swapped:
 * - Original: m x n
 * - Transposed: n x m
 *
 * 2. Each element's new position:
 * - matrix[i][j] -> result[j][i]
 * - row becomes column
 * - column becomes row
 *
 * 3. Need new matrix because:
 * - Dimensions might be different (non-square matrix)
 * - Can't modify in-place for non-square matrices
 *
 * Time Complexity: O(m*n) - visit each element once
 * Space Complexity: O(m*n) - new matrix needed
 *
 * Note: For square matrices (m=n), could do in-place
 * but this solution handles all cases
 */

// FOLLOW UP QUESTIOIN IF IT'S A SQUARE MATRIX THEN ??
class Solution {
public:
   vector<vector<int> > transpose(vector<vector<int> >& matrix){
      int n = matrix.size();   // since m = n for square matrix

      // Only need to traverse upper triangle of matrix
      // because swapping twice brings elements back to original position
      for (int i = 0; i < n; i++) {
         // Start from i+1 because:
         // 1. Diagonal elements (i==j) don't move
         // 2. Lower triangle would just reverse our swaps
         for (int j = i + 1; j < n; j++) {
            // Swap matrix[i][j] with matrix[j][i]
            swap(matrix[i][j], matrix[j][i]);
         }
      }
      return matrix;
   }
};

/*
 * Intuition for in-place transpose (square matrix only):
 * 1. Only traverse upper triangle (above diagonal)
 * 2. Each element needs exactly one swap
 *
 * Visual Example for 3x3:
 * [1 2 3]    Step 1: Swap (0,1)-(1,0)    [1 4 7]
 * [4 5 6] -> Step 2: Swap (0,2)-(2,0) -> [2 5 8]
 * [7 8 9]    Step 3: Swap (1,2)-(2,1)    [3 6 9]
 *
 * Key Points:
 * 1. j starts from (i+1) because:
 * - Diagonal elements (i==j) stay in place
 * - Lower triangle swaps would undo upper triangle swaps
 *
 * 2. Why upper triangle only?
 * If we swap element at (i,j):
 * - First swap: matrix[i][j] ↔ matrix[j][i]
 * - If we visit (j,i) later: matrix[j][i] ↔ matrix[i][j]
 * - Elements would return to original position!
 *
 * Time: O(n^2)
 * Space: O(1) - truly in-place
 *
 * Note: This only works for square matrices where m = n
 * For rectangular matrices, must use extra space
 */

/*
 * Before: matrix[i][j] = A, matrix[j][i] = B
 * After swap: matrix[i][j] = B, matrix[j][i] = A
 *
 * Would swap again: matrix[i][j] = A, matrix[j][i] = B
 * Back to original - undoing our work!
 *
 * Upper Triangle (what we process):
 * [- 2 3]
 * [- - 6]
 * [- - -]
 *
 * Why not Lower Triangle:
 * [- - -]
 * [4 - -]
 * [7 8 -]
 *
 * Because:
 * - If we swap (0,1)&(1,0), then later swap (1,0)&(0,1)
 * - We'd undo our work!
 */
