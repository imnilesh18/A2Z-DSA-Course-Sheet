// Before solving this question solve Leetcode: 392. Is Subsequence

/*
 * 792. Number of Matching Subsequences
 *
 * Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
 *
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 * Example 1:
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 *
 * Example 2:
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 *
 * Constraints:
 * 1 <= s.length <= 5 * 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 */

class Solution {
public:
   // Helper function to determine if `t` is a subsequence of `s`
   bool isSubsequence(string t, map<char, vector<int> >& mp){
      int m    = t.length();
      int prev = -1;

      for (int i = 0; i < m; i++) {
         char ch = t[i];

         // If character `ch` is not present in `s`, return false
         if (mp.find(ch) == mp.end()) {
            return false;
         }

         vector<int>& indices = mp[ch];
         // Find the next valid position for `ch` after `prev`
         auto it = upper_bound(indices.begin(), indices.end(), prev);

         // If there's no valid position, `t` is not a subsequence
         if (it == indices.end()) {
            return false;
         }

         prev = *it;    // Update `prev` to the current position
      }

      return true;
   }

   int numMatchingSubseq(string s, vector<string>& words){
      map<char, vector<int> > mp;

      // Preprocess `s` and store indices of each character
      for (int i = 0; i < s.length(); i++) {
         mp[s[i]].push_back(i);
      }

      int cnt = 0;

      // Check each word in `words` for being a subsequence
      for (int i = 0; i < words.size(); i++) {
         if (isSubsequence(words[i], mp)) {
            cnt++;
         }
      }

      return cnt;
   }
};
