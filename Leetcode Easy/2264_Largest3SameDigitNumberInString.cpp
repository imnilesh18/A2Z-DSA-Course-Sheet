/*
 * 2264. Largest 3-Same-Digit Number in String
 *
 * You are given a string num representing a large integer. An integer is good if it meets the following conditions:
 * It is a substring of num with length 3.
 * It consists of only one unique digit.
 * Return the maximum good integer as a string or an empty string "" if no such integer exists.
 * Note:
 * A substring is a contiguous sequence of characters within a string.
 * There may be leading zeroes in num or a good integer.
 *
 * Example 1:
 * Input: num = "6777133339"
 * Output: "777"
 * Explanation: There are two distinct good integers: "777" and "333".
 * "777" is the largest, so we return "777".
 *
 * Example 2:
 * Input: num = "2300019"
 * Output: "000"
 * Explanation: "000" is the only good integer.
 *
 * Example 3:
 * Input: num = "42352338"
 * Output: ""
 * Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 *
 * Constraints:
 * 3 <= num.length <= 1000
 * num only consists of digits.
 */

class Solution {
public:
   string largestGoodInteger(string num){
      int n = num.length();

      char maxChar = ' ';

      for (int i = 2; i < n; i++) {
         if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
            maxChar = max(maxChar, num[i]);
         }
      }

      if (maxChar == ' ') {
         return "";
      }

      return string(3, maxChar);
   }
};

class Solution {
public:
   string largestGoodInteger(string num){
      int n = num.length();

      // maxChar keeps track of the largest digit that appears three consecutive times
      // Initialize with space character to handle case when no good integer exists
      char maxChar = ' ';

      // Iterate through the string starting from index 2
      // This allows us to check current and previous two characters
      for (int i = 2; i < n; i++) {
         // Check if current digit and previous two digits are same
         // This identifies a substring of length 3 with same digits
         if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
            // Update maxChar if current digit is larger
            // This ensures we find the largest good integer
            maxChar = max(maxChar, num[i]);
         }
      }

      // If maxChar is still space, no good integer was found
      if (maxChar == ' ') {
         return "";
      }

      // Create and return a string of length 3 with maxChar
      // Example: if maxChar is '7', returns "777"
      return string(3, maxChar);
   }
};

/*
 * Intuition:
 * 1. A good integer is a substring of length 3 where all digits are same
 * 2. We need to find the largest such substring
 *
 * Approach:
 * 1. Use sliding window of size 3 to check consecutive characters
 * 2. Keep track of largest digit that appears three times consecutively
 * 3. Finally construct string with the largest digit found
 *
 * Time Complexity: O(n) where n is length of input string
 * Space Complexity: O(1) as we only use constant extra space
 */
