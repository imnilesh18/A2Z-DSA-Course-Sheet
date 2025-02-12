/*
 * 230. Kth Smallest Element in a BST
 *
 * Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 *
 * Example 1:
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 * Constraints:
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
 */

/*
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

// Approach: Use in-order traversal of the BST to process nodes in increasing order.
// During the traversal, decrement k and when k becomes 0, record the current node's value as the kth smallest element.
// Time Complexity: O(n) in the worst-case, where n is the number of nodes in the BST.
// Space Complexity: O(H) where H is the height of the tree due to the recursion stack.
class Solution {
public:
   // Helper function to perform in-order traversal.
   // In-order traversal of a BST yields nodes in ascending order.
   // 'k' is passed by reference and decremented each time a node is processed.
   // When 'k' reaches 0, the current node's value is the kth smallest element.
   void inorder(TreeNode* root, int&k, int&result) {
      if (!root) {
         return;
      }

      inorder(root->left, k, result); // Traverse the left subtree

      if (k == 0) {                   // If kth smallest is already found, exit early
         return;
      }

      k--;                   // Process the current node: decrement k

      if (k == 0) {          // If the current node is the kth smallest element
         result = root->val; // Record the current node's value
         return;
      }

      inorder(root->right, k, result);        // Traverse the right subtree
   }

   // Function to return the kth smallest element in the BST.
   int kthSmallest(TreeNode* root, int k) {
      int result = -1;          // Initialize result with a default value

      inorder(root, k, result); // Start in-order traversal to find kth smallest
      return result;            // Return the kth smallest element found
   }
};

/*
 * Dry Run:
 * Input: root = [3,1,4,null,2], k = 1
 *
 * Tree structure:
 *        3
 *       / \
 *      1   4
 *       \
 *        2
 *
 * Step-by-step:
 * 1. Start at root (3) and traverse left subtree.
 * 2. At node 1, traverse left (null) -> return.
 * 3. Process node 1: decrement k from 1 to 0, set result = 1, then return.
 * 4. Since k is 0, further traversal is stopped.
 * Final result = 1
 * End Dry Run.
 */
