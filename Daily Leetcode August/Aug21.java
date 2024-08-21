/*
 * 664. Strange Printer
 * 
 * There is a strange printer with the following two special properties:
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any place and will cover the original existing characters.
 * Given a string s, return the minimum number of turns the printer needed to
 * print it.
 * 
 * Example 1:
 * Input: s = "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * Example 2:
 * Input: s = "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 */

//Approach-1 (Recursion + Memoization)
class Solution {
    int n;
    int[][] t;

    public int solve(int l, int r, String s) {
        if (l == r)
            return 1;
        else if (l > r)
            return 0;

        if (t[l][r] != -1)
            return t[l][r];

        int i = l + 1;
        while (i <= r && s.charAt(i) == s.charAt(l))
            i++;

        if (i == r + 1)
            return 1;

        int normal = 1 + solve(i, r, s);

        int aage_ka = Integer.MAX_VALUE;

        for (int j = i; j <= r; j++) {
            if (s.charAt(l) == s.charAt(j)) {
                int x = solve(i, j - 1, s) + solve(j, r, s);
                aage_ka = Math.min(aage_ka, x);
            }
        }

        return t[l][r] = Math.min(aage_ka, normal);
    }

    public int strangePrinter(String s) {
        n = s.length();
        t = new int[n][n + 1];

        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(0, n - 1, s);
    }
}
