/*
 * 2696. Minimum String Length After Removing Substrings
 * 
 * You are given a string s consisting only of uppercase English letters.
 * You can apply some operations to this string where, in one operation, you can
 * remove any occurrence of one of the substrings "AB" or "CD" from s.
 * Return the minimum possible length of the resulting string that you can
 * obtain.
 * Note that the string concatenates after removing the substring and could
 * produce new "AB" or "CD" substrings.
 * 
 * Example 1:
 * Input: s = "ABFCACDB"
 * Output: 2
 * Explanation: We can do the following operations:
 * - Remove the substring "ABFCACDB", so s = "FCACDB".
 * - Remove the substring "FCACDB", so s = "FCAB".
 * - Remove the substring "FCAB", so s = "FC".
 * So the resulting length of the string is 2.
 * It can be shown that it is the minimum length that we can obtain.
 * 
 * Example 2:
 * Input: s = "ACBBD"
 * Output: 5
 * Explanation: We cannot do any operations on the string so the length remains
 * the same.
 * 
 * Constraints:
 * 1 <= s.length <= 100
 * s consists only of uppercase English letters.
 */

// Approach-2 (Using stack)
// T.C : O(n)
// S.C : O(n)

class Solution {
    public int minLength(String s) {
        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (st.isEmpty()) {
                st.push(ch);
                continue;
            }
            if ((ch == 'B' && st.peek() == 'A') || (ch == 'D' && st.peek() == 'C')) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.size();
    }
}

// Code with comments for better understanding:
class Solution {
    public int minLength(String s) {
        // We use a stack to track the characters as we process the string.
        Stack<Character> st = new Stack<>();

        // Iterate through each character in the string.
        for (char ch : s.toCharArray()) {
            // If the stack is empty, push the current character.
            if (st.isEmpty()) {
                st.push(ch);
                continue; // Move to the next character.
            }

            // Check if the current character forms a removable pair with the top of the
            // stack.
            // If the current character is 'B' and the top of the stack is 'A', we pop 'A'
            // (remove "AB").
            // Similarly, if the current character is 'D' and the top of the stack is 'C',
            // we pop 'C' (remove "CD").
            if ((ch == 'B' && st.peek() == 'A') || (ch == 'D' && st.peek() == 'C')) {
                st.pop(); // Remove the pair "AB" or "CD".
            } else {
                // If no removable pair is found, push the current character onto the stack.
                st.push(ch);
            }
        }

        // After processing the entire string, the remaining elements in the stack
        // represent the string that cannot be reduced further.
        // The size of the stack is the minimum possible length of the resulting string.
        return st.size();
    }
}

// Approach-3 (Using 2 pointers = i : read, j ; write)
// T.C : O(n)
// S.C : O(1) // Since Java strings are immutable, we cannot truly modify a
// String directly without using any additional space
class Solution {
    public int minLength(String s) {
        int n = s.length();
        int i = 0;
        int j = 1;

        StringBuilder sb = new StringBuilder(s);
        while (j < n) {

            if (i < 0) {
                i++;
                sb.setCharAt(i, sb.charAt(j));
            } else if ((sb.charAt(i) == 'A' && sb.charAt(j) == 'B') || (sb.charAt(i) == 'C' && sb.charAt(j) == 'D')) {
                i--;
            } else {
                i++;
                sb.setCharAt(i, sb.charAt(j));
            }
            j++;
        }
        return i + 1;
    }
}

// or you can use charArray:
class Solution {
    public int minLength(String s) {
        int n = s.length();
        int i = 0;
        int j = 1;

        char[] charS = s.toCharArray();
        while (j < n) {

            if (i < 0) {
                i++;
                charS[i] = charS[j];
            } else if ((charS[i] == 'A' && charS[j] == 'B') || (charS[i] == 'C' && charS[j] == 'D')) {
                i--;
            } else {
                i++;
                charS[i] = charS[j];
            }
            j++;
        }
        return i + 1;
    }
}

// Code with comments for better understanding:
class Solution {
    public int minLength(String s) {
        // Get the length of the input string
        int n = s.length();

        // Initialize two pointers: 'i' will track the last valid position in the
        // modified string,
        // 'j' will be the read pointer traversing through the original string.
        int i = 0; // Write pointer
        int j = 1; // Read pointer

        // Use StringBuilder to handle character changes (though it uses extra space)
        StringBuilder sb = new StringBuilder(s);

        // Traverse the string starting from the second character (j = 1) until the end
        while (j < n) {

            // If 'i' is less than 0 (meaning no valid characters to compare left),
            // reset i to 0 and copy the current character from j to i.
            if (i < 0) {
                i++;
                sb.setCharAt(i, sb.charAt(j)); // Set the current character at the write pointer
            }
            // Check if the current character at 'j' forms "AB" or "CD" with the previous
            // one at 'i'.
            // If it does, "remove" the pair by decrementing 'i' (moving back to "remove"
            // last valid character).
            else if ((sb.charAt(i) == 'A' && sb.charAt(j) == 'B') || (sb.charAt(i) == 'C' && sb.charAt(j) == 'D')) {
                i--; // Effectively "removing" the pair by moving the write pointer back
            }
            // If no matching pair is found, increment the write pointer 'i' and copy the
            // character from 'j' to 'i'.
            else {
                i++; // Move write pointer forward
                sb.setCharAt(i, sb.charAt(j)); // Copy character from 'j' to the write pointer
            }
            j++; // Move read pointer forward
        }

        // 'i + 1' will be the length of the resulting string after all removals
        return i + 1;
    }
}
