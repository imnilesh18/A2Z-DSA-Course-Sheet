/*
 * 840. Magic Squares In Grid
 * 
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
 * such that each row, column, and both diagonals all have the same sum.
 * Given a row x col grid of integers, how many 3 x 3 contiguous magic square
 * subgrids are there?
 * Note: while a magic square can only contain numbers from 1 to 9, grid may
 * contain numbers up to 15.
 * 
 * Example 1:
 * Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
 * Output: 1
 * Explanation:
 * The following subgrid is a 3 x 3 magic square:
 * while this one is not:
 * In total, there is only one magic square inside the given grid.
 * 
 * Example 2:
 * Input: grid = [[8]]
 * Output: 0
 */

// Other Approach:
class Solution {

    public boolean isMagicGrid(int[][] grid, int r, int c) {
        // Uniqueness 1 to 9 and distinct
        Set<Integer> st = new HashSet<>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.contains(num)) {
                    return false;
                } else {
                    st.add(num);
                }
            }
        }

        // Check Sum - Rows and Columns
        int SUM = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        // int SUM = 15;
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != SUM) {
                return false;
            }
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != SUM) {
                return false;
            }
        }

        // Diagonal Sum
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != SUM) {
            return false;
        }
        // Anti Diagonal Sum
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != SUM) {
            return false;
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicGrid(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
}

// Brute Force:
class Solution {
    public boolean checkRows(int[][] mat) {
        int n = 3;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
            }
            if (i == 0) {
                sum = rowSum;
            } else if (rowSum != sum) {
                return false;
            }
        }
        return true;
    }

    public boolean checkColumns(int[][] mat) {
        int n = 3;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int colSum = 0;
            for (int i = 0; i < n; i++) {
                colSum += mat[i][j];
            }
            if (j == 0) {
                sum = colSum;
            } else if (colSum != sum) {
                return false;
            }
        }
        return true;
    }

    public boolean checkDiagonals(int[][] mat) {
        int n = 3;
        int diag1Sum = 0, diag2Sum = 0;
        for (int i = 0; i < n; i++) {
            diag1Sum += mat[i][i];
            diag2Sum += mat[i][n - i - 1];
        }
        return diag1Sum == diag2Sum && diag1Sum == 15;
    }

    public boolean isMagicSquare(int[][] mat) {

        boolean[] seen = new boolean[10];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = mat[i][j];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }

        boolean rowsFlag = checkRows(mat);
        boolean columnsFlag = checkColumns(mat);
        boolean diagonalsFlag = checkDiagonals(mat);

        return rowsFlag && columnsFlag && diagonalsFlag;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;

        for (int i = 0; i < grid.length - 2; i++) {
            for (int j = 0; j < grid[0].length - 2; j++) {
                int[][] subgrid = new int[3][3];
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        subgrid[x][y] = grid[i + x][j + y];
                    }
                }

                if (isMagicSquare(subgrid)) {
                    count++;
                }
            }
        }

        return count;
    }
}
