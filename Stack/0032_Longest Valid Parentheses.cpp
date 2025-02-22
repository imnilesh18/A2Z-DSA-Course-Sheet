/*
 * 32. Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 * Example 2:
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 * Example 3:
 * Input: s = ""
 * Output: 0
 *
 * Constraints:
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 */

// Approach 1 (Using Stack): Use a stack to store indices of unmatched parentheses to compute valid substring lengths.
// TC: O(n) - The string is traversed once.
// SC: O(n) - In the worst-case, the stack stores all indices when every character is '('.
class Solution {
public:
   int longestValidParentheses(string s) {
      // Initialize the stack with -1 as a base index.
      stack<int> st;

      st.push(-1);
      int max_len = 0;

      // Traverse through the string.
      for (int i = 0; i < s.length(); i++) {
         if (s[i] == '(') {
            // Push index of '(' onto the stack.
            st.push(i);
         } else {
            // Pop the top element for ')'.
            st.pop();
            if (st.empty()) {
               // If stack is empty, push current index as new base.
               st.push(i);
            } else {
               // Update max_len using the current index minus the top index of the stack.
               max_len = max(max_len, i - st.top());
            }
         }
      }
      return max_len;
   }
};

/*
 * DRY RUN:
 * Input: s = ")()())"
 * Initial stack: [-1]
 * Iteration:
 * i = 0, char = ')': pop => stack becomes empty, then push 0 => stack: [0]
 * i = 1, char = '(': push index 1 => stack: [0, 1]
 * i = 2, char = ')': pop => remove index 1, stack: [0], valid length = 2 - 0 = 2, max_len = 2
 * i = 3, char = '(': push index 3 => stack: [0, 3]
 * i = 4, char = ')': pop => remove index 3, stack: [0], valid length = 4 - 0 = 4, max_len = 4
 * i = 5, char = ')': pop => remove index 0, stack becomes empty, then push 5 => stack: [5]
 * Final max_len = 4
 *
 */

// Approach 2 (Without Stack): Use two-pass scanning (left-to-right and right-to-left) to count matching parentheses without extra space.
// TC: O(n) - Two linear scans of the string.
// SC: O(1) - Only constant extra space is used.
class Solution {
public:
   int longestValidParentheses(string s) {
      int left = 0, right = 0, maxCount = 0;

      // Left-to-right scan.
      for (int i = 0; i < s.length(); i++) {
         if (s[i] == '(') {
            left++;
         } else {
            right++;
         }

         if (left == right) {
            maxCount = max(maxCount, 2 * left);
         } else if (right > left) {
            left = right = 0;          // Reset counters when invalid.
         }
      }

      // Right-to-left scan.
      left = right = 0;
      for (int i = s.length() - 1; i >= 0; i--) {
         if (s[i] == ')') {
            right++;
         } else {
            left++;
         }

         if (left == right) {
            maxCount = max(maxCount, 2 * left);
         } else if (left > right) {
            left = right = 0;          // Reset counters when invalid.
         }
      }
      return maxCount;
   }
};

/*
 * DRY RUN (Left-to-Right):
 * Input: s = ")()())"
 * Initialize left = 0, right = 0, maxCount = 0.
 * i = 0, char = ')': right becomes 1, left = 0; right > left so reset left and right to 0.
 * i = 1, char = '(': left becomes 1, right = 0.
 * i = 2, char = ')': right becomes 1, left = 1; left == right so valid length = 2, maxCount = 2.
 * i = 3, char = '(': left becomes 2, right = 1.
 * i = 4, char = ')': right becomes 2, left = 2; left == right so valid length = 4, maxCount = 4.
 * i = 5, char = ')': right becomes 3, left = 2; right > left so reset left and right to 0.
 * After left-to-right, maxCount = 4.
 *
 * DRY RUN (Right-to-Left):
 * Reset left = 0, right = 0.
 * i = 5, char = ')': right becomes 1, left = 0.
 * i = 4, char = ')': right becomes 2, left = 0.
 * i = 3, char = '(': left becomes 1, right = 2.
 * i = 2, char = ')': right becomes 3, left = 1.
 * i = 1, char = '(': left becomes 2, right = 3.
 * i = 0, char = ')': right becomes 4, left = 2.
 * No further update since counts never matched; maxCount remains 4.
 * Final maxCount = 4
 *
 */
