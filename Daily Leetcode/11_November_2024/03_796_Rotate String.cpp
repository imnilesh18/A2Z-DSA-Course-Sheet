/*
 * 796. Rotate String
 *
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 *
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 *
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 */

// Approach 1:
// T.C : O(n²)
// S.C : O(1)

class Solution {
public:
   bool rotateString(string s, string goal){
      int m = s.length();
      int n = goal.length();

      if (m != n) {
         return false;
      }

      for (int count = 1; count <= m; count++) {
         rotate(begin(s), begin(s) + 1, end(s));

         if (s == goal) {
            return true;
         }
      }

      return false;
   }
};

// Approach 2:
// T.C : O(n)
// S.C : O(2n) or O(n)

class Solution {
public:
   bool rotateString(string s, string goal){
      int m = s.length();
      int n = goal.length();

      if (m != n) {
         return false;
      }

      if ((s + s).find(goal) != string::npos) {
         return true;
      }

      return false;
   }
};

// Code with comments for better understanding:

/*
 * 796. Rotate String
 *
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 */

// Approach 1: Brute Force with built-in rotation
// Time Complexity: O(n²) where n is the length of string
// Space Complexity: O(1) as we only use constant extra space

class Solution {
public:
   bool rotateString(string s, string goal){
      // Get lengths of both strings
      int m = s.length();
      int n = goal.length();

      // If lengths are different, rotation is impossible
      if (m != n) {
         return false;
      }

      // Try all possible rotations (maximum n rotations needed)
      // For each rotation:
      // 1. Move first character to the end
      // 2. Check if rotated string matches the goal
      for (int count = 1; count <= m; count++) {
         // Use STL rotate function to shift first character to the end
         // rotate(first, middle, last) rotates the range [first, last)
         // such that middle becomes the first element
         rotate(begin(s), begin(s) + 1, end(s));

         // After each rotation, check if we've achieved the goal string
         if (s == goal) {
            return true;
         }
      }

      // If no rotation matches, return false
      return false;
   }
};

/*
 * Intuition:
 * 1. For strings to be rotations of each other, they must first be of same length
 * 2. We can try each possible rotation by moving the first character to the end
 * 3. After each rotation, we check if we get the goal string
 * 4. If after all possible rotations (n rotations for length n), we don't get
 * the goal string, then it's impossible to achieve the goal through rotations
 *
 * Example:
 * s = "abcde", goal = "cdeab"
 * Rotations:
 * 1st: "bcdea"
 * 2nd: "cdeab" (matches goal!) -> return true
 */


// Approach 2: String Concatenation and Find
// Time Complexity: O(n) where n is the length of string
// Space Complexity: O(n) as we create a new string of length 2n

class Solution {
public:
   bool rotateString(string s, string goal){
      // Get lengths of both strings
      int m = s.length();
      int n = goal.length();

      // If lengths are different, rotation is impossible
      if (m != n) {
         return false;
      }

      /* Key Intuition:
       * 1. If we concatenate s with itself, it will contain all possible rotations
       * 2. Example: s = "abcde", s + s = "abcdeabcde"
       * 3. All rotations of s will be substrings of s + s:
       *    - "abcde" (original)
       *    - "bcdea" (1 rotation)
       *    - "cdeab" (2 rotations)
       *    - "deabc" (3 rotations)
       *    - "eabcd" (4 rotations)
       */

      // Check if goal is a substring of s + s using find()
      // find() returns string::npos if substring is not found
      if ((s + s).find(goal) != string::npos) {
         return true;
      }

      return false;
   }
};

/*
 * Example walkthrough:
 * s = "abcde", goal = "cdeab"
 *
 * 1. Concatenate s with itself:
 * s + s = "abcdeabcde"
 *
 * 2. Now check if goal "cdeab" is a substring of "abcdeabcde"
 * "abcdeabcde"
 *    "cdeab"    <- found! return true
 *
 * Note: This approach is more efficient than the previous one:
 * 1. Time complexity is O(n) instead of O(n²)
 * 2. trade-off is the extra space needed for concatenated string
 * 3. string::find() uses efficient string matching algorithms internally
 */
