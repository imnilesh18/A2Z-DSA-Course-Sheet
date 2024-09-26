/*
 * Minimum number of Coins
 * Problem Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1/?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 * 
 * Given an infinite supply of each denomination of Indian currency { 1, 2, 5,
 * 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
 * Find the minimum number of coins and/or notes needed to make the change for
 * Rs N. You must return the list containing the value of coins required.
 * 
 * Example 1:
 * Input: N = 43
 * Output: 20 20 2 1
 * Explaination:
 * Minimum number of coins and notes needed
 * to make 43.
 * 
 * Example 2:
 * Input: N = 1000
 * Output: 500 500
 * Explaination: minimum possible notes
 * is 2 notes of 500.
 * 
 * Your Task:
 * You do not need to read input or print anything. Your task is to complete the
 * function minPartition() which takes the value N as input parameter and
 * returns a list of integers in decreasing order.
 * 
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(N)
 * 
 * Constraints:
 * 1 ≤ N ≤ 106
 * 
 */

class Solution {
    // Method to determine the minimum number of coins needed to make up the amount
    // N
    static List<Integer> minPartition(int N) {
        // List to store the result, which will be the coins used to make up the amount
        List<Integer> result = new ArrayList<Integer>();

        // Array of coin denominations available in descending order
        int[] coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

        // Get the number of different coin types
        int n = coins.length;

        // Loop through the coin array from largest to smallest
        for (int i = n - 1; i >= 0; i--) {
            // While the remaining amount N is at least the value of the current coin
            while (N >= coins[i]) {
                // Reduce N by the value of the current coin
                N -= coins[i];
                // Add the current coin to the result list
                result.add(coins[i]);
            }
        }
        // Return the list of coins that make up the original amount
        return result;
    }
}