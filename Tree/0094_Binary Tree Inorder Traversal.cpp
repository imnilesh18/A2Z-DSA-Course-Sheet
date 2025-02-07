/*
 * 94. Binary Tree Inorder Traversal
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
 * Output: [4,2,6,5,7,1,3,9,8]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Example 4:
 * Input: root = [1]
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

// Approach: Recursively perform an inorder traversal by visiting the left subtree, then the current node, and finally the right subtree.
// Time Complexity: O(n) - Each of the n nodes is visited exactly once.
// Space Complexity: O(n) - In the worst-case (skewed tree), the recursion stack can go up to n levels.
class Solution {
public:
   // Recursive helper function to perform inorder traversal.
   void solve(TreeNode* root, vector<int>& result) {
      if (!root) {
         return;                   // Base case: if the node is null, simply return.
      }
      solve(root->left, result);   // Traverse the left subtree.
      result.push_back(root->val); // Visit the current node.
      solve(root->right, result);  // Traverse the right subtree.
   }

   // Main function to initiate inorder traversal and return the traversal result.
   vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;        // Vector to store the inorder traversal sequence.

      solve(root, result);
      return result;
   }
};

/*
 * Dry Run Example:
 * For the tree represented by [1, null, 2, 3]:
 *    1
 *     \
 *      2
 *     /
 *    3
 * Inorder traversal steps:
 * 1. Start at root (1): traverse left subtree → null.
 * 2. Visit node 1 → result = [1].
 * 3. Traverse right subtree of 1 (node 2):
 *     a. At node 2: traverse left subtree (node 3):
 *           i. At node 3: traverse left → null.
 *          ii. Visit node 3 → result = [1, 3].
 *         iii. Traverse right → null.
 *     b. Visit node 2 → result = [1, 3, 2].
 *     c. Traverse right subtree → null.
 * Final inorder traversal result: [1, 3, 2]
 */
