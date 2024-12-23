/*
 * 2471. Minimum Number of Operations to Sort a Binary Tree by Level
 *
 * You are given the root of a binary tree with unique values.
 * In one operation, you can choose any two nodes at the same level and swap their values.
 * Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
 * The level of a node is the number of edges along the path between it and the root node.
 *
 * Example 1:
 * Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
 * Output: 3
 * Explanation:
 * - Swap 4 and 3. The 2nd level becomes [3,4].
 * - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
 * - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
 * We used 3 operations so return 3.
 * It can be proven that 3 is the minimum number of operations needed.
 *
 * Example 2:
 * Input: root = [1,3,2,7,6,5,4]
 * Output: 3
 * Explanation:
 * - Swap 3 and 2. The 2nd level becomes [2,3].
 * - Swap 7 and 4. The 3rd level becomes [4,6,5,7].
 * - Swap 6 and 5. The 3rd level becomes [4,5,6,7].
 * We used 3 operations so return 3.
 * It can be proven that 3 is the minimum number of operations needed.
 *
 * Example 3:
 * Input: root = [1,2,3,4,5,6]
 * Output: 0
 * Explanation: Each level is already sorted in increasing order so return 0.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 * All the values of the tree are unique.
 */

// Approach: BFS to traverse the tree level by level and calculate minimum swaps for sorting node values at each level.
// Time Complexity: O(n + m * w log w), where n is the number of nodes, m is the number of levels, and w is the number of nodes per level.
// Space Complexity:  O(n), for storing nodes in the BFS queue and level values.
class Solution {
public:
   // Function to count the minimum number of swaps needed to sort an array
   int countMinSwapsToSort(vector<int>&vec){
      int swaps = 0;

      // Create a sorted copy of the input vector for comparison
      vector<int> sortedVec(begin(vec), end(vec));

      sort(begin(sortedVec), end(sortedVec));

      // Map to store the index of each element in the original vector
      unordered_map<int, int> mp;
      for (int i = 0; i < vec.size(); i++) {
         mp[vec[i]] = i;
      }

      // Iterate through the vector to calculate the number of swaps
      for (int i = 0; i < vec.size(); i++) {
         // If the current element is already in the correct position, skip
         if (vec[i] == sortedVec[i]) {
            continue;
         }

         // Find the index of the correct element from the map
         int currIdx = mp[sortedVec[i]];

         // Update the map to reflect the swap
         mp[vec[i]]       = currIdx;
         mp[vec[currIdx]] = i;

         // Swap the elements to move one step closer to the sorted order
         swap(vec[currIdx], vec[i]);
         swaps++;
      }
      return swaps;   // Return the total number of swaps
   }

   // Function to calculate the minimum operations to sort the binary tree by level
   int minimumOperations(TreeNode *root){
      queue<TreeNode *> que; // Queue for BFS

      que.push(root);        // Start BFS from the root node

      int result = 0;        // Initialize the result to store the total number of operations

      // Perform BFS level by level
      while (!que.empty()) {
         int         n = que.size(); // Get the number of nodes at the current level
         vector<int> vec;            // Vector to store the values of nodes at this level

         // Process all nodes at the current level
         while (n--) {
            TreeNode *temp = que.front();
            que.pop();
            vec.push_back(temp->val);     // Add the node value to the vector

            // Add the left and right children to the queue for the next level
            if (temp->left) {
               que.push(temp->left);
            }
            if (temp->right) {
               que.push(temp->right);
            }
         }

         // Calculate the number of swaps required to sort the current level
         result += countMinSwapsToSort(vec);
      }
      return result;   // Return the total number of operations
   }
};
