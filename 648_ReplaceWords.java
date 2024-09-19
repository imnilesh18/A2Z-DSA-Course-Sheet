/*
 * 648. Replace Words
 * 
 * In English, we have a concept called root, which can be followed by some
 * other word to form another longer word - let's call this word derivative. For
 * example, when the root "help" is followed by the word "ful", we can form a
 * derivative "helpful".
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the derivatives in the sentence with
 * the root forming it. If a derivative can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 * Return the sentence after the replacement.
 * 
 * Example 1:
 * Input: dictionary = ["cat","bat","rat"], sentence =
 * "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * Example 2:
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 * 
 * Constraints:
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 106
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Every two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 */

/*
 * Time Complexity: O(n * m), where 'n' is the number of words in the sentence
 * and 'm' is the number of root words in the dictionary. For each word in the
 * sentence, we check all the roots in the dictionary, and the `startsWith`
 * method runs in O(k) where 'k' is the length of the word (average case).
 *
 * Space Complexity: O(n), where 'n' is the length of the input sentence,
 * because we're storing the split sentence in an array and returning the
 * updated sentence.
 */
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        // Split the sentence into words
        String[] splitSentence = sentence.split(" ");
        // System.out.println(Arrays.toString(splitSentence)); // Debug print statement
        // (commented out)

        // Loop through each word in the sentence
        for (int i = 0; i < splitSentence.length; i++) {
            String word = splitSentence[i];

            String shortestRoot = null; // Variable to store the shortest root found
            // Check each root in the dictionary
            for (String root : dictionary) {
                // If the word starts with the root
                if (word.startsWith(root)) {
                    // If no root has been found yet or the current root is shorter than the found
                    // one
                    if (shortestRoot == null || root.length() < shortestRoot.length()) {
                        shortestRoot = root; // Update the shortest root
                    }
                }
            }
            // If a matching root is found, replace the word in the sentence with the root
            if (shortestRoot != null) {
                splitSentence[i] = shortestRoot;
            }
        }
        // Join the sentence back into a string and return it
        String updatedSentence = String.join(" ", splitSentence);
        return updatedSentence;
    }
}
