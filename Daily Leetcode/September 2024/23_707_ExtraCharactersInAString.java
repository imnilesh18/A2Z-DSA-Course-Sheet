/*
 * 707. Extra Characters in a String
 * 
 * You are given a 0-indexed string s and a dictionary of words dictionary. You
 * have to break s into one or more non-overlapping substrings such that each
 * substring is present in dictionary. There may be some extra characters in s
 * which are not present in any of the substrings.
 * Return the minimum number of extra characters left over if you break up s
 * optimally.
 * 
 * Example 1:
 * Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
 * Output: 1
 * Explanation: We can break s in two substrings: "leet" from index 0 to 3 and
 * "code" from index 5 to 8. There is only 1 unused character (at index 4), so
 * we return 1.
 * 
 * Example 2:
 * Input: s = "sayhelloworld", dictionary = ["hello","world"]
 * Output: 3
 * Explanation: We can break s in two substrings: "hello" from index 3 to 7 and
 * "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in
 * any substring and thus are considered as extra characters. Hence, we return
 * 3.
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 50
 * 1 <= dictionary.length <= 50
 * 1 <= dictionary[i].length <= 50
 * dictionary[i] and s consists of only lowercase English letters
 * dictionary contains distinct words
 */

class Solution {
    public int minExtraChar(String s, String[] dict) {
        int n = s.length(); // Length of the string 's'

        // Store dictionary words in a set for quick lookup
        Set<String> st = new HashSet<>(Arrays.asList(dict));

        // DP array to store minimum extra characters from index i to the end
        int[] t = new int[n + 1]; // Initialize DP array

        // Traverse the string backwards
        for (int i = n - 1; i >= 0; i--) {
            t[i] = 1 + t[i + 1]; // Assume the character at index i is extra

            // Check all substrings starting from index i
            for (int j = i; j < n; j++) {
                String curr = s.substring(i, j + 1); // Get substring s[i...j]
                if (st.contains(curr)) { // If the substring is in the dictionary
                    t[i] = Math.min(t[i], t[j + 1]); // Update the DP array
                }
            }
        }
        return t[0]; // The result is the minimum extra characters for the whole string
    }
}
