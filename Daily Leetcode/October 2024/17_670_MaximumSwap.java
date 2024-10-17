/*
 * 670. Maximum Swap
 * 
 * You are given an integer num. You can swap two digits at most once to get the
 * maximum valued number.
 * Return the maximum valued number you can get.
 * 
 * Example 1:
 * Input: num = 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * Example 2:
 * Input: num = 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * Constraints:
 * 0 <= num <= 10^8
 */

// Approach 1: (using space to store maxRight indices)
// T.C : O(N)
// S.C : O(N)
class Solution {
    void swap(int i1, int i2, char[] s) {
        char temp = s[i1];
        s[i1] = s[i2];
        s[i2] = temp;
    }

    public int maximumSwap(int num) {

        String S = String.valueOf(num);
        char[] s = S.toCharArray();
        int n = s.length;

        int[] maxRight = new int[n];
        maxRight[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int maxRightIdx = maxRight[i + 1];
            int maxRightElement = s[maxRightIdx] - '0';

            maxRight[i] = (s[i] - '0') > maxRightElement ? i : maxRightIdx;

        }

        for (int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx] - '0';

            if ((s[i] - '0') < maxRightElement) {
                swap(i, maxRightIdx, s);
                return Integer.parseInt(new String(s));
            }
        }

        return num;
    }
}

// Code with comments for better understanding:
// Approach 1: (using space to store maxRight indices)
// T.C : O(N)
// S.C : O(N)

class Solution {

    // Swap method to exchange the characters at two given indices in the char array
    void swap(int i1, int i2, char[] s) {
        char temp = s[i1];
        s[i1] = s[i2];
        s[i2] = temp;
    }

    public int maximumSwap(int num) {

        // Convert the integer 'num' to a String, then to a char array for manipulation
        String S = String.valueOf(num);
        char[] s = S.toCharArray(); // Convert the string representation of 'num' to a char array
        int n = s.length; // Store the length of the char array

        // maxRight[i] will store the index of the maximum element to the right of the
        // current index i (including i)
        int[] maxRight = new int[n];
        maxRight[n - 1] = n - 1; // The last element is the maximum for itself (base case)

        // Traverse the array from right to left and fill the maxRight array
        for (int i = n - 2; i >= 0; i--) {
            int maxRightIdx = maxRight[i + 1]; // Get the index of the maximum element to the right of i
            int maxRightElement = s[maxRightIdx] - '0'; // Convert the character at maxRightIdx to an integer

            // Update maxRight[i] with the index of the larger element between s[i] and
            // maxRight[i+1]
            maxRight[i] = (s[i] - '0') > maxRightElement ? i : maxRightIdx;
        }

        // Traverse the array again to find the first position where a swap would result
        // in a larger number
        for (int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i]; // Get the index of the maximum element to the right of i
            int maxRightElement = s[maxRightIdx] - '0'; // Convert the character at maxRightIdx to an integer

            // If the current digit is smaller than the maximum digit to the right, swap
            // them
            if ((s[i] - '0') < maxRightElement) {
                swap(i, maxRightIdx, s); // Swap the current digit with the maximum right digit

                // Convert the modified char array back to a string and then parse it as an
                // integer to return the result
                return Integer.parseInt(new String(s));
            }
        }

        // If no swap was made, return the original number as no larger number can be
        // formed
        return num;
    }
}

// Approach-2 (using constant space)
// T.C : O(n)
// S.C : O(1)

class Solution {
    void swap(int i1, int i2, char[] s) {
        char temp = s[i1];
        s[i1] = s[i2];
        s[i2] = temp;
    }

    public int maximumSwap(int num) {

        String S = String.valueOf(num);
        char[] s = S.toCharArray();
        int n = s.length;

        int[] maxRight = new int[10];

        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }

        for (int i = 0; i < n; i++) {
            int currDigit = s[i] - '0';

            for (int digit = 9; digit > currDigit; digit--) {
                if (maxRight[digit] > i) {
                    swap(i, maxRight[digit], s);
                    return Integer.parseInt(new String(s));
                }
            }
        }
        return num;
    }
}

// Code with comments for better understanding:
// Approach-2 (using constant space)
// T.C : O(n)
// S.C : O(1)

class Solution {
    // Swap method to exchange the characters at two given indices in the char array
    void swap(int i1, int i2, char[] s) {
        char temp = s[i1]; // Store the character at index i1 temporarily
        s[i1] = s[i2]; // Assign the character at index i2 to index i1
        s[i2] = temp; // Assign the temporary character (from i1) to index i2
    }

    public int maximumSwap(int num) {
        // Convert the integer 'num' to a String, then to a char array for manipulation
        String S = String.valueOf(num);
        char[] s = S.toCharArray(); // Convert the string representation of 'num' to a char array
        int n = s.length; // Store the length of the char array

        // Array to store the last occurrence of each digit (0-9) in the number
        int[] maxRight = new int[10]; // Index 0 to 9 represent digits 0 to 9

        // Populate the maxRight array with the last seen index of each digit
        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0'; // Convert the current character to an integer (digit)
            maxRight[idx] = i; // Store the index of the last occurrence of this digit
        }

        // Traverse the number from left to right to find the first digit that can be
        // swapped
        for (int i = 0; i < n; i++) {
            int currDigit = s[i] - '0'; // Convert the current character to an integer (digit)

            // Check if there is a larger digit (9 to currDigit+1) that appears after the
            // current index
            for (int digit = 9; digit > currDigit; digit--) {
                // If the larger digit exists after the current digit's position, swap them
                if (maxRight[digit] > i) {
                    swap(i, maxRight[digit], s); // Swap current digit with the larger one found
                    // Convert the modified char array back to a string and then parse it as an
                    // integer
                    return Integer.parseInt(new String(s)); // Return the new maximum number after the swap
                }
            }
        }

        // If no swap is performed, return the original number as no larger number can
        // be formed
        return num;
    }
}
