// Optimal Approach
import java.io.*;
import java.util.*;
public class Solution {
        static ArrayList<ArrayList<Integer>> zeroMatrix(
                ArrayList<ArrayList<Integer>> matrix, int n, int m) {
                // int[] row = new int[n]; --> matrix[..][0]
                // int[] col = new int[m]; --> matrix[0][..]

                int col0 = 1;
                // step 1: Traverse the matrix and
                // mark 1st row & col accordingly:
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (matrix.get(i).get(j) == 0) {
                                        // mark i-th row:
                                        matrix.get(i).set(0, 0);

                                        // mark j-th column:
                                        if (j != 0)
                                                matrix.get(0).set(j, 0);
                                        else
                                                col0 = 0;
                                }
                        }
                }

                // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
                for (int i = 1; i < n; i++) {
                        for (int j = 1; j < m; j++) {
                                if (matrix.get(i).get(j) != 0) {
                                        // check for col & row:
                                        if (matrix.get(i).get(0) == 0 || matrix.get(0).get(j) == 0) {
                                                matrix.get(i).set(j, 0);
                                        }
                                }
                        }
                }

                // step 3: Finally mark the 1st col & then 1st row:
                if (matrix.get(0).get(0) == 0) {
                        for (int j = 0; j < m; j++) {
                                matrix.get(0).set(j, 0);
                        }
                }
                if (col0 == 0) {
                        for (int i = 0; i < n; i++) {
                                matrix.get(i).set(0, 0);
                        }
                }

                return matrix;
        }
}

// Better Approach Coding Ninjas
import java.io.*;
import java.util.*;
public class Solution {
        public static ArrayList<ArrayList<Integer>> zeroMatrix(
                ArrayList<ArrayList<Integer>> matrix, Integer n, Integer m) {
                int[] row = new int[n]; // row array
                int[] col = new int[m]; // col array

                // Traverse the matrix:
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (matrix.get(i).get(j) == 0) {
                                        // mark ith index of row wih 1:
                                        row[i] = 1;

                                        // mark jth index of col wih 1:
                                        col[j] = 1;
                                }
                        }
                }

                // Finally, mark all (i, j) as 0
                // if row[i] or col[j] is marked with 1.
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (row[i] == 1 || col[j] == 1) {
                                        matrix.get(i).set(j, 0);
                                }
                        }
                }

                return matrix;
        }
}

// Better Approach Leetcode:
class Solution {
        public void setZeroes(int[][] matrix) {
                int[] row = new int[matrix.length]; // row array
                int[] column = new int[matrix[0].length]; // column array

                // Traverse the matrix:
                for(int i = 0; i < matrix.length; i++){
                        for(int j = 0; j < matrix[i].length; j++){
                                if(matrix[i][j] == 0){
                                        // mark ith index of row wih 1:
                                        row[i] = 1;
                                        // mark jth index of col wih 1:
                                        column[j] = 1;
                                }
                        }
                }
                // Finally, mark all (i, j) as 0
                // if row[i] or column[j] is marked with 1.
                for (int i = 0; i < matrix.length; i++) {
                        for (int j = 0; j < matrix[i].length; j++) {
                                if (row[i] == 1 || column[j] == 1) {
                                        matrix[i][j] = 0;
                                }
                        }
                }
        }
}
// Time Complexity: O(2 x n x m)
// Space Complexity: O(n) + O(m)


// Brute Force Approach Coding Ninjas:
import java.util.* ;
import java.io.*;
public class Solution {
        // set all non-zero elements as -1 in the row i:
        static void markRow(ArrayList<ArrayList<Integer>> matrix, int n, int m, int i){
                for(int j = 0; j < m;  j++){
                        if(matrix.get(i).get(j) != 0) {
                                matrix.get(i).set(j, -1);
                        }
                }
        }

        static void markColumn(ArrayList<ArrayList<Integer>> matrix, int n, int m, int j){
                // set all non-zero elements as -1 in the col j:
                for(int i = 0; i < n; i++){
                        if(matrix.get(i).get(j) != 0) {
                                matrix.get(i).set(j, -1);
                        }
                }
        }
        public static ArrayList<ArrayList<Integer>> zeroMatrix(ArrayList<ArrayList<Integer>> matrix, Integer n, Integer m) {
                // Set -1 for rows and cols that contains 0. Don't mark any 0 as -1:
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                                if(matrix.get(i).get(j) == 0){
                                        markRow(matrix, n, m, i);
                                        markColumn(matrix, n, m ,j);
                                }
                        }
                }
                // Finally, mark all -1 as 0:
                for(int i = 0; i < n; i ++){
                        for(int j = 0; j < m; j++){
                                if(matrix.get(i).get(j) == -1 ){
                                        matrix.get(i).set(j, 0);
                                }
                        }
                }
                return matrix;
        }
}

// Brute Force Leetcode:
class Solution {

        public void markRow(int i, int[][] matrix){
                for(int j = 0; j < matrix[i].length; j++){
                        if(matrix[i][j] != 0 ){
                                matrix[i][j] = -1;
                        }
                }
        }

        public void markColumn(int j, int[][] matrix){
                for(int i = 0; i < matrix.length; i++){
                        if(matrix[i][j] != 0 ){
                                matrix[i][j] = -1;
                        }
                }
        }

        public void setZeroes(int[][] matrix) {
                for(int i = 0; i < matrix.length; i++){
                        for( int j = 0; j < matrix[i].length; j++){
                                if(matrix[i][j] == 0){
                                        markRow(i, matrix);
                                        markColumn(j, matrix);
                                }
                        }
                }
                for (int i = 0; i < matrix.length; i++) {
                        for (int j = 0; j < matrix[i].length; j++) {
                                if (matrix[i][j] == -1) {
                                        matrix[i][j] = 0;
                                }
                        }
                }
        }
}

// Brute Force Time Complexitiy : O(n x m) x O(n + m) + O(n x m) almost power of cube