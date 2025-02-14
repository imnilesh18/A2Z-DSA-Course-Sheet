/*
 * 99. Recover Binary Search Tree
 *
 * You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
 *
 * Example 1:
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
 *
 * Example 2:
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 * Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
 */

// Approach: Use in-order traversal to find the two nodes that are out of order (violating BST properties) and then swap their values.
// TC: O(n) - We traverse each node exactly once during in-order traversal.
// SC: O(h) - The recursion stack uses O(h) space, where h is the height of the tree.
class Solution {
public:
   TreeNode* first = nullptr, * second = nullptr, * prev = nullptr;

   // In-order traversal to identify the two nodes that are swapped by mistake
   void inOrder(TreeNode* root) {
      if (root == nullptr) {
         return;
      }

      // Traverse the left subtree
      inOrder(root->left);

      // Detect the violation: if previous node's value is greater than current node's value
      if (prev != nullptr && root->val < prev->val) {
         if (first == nullptr) {
            first = prev;       // Mark the first node that is out of order
         }
         second = root;         // Mark the second node that is out of order (update if more than one violation)
      }

      // Update the previous node pointer to current node
      prev = root;

      // Traverse the right subtree
      inOrder(root->right);
   }

   // Function to recover the BST by swapping the values of the two incorrect nodes
   void recoverTree(TreeNode* root) {
      inOrder(root);                    // Identify the two swapped nodes using in-order traversal
      if (first != nullptr && second != nullptr) {
         swap(first->val, second->val); // Swap the values to fix the BST
      }
   }
};

/*
 * Dry Run:
 * Input Tree: [3,1,4,null,null,2]
 * In-order Traversal Sequence: 1, 3, 2, 4
 * Violation detected when comparing 3 and 2 (since 2 < 3): first = node with value 3, second = node with value 2.
 * After in-order traversal, swap the values of first (3) and second (2).
 * Corrected Tree becomes: [2,1,4,null,null,3]
 */
