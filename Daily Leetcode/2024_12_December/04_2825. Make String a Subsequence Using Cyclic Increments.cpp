// Before solving this question solve Leetcode:
// i). 392. Is Subsequence
// ii). 792. Number of Matching Subsequences

/*
 * 2825. Make String a Subsequence Using Cyclic Increments
 *
 * You are given two 0-indexed strings str1 and str2.
 * In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
 * Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
 * Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.
 *
 * Example 1:
 * Input: str1 = "abc", str2 = "ad"
 * Output: true
 * Explanation: Select index 2 in str1.
 * Increment str1[2] to become 'd'.
 * Hence, str1 becomes "abd" and str2 is now a subsequence. Therefore, true is returned.
 *
 * Example 2:
 * Input: str1 = "zc", str2 = "ad"
 * Output: true
 * Explanation: Select indices 0 and 1 in str1.
 * Increment str1[0] to become 'a'.
 * Increment str1[1] to become 'd'.
 * Hence, str1 becomes "ad" and str2 is now a subsequence. Therefore, true is returned.
 *
 * Example 3:
 * Input: str1 = "ab", str2 = "d"
 * Output: false
 * Explanation: In this example, it can be shown that it is impossible to make str2 a subsequence of str1 using the operation at most once.
 * Therefore, false is returned.
 *
 * Constraints:
 * 1 <= str1.length <= 10^5
 * 1 <= str2.length <= 10^5
 * str1 and str2 consist of only lowercase English letters.
 */

// T.C: O(m + n)
// S.C: O(1)
class Solution {
public:
   bool canMakeSubsequence(string str1, string str2){
      int m = str1.length();
      int n = str2.length();

      int i = 0;   // pointer for str1
      int j = 0;   // pointer for str2

      while (i < m && j < n) {
         if ((str1[i] == str2[j]) ||
             (str1[i] + 1 == str2[j]) ||
             (str1[i] - 25 == str2[j])
             ) {
            j++;
         }
         i++;
      }

      return j == str2.length();
   }
};

/************************************************************
*                   Code with Comments                    *
* This section contains code with detailed explanations   *
* to improve understanding of the logic and functionality.*
************************************************************/

// T.C: O(m + n)
// S.C: O(1)
class Solution {
public:
   bool canMakeSubsequence(string str1, string str2){
      int m = str1.length(); // Length of the first string
      int n = str2.length(); // Length of the second string

      int i = 0;             // Pointer for iterating through str1
      int j = 0;             // Pointer for iterating through str2

      // Traverse both strings to determine if str2 can be made a subsequence of str1
      while (i < m && j < n) {
         // Check if the current character in str1 matches the current character in str2
         // or if the current character in str1 can be incremented cyclically to match
         if ((str1[i] == str2[j]) ||     // Characters are already equal
             (str1[i] + 1 == str2[j]) || // Incrementing str1[i] by 1 matches str2[j]
             (str1[i] - 25 == str2[j])   // Incrementing 'z' to 'a' matches str2[j]
             ) {
            j++;                         // Move to the next character in str2 as it has been matched
         }
         i++;                            // Move to the next character in str1 to continue the search
      }

      // If we have matched all characters of str2, return true
      return j == str2.length();
   }
};

/*
 *
 * Pointers i and j:
 * i traverses str1.
 * j traverses str2.
 * The goal is to match all characters of str2 in order within str1.
 * Cyclic Increment Check:
 * (str1[i] + 1 == str2[j]): Checks if incrementing the character at str1[i] makes it equal to str2[j].
 * (str1[i] - 25 == str2[j]): Handles the wrap-around from 'z' to 'a'.
 * Match Success:
 * If j reaches the length of str2, it means all characters in str2 have been matched in sequence in str1.
 * Efficiency:
 * Time Complexity: O(m + n) because both str1 and str2 are traversed once.
 * Space Complexity: O(1) as no extra space is used beyond variables.
 */
