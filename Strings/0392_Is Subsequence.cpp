// After solving this question solve Leetcode:
// i). 792. Number of Matching Subsequences
// ii). 2825. Make String a Subsequence Using Cyclic Increments

/*
 * 392. Is Subsequence
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 *
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 * Constraints:
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
 */

// T.C: O(m + n)
// S.C: O(1)
class Solution {
public:
   bool isSubsequence(string s, string t){
      int m = s.length();
      int n = t.length();

      int i = 0, j = 0;

      while (i < m && j < n) {
         if (s[i] == t[j]) {   // we foound ith character of s in t
            i++;
         }
         j++;
      }

      return i == m;   // we found all chars of s in t
   }
};

// Follow Up:
// T.C:  O(m * log(n))
// S.C:  O(n)
class Solution {
public:
   bool isSubsequence(string s, string t){
      int m = s.length();
      int n = t.length();

      map<char, vector<int> > mp;

      for (int i = 0; i < n; i++) {
         mp[t[i]].push_back(i);
      }

      int prev = -1;

      for (int i = 0; i < m; i++) {
         char ch = s[i];

         if (mp.find(ch) == mp.end()) {
            return false;
         }

         vector<int> indices = mp[ch];

         auto it = upper_bound(begin(indices), end(indices), prev);

         if (it == indices.end()) {
            return false;
         }

         prev = *it;
      }

      return true;
   }
};
