/*
 * Shortest Common Supersequence
 *
 * (GfG Link: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1)
 * (Solve before LeetCode: 1092. Shortest Common Supersequence)
 *
 * Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
 * Note: s1 and s2 can have both uppercase and lowercase English letters.
 *
 * Examples:
 * Input: s1 = "geek", s2 = "eke"
 * Output: 5
 * Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
 * Input: s1 = "AGGTAB", s2 = "GXTXAYB"
 * Output: 9
 * Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
 * Input: s1 = "geek", s2 = "ek"
 * Output: 4
 * Explanation: String "geek" has both string "geek" and "ek" as subsequences.
 * Constraints:
 * 1<= s1.size(), s2.size() <= 500
 */

// Approach-1 (Recursion + Memoization) Test Cases Passed: 1110 /1111
// Approach: Use recursion with memoization to compute the SCS length by exploring subproblems and caching results.
// T.C: O(m*n) because each subproblem is computed only once.
// S.C: O(m*n) due to the memoization table.
class Solution {
public:
   int t[101][101];  // Memoization table; adjust size if needed

   int solve(string&s1, string&s2, int m, int n) {
      // Base Case: if one string is empty, SCS length is the sum of remaining characters.
      if (m == 0 || n == 0) {
         return m + n;
      }
      // Return memoized result if available.
      if (t[m][n] != -1) {
         return t[m][n];
      }
      // If last characters match, include one occurrence and reduce both strings.
      if (s1[m - 1] == s2[n - 1]) {
         return t[m][n] = 1 + solve(s1, s2, m - 1, n - 1);
      }else{
         // Otherwise, choose the minimum between removing one character from s1 or s2.
         return t[m][n] = 1 + min(solve(s1, s2, m - 1, n), solve(s1, s2, m, n - 1));
      }
   }

   // Function to find length of shortest common supersequence of two strings.
   int shortestCommonSupersequence(string&s1, string&s2) {
      int m = s1.size(), n = s2.size();

      memset(t, -1, sizeof(t));   // Initialize memoization table with -1.
      return solve(s1, s2, m, n);
   }
};

/*
 * Dry Run for Approach-1:
 * Input: s1 = "abac", s2 = "cab"
 * Call shortestCommonSupersequence("abac", "cab") computes m=4, n=3 and initializes t.
 * solve(4,3): compares s1[3]='c' with s2[2]='b' -> not equal, so calls solve(3,3) and solve(4,2).
 * Recursively solves subproblems until base cases (m==0 or n==0) are reached.
 * Final computed SCS length is 5.
 */

// Approach-2 (Bottom Up)
// Approach: Use bottom-up dynamic programming to fill a DP table that stores the SCS length for every substring pair.
// T.C: O(m*n) because we fill a DP table of size (m+1) x (n+1) using nested loops.
// S.C: O(m*n) due to the DP table storage.
class Solution {
public:
   // Function to find length of shortest common supersequence of two strings using bottom-up DP.
   int shortestCommonSupersequence(string&s1, string&s2) {
      int m = s1.size(), n = s2.size();
      vector<vector<int> > t(m + 1, vector<int>(n + 1, 0));

      // Fill the DP table.
      for (int i = 0; i <= m; i++) {
         for (int j = 0; j <= n; j++) {
            // If one string is empty, SCS length is the sum of indices.
            if (i == 0 || j == 0) {
               t[i][j] = i + j;
            }else if (s1[i - 1] == s2[j - 1]) {
               t[i][j] = 1 + t[i - 1][j - 1];
            }else{
               t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
            }
         }
      }

      return t[m][n];
   }
};

/*
 * Dry Run for Approach-2:
 * Input: s1 = "abac", s2 = "cab"
 * m = 4, n = 3; DP table base cases: t[0][j] = j and t[i][0] = i.
 * For i=1, j=1: s1[0]='a' vs s2[0]='c' -> not equal, so t[1][1] = 1 + min(t[0][1], t[1][0]) = 1 + min(1,1) = 2.
 * Continue filling table until t[4][3] becomes 5.
 * Final SCS length = 5.
 */

// Approach-3 (Using LCS Code)
// Approach: Compute the Longest Common Subsequence (LCS) first, then derive the SCS length using the formula: SCS = (length(s1) + length(s2) - LCS).
// T.C: O(m*n) for computing the LCS using dynamic programming.
// S.C: O(m*n) due to the DP table used for the LCS computation.
class Solution {
public:
   // Function to find length of shortest common supersequence of two strings using the LCS approach.
   int shortestCommonSupersequence(string&s1, string&s2) {
      int m = s1.size(), n = s2.size();
      vector<vector<int> > t(m + 1, vector<int>(n + 1, 0));

      // Build the LCS DP table.
      for (int i = 0; i <= m; i++) {
         for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
               t[i][j] = 0;
            }else if (s1[i - 1] == s2[j - 1]) {
               t[i][j] = 1 + t[i - 1][j - 1];
            }else{
               t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
         }
      }

      int LCS             = t[m][n];
      int letters_from_s1 = m - LCS;
      int letters_from_s2 = n - LCS;
      return LCS + letters_from_s1 + letters_from_s2;   // Equivalent to m + n - LCS.
   }
};

/*
 * Dry Run for Approach-3:
 * Input: s1 = "abac", s2 = "cab"
 * m = 4, n = 3; Compute LCS DP table, where LCS("abac", "cab") is computed as 2.
 * letters_from_s1 = 4 - 2 = 2 and letters_from_s2 = 3 - 2 = 1.
 * SCS length = 2 + 2 + 1 = 5.
 */
