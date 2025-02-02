/*
 * 104. Maximum Depth of Binary Tree
 *
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 * Example 2:
 * Input: root = [1,null,2]
 * Output: 2
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
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

// Approach 1: Use recursion to compute the maximum depth by finding the maximum depth of left and right subtrees and adding 1.
// TC: O(n) - each node is visited once.
// SC: O(h) - recursion stack depth, where h is the height of the tree.
class Solution {
public:
   // Function to compute the maximum depth of a binary tree.
   int maxDepth(TreeNode* root) {
      // Base case: if the current node is null, then the depth is 0.
      if (root == nullptr) {
         return 0;
      }

      // Recursively compute the maximum depth of the left subtree.
      int lh = maxDepth(root->left);
      // Recursively compute the maximum depth of the right subtree.
      int rh = maxDepth(root->right);

      // The maximum depth of the current tree is 1 (for the root) plus the maximum of the depths of its subtrees.
      return 1 + max(lh, rh);
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
 * 1. Call maxDepth(3)
 * - Calls maxDepth(9) and maxDepth(20)
 * 2. For node 9:
 * - Calls maxDepth(nullptr) for both left and right, each returns 0.
 * - So, maxDepth(9) = 1 + max(0, 0) = 1.
 * 3. For node 20:
 * - Calls maxDepth(15) and maxDepth(7)
 * 4. For node 15:
 * - Calls maxDepth(nullptr) for both left and right, returns 0.
 * - So, maxDepth(15) = 1 + max(0, 0) = 1.
 * 5. For node 7:
 * - Calls maxDepth(nullptr) for both left and right, returns 0.
 * - So, maxDepth(7) = 1 + max(0, 0) = 1.
 * 6. Back to node 20:
 * - maxDepth(20) = 1 + max(1, 1) = 2.
 * 7. Finally, back to node 3:
 * - maxDepth(3) = 1 + max(1, 2) = 3.
 * Output: 3 (The maximum depth of the tree is 3)
 */


// Approach 2: Use a breadth-first search (BFS) with a queue to traverse the tree level by level, incrementing height at each level.
// TC: O(n) - every node is processed exactly once.
// SC: O(n) - in the worst case, the queue holds all nodes at the deepest level.
class Solution {
public:
   // Function to compute the maximum depth of a binary tree using level order traversal.
   int maxDepth(TreeNode* root) {
      // If the tree is empty, return 0 as its depth.
      if (!root) {
         return 0;
      }

      // Queue to perform BFS (level order traversal).
      queue<TreeNode*> que;
      que.push(root);

      // Variable to store the height (or depth) of the tree.
      int height = 0;

      // Process nodes level by level.
      while (!que.empty()) {
         // Increment height for each level.
         height++;

         // Get the number of nodes at the current level.
         int levelSize = que.size();

         // Process each node in the current level.
         for (int i = 0; i < levelSize; i++) {
            // Retrieve the node from the front of the queue.
            TreeNode* curr = que.front();
            que.pop();

            // If a left child exists, add it to the queue for the next level.
            if (curr->left) {
               que.push(curr->left);
            }
            // If a right child exists, add it to the queue for the next level.
            if (curr->right) {
               que.push(curr->right);
            }
         }
      }
      // Return the maximum depth of the tree.
      return height;
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
 * - Process node 3: enqueue its children: [9, 20].
 * 3. Level 2:
 * - height becomes 2.
 * - levelSize = 2.
 * - Process node 9: no children.
 * - Process node 20: enqueue its children: [15, 7].
 * 4. Level 3:
 * - height becomes 3.
 * - levelSize = 2.
 * - Process node 15: no children.
 * - Process node 7: no children.
 * 5. Queue is now empty, so the final maximum depth is 3.
 */
