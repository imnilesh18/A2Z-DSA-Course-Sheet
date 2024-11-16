/*
 * 1496. Path Crossing
 *
 * Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
 * Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.
 *
 * Example 1:
 * Input: path = "NES"
 * Output: false
 * Explanation: Notice that the path doesn't cross any point more than once.
 *
 * Example 2:
 * Input: path = "NESWW"
 * Output: true
 * Explanation: Notice that the path visits the origin twice.
 *
 * Constraints:
 * 1 <= path.length <= 10^4
 * path[i] is either 'N', 'S', 'E', or 'W'.
 */

// Approach (simply simulate and check visited)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
   bool isPathCrossing(string path){
      unordered_set<string> st;
      int x = 0;
      int y = 0;

      string key = to_string(x) + "_" + to_string(y);

      st.insert(key);

      for (char&ch : path) {
         if (ch == 'E') {
            x++;     // ----->
         } else if (ch == 'W') {
            x--;     // <-----
         } else if (ch == 'N') {
            y++;
         } else {
            y--;
         }

         key = to_string(x) + "_" + to_string(y);

         if (st.find(key) != st.end()) {
            return true;
         }

         st.insert(key);
      }
      return false;
   }
};

// Code with comments for better understanding:

// Approach (simply simulate and check visited)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
   bool isPathCrossing(string path){
      // Using an unordered_set to store visited positions on the 2D plane
      unordered_set<string> st;

      // Starting coordinates at the origin (0, 0)
      int x = 0;
      int y = 0;

      // Create a unique key for the starting position and add it to the set
      string key = to_string(x) + "_" + to_string(y);

      st.insert(key);

      // Iterate through each character in the path
      for (char&ch : path) {
         // Update coordinates based on the direction
         if (ch == 'E') {        // Move East (right)
            x++;
         } else if (ch == 'W') { // Move West (left)
            x--;
         } else if (ch == 'N') { // Move North (up)
            y++;
         } else {                // Move South (down)
            y--;
         }

         // Generate a unique key for the current position
         key = to_string(x) + "_" + to_string(y);

         // Check if the position has already been visited
         if (st.find(key) != st.end()) {
            return true;     // Path crosses itself
         }

         // Mark the current position as visited
         st.insert(key);
      }

      // If no crossing is detected, return false
      return false;
   }
};
