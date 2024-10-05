/*
 * 567. Permutation in String
 * 
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * Constraints:
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 */

//Approach-3 (Sliding Window) - ACCEPTED
//T.C : O(m+n)
//S.C : O(26)
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) {
            return false;
        }

        int[] s1_freq = new int[26];
        int[] s2_freq = new int[26];

        for (char ch : s1.toCharArray()) {
            s1_freq[ch - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < m) {
            s2_freq[s2.charAt(j) - 'a']++;

            if (j - i + 1 > n) {
                s2_freq[s2.charAt(i) - 'a']--;
                i++;
            }

            if (Arrays.equals(s1_freq, s2_freq)) {
                return true;
            }
            j++;
        }
        return false;
    }
}

// Code with comments for better understanding:
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length(); // Length of string s1 (pattern)
        int m = s2.length(); // Length of string s2 (text)

        // If s1's length is greater than s2's, permutation can't be found
        if (n > m) {
            return false;
        }

        // Frequency arrays to store the count of characters in s1 and the current
        // window in s2
        int[] s1_freq = new int[26]; // For storing the frequency of characters in s1
        int[] s2_freq = new int[26]; // For storing the frequency of characters in the current window of s2

        // Populate the frequency array for s1
        for (char ch : s1.toCharArray()) {
            s1_freq[ch - 'a']++; // Increment the frequency of each character in s1
        }

        int i = 0; // Left pointer for the sliding window
        int j = 0; // Right pointer for the sliding window

        // Start sliding the window over s2
        while (j < m) {
            // Add the current character of s2 to the window's frequency array
            s2_freq[s2.charAt(j) - 'a']++;

            // If the window size exceeds the size of s1, shrink the window from the left
            if (j - i + 1 > n) {
                // Remove the character at the left of the window
                s2_freq[s2.charAt(i) - 'a']--;
                i++; // Move the left pointer
            }

            // If the frequency arrays of s1 and current window of s2 match, it means
            // the current window is a permutation of s1
            if (Arrays.equals(s1_freq, s2_freq)) {
                return true;
            }

            // Move the right pointer to expand the window
            j++;
        }

        // If no permutation of s1 is found in s2, return false
        return false;
    }
}

// T.C : O((m-n) * nlogn)
// S.C : O(n)
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) {
            return false;
        }
        char[] sortedS1 = s1.toCharArray();
        Arrays.sort(sortedS1);
        for (int i = 0; i <= m - n; i++) {
            String subStr = s2.substring(i, i + n);

            char[] sortedsubStr = subStr.toCharArray();
            Arrays.sort(sortedsubStr);

            if (Arrays.equals(sortedS1, sortedsubStr)) {
                return true;
            }
        }
        return false;
    }
}