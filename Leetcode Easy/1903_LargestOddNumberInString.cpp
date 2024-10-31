/*
 * 1903. Largest Odd Number in String
 *
 * You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
 *
 * A substring is a contiguous sequence of characters within a string.
 *
 * Example 1:
 * Input: num = "52"
 * Output: "5"
 * Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
 *
 * Example 2:
 * Input: num = "4206"
 * Output: ""
 * Explanation: There are no odd numbers in "4206".
 *
 * Example 3:
 * Input: num = "35427"
 * Output: "35427"
 * Explanation: "35427" is already an odd number.
 *
 * Constraints:
 * 1 <= num.length <= 10^5
 * num only consists of digits and does not contain any leading zeros.
 */

class Solution {
public:
   string largestOddNumber(string num){
      int n = num.length();

      for (int i = n - 1; i >= 0; i--) {
         if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
         }
      }

      return "";
   }
};

// Code with comments for better understanding:
class Solution {
public:
   string largestOddNumber(string num){
      int n = num.length();

      // We traverse from right to left
      // Intuition: for a number to be odd, its LAST digit must be odd
      // So find the rightmost odd digit and include all digits to its left
      for (int i = n - 1; i >= 0; i--) {
         // Convert char to integer by subtracting '0'
         // Example: '5' - '0' = 5
         // Then check if this digit is odd
         if ((num[i] - '0') % 2 != 0) {
            // Found an odd digit!
            // Return substring from index 0 to i (inclusive)
            // Since these digits form the largest possible odd number
            return num.substr(0, i + 1);
         }
      }

      // No odd digits found in entire string
      return "";
   }
};

/*
 * Intuition:
 * 1. Key insight: A number is odd if and ONLY if its last digit is odd
 *
 * 2. Therefore:
 * - We don't need to check all possible substrings
 * - We just need to find the rightmost odd digit
 * - All digits to its left will give us largest possible number
 *
 * 3. Example: "35427"
 * - Check 7: odd! Return "35427"
 * - Don't need to check other digits as this is largest possible
 *
 * 4. Example: "52"
 * - Check 2: even
 * - Check 5: odd! Return "5"
 *
 * 5. Example: "4206"
 * - Check digits from right: 6,0,2,4
 * - All even, so return ""
 *
 * Time: O(n) - at worst check all digits
 * Space: O(1) - excluding output string
 *
 * Note: This problem tests understanding that:
 * 1. Leftmost digits contribute most to number's value
 * 2. Only last digit determines if number is odd
 */
