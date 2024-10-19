/*
 * 1545. Find Kth Bit in Nth Binary String
 * 
 * Given two positive integers n and k, the binary string Sn is formed as
 * follows:
 * S1 = "0"
 * Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
 * Where + denotes the concatenation operation, reverse(x) returns the reversed
 * string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1
 * changes to 0).
 * For example, the first four strings in the above sequence are:
 * S1 = "0"
 * S2 = "011"
 * S3 = "0111001"
 * S4 = "011100110110001"
 * Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
 * 
 * Example 1:
 * Input: n = 3, k = 1
 * Output: "0"
 * Explanation: S3 is "0111001".
 * The 1st bit is "0".
 * 
 * Example 2:
 * Input: n = 4, k = 11
 * Output: "1"
 * Explanation: S4 is "011100110110001".
 * The 11th bit is "1".
 * 
 * Constraints:
 * 1 <= n <= 20
 * 1 <= k <= 2^n - 1
 */

// T.C : O(n)
// S.C : O(n)
class Solution {
    public char findKthBit(int n, int k) {
        int length = (1 << n) - 1;

        if (n == 1) {
            return '0';
        }

        if (k < Math.ceil(length / 2.0)) {
            return findKthBit(n - 1, k);
        } else if (k == Math.ceil(length / 2.0)) {
            return '1';
        } else {
            char ch = findKthBit(n - 1, (length - (k - 1)));
            return (ch == '0') ? '1' : '0';
        }
    }
}

// Code with comments for better understanding:
// Time Complexity: O(n) - As we are recursively solving the problem by reducing
// n each time
// Space Complexity: O(n) - Recursive stack space grows proportional to n
class Solution {
    public char findKthBit(int n, int k) {
        // Calculate the total length of the binary string Sn for the given n
        // Formula: (2^n) - 1
        int length = (1 << n) - 1; // Equivalent to (2^n) - 1

        // Base case: If n is 1, the binary string is "0", so return '0'
        if (n == 1) {
            return '0';
        }

        // If k is less than the middle element of the string (length/2), it lies in the
        // first half
        // So we recursively find the k-th bit in the (n-1)th string
        if (k < Math.ceil(length / 2.0)) {
            return findKthBit(n - 1, k); // Recur on the first half of the string
        }
        // If k is exactly the middle element of the string (length/2), return '1' (as
        // per the pattern)
        else if (k == Math.ceil(length / 2.0)) {
            return '1';
        }
        // If k is in the second half, we need to look at the mirrored and inverted
        // value from the first half
        else {
            // Find the mirrored position in the first half using (length - (k - 1))
            char ch = findKthBit(n - 1, (length - (k - 1)));
            // Invert the bit: if it's '0', return '1' and if it's '1', return '0'
            return (ch == '0') ? '1' : '0';
        }
    }
}
