/*
 * 113. Path Sum II
 *
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
 *
 * A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 *
 * Example 1:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * Explanation: There are two paths whose sum equals targetSum:
 * 5 + 4 + 11 + 2 = 22
 * 5 + 8 + 4 + 5 = 22
 *
 * Example 2:
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 *
 * Example 3:
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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

// Approach: Use DFS to explore all root-to-leaf paths, accumulating the sum and storing the path when a leaf node's sum equals targetSum.
// Time Complexity: O(N) average; worst-case O(N^2) in skewed trees due to vector copying.
// Space Complexity: O(H), where H is the height of the tree, for recursion stack and temporary path storage.
class Solution {
public:
   vector<vector<int> > result;     // stores all valid paths

   // Helper function to perform DFS on the tree.
   void fill(TreeNode* root, int sum, vector<int> temp, int& targetSum) {
      if (!root) {       // if node is null, return
         return;
      }
      sum += root->val;                  // add current node's value to running sum
      temp.push_back(root->val);         // add current node's value to current path

      // Check if current node is a leaf node.
      if (root->left == nullptr && root->right == nullptr) {
         if (sum == targetSum) {         // if sum equals targetSum, add current path to result
            result.push_back(temp);
         }
         return;
      }

      // Recurse on left and right subtrees.
      fill(root->left, sum, temp, targetSum);
      fill(root->right, sum, temp, targetSum);
   }

   vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
      int         sum = 0;
      vector<int> temp;

      fill(root, sum, temp, targetSum);       // start DFS traversal from root
      return result;
   }
};

/* *** Dry Run ***
 * Tree Visualization:
 *          5
 *        /   \
 *       4     8
 *      /     / \
 *    11     13  4
 *   /  \       / \
 *  7    2     5   1
 *
 * Step-by-step:
 * 1. Start at node 5 (root):
 * - Current Path: [5]
 * - Current Sum: 5
 *
 * 2. Traverse to left child, node 4:
 * - Current Path: [5, 4]
 * - Current Sum: 9
 *
 * 3. Traverse to left child, node 11:
 * - Current Path: [5, 4, 11]
 * - Current Sum: 20
 *
 * 4. Traverse to left child, node 7:
 * - Current Path: [5, 4, 11, 7]
 * - Current Sum: 27
 * - Node 7 is a leaf but 27 != 22; backtrack.
 *
 * 5. Back at node 11, traverse to right child, node 2:
 * - Current Path: [5, 4, 11, 2]
 * - Current Sum: 22
 * - Node 2 is a leaf and 22 == targetSum; add path [5, 4, 11, 2] to result.
 *
 * 6. Backtrack to root (5) and traverse to right child, node 8:
 * - Current Path: [5, 8]
 * - Current Sum: 13
 *
 * 7. Traverse to left child, node 13:
 * - Current Path: [5, 8, 13]
 * - Current Sum: 26
 * - Node 13 is a leaf but 26 != 22; backtrack.
 *
 * 8. Back at node 8, traverse to right child, node 4:
 * - Current Path: [5, 8, 4]
 * - Current Sum: 17
 *
 * 9. Traverse to left child, node 5:
 * - Current Path: [5, 8, 4, 5]
 * - Current Sum: 22
 * - Node 5 is a leaf and 22 == targetSum; add path [5, 8, 4, 5] to result.
 *
 * 10. Back at node 4 (child of node 8), traverse to right child, node 1:
 *  - Current Path: [5, 8, 4, 1]
 *  - Current Sum: 18
 *  - Node 1 is a leaf but 18 != 22; backtrack.
 *
 * Final Result: [[5, 4, 11, 2], [5, 8, 4, 5]]
 */
