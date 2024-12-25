/*
 * 515. Find Largest Value in Each Tree Row
 *
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
 *
 * Example 1:
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 *
 * Example 2:
 * Input: root = [1,2,3]
 * Output: [1,3]
 *
 * Constraints:
 * The number of nodes in the tree will be in the range [0, 104].
 * -2^31 <= Node.val <= 2^31 - 1
 */



// Approach 1: BFS to traverse the tree level by level, finding and storing the maximum value for each level.
// Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
// Space Complexity: O(w), where w is the maximum width of the tree, representing the maximum number of nodes in the queue at any level.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<int> largestValues(TreeNode *root){
      // If the root is null, return an empty vector
      if (root == NULL) {
         return {};
      }

      // Queue for BFS to traverse the tree level by level
      queue<TreeNode *> que;
      que.push(root);

      // Result vector to store the largest values from each row
      vector<int> result;

      // Perform BFS
      while (!que.empty()) {
         int n     = que.size(); // Get the number of nodes at the current level
         int maxEl = INT_MIN;    // Initialize the maximum element for this level

         // Process all nodes at the current level
         while (n--) {
            TreeNode *node = que.front();
            que.pop();

            // Update the maximum element for the current level
            maxEl = max(maxEl, node->val);

            // Add the left child to the queue if it exists
            if (node->left) {
               que.push(node->left);
            }

            // Add the right child to the queue if it exists
            if (node->right) {
               que.push(node->right);
            }
         }

         // Add the maximum element of this level to the result
         result.push_back(maxEl);
      }

      // Return the list of largest values from each row
      return result;
   }
};

// Follow Up to solve using DFS:
// Approach 2: DFS to traverse the tree depth-wise, updating the largest value at each depth during the traversal.
// Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
// Space Complexity: O(h), where h is the height of the tree, representing the recursive call stack depth.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   // Vector to store the largest value at each depth (row) of the tree
   vector<int> result;

   // Helper function to perform Depth-First Search (DFS)
   void DFS(TreeNode *root, int depth){
      // Base case: If the current node is null, return
      if (root == NULL) {
         return;
      }

      // If this is the first time visiting this depth, add the node's value
      if (depth == result.size()) {
         result.push_back(root->val);
      }
      // Otherwise, update the maximum value for this depth
      else {
         result[depth] = max(result[depth], root->val);
      }

      // Recursively call DFS for the left and right children, increasing depth
      DFS(root->left, depth + 1);
      DFS(root->right, depth + 1);
   }

   // Main function to find the largest values in each row of the tree
   vector<int> largestValues(TreeNode *root){
      // Start the DFS traversal from the root at depth 0
      DFS(root, 0);

      // Return the result vector containing largest values for each row
      return result;
   }
};
