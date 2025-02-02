/*
 * // Solve LeetCode 104
 * 111. Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * Note: A leaf is a node with no children.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 * Example 2:
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 */

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

// Approach 1: Use BFS (level order traversal) to find the minimum depth by returning the depth at the first encountered leaf node.
// TC: O(n) - in the worst-case, all nodes are processed.
// SC: O(n) - in the worst-case, the queue holds all nodes at the last level.
class Solution {
public:
   // Function to find the minimum depth of a binary tree.
   int minDepth(TreeNode* root) {
      // If the tree is empty, return 0.
      if (!root) {
         return 0;
      }

      // Queue to perform level order traversal.
      queue<TreeNode*> que;
      que.push(root);

      // Initialize height (depth) of the tree.
      int height = 0;

      // Continue until the queue is empty.
      while (!que.empty()) {
         // Increment the depth as we move to the next level.
         height++;

         // Number of nodes at the current level.
         int levelSize = que.size();

         // Process each node at the current level.
         for (int i = 0; i < levelSize; i++) {
            // Get the front node from the queue.
            TreeNode* curr = que.front();
            que.pop();

            // If the current node is a leaf, return the current depth.
            if (!curr->left && !curr->right) {
               return height;
            }

            // If left child exists, add it to the queue.
            if (curr->left) {
               que.push(curr->left);
            }
            // If right child exists, add it to the queue.
            if (curr->right) {
               que.push(curr->right);
            }
         }
      }

      // This return statement is never reached because we will always return from within the loop when a leaf is encountered.
      return -1;
   }
};

/*
 * Dry Run:
 * Consider the binary tree:
 *       3
 *      / \
 *     9  20
 *        /  \
 *       15   7
 *
 * Step-by-step:
 * 1. Start: queue = [3], height = 0.
 * 2. Level 1:
 * - height becomes 1.
 * - levelSize = 1.
 * - Process node 3: not a leaf, so enqueue its children [9, 20].
 * 3. Level 2:
 * - height becomes 2.
 * - levelSize = 2.
 * - Process node 9: it's a leaf (no children), so return height = 2.
 *
 * Thus, the minimum depth is 2.
 */


// Approach 2: Use recursion to compute the minimum depth by exploring both subtrees; if one subtree is missing, ignore it by using INT_MAX, and add 1 for the current node.
// TC: O(n) - every node is processed once.
// SC: O(h) - recursion stack space, where h is the height of the tree.
class Solution {
public:
   // Function to compute the minimum depth of a binary tree.
   int minDepth(TreeNode* root) {
      // If the current node is null, return 0.
      if (!root) {
         return 0;
      }
      // If the current node is a leaf node, return 1.
      if (!root->left && !root->right) {
         return 1;
      }

      // Compute the minimum depth of the left subtree if it exists; otherwise, set it to INT_MAX.
      int lh = root->left ? minDepth(root->left) : INT_MAX;
      // Compute the minimum depth of the right subtree if it exists; otherwise, set it to INT_MAX.
      int rh = root->right ? minDepth(root->right) : INT_MAX;

      // Return 1 (for the current node) plus the minimum of the depths of the left and right subtrees.
      return 1 + min(lh, rh);
   }
};

/*
 * Dry Run:
 * Consider the binary tree:
 *       3
 *      / \
 *     9  20
 *        /  \
 *       15   7
 *
 * 1. For root node (3):
 * - It is not null and not a leaf.
 * - Compute left subtree:
 *     - For node (9):
 *       - Node 9 is a leaf (no left and right child), so minDepth(9) = 1.
 * - Compute right subtree:
 *     - For node (20):
 *       - It is not null and not a leaf.
 *       - Compute left subtree:
 *           - For node (15):
 *             - Node 15 is a leaf, so minDepth(15) = 1.
 *       - Compute right subtree:
 *           - For node (7):
 *             - Node 7 is a leaf, so minDepth(7) = 1.
 *       - For node (20), minDepth = 1 + min(1, 1) = 2.
 * 2. For root node (3), minDepth = 1 + min(1, 2) = 2.
 *
 * Thus, the minimum depth of the tree is 2.
 */
