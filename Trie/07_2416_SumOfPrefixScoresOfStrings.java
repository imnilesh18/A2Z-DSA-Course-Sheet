/*
 * 2416. Sum of Prefix Scores of Strings
 * 
 * You are given an array words of size n consisting of non-empty strings.
 * We define the score of a string term as the number of strings words[i] such
 * that term is a prefix of words[i].
 * For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is
 * 2, since "ab" is a prefix of both "ab" and "abc".
 * Return an array answer of size n where answer[i] is the sum of scores of
 * every non-empty prefix of words[i].
 * Note that a string is considered as a prefix of itself.
 * 
 * Example 1:
 * Input: words = ["abc","ab","bc","b"]
 * Output: [5,4,3,2]
 * Explanation: The answer for each string is the following:
 * - "abc" has 3 prefixes: "a", "ab", and "abc".
 * - There are 2 strings with the prefix "a", 2 strings with the prefix "ab",
 * and 1 string with the prefix "abc".
 * The total is answer[0] = 2 + 2 + 1 = 5.
 * - "ab" has 2 prefixes: "a" and "ab".
 * - There are 2 strings with the prefix "a", and 2 strings with the prefix
 * "ab".
 * The total is answer[1] = 2 + 2 = 4.
 * - "bc" has 2 prefixes: "b" and "bc".
 * - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
 * The total is answer[2] = 2 + 1 = 3.
 * - "b" has 1 prefix: "b".
 * - There are 2 strings with the prefix "b".
 * The total is answer[3] = 2.
 * 
 * Example 2:
 * Input: words = ["abcd"]
 * Output: [4]
 * Explanation:
 * "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
 * Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 =
 * 4.
 * 
 * Constraints:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists of lowercase English letters.
 */

//Approach - Using TRIE 
//T.C : O(n*l), n = number of words, l = average length of each word
//S.C : O(n*l), need to store all characters of words

// Definition of TrieNode class
class TrieNode {
    int countP; // Counter for the number of times this node is part of a prefix
    TrieNode[] children; // Array to hold child nodes

    // Constructor for TrieNode initializes countP and children array
    TrieNode() {
        this.countP = 0; // Initialize prefix count to zero
        this.children = new TrieNode[26]; // Initialize children array for 26 letters of the alphabet
    }
}

// Definition of Solution class
class Solution {

    // Method to insert a word into the Trie
    void insert(String word, TrieNode root) {
        TrieNode crawl = root; // Start from the root node

        for (char ch : word.toCharArray()) { // Iterate over each character in the word
            int idx = ch - 'a'; // Calculate index for the character

            if (crawl.children[idx] == null) { // If no node exists at this index, create one
                crawl.children[idx] = new TrieNode();
            }

            crawl.children[idx].countP += 1; // Increment the prefix count for this node
            crawl = crawl.children[idx]; // Move to the next node
        }
    }

    // Method to calculate the score of a word based on prefix occurrences
    int getScore(String word, TrieNode root) {
        TrieNode crawl = root; // Start from the root node
        int score = 0; // Initialize score to zero

        for (char ch : word.toCharArray()) { // Iterate over each character in the word
            int idx = ch - 'a'; // Calculate index for the character
            if (crawl.children[idx] == null) { // If no node exists at this index, break the loop
                break;
            }
            score += crawl.children[idx].countP; // Add the count of this node to the score
            crawl = crawl.children[idx]; // Move to the next node
        }
        return score; // Return the calculated score
    }

    // Method to compute the sum of prefix scores for an array of words
    public int[] sumPrefixScores(String[] words) {
        int n = words.length; // Number of words
        TrieNode root = new TrieNode(); // Create a root node for the Trie

        for (String word : words) { // Insert each word into the Trie
            insert(word, root);
        }

        int[] result = new int[n]; // Array to store results

        for (int i = 0; i < n; i++) { // Calculate score for each word
            result[i] = getScore(words[i], root); // Store the score in the result array
        }
        return result; // Return the result array
    }
}
