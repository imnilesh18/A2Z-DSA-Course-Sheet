/*
 * 1528. Shuffle String
 * 
 * You are given a string s and an integer array indices of the same length. The
 * string s will be shuffled such that the character at the ith position moves
 * to indices[i] in the shuffled string.
 * Return the shuffled string.
 * 
 * Example 1:
 * Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
 * Output: "leetcode"
 * Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
 * 
 * Example 2:
 * Input: s = "abc", indices = [0,1,2]
 * Output: "abc"
 * Explanation: After shuffling, each character remains in its position.
 * 
 * Constraints:
 * s.length == indices.length == n
 * 1 <= n <= 100
 * s consists of only lowercase English letters.
 * 0 <= indices[i] < n
 * All values of indices are unique.
 */

class Solution {
    // Method to restore the string based on the given indices
    public String restoreString(String s, int[] indices) {
        // Create an array of characters to hold the shuffled result
        char[] shuffled = new char[s.length()];

        // Loop through each character in the input string
        for(int i = 0; i < s.length(); i++){
            // Place each character at the correct position as per the indices array
            shuffled[indices[i]] = s.charAt(i);
        }

        // Convert the character array back to a string and return it
        return new String(shuffled);
    }
}
