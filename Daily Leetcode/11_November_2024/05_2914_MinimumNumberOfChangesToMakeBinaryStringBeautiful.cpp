/*
 * 2914. Minimum Number of Changes to Make Binary String Beautiful
 *
 * You are given a 0-indexed binary string s having an even length.
 * A string is beautiful if it's possible to partition it into one or more substrings such that:
 * Each substring has an even length.
 * Each substring contains only 1's or only 0's.
 * You can change any character in s to 0 or 1.
 * Return the minimum number of changes required to make the string s beautiful.
 *
 * Example 1:
 * Input: s = "1001"
 * Output: 2
 * Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
 * It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
 * It can be proven that 2 is the minimum number of changes needed to make the string beautiful.
 *
 * Example 2:
 * Input: s = "10"
 * Output: 1
 * Explanation: We change s[1] to 1 to get string "11".
 * It can be seen that the string "11" is beautiful because we can partition it into "11".
 * It can be proven that 1 is the minimum number of changes needed to make the string beautiful.
 *
 * Example 3:
 * Input: s = "0000"
 * Output: 0
 * Explanation: We don't need to make any changes as the string "0000" is beautiful already.
 *
 * Constraints:
 * 2 <= s.length <= 10^5
 * s has an even length.
 * s[i] is either '0' or '1'.
 */

// Approach 1:
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   int minChanges(string s){
      int n = s.length();

      char ch      = s[0];
      int  count   = 0;
      int  changes = 0;

      for (int i = 0; i < n; i++) {
         if (s[i] == ch) {
            count++;
            continue;
         }

         if (count % 2 == 0) {
            count = 1;
         } else {
            changes++;
            count = 0;
         }
         ch = s[i];
      }
      return changes;
   }
};

// Approach 2:
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   int minChanges(string s){
      int n = s.length();

      int changes = 0;

      for (int i = 0; i < n; i += 2) {
         if (s[i] != s[i + 1]) {
            changes++;
         }
      }

      return changes;
   }
};

// Code with comments of better understanding:

// Approach 1:
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   int minChanges(string s){
      int n = s.length();

      // Keep track of current character we're counting
      char ch = s[0];
      // Count consecutive occurrences of current character
      int count = 0;
      // Track minimum changes needed
      int changes = 0;

      // Intuition: Process string character by character
      // Try to form even-length substrings of same character
      for (int i = 0; i < n; i++) {
         // If current char matches what we're counting
         if (s[i] == ch) {
            count++;
            continue;
         }

         // If we've counted an even number of characters
         // We can start a new substring with current character
         if (count % 2 == 0) {
            count = 1;      // Reset count for new character
         }
         // If we've counted an odd number
         // We need to change current character to match previous ones
         else {
            changes++;  // Increment changes needed
            count = 0;  // Reset count as we're forcing this char to match previous
         }
         ch = s[i];     // Update character we're tracking
      }
      return changes;
   }
};

// Approach 2:
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   int minChanges(string s){
      int n       = s.length();
      int changes = 0;

      // Intuition: Process string in pairs of characters (i, i+1)
      // since each substring must have even length

      // Iterate through string taking 2 characters at a time
      // i.e., checking positions (0,1), (2,3), (4,5), etc.
      for (int i = 0; i < n; i += 2) {
         // If characters in a pair don't match
         // we need to change one of them to match the other
         // (it doesn't matter which one we change)
         if (s[i] != s[i + 1]) {
            changes++;
         }
      }

      return changes;
   }
};

/*
 * Since the problem requires:
 *
 * Each substring must have even length
 * Each substring must contain only 1's or only 0 's
 *
 * The optimal solution is to:
 * Process the string in pairs of characters
 * Each pair must be either "00" or "11" to satisfy the conditions
 * If any pair has different characters (e.g., "01" or "10"), we need one change
 *
 *
 * Why this works:
 * You can't have substrings longer than 2 characters that would reduce the number of changes
 * If you tried to make longer substrings, you 'd still need the same number of changes
 * The minimum changes will always be the number of mismatched pairs
 *
 * Advantages of this solution:
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Much simpler to understand and implement
 * Less prone to edge cases
 * More direct mapping to the problem requirements
 *
 *
 * This solution essentially recognizes that the optimal partitioning is always to use length-2 substrings, which greatly simplifies the problem.
 */
