/*
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 *
 * Example 3:
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *
 * Constraints:
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach: Recursively traverse the tree; if the current node is NULL or equals p or q, return it.
// Otherwise, get LCA from left and right subtrees. If both sides return non-NULL, current node is LCA.
// TC: O(n) where n is the number of nodes in the tree.
// SC: O(n) in the worst case due to the recursion stack.
class Solution {
public:
   // Function to find the Lowest Common Ancestor (LCA) in a binary tree.
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // If the current node is NULL, or equals p or q, return the current node.
      if (!root || root == p || root == q) {
         return root;
      }

      // Recursively search for LCA in the left subtree.
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      // Recursively search for LCA in the right subtree.
      TreeNode* right = lowestCommonAncestor(root->right, p, q);

      // If left subtree returns NULL, then LCA must be in the right subtree.
      if (left == nullptr) {
         return right;
      }
      // If right subtree returns NULL, then LCA must be in the left subtree.
      else if (right == nullptr) {
         return left;
      }
      // If both left and right are non-NULL, then the current node is the LCA.
      else {
         return root;
      }
   }
};

/*
 * Dry run:
 * Example Tree:
 *          3
 *         / \
 *        5   1
 *       / \  / \
 *      6   2 0  8
 *         / \
 *        7   4
 * p = 5, q = 1
 * Start at root (3): not NULL, not equal to p or q.
 * Recurse left from 3: at node 5, which equals p, so return 5.
 * Recurse right from 3: at node 1, which equals q, so return 1.
 * At root (3), both left and right calls returned non-NULL (5 and 1), so LCA is 3.
 * Result: Node with value 3.
 */
