/*
 * 226. Invert Binary Tree
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 * Example 1:
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 * Example 2:
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
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

// Approach: Recursively swap the left and right children for each node in the binary tree (using depth-first traversal).
// Time Complexity: O(n) - Each node is visited exactly once.
// Space Complexity: O(h) - The maximum space used is the recursion call stack, where h is the height of the tree.
class Solution {
public:
   TreeNode* invertTree(TreeNode* root) {
      // Base case: if the current node is null, just return null.
      if (!root) {
         return nullptr;
      }

      // Debug: Before swapping, print the current node value (optional).
      // std::cout << "Swapping children of node: " << root->val << std::endl;

      // Swap the left and right child pointers.
      TreeNode* temp = root->left;
      root->left  = root->right;
      root->right = temp;

      // Recursively invert the left subtree.
      invertTree(root->left);
      // Recursively invert the right subtree.
      invertTree(root->right);

      // Return the root of the inverted tree.
      return root;
   }
};

/*
 * Dry Run:
 * ----------
 * Input Tree: [4,2,7,1,3,6,9]
 *       4
 *      / \
 *     2   7
 *    / \ / \
 *   1  3 6  9
 *
 * Step 1: Call invertTree(root) where root is node 4.
 * Step 2: At node 4, swap its left and right children.
 *       Tree becomes:
 *            4
 *           / \
 *          7   2
 *         / \ / \
 *        6  9 1  3
 * Step 3: Recursively invert the subtree rooted at node 7.
 *       - At node 7, swap its left and right children.
 *       - After swapping, node 7’s children become: left = 9, right = 6.
 *       - Recursively process node 9 and node 6 (both are leaves, so no further changes).
 * Step 4: Recursively invert the subtree rooted at node 2.
 *       - At node 2, swap its left and right children.
 *       - After swapping, node 2’s children become: left = 3, right = 1.
 *       - Recursively process node 3 and node 1 (both are leaves, so no further changes).
 * Step 5: All nodes processed. The final inverted tree is:
 *       4
 *      / \
 *     7   2
 *    / \ / \
 *   9  6 3  1
 * ----------
 *
 * Below is the complete commented code:
 */
