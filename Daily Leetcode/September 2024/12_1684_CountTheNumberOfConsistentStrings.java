/*
 * 1684. Count the Number of Consistent Strings
 * 
 * You are given a string allowed consisting of distinct characters and an array
 * of strings words. A string is consistent if all characters in the string
 * appear in the string allowed.
 * Return the number of consistent strings in the array words.
 * 
 * Example 1:
 * Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
 * Output: 2
 * Explanation: Strings "aaab" and "baa" are consistent since they only contain
 * characters 'a' and 'b'.
 * 
 * Example 2:
 * Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
 * Output: 7
 * Explanation: All strings are consistent.
 * 
 * Example 3:
 * Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
 * Output: 4
 * Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 * 
 * Constraints:
 * 1 <= words.length <= 104
 * 1 <= allowed.length <= 26
 * 1 <= words[i].length <= 10
 * The characters in allowed are distinct.
 * words[i] and allowed contain only lowercase English letters.
 */

// Time Complexity: O(m + n*k)
// Space Complexity: O(1)
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = 0; // 00000000000....0000

        for (char ch : allowed.toCharArray()) {
            mask = mask | (1 << (ch - 'a'));
        }

        int count = 0;

        for (String word : words) {
            boolean allCharPresent = true;

            for (char ch : word.toCharArray()) {
                if (((mask >> (ch - 'a')) & 1) == 0) {
                    allCharPresent = false;
                    break;
                }
            }

            if (allCharPresent) {
                count++;
            }
        }
        return count;
    }
}

// Code with comments for better understanding:
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = 0; // Initialize a bitmask to represent allowed characters (26 bits for 'a' to 'z')

        // Loop through each character in the 'allowed' string and set its corresponding
        // bit in the mask
        for (char ch : allowed.toCharArray()) {
            mask = mask | (1 << (ch - 'a')); // Shift 1 left by the position of the character (relative to 'a') and OR
                                             // it with the current mask
        }

        int count = 0; // Initialize the count of consistent strings

        // Loop through each word in the words array
        for (String word : words) {
            boolean allCharPresent = true; // Assume all characters in the word are present in the allowed set

            // Check each character in the word
            for (char ch : word.toCharArray()) {
                // Right shift the mask by the position of the character (ch - 'a') and AND it
                // with 1
                // If the result is 0, it means the character is not in the allowed set
                if (((mask >> (ch - 'a')) & 1) == 0) {
                    allCharPresent = false; // Mark as false if any character is not allowed
                    break; // No need to check further characters for this word
                }
            }

            // If all characters in the word are allowed, increment the count
            if (allCharPresent) {
                count++;
            }
        }
        return count; // Return the total count of consistent strings
    }
}
