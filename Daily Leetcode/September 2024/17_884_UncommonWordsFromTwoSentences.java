/*
 * 884. Uncommon Words from Two Sentences
 * 
 * A sentence is a string of single-space separated words where each word
 * consists only of lowercase letters.
 * A word is uncommon if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 * Given two sentences s1 and s2, return a list of all the uncommon words. You
 * may return the answer in any order.
 * 
 * Example 1:
 * Input: s1 = "this apple is sweet", s2 = "this apple is sour"
 * Output: ["sweet","sour"]
 * Explanation:
 * The word "sweet" appears only in s1, while the word "sour" appears only in
 * s2.
 * 
 * Example 2:
 * Input: s1 = "apple apple", s2 = "banana"
 * Output: ["banana"]
 * 
 * Constraints:
 * 1 <= s1.length, s2.length <= 200
 * s1 and s2 consist of lowercase English letters and spaces.
 * s1 and s2 do not have leading or trailing spaces.
 * All the words in s1 and s2 are separated by a single space.
 */

// Time Complexity: O(n1 + n2)
// - Splitting both sentences takes O(n1 + n2), where n1 and n2 are the lengths of s1 and s2.
// - Inserting words into the HashMap takes O(w1 + w2), where w1 and w2 are the number of words in s1 and s2.
// - Iterating through the HashMap to find uncommon words takes O(w1 + w2).
// Thus, overall time complexity is O(n1 + n2).

// Space Complexity: O(n1 + n2)
// - The HashMap stores up to O(w1 + w2) words from both sentences.
// - The result list and arrays used for splitting also take O(w1 + w2) space.
// Thus, overall space complexity is O(n1 + n2).

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {

        // Create a HashMap to store the frequency of each word from both sentences
        HashMap<String, Integer> mpp = new HashMap<>();

        // Split the first sentence into words and add their counts to the map
        String[] words1 = s1.split(" ");
        for (String word : words1) {
            // Use getOrDefault to get the current count of the word, increment by 1, and
            // update the map
            mpp.put(word, mpp.getOrDefault(word, 0) + 1);
        }

        // Split the second sentence into words and add their counts to the map
        String[] words2 = s2.split(" ");
        for (String word : words2) {
            // Same logic as above, update the count for words from the second sentence
            mpp.put(word, mpp.getOrDefault(word, 0) + 1);
        }

        // Create a list to store the uncommon words
        List<String> result = new ArrayList<>();

        // Iterate through the map to find words that appear exactly once
        for (Map.Entry<String, Integer> entry : mpp.entrySet()) {
            // If the word appears only once (value is 1), it is an uncommon word
            if (entry.getValue() == 1) {
                result.add(entry.getKey());
            }
        }

        // Convert the result list to an array and return it
        return result.toArray(new String[0]);
    }
}
