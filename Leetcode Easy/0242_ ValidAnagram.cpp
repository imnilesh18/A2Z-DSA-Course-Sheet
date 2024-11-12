/*
 * 242. Valid Anagram
 *
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 */

// Approach-1 (Using sorting)
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
public:
   bool isAnagram(string s, string t){
      sort(begin(s), end(s));
      sort(begin(t), end(t));

      return s == t;
   }
};

// Approach 2: (Using map)
// T.C : O(n)
// S.C : O(26) ~ O(1)
class Solution {
public:
   bool isAnagram(string s, string t){
      vector<int> count(26, 0);

      for (char&ch : s) {
         count[ch - 'a']++;
      }

      for (char&ch : t) {
         count[ch - 'a']--;
      }

      //NOTE : You can also do above in only one for loop.

      /*
       *  for(int i = 0; i<n; i++) {
       *      count[s[i]-'a']++;
       *      count[t[i]-'a']--;
       *  }
       */
      // Check if all elements in the array are 0 --> You can write a for loop as well
      //This is just for learning purpose
      bool allZeros = all_of(begin(count), end(count), [](int element) {
         return element == 0;
      });

      return allZeros;
   }
};
