/*
 * 1436. Destination City
 *
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
 * It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
 *
 * Example 1:
 * Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * Output: "Sao Paulo"
 * Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 *
 * Example 2:
 * Input: paths = [["B","C"],["D","B"],["C","A"]]
 * Output: "A"
 * Explanation: All possible trips are:
 * "D" -> "B" -> "C" -> "A".
 * "B" -> "C" -> "A".
 * "C" -> "A".
 * "A".
 * Clearly the destination city is "A".
 *
 * Example 3:
 * Input: paths = [["A","Z"]]
 * Output: "Z"
 *
 * Constraints:
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * All strings consist of lowercase and uppercase English letters and the space character.
 */

// Approach-1 (Using HashMap) - Count Outdegrees
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
   string destCity(vector<vector<string> >& paths){
      unordered_map<string, int> mp;

      for (auto&path : paths) {
         string source = path[0];

         mp[source]++;
      }

      for (auto&path : paths) {
         string dest = path[1];

         if (mp[dest] == 0) {
            return dest;
         }
      }

      return "";
   }
};

// Approach - 2 (Using HashSet) - Count Outdegrees
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
   string destCity(vector<vector<string> >& paths){
      unordered_set<string> st;

      for (auto&path : paths) {
         string source = path[0];

         st.insert(source);
      }

      for (auto&path : paths) {
         string dest = path[1];

         if (st.find(dest) == st.end()) {
            return dest;
         }
      }

      return "";
   }
};

// Code with comments for better understanding:

// Approach-1 (Using HashMap) - Count Outdegrees
// T.C : O(n)
// S.C : O(n

/*
 * Problem: Destination City
 *
 * Intuition:
 * 1. The destination city will have no outgoing paths
 * 2. Every other city will have exactly one outgoing path
 * 3. We can count outgoing paths from each city:
 *    - If a city has 0 outgoing paths and is in the paths array,
 *    - It must be the destination city
 *
 * Example path: London -> New York -> Lima -> Sao Paulo
 * Outgoing count: London(1), New York(1), Lima(1), Sao Paulo(0)
 * Therefore, Sao Paulo is the destination
 */

class Solution {
public:
   string destCity(vector<vector<string> >& paths){
      // Map to store count of outgoing paths from each city
      unordered_map<string, int> mp;

      // First pass: Count outgoing paths for each source city
      for (auto& path : paths) {
         string source = path[0];    // City with outgoing path
         mp[source]++;               // Increment outgoing path count
      }

      // Second pass: Find city with no outgoing paths
      for (auto& path : paths) {
         string dest = path[1];      // Candidate destination city

         // If this city has no outgoing paths,
         // it's the destination city
         if (mp[dest] == 0) {
            return dest;
         }
      }

      return "";    // Will never reach here as per problem constraints
   }
};

/*
 * Time Complexity: O(n)
 * - First pass to count outgoing paths: O(n)
 * - Second pass to find destination: O(n)
 * where n is number of paths
 *
 * Space Complexity: O(n)
 * - HashMap storing count of outgoing paths
 * - In worst case, all cities are unique
 *
 * Why this works:
 * 1. Every city except destination has exactly one outgoing path
 * 2. Destination city must appear as path[1] in some path
 * 3. But destination won't appear as path[0] in any path
 * 4. Therefore, mp[destination] will be 0
 */

// Approach - 2 (Using HashSet) - Count Outdegrees
// T.C : O(n)
// S.C : O(n)

/*
 * Problem: Destination City
 *
 * Intuition:
 * 1. Every city that appears as a source will have an outgoing path
 * 2. The destination city will:
 *    - Never appear as a source city
 *    - Only appear as a destination in some path
 * 3. We can store all source cities in a set
 *    Then find the destination that's not in this set
 *
 * Example: [["London","New York"], ["New York","Lima"], ["Lima","Sao Paulo"]]
 * Source cities set: {London, New York, Lima}
 * Sao Paulo is not in set -> It's the destination
 */

class Solution {
public:
   string destCity(vector<vector<string> >& paths){
      // Set to store all cities that have outgoing paths (source cities)
      unordered_set<string> st;

      // First pass: Store all source cities in set
      for (auto&path : paths) {
         string source = path[0];     // City at start of path
         st.insert(source);           // Add to set of cities with outgoing paths
      }

      // Second pass: Find destination city
      // It will be the city that appears as destination but not as source
      for (auto&path : paths) {
         string dest = path[1];       // City at end of path

         // If this city is not in our set of source cities,
         // it must be the final destination
         if (st.find(dest) == st.end()) {
            return dest;
         }
      }

      return "";    // Never reached due to problem constraints
   }
};

/*
 * Time Complexity: O(n)
 * - First pass to store sources: O(n)
 * - Second pass to find destination: O(n)
 * - Set operations (insert/find) are O(1) average case
 * where n is number of paths
 *
 * Space Complexity: O(n)
 * - Set storing source cities
 * - In worst case, all cities except destination are sources
 *
 * Advantage over map approach:
 * 1. More intuitive - directly stores cities with outgoing paths
 * 2. No need to count - we only care if city is a source or not
 * 3. Set operations might be slightly faster than map
 */
