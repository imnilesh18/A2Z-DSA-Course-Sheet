/*
 * Search Pattern (KMP-Algorithm)
 * Difficulty: MediumAccuracy: 45.04%Submissions: 64K+Points: 4
 * Given two strings, one is a text string, txt and other is a pattern string,
 * pat. The task is to print the indexes of all the occurences of pattern string
 * in the text string. Use one-based indexing while returning the indices.
 * Note: Return an empty list incase of no occurences of pattern. Driver will
 * print -1 in this case.
 * 
 * Example 1:
 * Input:
 * txt = "geeksforgeeks"
 * pat = "geek"
 * Output:
 * 1 9
 * Explanation:
 * The string "geek" occurs twice in txt, one starts are index 1 and the other
 * at index 9.
 * 
 * Example 2:
 * Input:
 * txt = "abesdu"
 * pat = "edu"
 * Output: -1
 * Explanation:
 * There's not substring "edu" present in txt.
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the
 * function search() which takes the string txt and the string pat as inputs and
 * returns an array denoting the start indices (1-based) of substring pat in the
 * string txt.
 * 
 * Expected Time Complexity: O(|txt|).
 * Expected Auxiliary Space: O(|txt|).
 * 
 * Constraints:
 * 1 ≤ |txt| ≤ 106
 * 1 ≤ |pat| < |S|
 * Both the strings consists of lowercase English alphabets.
 * 
 */

class Solution {
    // Method to compute the Longest Prefix Suffix (LPS) array
    void computeLPS(String pat, int[] LPS, int M) {
        int len = 0;
        LPS[0] = 0; // LPS[0] is always 0

        int i = 1;
        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1]; // Backtrack len to previous LPS position
                } else {
                    LPS[i] = 0; // If no match, set LPS[i] to 0
                    i++;
                }
            }
        }
    }

    // Method to search for pattern in text using KMP algorithm
    ArrayList<Integer> search(String pat, String txt) {
        ArrayList<Integer> result = new ArrayList<>();
        int N = txt.length();
        int M = pat.length();

        // Create LPS array and preprocess the pattern
        int[] LPS = new int[M];
        computeLPS(pat, LPS, M);

        int i = 0; // Index for txt[]
        int j = 0; // Index for pat[]

        while (i < N) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            }

            if (j == M) {
                // Pattern found, add the starting index (1-based index)
                result.add(i - j + 1);
                j = LPS[j - 1]; // Get the next position from LPS array
            } else if (i < N && txt.charAt(i) != pat.charAt(j)) {
                // Mismatch after j matches
                if (j != 0) {
                    j = LPS[j - 1]; // Fall back to the previous LPS index
                } else {
                    i++; // If no matches, just move to the next character in txt
                }
            }
        }
        return result;
    }
}