// Leetcode :

// Optimal:
// First Transpose then Reverse each rows:

class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        transpose(matrix, n);
        reverseRows(matrix, n);
    }

    public void swap(int[][] matrix, int i1, int j1, int i2, int j2) {
        int temp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = temp;
    }
    
    public void transpose(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix, i, j, j, i);
            }
        }
    }

    public void reverseRows(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                swap(matrix, i, start, i, end);
                start++;
                end--;
            }
        }
    }
}

// Brute Force: 
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int[][] ans = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
}



