/*
 * 1957. Delete Characters to Make Fancy String
 *
 * A fancy string is a string where no three consecutive characters are equal.
 * Given a string s, delete the minimum possible number of characters from s to make it fancy.
 * Return the final string after the deletion. It can be shown that the answer will always be unique.
 *
 * Example 1:
 * Input: s = "leeetcode"
 * Output: "leetcode"
 * Explanation:
 * Remove an 'e' from the first group of 'e's to create "leetcode".
 * No three consecutive characters are equal, so return "leetcode".
 *
 * Example 2:
 * Input: s = "aaabaaaa"
 * Output: "aabaa"
 * Explanation:
 * Remove an 'a' from the first group of 'a's to create "aabaaaa".
 * Remove two 'a's from the second group of 'a's to create "aabaa".
 * No three consecutive characters are equal, so return "aabaa".
 *
 * Example 3:
 * Input: s = "aab"
 * Output: "aab"
 * Explanation: No three consecutive characters are equal, so return "aab".
 *
 * Constraints:
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters
 */

// My Approach:
// T.C : O(n)
// S.C : O(1) // They told to return the answer in string so I'm considering no extra space
class Solution {
public:
   string makeFancyString(string s){
      string result = "";
      int    n      = s.length();

      result.push_back(s[0]);
      if (n >= 2) {
         result.push_back(s[1]);
      }


      for (int i = 2; i < n; i++) {
         if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            continue;
         } else {
            result.push_back(s[i]);
         }
      }
      return result;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   string makeFancyString(string s){
      // Initialize empty result string to build our fancy string
      string result = "";
      int    n      = s.length();

      // Always include the first character since a single character can't violate
      // the fancy string rule
      result.push_back(s[0]);

      // If string length is at least 2, include second character as well
      // since two consecutive same characters are allowed
      if (n >= 2) {
         result.push_back(s[1]);
      }

      // Start checking from third character onwards
      // Core logic: For each character starting at index 2:
      // - If current char matches both previous chars, skip it (avoid three consecutive)
      // - Otherwise, it's safe to include the current char
      for (int i = 2; i < n; i++) {
         // Check if current char would form three consecutive identical chars
         if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            // Skip this char to prevent three consecutive identical chars
            continue;
         } else {
            // Safe to add this char as it won't create three consecutive identical chars
            result.push_back(s[i]);
         }
      }
      return result;
   }
};

/*
 * Time Complexity Analysis:
 * -------------------------
 * Total Time Complexity: O(n)
 * - We iterate through the string exactly once from index 2 to n
 * - Each operation within the loop (comparison and push_back) is O(1)
 * - First two character insertions are O(1)
 *
 * Space Complexity Analysis: O(1) but
 * -------------------------
 * Total Space Complexity: O(n)
 * - We create a new string 'result' that will store the fancy string
 * - In the best case (when string is already fancy), it will store all n characters
 * - In the worst case (many consecutive repeated chars), it will store about n/3 characters
 * - Therefore, space complexity remains O(n)
 *
 * where n is the length of the input string s
 */

// Approach 2:
class Solution {
public:
   string makeFancyString(string s){
      int n = s.length();

      // Initialize result string and add first character
      // since a single character is always valid
      string result = "";

      result.push_back(s[0]);

      // Keep track of consecutive occurrences of current character
      int freq = 1;

      // Iterate through string starting from second character
      for (int i = 1; i < n; i++) {
         // If current character matches the last character in result
         if (s[i] == result.back()) {
            // Increment frequency of consecutive characters
            freq++;
            // Only add the character if it won't create three consecutive chars
            if (freq < 3) {
               result.push_back(s[i]);
            }
         }
         // If current character is different from last character
         else {
            // Add new character and reset frequency to 1
            result.push_back(s[i]);
            freq = 1;
         }
      }
      return result;
   }
};

/*
 * Time Complexity Analysis:
 * -------------------------
 * Total Time Complexity: O(n)
 * - We iterate through the string once from index 1 to n
 * - Each operation in the loop (comparison, push_back, back()) is O(1)
 * - First character insertion is O(1)
 *
 * Space Complexity Analysis:
 * -------------------------
 * Total Space Complexity: O(n)
 * - We create a new string 'result' to store the fancy string
 * - In the best case (string is already fancy), it will store all n characters
 * - In worst case (many consecutive repeated chars), it will store about n/3 characters
 * - Therefore, space complexity remains O(n)
 *
 * Key Differences from Previous Approach:
 * -------------------------------------
 * 1. Uses a frequency counter instead of checking previous two characters
 * 2. More efficient as it only needs to check the last character of result
 * 3. Maintains running count of consecutive characters
 * 4. Only requires one string comparison per iteration instead of two
 *
 * where n is the length of the input string s
 */
