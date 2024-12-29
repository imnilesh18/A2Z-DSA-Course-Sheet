/*
 * 1639. Number of Ways to Form a Target String Given a Dictionary
 *
 * You are given a list of strings of the same length words and a string target.
 * Your task is to form target using the given words under the following rules:
 * target should be formed from left to right.
 * To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
 * Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
 * Repeat the process until you form the string target.
 * Notice that you can use multiple characters from the same string in words provided the conditions above are met.
 * Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
 *
 * Example 1:
 * Input: words = ["acca","bbbb","caca"], target = "aba"
 * Output: 6
 * Explanation: There are 6 ways to form target.
 * "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
 * "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
 * "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
 * "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
 * "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
 * "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
 *
 * Example 2:
 * Input: words = ["abba","baab"], target = "bab"
 * Output: 4
 * Explanation: There are 4 ways to form target.
 * "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
 * "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
 * "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
 * "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
 *
 * Constraints:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * All strings in words have the same length.
 * 1 <= target.length <= 1000
 * words[i] and target contain only lowercase English letters.
 */


// Approach 1 (Using Recursion and Memoization): Use a frequency matrix to count character occurrences column-wise, then solve recursively with memoization to count ways to form the target string while ensuring modular arithmetic for large values.
// Time Complexity: O(m × k + 26 × k), where m is the length of the target, k is the number of columns, and 26 × k is for building the frequency matrix.
// Space Complexity: O(m × k + 26 × k), for the memoization table and the frequency matrix.
class Solution {
public:
   int m, k;
   const int MOD = 1e9 + 7;

   int solve(int i, int j, vector<vector<long long> >&freq, string&target, vector<vector<int> >&dp){
      if (i == m) {
         return 1;            // All characters of target are formed.
      }
      if (j == k) {
         return 0;            // Exhausted all columns without forming the target.
      }
      if (dp[i][j] != -1) {
         return dp[i][j];                    // Return cached result.
      }
      // Option 1: Skip this column
      int not_taken = solve(i, j + 1, freq, target, dp);

      // Option 2: Use this column (if possible)
      int taken = 0;
      if (freq[target[i] - 'a'][j] > 0) {
         taken = (freq[target[i] - 'a'][j] * 1LL * solve(i + 1, j + 1, freq, target, dp)) % MOD;
      }

      return dp[i][j] = (not_taken + taken) % MOD;
   }

   int numWays(vector<string>& words, string target){
      m = target.length();
      k = words[0].length();

      // Frequency matrix
      vector<vector<long long> > freq(26, vector<long long>(k, 0));
      for (int col = 0; col < k; col++) {
         for (string&word : words) {
            char ch = word[col];
            freq[ch - 'a'][col]++;
         }
      }

      // Memoization table
      vector<vector<int> > dp(m, vector<int>(k, -1));

      return solve(0, 0, freq, target, dp);
   }
};
