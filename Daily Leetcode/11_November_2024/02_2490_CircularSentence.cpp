/*
 * 2490. Circular Sentence
 *
 * A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
 * For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
 * Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.
 *
 * A sentence is circular if:
 * The last character of a word is equal to the first character of the next word.
 * The last character of the last word is equal to the first character of the first word.
 * For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.
 * Given a string sentence, return true if it is circular. Otherwise, return false.
 *
 * Example 1:
 * Input: sentence = "leetcode exercises sound delightful"
 * Output: true
 * Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
 * - leetcode's last character is equal to exercises's first character.
 * - exercises's last character is equal to sound's first character.
 * - sound's last character is equal to delightful's first character.
 * - delightful's last character is equal to leetcode's first character.
 * The sentence is circular.
 *
 * Example 2:
 * Input: sentence = "eetcode"
 * Output: true
 * Explanation: The words in sentence are ["eetcode"].
 * - eetcode's last character is equal to eetcode's first character.
 * The sentence is circular.
 *
 * Example 3:
 * Input: sentence = "Leetcode is cool"
 * Output: false
 * Explanation: The words in sentence are ["Leetcode", "is", "cool"].
 * - Leetcode's last character is not equal to is's first character.
 * The sentence is not circular.
 *
 * Constraints:
 *
 * 1 <= sentence.length <= 500
 * sentence consist of only lowercase and uppercase English letters and spaces.
 * The words in sentence are separated by a single space.
 * There are no leading or trailing spaces.
 */

// My Approach:
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   bool isCircularSentence(string s){
      int n = s.length();

      if (s[0] != s[n - 1]) {
         return false;
      }

      for (int i = 1; i < n - 1; i++) {
         if (s[i] == ' ') {
            if (s[i - 1] != s[i + 1]) {
               return false;
            }
         }
      }
      return true;
   }
};

// Code with comments for better understanding:

/*
 * Intuition:
 * The problem requires us to check if a sentence is circular by verifying:
 * 1. Last character of each word matches first character of next word
 * 2. Last character of last word matches first character of first word
 *
 * Approach:
 * 1. First check if first and last characters of entire string match
 * (This handles requirement 2)
 * 2. Then at each space, check if character before space matches character after space
 * (This handles requirement 1)
 * 3. Using spaces as word boundaries avoids having to split string into words
 *
 * Time Complexity: O(n)
 * - We iterate through the string once
 * - Each character is checked at most once
 * - n is the length of input string
 *
 * Space Complexity: O(1)
 * - We only use a few variables
 * - No extra data structures used
 * - Space used is constant regardless of input size
 */

class Solution {
public:
   bool isCircularSentence(string s){
      int n = s.length();

      // First check: For a sentence to be circular,
      // the first character of first word (s[0]) must match
      // the last character of last word (s[n-1])
      if (s[0] != s[n - 1]) {
         return false;
      }

      // Second check: Iterate through the string to check at each space
      // For adjacent words to be circular:
      // - Character before space (last char of current word)
      // - Must match character after space (first char of next word)
      for (int i = 1; i < n - 1; i++) {
         if (s[i] == ' ') {             // Found a space between words
            if (s[i - 1] != s[i + 1]) { // Compare chars before and after space
               return false;            // If they don't match, sentence isn't circular
            }
         }
      }

      // If we've made it here:
      // 1. First and last characters match
      // 2. All adjacent words have matching last/first characters
      // Therefore, the sentence is circular
      return true;
   }
};
