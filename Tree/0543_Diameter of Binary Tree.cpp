/*
 * 543. Diameter of Binary Tree
 *
 * Given the root of a binary tree, return the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * The length of a path between two nodes is represented by the number of edges between them.
 *
 * Example 1:
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Example 2:
 * Input: root = [1,2]
 * Output: 1
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
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

// Approach: Use postorder traversal to compute the height of each subtree while updating the diameter (sum of left and right subtree heights) at each node.
// Time Complexity: O(n) (Each node is visited once)
// Space Complexity: O(n) (In worst-case, recursion stack space for a skewed tree)
class Solution {
public:
   // Helper function to compute the height of a node while updating the diameter.
   int solve(TreeNode* root, int& result) {
      // Base case: If node is NULL, return height as 0.
      if (!root) {
         return 0;
      }

      // Recursively find the height of the left subtree.
      int lh = solve(root->left, result);
      // Recursively find the height of the right subtree.
      int rh = solve(root->right, result);

      // Update the diameter (longest path) found so far.
      result = max(result, lh + rh);

      // Return height of the current node.
      return 1 + max(lh, rh);
   }

   // Function to find the diameter of the binary tree.
   int diameterOfBinaryTree(TreeNode* root) {
      // If tree is empty, return 0.
      if (!root) {
         return 0;
      }

      // Initialize result to the smallest possible integer value.
      int result = INT_MIN;

      // Call the helper function to compute the height and update the diameter.
      solve(root, result);

      // Return the maximum diameter found.
      return result;
   }
};

/*
 * Dry Run:
 * Consider the binary tree:
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * Step 1: Call diameterOfBinaryTree(Node(1)):
 * - Check if root is NULL → false.
 * - Initialize result = INT_MIN.
 * - Call solve(Node(1)).
 *
 * Step 2: solve(Node(1)):
 * - Call solve(Node(2)):
 * Call solve(Node(4)):
 *         - Both left and right are NULL → returns 0.
 *         - Update result = max(INT_MIN, 0 + 0) = 0.
 *         - Return height = 1 + max(0, 0) = 1.
 * Call solve(Node(5)):
 *         - Both left and right are NULL → returns 0.
 *         - Update result = max(0, 0 + 0) = 0.
 *         - Return height = 1 + max(0, 0) = 1.
 * Back at Node(2):
 *         - Left height = 1, right height = 1.
 *         - Update result = max(0, 1 + 1) = 2.
 *         - Return height = 1 + max(1, 1) = 2.
 * - Call solve(Node(3)):
 * Both left and right are NULL → returns 0.
 * Update result = max(2, 0 + 0) = 2.
 * Return height = 1 + max(0, 0) = 1.
 * - Back at Node(1):
 * Left height = 2 (from Node(2)), right height = 1 (from Node(3)).
 * Update result = max(2, 2 + 1) = 3.
 * Return height = 1 + max(2, 1) = 3.
 *
 * Step 3: diameterOfBinaryTree(Node(1)) returns result = 3.
 */
