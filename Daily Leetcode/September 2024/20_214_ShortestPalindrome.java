/*
 * 214. Shortest Palindrome
 * 
 * You are given a string s. You can convert s to a palindrome by adding
 * characters in front of it.
 * Return the shortest palindrome you can find by performing this
 * transformation.
 * 
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 * 
 * Constraints:
 * 0 <= s.length <= 5 * 104
 * s consists of lowercase English letters only.
 */

//Approach (Using simple substring check for Prefix and Suffix)
//T.C : O(n^2)
//S.C : O(n)
class Solution {

    public String shortestPalindrome(String s) {
        int length = s.length();
        String reversedString = new StringBuilder(s).reverse().toString();

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < length; i++) {
            if (
                s.substring(0, length - i).equals(reversedString.substring(i))
            ) {
                return new StringBuilder(reversedString.substring(0, i))
                    .append(s)
                    .toString();
            }
        }
        return "";
    }
}