/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 *
 * Example 1:
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 * Constraints:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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

// Approach: Use recursion to construct the binary tree by selecting the current element in the preorder array as the root,
//           locating its index in the inorder array to determine the left and right subtrees, and recursively constructing these subtrees.
// Time Complexity: O(n^2) in the worst-case (due to linear search in the inorder array), which can be improved to O(n) with a hash map.
// Space Complexity: O(n) due to the recursion stack space in the worst-case.
class Solution {
public:
   // Recursive helper function to construct the tree.
   TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
      // Base case: if there are no elements to form a subtree.
      if (start > end) {
         return nullptr;
      }

      // Get the current root value from the preorder array.
      int rootVal = preorder[idx];

      // Locate the index of rootVal in the inorder array.
      int i;
      for (i = start; i <= end; i++) {
         if (inorder[i] == rootVal) {
            break;
         }
      }

      // Increment the preorder index for the next recursive call.
      idx++;

      // Create a new tree node with the current root value.
      TreeNode* root = new TreeNode(rootVal);

      // Recursively build the left subtree using elements before index 'i' in inorder.
      root->left = solve(preorder, inorder, start, i - 1, idx);

      // Recursively build the right subtree using elements after index 'i' in inorder.
      root->right = solve(preorder, inorder, i + 1, end, idx);

      // Return the constructed subtree rooted at 'root'.
      return root;
   }

   // Main function to build the binary tree from preorder and inorder traversals.
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n   = preorder.size();  // Number of nodes in the tree.
      int idx = 0;                // Initialize the index pointer for preorder traversal.

      return solve(preorder, inorder, 0, n - 1, idx);
   }
};

/*
 * Dry Run Example: For preorder = [3,9,20,15,7] and inorder = [9,3,15,20,7]:
 *  - idx = 0: root = 3; found in inorder at index 1.
 *       Left subtree: inorder indices [0,0] -> picks 9 as root (leaf node).
 *       Right subtree: inorder indices [2,4] -> picks 20 as root.
 *  - For the subtree with root 20: found in inorder at index 3.
 *       Left subtree: inorder indices [2,2] -> picks 15 as leaf.
 *       Right subtree: inorder indices [4,4] -> picks 7 as leaf.
 *  Final Tree Structure: [3, 9, 20, null, null, 15, 7]
 */
