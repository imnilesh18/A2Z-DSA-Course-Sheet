/*
 * 208. Implement Trie (Prefix Tree)
 * 
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 * Implement the Trie class:
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 * 
 * Example 1:
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple"); // return True
 * trie.search("app"); // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app"); // return True
 * 
 * Constraints:
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 104 calls in total will be made to insert, search, and
 * startsWith.
 */

class Trie {
    static class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;

        TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
    }

    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null)
                crawler.children[index] = new TrieNode();

            crawler = crawler.children[index];
        }

        crawler.isEndOfWord = true;
    }

    public boolean search(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null)
                return false;
            crawler = crawler.children[index];
        }
        return crawler != null && crawler.isEndOfWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) {
            int index = prefix.charAt(i) - 'a';

            if (crawler.children[index] == null)
                return false;

            crawler = crawler.children[index];
        }
        return i == prefix.length();
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
