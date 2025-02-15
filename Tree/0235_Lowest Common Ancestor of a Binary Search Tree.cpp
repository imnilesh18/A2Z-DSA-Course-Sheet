/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Example 1:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 *
 * Example 2:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 *
 * Example 3:
 * Input: root = [2,1], p = 2, q = 1
 * Output: 2
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 1^09
 * All Node.val are unique.
 * p != q
 * p and q will exist in the BST.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach: Use BST properties to decide traversal. If both nodes are less than the current node, LCA is in the left subtree; if both are greater, it's in the right subtree; otherwise, the current node is the LCA.
// TC: O(h) where h is the height of the BST.
// SC: O(h) due to recursion stack space.
class Solution {
public:
   // Function to find the Lowest Common Ancestor (LCA) in a BST.
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // If root is NULL, return NULL.
      if (!root) {
         return nullptr;
      }

      // If both p and q are less than the current node, LCA is in the left subtree.
      if (root->val > p->val && root->val > q->val) {
         return lowestCommonAncestor(root->left, p, q);
      }

      // If both p and q are greater than the current node, LCA is in the right subtree.
      if (root->val < p->val && root->val < q->val) {
         return lowestCommonAncestor(root->right, p, q);
      }

      // Else, the current node is the LCA.
      return root;
   }
};

/*
 * Dry run:
 * Example BST:
 *         6
 *       /   \
 *      2     8
 *     / \   / \
 *    0   4 7   9
 *       / \
 *      3   5
 * p = 2, q = 8
 * Start at root (6): p (2) < 6 and q (8) > 6, so current node is the LCA.
 * Result: Node with value 6.
 */
