/*
 * 3043. Find the Length of the Longest Common Prefix
 * 
 * You are given two arrays with positive integers arr1 and arr2.
 * A prefix of a positive integer is an integer formed by one or more of its
 * digits, starting from its leftmost digit. For example, 123 is a prefix of the
 * integer 12345, while 234 is not.
 * A common prefix of two integers a and b is an integer c, such that c is a
 * prefix of both a and b. For example, 5655359 and 56554 have a common prefix
 * 565 while 1223 and 43456 do not have a common prefix.
 * You need to find the length of the longest common prefix between all pairs of
 * integers (x, y) such that x belongs to arr1 and y belongs to arr2.
 * Return the length of the longest common prefix among all pairs. If no common
 * prefix exists among them, return 0.
 * 
 * Example 1:
 * Input: arr1 = [1,10,100], arr2 = [1000]
 * Output: 3
 * Explanation: There are 3 pairs (arr1[i], arr2[j]):
 * - The longest common prefix of (1, 1000) is 1.
 * - The longest common prefix of (10, 1000) is 10.
 * - The longest common prefix of (100, 1000) is 100.
 * The longest common prefix is 100 with a length of 3.
 * 
 * Example 2:
 * Input: arr1 = [1,2,3], arr2 = [4,4,4]
 * Output: 0
 * Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]),
 * hence we return 0.
 * Note that common prefixes between elements of the same array do not count.
 * 
 * Constraints:
 * 1 <= arr1.length, arr2.length <= 5 * 104
 * 1 <= arr1[i], arr2[i] <= 108
 */

// Time Complexity: O(n * m * x)
// Space Complexity: O(x)
// TLE:
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        int result = 0; // To store the longest common prefix length

        for (int i = 0; i < arr1.length; i++) {
            char[] charArr1 = Integer.toString(arr1[i]).toCharArray(); // Convert arr1[i] to char array

            for (int j = 0; j < arr2.length; j++) {
                int length = 0; // Length of the current common prefix
                int k = 0; // Index for character comparison

                char[] charArr2 = Integer.toString(arr2[j]).toCharArray(); // Convert arr2[j] to char array

                // Compare each character of both arrays until a mismatch or end of one of the
                // arrays
                while (k < charArr1.length && k < charArr2.length && charArr1[k] == charArr2[k]) {
                    k++;
                    length++;
                }

                // Update the result with the longest prefix found so far
                result = Math.max(result, length);
            }
        }

        return result;
    }
}

// Approach 2 - Brute Force
// T.C : O(m⋅log10​M + n⋅log10​N)
// S.C : O(m⋅log10​M)
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        // Create a HashSet to store the prefixes from arr1
        Set<Integer> st = new HashSet<>();

        // Loop through each number in arr1 to store all its prefixes
        for (int val : arr1) {
            // Example: val = 123
            // Prefixes: 123, 12, 1 will be added to the set
            // Set: {123, 12, 1}

            // Example: val = 12345
            // Prefixes: 12345, 1234, 123 (already present), 12 (already present), 1
            // (already present)
            // Set will now contain: {12345, 1234, 123, 12, 1}

            while (!st.contains(val) && val > 0) {
                st.add(val); // Add the current prefix to the set
                val = val / 10; // Remove the last digit to form the next prefix
            }
        }

        int result = 0; // Initialize result to store the longest common prefix length

        // Loop through each number in arr2 to find the longest common prefix
        for (int num : arr2) {
            // Example: num = 1234, check if it's present in the set or any of its prefixes
            // Keep dividing num by 10 until a prefix is found or num becomes 0
            // If 1234 is present in the set, it will stop here, otherwise, it will check
            // 123, 12, 1, and so on.

            while (!st.contains(num) && num > 0) {
                num = num / 10; // Keep removing digits from num
            }

            // If a valid common prefix is found (num > 0), calculate its length
            if (num > 0) {
                // Calculate the number of digits in the common prefix using log10
                result = Math.max(result, (int) (Math.log10(num) + 1));
                // Example: if num = 123, then log10(123) + 1 = 3, so the prefix length is 3
                // digits
            }
        }

        return result; // Return the longest common prefix length found
    }
}
