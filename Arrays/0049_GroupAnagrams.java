/*
 * 49. Group Anagrams
 * 
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Explanation:
 * There is no string in strs that can be rearranged to form "bat".
 * The strings "nat" and "tan" are anagrams as they can be rearranged to form
 * each other.
 * The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to
 * form each other.
 * 
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * 
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 */

// Approach-1 (Using Sorting)
// T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
// S.C : O(n*k)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<>();

        for (String str : strs) {
            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            String sortedStr = new String(charArr);

            if (!mp.containsKey(sortedStr)) {
                mp.put(sortedStr, new ArrayList<>());
            }

            mp.get(sortedStr).add(str);
        }
        return new ArrayList<>(mp.values());
    }
}

// Code with comments for better understanding:
// Approach-1 (Using Sorting)
// T.C : O(n*klog(k)) (n = size of input, k = maximum length of a string in the
// input vector)
// S.C : O(n*k)

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Create a HashMap to map the sorted string as a key to the list of anagrams
        HashMap<String, List<String>> mp = new HashMap<>();

        // Iterate over each string in the input array
        for (String str : strs) {
            // Convert the current string to a character array
            char[] charArr = str.toCharArray();

            // Sort the character array to get a common form for all anagrams
            Arrays.sort(charArr);

            // Convert the sorted character array back to a string
            String sortedStr = new String(charArr);

            // If the sorted string is not present in the map, add it with a new empty list
            if (!mp.containsKey(sortedStr)) {
                mp.put(sortedStr, new ArrayList<>());
            }

            // Add the original string to the list corresponding to the sorted string
            mp.get(sortedStr).add(str);
        }

        // Return all the lists of anagrams as a new ArrayList
        return new ArrayList<>(mp.values());
    }
}
