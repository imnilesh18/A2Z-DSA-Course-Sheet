/*
 * 3304. Find the K-th Character in String Game I
 * 
 * Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 * You are given a positive integer k.
 * Now Bob will ask Alice to perform the following operation forever:
 * Generate a new string by changing each character in word to its next
 * character in the English alphabet, and append it to the original word.
 * For example, performing the operation on "c" generates "cd" and performing
 * the operation on "zb" generates "zbac".
 * Return the value of the kth character in word, after enough operations have
 * been done for word to have at least k characters.
 * Note that the character 'z' can be changed to 'a' in the operation.
 * 
 * Example 1:
 * Input: k = 5
 * Output: "b"
 * Explanation:
 * Initially, word = "a". We need to do the operation three times:
 * Generated string is "b", word becomes "ab".
 * Generated string is "bc", word becomes "abbc".
 * Generated string is "bccd", word becomes "abbcbccd".
 * 
 * Example 2:
 * Input: k = 10
 * Output: "c"
 * 
 * Constraints:
 * 1 <= k <= 500
 */

 public class Solution {
    public char kthCharacter(int k) {
        String word = "a";

        // Continue the operation until the length of the word is at least k
        while (word.length() < k) {
            String newString = "";
            // Generate a new string by changing each character in word to its next character
            for (int i = 0; i < word.length(); i++) {
                char nextChar = (char) (word.charAt(i) + 1);
                if (nextChar > 'z') { // Wrap around if the character goes beyond 'z'
                    nextChar = 'a';
                }
                newString += nextChar;
            }
            // Append the new string to the original word
            word += newString;
        }

        // Return the k-th character (0-based index)
        return word.charAt(k - 1);
    }
}