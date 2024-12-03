/*
 * 1312. Minimum Insertion Steps to Make a String Palindrome
 *
 * Given a string s. In one step you can insert any character at any index of the string.
 * Return the minimum number of steps to make s palindrome.
 * A Palindrome String is one that reads the same backward as well as forward.
 *
 * Example 1:
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we do not need any insertions.
 *
 * Example 2:
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 *
 * Example 3:
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 *
 * Constraints:
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 */

// Without Memoization
// TLE
// Time Complexity: O(2^n)
class Solution {
public:
   int n;

   int solve(string& s, int i, int j){
      if (i >= j) {
         return 0;
      }

      if (s[i] == s[j]) {
         return solve(s, i + 1, j - 1);
      }

      return 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
   }

   int minInsertions(string s){
      n = s.length();

      return solve(s, 0, n - 1);
   }
};

/*
 * Without Memoization:
 * The recursive function solve is defined to calculate the minimum number of insertions for the substring s[i...j].
 * Base Case:
 * If i >= j, the substring is already a palindrome or empty, requiring 0 insertions.
 * Recursive Case:
 * If s[i] == s[j], move inward with solve(s, i + 1, j - 1).
 * Otherwise, try inserting at either end:
 * Insert at i → solve(s, i + 1, j)
 * Insert at j → solve(s, i, j - 1)
 * Take the minimum of both and add 1 for the current insertion.
 * Time Complexity: O(2^n) due to the exponential number of recursive calls. This is why it leads to TLE for larger inputs.
 */

// With Memoization
// Time Complexity: O(n²)
// Space Complexity: O(n²) due to the memoization table.
class Solution {
public:
   int n;
   int t[501][501];
   int solve(string& s, int i, int j){
      if (i >= j) {
         return 0;
      }

      if (t[i][j] != -1) {
         return t[i][j];
      }

      if (s[i] == s[j]) {
         return t[i][j] = solve(s, i + 1, j - 1);
      }

      return t[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
   }

   int minInsertions(string s){
      n = s.length();

      memset(t, -1, sizeof(t));
      return solve(s, 0, n - 1);
   }
};

/*
 * To optimize, use a 2D table t[i][j] to store results of overlapping subproblems for substrings s[i...j].
 * Changes:
 * Before computing, check if t[i][j] != -1 (already computed).
 * Save the computed result in t[i][j].
 * This reduces the time complexity to O(n²), as each substring is solved once.
 * Space Complexity: O(n²) due to the memoization table.
 */
