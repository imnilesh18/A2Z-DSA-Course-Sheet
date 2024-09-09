/*
 * 326. Spiral Matrix IV
 * 
 * You are given two integers m and n, which represent the dimensions of a
 * matrix.
 * You are also given the head of a linked list of integers.
 * Generate an m x n matrix that contains the integers in the linked list
 * presented in spiral order (clockwise), starting from the top-left of the
 * matrix. If there are remaining empty spaces, fill them with -1.
 * Return the generated matrix.
 * 
 * Example 1:
 * Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
 * Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
 * Explanation: The diagram above shows how the values are printed in the
 * matrix.
 * Note that the remaining spaces in the matrix are filled with -1.
 * 
 * Example 2:
 * Input: m = 1, n = 4, head = [0,1,2]
 * Output: [[0,1,2,-1]]
 * Explanation: The diagram above shows how the values are printed from left to
 * right in the matrix.
 * The last space in the matrix is set to -1.
 * 
 * Constraints:
 * 1 <= m, n <= 105
 * 1 <= m * n <= 105
 * The number of nodes in the list is in the range [1, m * n].
 * 0 <= Node.val <= 1000
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int left = 0; 
        int top = 0;
        int bottom = m - 1;
        int right = n - 1;
        ListNode curr = head;
        int[][] result = new int[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[i][j] = -1;
            }
        }

        while(top <= bottom && left <= right){

            for(int i = left; curr != null && i<= right; i++){
                result[top][i] = curr.val;
                curr = curr.next;
            }
            top++;

            for(int i = top; curr != null && i <= bottom; i++){
                result[i][right] = curr.val;
                curr = curr.next;
            }
            right--;


            if (top <= bottom) {
                for (int i = right; curr != null && i >= left; i--) {
                    result[bottom][i] = curr.val;
                    curr = curr.next;
                    
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; curr != null && i >= top; i--) {
                    result[i][left] = curr.val;
                    curr = curr.next;
                }
                left++;
            }
        }
        return result;
    }
}

// Other Approach: 

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int left = 0;
        int top = 0;
        int bottom = m - 1;
        int right = n - 1;
        ListNode curr = head;
        int[][] result = new int[m][n];

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                if (curr != null) {
                    result[top][i] = curr.val;
                    curr = curr.next;
                } else {
                    result[top][i] = -1;
                }

            }
            top++;

            for (int i = top; i <= bottom; i++) {
                if (curr != null) {
                    result[i][right] = curr.val;
                    curr = curr.next;
                } else {
                    result[i][right] = -1;
                }

            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    if (curr != null) {
                        result[bottom][i] = curr.val;
                        curr = curr.next;
                    } else {
                        result[bottom][i] = -1;
                    }

                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    if (curr != null) {
                        result[i][left] = curr.val;
                        curr = curr.next;
                    } else {
                        result[i][left] = -1;
                    }

                }
                left++;
            }
        }
        return result;
    }
}