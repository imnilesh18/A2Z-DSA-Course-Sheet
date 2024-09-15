/*
 * 1371. Find the Longest Substring Containing Vowels in Even Counts
 * 
 * Given the string s, return the size of the longest substring containing each
 * vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must
 * appear an even number of times.
 * 
 * Example 1:
 * Input: s = "eleetminicoworoep"
 * Output: 13
 * Explanation: The longest substring is "leetminicowor" which contains two each
 * of the vowels: e, i and o and zero of the vowels: a and u.
 * 
 * Example 2:
 * Input: s = "leetcodeisgreat"
 * Output: 5
 * Explanation: The longest substring is "leetc" which contains two e's.
 * 
 * Example 3:
 * Input: s = "bcbcbc"
 * Output: 6
 * Explanation: In this case, the given string "bcbcbc" is the longest because
 * all vowels: a, e, i, o and u appear zero times.
 * 
 * Constraints:
 * 1 <= s.length <= 5 x 10^5
 * s contains only lowercase English letters.
 */

//Approach-1 (Using map to store states)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<String, Integer> mpp = new HashMap<>();

        // Initialize an array to track the count of each vowel
        int[] vowelCount = new int[5]; // Count of 'a', 'e', 'i', 'o', 'u'

        String currentState = "00000"; // Initial state where all vowels have even counts
        mpp.put(currentState, -1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Update count for the vowel encountered
            if (s.charAt(i) == 'a')
                vowelCount[0] = (vowelCount[0] + 1) % 2;
            else if (s.charAt(i) == 'e')
                vowelCount[1] = (vowelCount[1] + 1) % 2;
            else if (s.charAt(i) == 'i')
                vowelCount[2] = (vowelCount[2] + 1) % 2;
            else if (s.charAt(i) == 'o')
                vowelCount[3] = (vowelCount[3] + 1) % 2;
            else if (s.charAt(i) == 'u')
                vowelCount[4] = (vowelCount[4] + 1) % 2;

            // Create a string representing the current parity state of vowels
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += vowelCount[j];
            }

            // Check if we've seen this state before
            if (mpp.containsKey(currentState)) {
                // Calculate the length of the substring
                maxLength = Math.max(maxLength, i - mpp.get(currentState));
            } else {
                // Store the first occurrence of this state
                mpp.put(currentState, i);
            }
        }

        return maxLength;
    }
}

// Approach-2 (Using map to store states and using XOR to make states)
// T.C : O(n)
// S.C ; O(1):
class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<String, Integer> mpp = new HashMap<>();

        // Initialize an array to track the count of each vowel
        int[] vowelCount = new int[5]; // Count of 'a', 'e', 'i', 'o', 'u'

        String currentState = "00000"; // Initial state where all vowels have even counts
        mpp.put(currentState, -1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Update count for the vowel encountered
            if (s.charAt(i) == 'a')
                vowelCount[0] = (vowelCount[0] ^ 1); // Flip between even/odd for 'a'
            else if (s.charAt(i) == 'e')
                vowelCount[1] = (vowelCount[1] ^ 1); // Flip for 'e'
            else if (s.charAt(i) == 'i')
                vowelCount[2] = (vowelCount[2] ^ 1); // Flip for 'i'
            else if (s.charAt(i) == 'o')
                vowelCount[3] = (vowelCount[3] ^ 1); // Flip for 'o'
            else if (s.charAt(i) == 'u')
                vowelCount[4] = (vowelCount[4] ^ 1); // Flip for 'u'

            // Create a string representing the current parity state of vowels
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += vowelCount[j];
            }

            // Check if we've seen this state before
            if (mpp.containsKey(currentState)) {
                // Calculate the length of the substring
                maxLength = Math.max(maxLength, i - mpp.get(currentState));
            } else {
                // Store the first occurrence of this state
                mpp.put(currentState, i);
            }
        }

        return maxLength;
    }
}

// Approach-3 (using Mask and XOR property)
// T.C : O(n)
// S.C : O(32) ~ O(1) - Maximum 2^5 states possible
// This belongs to the Bit_Magic repository as well (You will find the link to
// this question in the Bit_Magic repository too)

class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> mpp = new HashMap<>();
        int mask = 0;
        mpp.put(mask, -1);
        int maxL = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = 0;
            if (s.charAt(i) == 'a')
                val = (1 << 0);
            else if (s.charAt(i) == 'e')
                val = (1 << 1);
            else if (s.charAt(i) == 'i')
                val = (1 << 2);
            else if (s.charAt(i) == 'o')
                val = (1 << 3);
            else if (s.charAt(i) == 'u')
                val = (1 << 4);

            mask ^= val; // XOR the value

            if (!mpp.containsKey(mask)) // if not seen before, add it to the map
                mpp.put(mask, i);

            maxL = Math.max(maxL, i - mpp.get(mask)); // update maxL with the longest substring length
        }
        return maxL;
    }
}
