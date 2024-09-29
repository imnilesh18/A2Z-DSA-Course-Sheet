/*
 * 3305. Count of Substrings Containing Every Vowel and K Consonants I
 * 
 * You are given a string word and a non-negative integer k.
 * Return the total number of substrings of word that contain every vowel ('a',
 * 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 * 
 * Example 1:
 * Input: word = "aeioqq", k = 1
 * Output: 0
 * Explanation:
 * There is no substring with every vowel.
 * 
 * Example 2:
 * Input: word = "aeiou", k = 0
 * Output: 1
 * Explanation:
 * The only substring with every vowel and zero consonants is word[0..4], which
 * is "aeiou".
 * 
 * Example 3:
 * Input: word = "ieaouqqieaouqq", k = 1
 * Output: 3
 * Explanation:
 * The substrings with every vowel and one consonant are:
 * word[0..5], which is "ieaouq".
 * word[6..11], which is "qieaou".
 * word[7..12], which is "ieaouq".
 * 
 * Constraints:
 * 5 <= word.length <= 250
 * word consists only of lowercase English letters.
 * 0 <= k <= word.length - 5
 */

class Solution {
    public int countOfSubstrings(String word, int k) {
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            int cnta = 0, cnte = 0, cnti = 0, cnto = 0, cntu = 0;
            int consonantCount = 0; // Use this to count consonants
            for (int j = i; j < word.length(); j++) {
                char ch = word.charAt(j);
                
                if (ch == 'a') cnta++;
                else if (ch == 'e') cnte++;
                else if (ch == 'i') cnti++;
                else if (ch == 'o') cnto++;
                else if (ch == 'u') cntu++;
                else consonantCount++; // Increment consonant count for non-vowel characters
                
                // Check if all vowels are present and exactly k consonants are there
                if (cnta > 0 && cnte > 0 && cnti > 0 && cnto > 0 && cntu > 0 && consonantCount == k) {
                    cnt++; // Valid substring found
                }
            }
        }
        return cnt;
    }
}