/*
 * 139. Word Break
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 */

// Approach: Use recursion with memoization (top-down DP) to try every possible substring starting at each index; if a valid word is found and the rest of the string can be segmented, return true.
// Time Complexity: O(n^2 * k) worst-case, where n is the length of s and k is the average substring extraction cost.
// Space Complexity: O(n) for the recursion stack and memoization array.
class Solution {
public:
    int n;
    unordered_set<string> st;     // Set to store dictionary words for quick lookup.
    int t[301];                   // Fixed-size memoization array to store results for each index.

    // Recursive function to solve the problem starting from index 'idx'.
    bool solve(int idx, string& s) {
        // Base case: if we've reached the end of the string, the segmentation is successful.
        if (idx >= n) {
            return true;
        }

        // Return the stored result if it exists to avoid recomputation.
        if (t[idx] != -1) {
            return t[idx];
        }

        // Check if the remaining substring is a word in the dictionary.
        if (st.find(s.substr(idx)) != st.end()) {
            return t[idx] = true;
        }

        // Try every possible substring starting from the current index.
        for (int l = 1; l <= n - idx; l++) {
            // Extract substring starting from idx with length l.
            string temp = s.substr(idx, l);
            // If the substring is in the dictionary and the remaining string can be segmented, return true.
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = true;
            }
        }

        // If no valid segmentation is found, store and return false.
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t, -1, sizeof(t));      // Initialize memoization array with -1 (unset).
        // Insert all words from the dictionary into the set.
        for (string& word : wordDict) {
            st.insert(word);
        }
        // Start the recursion from index 0.
        return solve(0, s);
    }
};

/*
 * Dry Run:
 * For s = "leetcode" and wordDict = ["leet", "code"]:
 * - n is set to 8; memoization array t[] is initialized with -1.
 * - The dictionary set st becomes {"leet", "code"}.
 * - Call solve(0, s):
 * idx = 0; not at end, t[0] is -1.
 * Check if s.substr(0) i.e. "leetcode" is in dictionary -> false.
 * Try substring of length 1: temp = "l" -> not in dictionary.
 * Try substring of length 2: temp = "le" -> not in dictionary.
 * Try substring of length 3: temp = "lee" -> not in dictionary.
 * Try substring of length 4: temp = "leet" -> found in dictionary.
 *    - Call solve(4, s):
 + idx = 4; not at end, t[4] is -1.
 + Check if s.substr(4) i.e. "code" is in dictionary -> true, so return true.
 + t[4] is set to true.
 * t[0] is set to true.
 * - The function wordBreak returns true, meaning "leetcode" can be segmented as "leet code".
 */
