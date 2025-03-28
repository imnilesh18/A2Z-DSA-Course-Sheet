/*
 * 1140. Stone Game II
 * 
 * Alice and Bob continue their games with piles of stones. There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i]. The objective of the game is to end with the most stones.
 * Alice and Bob take turns, with Alice starting first. Initially, M = 1.
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X).
 * The game continues until all the stones have been taken.
 * Assuming Alice and Bob play optimally, return the maximum number of stones
 * Alice can get.
 * 
 * Example 1:
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation: If Alice takes one pile at the beginning, Bob takes two piles,
 * then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total.
 * If Alice takes two piles at the beginning, then Bob can take all three piles
 * left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since
 * it's larger.
 * 
 * Example 2:
 * Input: piles = [1,2,3,4,5,100]
 * Output: 104
 */
//Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^3)
class Solution {
    private int n;
    private int[][][] t = new int[2][101][101]; // t[2][n+1][n+1] ~ O(n^3)

    private int solveForAlice(int[] piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }

        if (t[person][i][M] != -1) {
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;

        for (int x = 1; x <= Math.min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];

            if (person == 1) { // Alice
                result = Math.max(result, stones + solveForAlice(piles, 0, i + x, Math.max(M, x)));
            } else { // Bob
                result = Math.min(result, solveForAlice(piles, 1, i + x, Math.max(M, x)));
            }
        }

        return t[person][i][M] = result;
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;

        for (int[][] arr2D : t) {
            for (int[] arr1D : arr2D) {
                Arrays.fill(arr1D, -1);
            }
        }

        return solveForAlice(piles, 1, 0, 1);
    }
}