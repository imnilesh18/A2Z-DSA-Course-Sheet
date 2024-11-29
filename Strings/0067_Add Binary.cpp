// Problem Link: https://leetcode.com/problems/add-binary/description/

/*
 * 67. Add Binary
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 * Constraints:
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 */

/************************************************************ C++ ************************************************/

// T.C: O(n1 + n2) where n1 is length of s1 string and n2 is length of s2 string
// S.C: O(1)
class Solution {
public:
   string addBinary(string& s1, string& s2){
      int    n1 = s1.length();
      int    n2 = s2.length();
      int    i = 0, carry = 0;
      string ans = "";

      while (i < n1 || i < n2 || carry != 0) {
         int x = (i < n1 && s1[n1 - i - 1] == '1') ? 1 : 0; // Get the binary digit from s1
         int y = (i < n2 && s2[n2 - i - 1] == '1') ? 1 : 0; // Get the binary digit from s2

         int sum = x + y + carry;                           // Sum of both digits and carry
         ans   = char((sum % 2) + '0') + ans;               // Prepend the binary digit to the result
         carry = sum / 2;                                   // Update carry for the next iteration
         i++;
      }
      // Remove leading zeros from the result, if any
      while (ans.length() > 1 && ans[0] == '0') {
         ans.erase(0, 1);
      }

      return ans;
   }
};

/************************************************************ JAVA ************************************************/

// T.C: O(n1 + n2) where n1 is length of s1 string and n2 is length of s2 string
// S.C: O(1)
class Solution {
   public String addBinary(String s1, String s2){
      int           n1 = s1.length();
      int           n2 = s2.length();
      int           i = 0, carry = 0;
      StringBuilder ans = new StringBuilder();   // Use StringBuilder for efficient string manipulation

      // Process the binary strings from the least significant digit
      while (i < n1 || i < n2 || carry != 0) {
         int x = (i < n1 && s1.charAt(n1 - i - 1) == '1') ? 1 : 0; // Get the binary digit from s1
         int y = (i < n2 && s2.charAt(n2 - i - 1) == '1') ? 1 : 0; // Get the binary digit from s2

         int sum = x + y + carry;                                  // Sum of both digits and carry
         ans.append(sum % 2);                                      // Append the current binary digit to the result
         carry = sum / 2;                                          // Update carry for the next iteration
         i++;
      }

      // Reverse the result since we built it backwards
      ans.reverse();

      // Remove leading zeros, if any
      while (ans.length() > 1 && ans.charAt(0) == '0') {
         ans.deleteCharAt(0);
      }

      return ans.toString();   // Convert StringBuilder to String
   }
}
