/*
 * 437. Path Sum III
 * // Solve Path Sum (LeetCode: 112) and Path Sum II (LeetCode: 113)
 *
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 *
 * Example 1:
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 * Example 2:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
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

// Approach: Use DFS with a prefix sum hashmap to track cumulative sums; for each node, check if (currentSum - targetSum)
// exists in the hashmap to count the valid paths.
// Time Complexity: O(n) - Each node is visited exactly once.
// Space Complexity: O(n) - In the worst-case (skewed tree), the recursion stack and hashmap can hold up to n elements.
class Solution {
public:
   // DFS helper function that returns the count of valid paths in the subtree rooted at 'root'
   int fill(TreeNode* root, int k, long long currSum, unordered_map<long long, int>& prefixSum) {
      if (!root) {   // Base case: if the current node is null, return 0 as there are no paths.
         return 0;
      }

      currSum += root->val;   // Update the current prefix sum with the value of the current node.

      // Count the number of times a prefix sum of (currSum - targetSum) has occurred.
      // This indicates the number of valid paths ending at the current node.
      int count = prefixSum[currSum - k];

      // Add the current prefix sum to the hashmap.
      prefixSum[currSum]++;

      // Recursively search for valid paths in the left and right subtrees.
      count += fill(root->left, k, currSum, prefixSum);
      count += fill(root->right, k, currSum, prefixSum);

      // Backtrack: remove the current prefix sum from the hashmap before returning to the parent.
      prefixSum[currSum]--;

      return count;   // Return the total count of valid paths found in this subtree.
   }

   // Main function that initializes the prefixSum map and calls the helper function.
   int pathSum(TreeNode* root, int targetSum) {
      unordered_map<long long, int> prefixSum;

      prefixSum[0] = 1;   // Base case: a prefix sum of 0 occurs once (for the empty path).
      return fill(root, targetSum, 0LL, prefixSum);
   }
};

// Dry Run:

/*
 * Consider the binary tree:
 *            10
 *           /  \
 *          5    -3
 *         / \     \
 *        3   2     11
 *       / \   \
 *      3  -2   1
 * TargetSum = 8
 *
 * 1. Start at root (10):
 *    - currentSum = 10
 *    - prefixSum = {0:1, 10:1}
 *    - count = prefixSum[10 - 8] = prefixSum[2] = 0
 *
 * 2. Go left to node (5):
 *    - currentSum = 10 + 5 = 15
 *    - prefixSum = {0:1, 10:1, 15:1}
 *    - count = prefixSum[15 - 8] = prefixSum[7] = 0
 *
 * 3. Go left to node (3) under (5):
 *    - currentSum = 15 + 3 = 18
 *    - prefixSum = {0:1, 10:1, 15:1, 18:1}
 *    - count = prefixSum[18 - 8] = prefixSum[10] = 1   (Valid path: 10 -> 5 -> 3)
 *
 * 4. Go left to node (3) under the previous (3):
 *    - currentSum = 18 + 3 = 21
 *    - prefixSum = {0:1, 10:1, 15:1, 18:1, 21:1}
 *    - count = prefixSum[21 - 8] = prefixSum[13] = 0
 *    - Backtrack: remove currentSum 21 from prefixSum.
 *
 * 5. Go right to node (-2) under the first (3):
 *    - currentSum = 18 + (-2) = 16
 *    - prefixSum = {0:1, 10:1, 15:1, 18:1, 16:1}
 *    - count = prefixSum[16 - 8] = prefixSum[8] = 0
 *    - Backtrack: remove currentSum 16 from prefixSum.
 *
 * 6. Backtrack from node (3) under (5): remove currentSum 18 from prefixSum.
 *
 * 7. Go right to node (2) under (5):
 *    - currentSum = 15 + 2 = 17
 *    - prefixSum = {0:1, 10:1, 15:1, 17:1}
 *    - count = prefixSum[17 - 8] = prefixSum[9] = 0
 *
 * 8. Go right to node (1) under (2):
 *    - currentSum = 17 + 1 = 18
 *    - prefixSum = {0:1, 10:1, 15:1, 17:1, 18:1}
 *    - count = prefixSum[18 - 8] = prefixSum[10] = 1   (Valid path: 10 -> 5 -> 2 -> 1)
 *    - Backtrack: remove currentSum 18 from prefixSum.
 *
 * 9. Backtrack from node (2): remove currentSum 17 from prefixSum.
 * 10. Backtrack from node (5): remove currentSum 15 from prefixSum.
 *
 * 11. Go right to node (-3) of root (10):
 *     - currentSum = 10 + (-3) = 7
 *     - prefixSum = {0:1, 10:1, 7:1}
 *     - count = prefixSum[7 - 8] = prefixSum[-1] = 0
 *
 * 12. Go right to node (11) under (-3):
 *     - currentSum = 7 + 11 = 18
 *     - prefixSum = {0:1, 10:1, 7:1, 18:1}
 *     - count = prefixSum[18 - 8] = prefixSum[10] = 1   (Valid path: 10 -> -3 -> 11)
 *     - Backtrack: remove currentSum 18 from prefixSum.
 *
 * 13. Backtrack from node (-3): remove currentSum 7 from prefixSum.
 * 14. Backtrack from root (10): remove currentSum 10 from prefixSum.
 *
 * Total valid paths = 1 (from step 3) + 1 (from step 8) + 1 (from step 12) = 3.
 */
