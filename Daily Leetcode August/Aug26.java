/*
 * 590. N-ary Tree Postorder Traversal
 * 
 * Given the root of an n-ary tree, return the postorder traversal of its nodes'
 * values.
 * Nary-Tree input serialization is represented in their level order traversal.
 * Each group of children is separated by the null value (See examples)
 * 
 * Example 1:
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [5,6,3,2,4,1]
 * 
 * Example 2:
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,
 * null,null,14]
 * Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 */

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    // Helper method to perform depth-first search (DFS) for postorder traversal
    public void dfs(Node root, List<Integer> list) {
        // Base case: if the root is null, return (no action needed)
        if (root == null) {
            return;
        }
        
        // Recursively call dfs on all children of the current node
        for (Node child : root.children) {
            dfs(child, list);
        }
        
        // After visiting all children, add the current node's value to the list
        list.add(root.val);
    }
    
    // Main method to return the postorder traversal of an N-ary tree
    public List<Integer> postorder(Node root) {
        // Create a list to store the traversal result
        List<Integer> list = new ArrayList<>();
        
        // Start the DFS traversal from the root node
        dfs(root, list);
        
        // Return the result list containing the postorder traversal
        return list;
    }
}