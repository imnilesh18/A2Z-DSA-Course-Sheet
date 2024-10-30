// Problem Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

/*
 * 1160. Find Words That Can Be Formed by Characters
 *
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * Return the sum of lengths of all good strings in words.
 *
 * Example 1:
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
 *
 * Example 2:
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 *
 * Constraints:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * words[i] and chars consist of lowercase English letters.
 */

// T.C : O(words.length())
// S.C : O(26)
class Solution {
public:
   int countCharacters(vector<string>& words, string chars){
      vector<int> charCount(26, 0);

      for (char&ch : chars) {
         charCount[ch - 'a']++;
      }

      int result = 0;
      for (string&word : words) {
         vector<int> wordCount(26, 0);
         for (char&ch : word) {
            wordCount[ch - 'a']++;
         }

         bool ok = true;
         for (int i = 0; i < 26; i++) {
            if (wordCount[i] > charCount[i]) {
               ok = false;
               break;
            }
         }

         if (ok == true) {
            result += word.length();
         }
      }
      return result;
   }
};

// Code with comments for better understanding:

/* Approach:
 * - Count the occurrences of each character in chars and store them in a vector.
 * - For each word in words, count its character occurrences.
 * - Check if each character's count in the word is within the limit provided by chars.
 * - If it meets the criteria, add the length of that word to the result.
 *
 * Time Complexity (T.C): O(words.length() * word.length()), where word.length is the average length of words in words.
 * Space Complexity (S.C): O(26), for the character count arrays.
 */
class Solution {
public:
   int countCharacters(vector<string>& words, string chars){
      // Count occurrences of each character in chars
      vector<int> charCount(26, 0); // Array to store character counts for chars

      for (char&ch : chars) {
         charCount[ch - 'a']++; // Increment the count for each character
      }

      int result = 0; // To accumulate the lengths of "good" words

      // Process each word in the words array
      for (string&word : words) {
         vector<int> wordCount(26, 0); // Array to store character counts for the current word

         // Count occurrences of each character in the current word
         for (char&ch : word) {
            wordCount[ch - 'a']++; // Increment the count for each character
         }

         // Check if the word can be formed by chars
         bool ok = true; // Flag to indicate if the word can be formed
         for (int i = 0; i < 26; i++) {
            // If wordCount exceeds charCount for any character, set flag to false
            if (wordCount[i] > charCount[i]) {
               ok = false;
               break;
            }
         }

         // If the word is "good", add its length to the result
         if (ok == true) {
            result += word.length();
         }
      }

      // Return the total length of all "good" words
      return result;
   }
};
