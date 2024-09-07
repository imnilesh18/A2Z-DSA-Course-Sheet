/*
 * 1367. Linked List in Binary Tree
 * 
 * Given a binary tree root and a linked list with head as the first node.
 * Return True if all the elements in the linked list starting from the head
 * correspond to some downward path connected in the binary tree otherwise
 * return False.
 * In this context downward path means a path that starts at some node and goes
 * downwards.
 * 
 * Example 1:
 * Input: head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 * Explanation: Nodes in blue form a subpath in the binary Tree.
 * 
 * Example 2:
 * Input: head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: true
 * 
 * Example 3:
 * Input: head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * Output: false
 * Explanation: There is no path in the binary tree that contains all the
 * elements of the linked list from head.
 * 
 * Constraints:
 * The number of nodes in the tree will be in the range [1, 2500].
 * The number of nodes in the list will be in the range [1, 100].
 * 1 <= Node.val <= 100 for each node in the linked list and binary tree
 */


// Time Complexity: O(n*m), where n is the number of nodes in the binary tree and m is the length of the linked list.
// Space Complexity: In the worst case of a skewed tree, the space complexity will be O(n + m) due to the recursive stack.

// Without Comments:
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    boolean check(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        }
        if (root == null) {
            return false;
        }
        if (root.val != head.val) {
            return false;
        }
        return check(head.next, root.left) || check(head.next, root.right);
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) {
            return false;
        }
        return check(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }
}

// Code with added comments for better understanding

// Time Complexity: O(n*m), where n is the number of nodes in the binary tree and m is the length of the linked list.
// Space Complexity: In the worst case of a skewed tree, the space complexity will be O(n + m) due to the recursive stack.

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    /**
     * This method checks if the current path in the binary tree starting
     * from the node 'root' contains the sequence of values from the linked list
     * starting with 'head'.
     * 
     * @param head the current node in the linked list.
     * @param root the current node in the binary tree.
     * @return true if the linked list matches a path in the tree, otherwise false.
     */
    boolean check(ListNode head, TreeNode root) {

        // Base case 1: If we have reached the end of the linked list, 
        // it means we've successfully matched all nodes.
        if (head == null) { 
            return true; // Successfully found the entire linked list.
        }

        // Base case 2: If we have reached a null node in the tree 
        // and still have remaining nodes in the linked list, return false.
        if (root == null) { 
            return false; // No more nodes to match in the tree.
        }

        // If the current values of the linked list and tree node do not match, return false.
        if (root.val != head.val) {
            return false; // Current values do not match.
        }
        
        // Recursively check either the left or right subtree for the next node in the list.
        return check(head.next, root.left) || check(head.next, root.right);
    }

    /**
     * This method checks if there is any path in the binary tree that matches the given linked list.
     * 
     * @param head the head of the linked list.
     * @param root the root of the binary tree.
     * @return true if there exists a sub-path in the binary tree that matches the linked list, otherwise false.
     */
    public boolean isSubPath(ListNode head, TreeNode root) {

        // Base case: If the binary tree is empty, there can't be any sub-path, return false.
        if (root == null) {
            return false; 
        }

        // Check the current node of the tree for a matching path using the 'check' method.
        // If not found, recursively check the left and right subtrees.
        return check(head, root) ||
               isSubPath(head, root.left) || // Recursively check the left subtree.
               isSubPath(head, root.right);  // Recursively check the right subtree.
    }
}


