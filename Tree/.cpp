/*
 * 112. Path Sum
 *
 * Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 * A leaf is a node with no children.
 *
 * Example 1:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * Explanation: The root-to-leaf path with the target sum is shown.
 *
 * Example 2:
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * Explanation: There are two root-to-leaf paths in the tree:
 * (1 --> 2): The sum is 3.
 * (1 --> 3): The sum is 4.
 * There is no root-to-leaf path with sum = 5.
 *
 * Example 3:
 * Input: root = [], targetSum = 0
 * Output: false
 * Explanation: Since the tree is empty, there are no root-to-leaf paths.
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

// Approach: Use DFS to traverse the tree, accumulating the sum along each path and checking if any leaf node's cumulative sum equals targetSum.
// Time Complexity: O(N), where N is the number of nodes, as each node is visited once.
// Space Complexity: O(H), where H is the height of the tree, due to the recursion stack.
// C++ Code with Comments for Problem 112: Path Sum
class Solution {
public:
   // Helper function to check for a root-to-leaf path with the given sum.
   bool fill(TreeNode* root, int sum, int& targetSum) {
      if (!root) {       // If the current node is null, no valid path exists.
         return false;
      }

      sum += root->val;       // Add the current node's value to the cumulative sum.

      // If the node is a leaf, check if the accumulated sum equals targetSum.
      if (root->left == nullptr && root->right == nullptr) {
         if (sum == targetSum) {
            return true;
         }
      }

      // Recursively check the left and right subtrees.
      return fill(root->left, sum, targetSum) || fill(root->right, sum, targetSum);
   }

   // Main function to determine if there is any root-to-leaf path that equals targetSum.
   bool hasPathSum(TreeNode* root, int targetSum) {
      int sum = 0;       // Initialize the cumulative sum.

      return fill(root, sum, targetSum);
   }
};

/* *** Dry Run ***
 * Tree Visualization for Example 1:
 *         5
 *       /   \
 *      4     8
 *     /     / \
 *    11    13  4
 *   /  \        \
 *  7    2         1
 *
 * Step-by-step:
 * 1. Start at the root (5):
 * - Current Path Sum: 5
 *
 * 2. Traverse left to node (4):
 * - Current Path Sum: 5 + 4 = 9
 *
 * 3. Traverse left to node (11):
 * - Current Path Sum: 9 + 11 = 20
 *
 * 4. Traverse left to node (7):
 * - Current Path Sum: 20 + 7 = 27
 * - Leaf reached: 27 != 22 → returns false.
 *
 * 5. Backtrack to node (11) and traverse right to node (2):
 * - Current Path Sum: 20 + 2 = 22
 * - Leaf reached: 22 == targetSum → returns true.
 *
 * 6. Since a valid path is found (5 → 4 → 11 → 2), the function returns true.
 */
