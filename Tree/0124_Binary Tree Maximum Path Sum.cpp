/*
 * 124. Binary Tree Maximum Path Sum
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.A node can only appear in the sequence at most once.Note that the path does not need to pass through the root.
 * The path sum of a path is the sum of the node 's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 *
 * Example 1:
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 *
 * Example 2:
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 3 * 10^4].
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


// Approach: Use recursion to compute the maximum path sum at each node by considering three possibilities:
// 1) a path that passes through the node including both subtrees,
// 2) a path extending from the node through one subtree, and
// 3) the node itself, while updating a global maximum.
// TC: O(n) - Each node is visited once.
// SC: O(h) - Recursion stack space, where h is the height of the tree.
class Solution {
public:
   int maxSum;  // Global variable to store the maximum path sum

   // Recursive function to calculate the maximum path sum that can be extended from the current node.
   int solve(TreeNode* root) {
      if (!root) {
         return 0;    // Base case: if the node is null, return 0.
      }

      // Recursively compute the maximum path sum from the left and right subtrees.
      int lh = solve(root->left);
      int rh = solve(root->right);

      // Calculate the path sum when the path passes through the current node including both left and right paths.
      int sumThroughRoot = lh + rh + root->val;

      // Calculate the maximum path sum when extending from the current node to one child.
      int maxChildPath = max(lh, rh) + root->val;

      // Consider the path that consists of only the current node.
      int singleNode = root->val;

      // Update the global maximum path sum with the best option among the computed values.
      maxSum = max({ maxSum, sumThroughRoot, maxChildPath, singleNode });

      // Return the maximum path sum extendable to the parent node.
      return max(maxChildPath, singleNode);
   }

   // Function to return the maximum path sum from any non-empty path in the binary tree.
   int maxPathSum(TreeNode* root) {
      maxSum = INT_MIN;   // Initialize maxSum to the smallest possible integer value.
      solve(root);        // Start the recursive computation from the root.
      return maxSum;      // Return the overall maximum path sum found.
   }
};

/*
 * Dry Run:
 * Consider the tree:
 *         -10
 *         /  \
 *        9   20
 *           /  \
 *          15   7
 *
 * Step 1: solve(9):
 *   - Both children are null, so:
 *       singleNode = 9
 *       maxChildPath = 9
 *       sumThroughRoot = 9
 *   - Update maxSum: max(INT_MIN, 9, 9, 9) = 9
 *   - Return 9.
 *
 * Step 2: solve(15):
 *   - Both children are null, so:
 *       singleNode = 15
 *       maxChildPath = 15
 *       sumThroughRoot = 15
 *   - Update maxSum: max(9, 15, 15, 15) = 15
 *   - Return 15.
 *
 * Step 3: solve(7):
 *   - Both children are null, so:
 *       singleNode = 7
 *       maxChildPath = 7
 *       sumThroughRoot = 7
 *   - maxSum remains max(15, 7, 7, 7) = 15
 *   - Return 7.
 *
 * Step 4: solve(20):
 *   - Left child returns 15 and right child returns 7, so:
 *       singleNode = 20
 *       maxChildPath = max(15, 7) + 20 = 35
 *       sumThroughRoot = 15 + 7 + 20 = 42
 *   - Update maxSum: max(15, 42, 35, 20) = 42
 *   - Return max(35, 20) = 35.
 *
 * Step 5: solve(-10):
 *   - Left child returns 9 and right child returns 35, so:
 *       singleNode = -10
 *       maxChildPath = max(9, 35) - 10 = 25
 *       sumThroughRoot = 9 + 35 - 10 = 34
 *   - Update maxSum: max(42, 34, 25, -10) = 42
 *   - Return max(25, -10) = 25.
 *
 * Final maximum path sum = 42.
 */
