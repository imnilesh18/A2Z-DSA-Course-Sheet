//Kmp Approach:
class Solution {
    public int strStr(String string, String pattern) {
        if (pattern.isEmpty())
            return 0; // Edge case for empty pattern
        int m = pattern.length(), n = string.length();
        if (m > n)
            return -1; // Edge case where pattern is longer than the string

        // Construct the KMP "partial match" table (also known as "pi" table)
        int[] piTable = new int[m];
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && pattern.charAt(j) != pattern.charAt(i)) {
                j = piTable[j - 1];
            }
            if (pattern.charAt(j) == pattern.charAt(i)) {
                j++;
            }
            piTable[i] = j;
        }

        // Search the pattern in the string using the piTable
        j = 0; // Reset j to 0 for the search process
        for (int i = 0; i < n; i++) {
            while (j > 0 && pattern.charAt(j) != string.charAt(i)) {
                j = piTable[j - 1];
            }
            if (pattern.charAt(j) == string.charAt(i)) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
}

// Brute Force:
class Solution {
    public int strStr(String string, String pattern) {
        int n = string.length(), m = pattern.length();
        for (int i = 0; i < n + 1 - m; i++) {
            int j = 0;
            while (j < m && string.charAt(i + j) == pattern.charAt(j))
                j++;
            if (j == m)
                return i;
        }
        return -1;
    }
}
