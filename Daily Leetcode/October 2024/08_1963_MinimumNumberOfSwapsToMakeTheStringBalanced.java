/*
 * 1963. Minimum Number of Swaps to Make the String Balanced
 * 
 * You are given a 0-indexed string s of even length n. The string consists of
 * exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
 * A string is called balanced if and only if:
 * It is the empty string, or
 * It can be written as AB, where both A and B are balanced strings, or
 * It can be written as [C], where C is a balanced string.
 * You may swap the brackets at any two indices any number of times.
 * Return the minimum number of swaps to make s balanced.
 * 
 * Example 1:
 * Input: s = "][]["
 * Output: 1
 * Explanation: You can make the string balanced by swapping index 0 with index
 * 3.
 * The resulting string is "[[]]".
 * 
 * Example 2:
 * Input: s = "]]][[["
 * Output: 2
 * Explanation: You can do the following to make the string balanced:
 * - Swap index 0 with index 4. s = "[]][][".
 * - Swap index 1 with index 5. s = "[[][]]".
 * The resulting string is "[[][]]".
 * 
 * Example 3:
 * Input: s = "[]"
 * Output: 0
 * Explanation: The string is already balanced.
 * 
 * Constraints:
 * n == s.length
 * 2 <= n <= 106
 * n is even.
 * s[i] is either '[' or ']'.
 * The number of opening brackets '[' equals n / 2, and the number of closing
 * brackets ']' equals n / 2.
 */

// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public int minSwaps(String s) {
        Stack<Character> stack = new Stack<>();

        // Traverse through the string
        for (char ch : s.toCharArray()) {
            if (ch == '[') {
                stack.push(ch); // Push opening brackets to the stack
            } else if (!stack.isEmpty()) {
                stack.pop(); // Pop a matching opening bracket for each closing bracket
            }
        }

        // The remaining elements in the stack are unmatched '[' brackets
        // The number of swaps needed is half the number of unmatched brackets
        return (stack.size() + 1) / 2;
    }
}

// Approach-2 (without using stack)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public int minSwaps(String s) {
        int size = 0;

        // Traverse through the string
        for (char ch : s.toCharArray()) {
            if (ch == '[') {
                size++; // Increment for every '['
            } else if (size != 0) {
                size--; // Decrement if there's a '[' to balance ']'
            }
        }

        // The number of swaps needed is (size + 1) / 2
        return (size + 1) / 2;
    }
}
