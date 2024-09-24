/*
 * 212. Word Search II
 * 
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 * 
 * Example 1:
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * 
 * Example 2:
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 * 
 * Constraints:
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 104
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 */

class Solution {
    List<String> result = new ArrayList<>(); // List to store the found words
    int m, n; // Dimensions of the board

    // TrieNode class representing each node in the Trie
    class TrieNode {
        boolean endOfWord; // Flag to indicate if the node marks the end of a valid word
        TrieNode[] children = new TrieNode[26]; // Array of child nodes for each letter (a-z)
        String word; // The word that ends at this node

        // Constructor to initialize the TrieNode
        TrieNode() {
            this.endOfWord = false; // Initially, the node does not mark the end of a word
            for (int i = 0; i < 26; i++) {
                this.children[i] = null; // Initialize all children to null
            }
            this.word = ""; // Initialize the word to an empty string
        }
    }

    // Method to insert a word into the Trie
    private void insert(TrieNode root, String word) {
        TrieNode pCrawl = root; // Pointer to traverse the Trie

        // Insert each character of the word into the Trie
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i); // Get the current character
            // If the child node for the character does not exist, create it
            if (pCrawl.children[ch - 'a'] == null) {
                pCrawl.children[ch - 'a'] = new TrieNode();
            }
            pCrawl = pCrawl.children[ch - 'a']; // Move to the child node
        }

        pCrawl.endOfWord = true; // Mark the end of the word
        pCrawl.word = word; // Store the word in the TrieNode
    }

    int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } }; // Directions for DFS (up, down, left, right)

    // Method for Depth-First Search to find words in the board
    private void DFS(char[][] board, int i, int j, TrieNode root) {
        // Check for out-of-bounds conditions
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return; // Return if the indices are out of bounds
        }

        // Check if the current cell is visited or does not lead to a valid TrieNode
        if (board[i][j] == '$' || root.children[board[i][j] - 'a'] == null) {
            return; // Return if the cell is already visited or invalid
        }

        // Move to the child TrieNode corresponding to the current character
        root = root.children[board[i][j] - 'a'];

        // If the current node marks the end of a word
        if (root.endOfWord) {
            result.add(root.word); // Add the word to the result list
            root.endOfWord = false; // Prevent adding the same word again
        }

        char temp = board[i][j]; // Save the current character
        board[i][j] = '$'; // Mark the current cell as visited

        // Explore all 4 directions (up, down, left, right)
        for (int[] dir : directions) {
            int new_i = i + dir[0]; // Calculate new row index
            int new_j = j + dir[1]; // Calculate new column index
            DFS(board, new_i, new_j, root); // Recursively search in the new direction
        }

        board[i][j] = temp; // Restore the character after DFS
    }

    // Method to find all words in the board that exist in the given list of words
    public List<String> findWords(char[][] board, String[] words) {
        m = board.length; // Rows of the board
        n = board[0].length; // Columns of the board

        TrieNode root = new TrieNode(); // Create the root of the Trie

        // Insert all words into the Trie
        for (String word : words) {
            insert(root, word);
        }

        // Iterate through each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j]; // Get the character at the current cell

                // If the character is present in the Trie, perform DFS from that cell
                if (root.children[ch - 'a'] != null) {
                    DFS(board, i, j, root);
                }
            }
        }
        return result; // Return the list of found words
    }
}
