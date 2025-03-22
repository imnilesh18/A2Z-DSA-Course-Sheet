/*
 * 91. Decode Ways
 *
 * You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
 *
 * "1" -> 'A'
 *
 * "2" -> 'B'
 *
 * ...
 *
 * "25" -> 'Y'
 *
 * "26" -> 'Z'
 *
 * However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
 *
 * For example, "11106" can be decoded into:
 *
 * "AAJF" with the grouping (1, 1, 10, 6)
 * "KJF" with the grouping (11, 10, 6)
 * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
 * Note: there may be strings that are impossible to decode.
 *
 * Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 * Example 1:
 * Input: s = "12"
 * Output: 2
 * Explanation:
 * "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 * Example 2:
 * Input: s = "226"
 * Output: 3
 * Explanation:
 * "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 * Example 3:
 * Input: s = "06"
 * Output: 0
 * Explanation:
 * "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.
 *
 * Constraints:
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 */

// Approach 1 (Recursion with Memoization): Recursion with Memoization (Top-Down DP) where we recursively compute the number of ways to decode the string starting from index i, using a memoization array to store intermediate results.
// Time Complexity: O(n) - Each index is computed only once.
// Space Complexity: O(n) - For the recursion stack and the memoization array.
class Solution {
public:
    int t[101];     // Memoization array to store results for subproblems

    int solve(int i, string& s, int n) {
        // If result is already computed for index i, return it.
        if (t[i] != -1) {
            return t[i];
        }
        // If reached the end of the string, return 1 as a valid decoding.
        if (i == n) {
            return t[i] = 1;
        }
        // If current character is '0', it cannot be decoded.
        if (s[i] == '0') {
            return t[i] = 0;
        }

        // Decode using one digit.
        int result = solve(i + 1, s, n);

        // Check if two digits form a valid number (10 to 26) and decode using two digits.
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                result += solve(i + 2, s, n);
            }
        }
        // Store the computed result in the memoization array and return it.
        return t[i] = result;
    }
    
    int numDecodings(string s) {
        int n = s.length();

        memset(t, -1, sizeof(t));     // Initialize memoization array with -1
        return solve(0, s, n);
    }
};

/*
 * Dry Run
 * Example: s = "123", n = 3
 * Call: solve(0, "123", 3)
 * s[0] = '1' (not '0'):
 *     result = solve(1, "123", 3)
 *         Call: solve(1, "123", 3)
 *            s[1] = '2' (not '0'):
 *                result = solve(2, "123", 3)
 *                    Call: solve(2, "123", 3)
 *                       s[2] = '3' (not '0'):
 *                           result = solve(3, "123", 3)
 *                               Call: solve(3, "123", 3) -> i == n, returns 1.
 *                       Back in solve(2): result = 1, no two-digit check.
 *                       Returns 1.
 *            Back in solve(1): result = 1, two-digit check "23" valid, so result += solve(3, "123", 3) returns 1.
 *            Total at index 1 = 1 + 1 = 2.
 *            Returns 2.
 * Back in solve(0): result = 2, two-digit check "12" valid, so result += solve(2, "123", 3) returns 1.
 * Total at index 0 = 2 + 1 = 3.
 * Returns 3.
 */

// Approach 2 (Bottom Up): Iterative Dynamic Programming (Bottom-Up) where we fill a dp array from right to left, with dp[i] representing the number of ways to decode the substring starting at index i.
// Time Complexity: O(n) - We traverse the string once.
// Space Complexity: O(n) - Using an extra dp array of size n+1.
class Solution {
public:
    int numDecodings(string s) {
        int         n = s.length();
        vector<int> t(n + 1, 0); // t[i] = ways to decode s from index i to end

        t[n] = 1;                // Base case: an empty string has one valid decoding

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                t[i] = 0;             // '0' cannot be decoded
            } else {
                t[i] = t[i + 1];      // Decode using one digit
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    t[i] += t[i + 2]; // Decode using two digits if valid
                }
            }
        }
        return t[0];     // Return the total number of ways to decode the entire string
    }
};

/*
 * Dry Run
 * Example: s = "123", n = 3, t initially = [0, 0, 0, 1]
 * Iteration:
 * i = 2, s[2] = '3' (not '0'): t[2] = t[3] = 1.
 * i = 1, s[1] = '2' (not '0'): t[1] = t[2] = 1; two-digit "23" valid, so t[1] += t[3] (1) => t[1] becomes 2.
 * i = 0, s[0] = '1' (not '0'): t[0] = t[1] = 2; two-digit "12" valid, so t[0] += t[2] (1) => t[0] becomes 3.
 * Return t[0] = 3.
 */
