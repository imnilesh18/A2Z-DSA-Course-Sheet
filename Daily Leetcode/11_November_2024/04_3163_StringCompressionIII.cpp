/*
 * 3163. String Compression III
 *
 * Given a string word, compress it using the following algorithm:
 * Begin with an empty string comp. While word is not empty, use the following operation:
 * Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
 * Append the length of the prefix followed by c to comp.
 * Return the string comp.
 *
 * Example 1:
 * Input: word = "abcde"
 * Output: "1a1b1c1d1e"
 * Explanation:
 * Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
 * For each prefix, append "1" followed by the character to comp.
 *
 * Example 2:
 * Input: word = "aaaaaaaaaaaaaabb"
 * Output: "9a5a2b"
 * Explanation:
 * Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.
 * For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
 * For prefix "aaaaa", append "5" followed by "a" to comp.
 * For prefix "bb", append "2" followed by "b" to comp.
 *
 * Constraints:
 * 1 <= word.length <= 2 * 10^5
 * word consists only of lowercase English letters.
 */

// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   string compressedString(string word){
      int n = word.length();

      string comp = "";
      int    i    = 0;

      while (i < n) {
         int  count = 0;
         char ch    = word[i];

         while (i < n && count < 9 && word[i] == ch) {
            count++;
            i++;
         }

         comp += to_string(count) + ch;
      }
      return comp;
   }
};


// Code with comments for better understanding:
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   string compressedString(string word){
      int n = word.length();

      // Initialize the compressed string
      string comp = "";

      // Iterate through the input string
      int i = 0;

      while (i < n) {
         // Get the current character
         char ch = word[i];

         // Count the number of consecutive occurrences of the current character
         // (up to a maximum of 9)
         // The intuition is to find the maximum length prefix of the same character
         // and encode it as the count followed by the character
         int count = 0;
         while (i < n && count < 9 && word[i] == ch) {
            count++;
            i++;
         }

         // Append the count and the character to the compressed string
         // The intuition is to build the compressed string by appending the
         // count and the character for each maximum length prefix of the same character
         comp += to_string(count) + ch;
      }

      return comp;
   }
};
