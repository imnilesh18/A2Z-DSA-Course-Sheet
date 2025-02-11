/*
 * 98. Validate Binary Search Tree
 *
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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

// Approach: Recursively validate each node by ensuring its value lies within a valid range that gets updated as we traverse the tree.
// Time Complexity (TC): O(N) - Every node in the tree is visited once.
// Space Complexity (SC): O(N) - In the worst-case (skewed tree), the recursion stack could contain up to N nodes.
class Solution {
public:
   // Helper function to validate the BST.
   // It checks whether the subtree rooted at 'root' is a valid BST
   // within the range (minVal, maxVal).
   bool check(TreeNode* root, long long minVal, long long maxVal) {
      // If the current node is null, it's a valid BST.
      if (!root) {
         return true;
      }
      // If the current node's value is not within the allowed range, return false.
      if (root->val <= minVal || root->val >= maxVal) {
         return false;
      }
      // Recursively check the left subtree (with updated maxVal)
      // and the right subtree (with updated minVal).
      return check(root->left, minVal, root->val) &&
             check(root->right, root->val, maxVal);
   }

   // Main function to check if the binary tree is a valid BST.
   bool isValidBST(TreeNode* root) {
      return check(root, LLONG_MIN, LLONG_MAX);
   }
};

/*
 * Dry Run Example
 *
 * Consider the binary tree: [2, 1, 3]
 *
 * Initial Call:
 * isValidBST(root) where root->val = 2
 *
 * Step 1:
 * Call check(2, LLONG_MIN, LLONG_MAX)
 *  - 2 is between LLONG_MIN and LLONG_MAX, so continue.
 *
 * Step 2 (Left Subtree):
 * Call check(1, LLONG_MIN, 2)
 *  - 1 is between LLONG_MIN and 2.
 *  - Call check(NULL, LLONG_MIN, 1) -> returns true.
 *  - Call check(NULL, 1, 2) -> returns true.
 * => Left subtree of 2 is valid.
 *
 * Step 3 (Right Subtree):
 * Call check(3, 2, LLONG_MAX)
 *  - 3 is between 2 and LLONG_MAX.
 *  - Call check(NULL, 2, 3) -> returns true.
 *  - Call check(NULL, 3, LLONG_MAX) -> returns true.
 * => Right subtree of 2 is valid.
 *
 * Conclusion:
 * Since both left and right subtrees are valid, the binary tree is a valid BST.
 */
