/*
 * 394. Decode String
 *
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 * You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
 * The test cases are generated so that the length of the output will never exceed 105.
 *
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 * Constraints:
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 */

// Approach: Use two stacks (one for numbers and one for strings) to iteratively build the decoded string without performing unnecessary reversals.
// TC: O(n) - Each character in the string is processed once.
// SC: O(n) - In the worst case, the stacks store a significant portion of the input.
class Solution {
public:
   string decodeString(string s) {
      stack<int>    numStack;           // Stack to store multipliers.
      stack<string> strStack;           // Stack to store the strings built so far.
      string        current;            // Current string being built.
      int           k = 0;              // Current multiplier.

      for (char c : s) {
         if (isdigit(c)) {
            // Build the multiplier k (handles multiple digits).
            k = k * 10 + (c - '0');
         } else if (c == '[') {
            // Push the current multiplier and string onto their stacks.
            numStack.push(k);
            strStack.push(current);
            // Reset k and current for the new substring.
            k       = 0;
            current = "";
         } else if (c == ']') {
            // Pop the last multiplier and previous string.
            int repeatTimes = numStack.top();
            numStack.pop();
            string decoded = strStack.top();
            strStack.pop();
            // Append the current substring repeated repeatTimes times.
            while (repeatTimes--) {
               decoded += current;
            }
            current = decoded;
         } else {
            // Append the current character to the current substring.
            current.push_back(c);
         }
      }
      return current;
   }
};

/*
 * Dry Run:
 * Example: s = "3[a2[c]]"
 *
 * Iteration 1: c = '3'
 *   - It's a digit, update k: k = 3.
 *
 * Iteration 2: c = '['
 *   - Push k (3) onto numStack, push current (empty) onto strStack.
 *   - Reset k to 0 and current to "".
 *
 * Iteration 3: c = 'a'
 *   - Append 'a' to current, current = "a".
 *
 * Iteration 4: c = '2'
 *   - It's a digit, update k: k = 2.
 *
 * Iteration 5: c = '['
 *   - Push k (2) onto numStack, push current ("a") onto strStack.
 *   - Reset k to 0 and current to "".
 *
 * Iteration 6: c = 'c'
 *   - Append 'c' to current, current = "c".
 *
 * Iteration 7: c = ']'
 *   - Pop numStack (2) and strStack ("a").
 *   - Repeat current ("c") 2 times: "cc".
 *   - Set current = "a" + "cc" = "acc".
 *
 * Iteration 8: c = ']'
 *   - Pop numStack (3) and strStack (empty string).
 *   - Repeat current ("acc") 3 times: "accaccacc".
 *   - Set current = "accaccacc".
 *
 * Final output: "accaccacc"
 */
