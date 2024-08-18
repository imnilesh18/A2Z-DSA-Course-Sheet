/*
 * 138. Copy List with Random Pointer
 * 
 * A linked list of length n is given such that each node contains an additional
 * random pointer, which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n
 * brand new nodes, where each new node has its value set to the value of its
 * corresponding original node. Both the next and random pointer of the new
 * nodes should point to new nodes in the copied list such that the pointers in
 * the original list and copied list represent the same list state. None of the
 * pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where
 * X.random --> Y, then for the corresponding two nodes x and y in the copied
 * list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * The linked list is represented in the input/output as a list of n nodes. Each
 * node is represented as a pair of [val, random_index] where:
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random
 * pointer points to, or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
 * 
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 */

// Optimal Approach:
/*
// Definition for a Node.
class Node {
    int val;        // Value of the node
    Node next;      // Pointer to the next node in the linked list
    Node random;    // Pointer to a random node in the linked list

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null; // Edge case: If the original list is empty

        Node temp = head;

        // 1st Part: Inserting copied nodes in between original nodes
        while (temp != null) {
            Node copyNode = new Node(temp.val); // Create a copy of the current node
            copyNode.next = temp.next; // Link the copy node's next to the original node's next
            temp.next = copyNode; // Insert the copy node after the original node
            temp = copyNode.next; // Move to the next original node
        }

        // 2nd Part: Connecting the random pointers
        temp = head;
        while (temp != null) {
            Node copyNode = temp.next; // Get the copy node
            if (temp.random != null) {
                copyNode.random = temp.random.next; // Set the random pointer of the copy node
            } else {
                copyNode.random = null;
            }
            temp = temp.next.next; // Move to the next original node
        }

        // 3rd Part: Connecting the next pointers (Separating the copied nodes to form
        // the new list)
        Node dummyNode = new Node(-1); // Dummy node to help with extracting the copied list
        Node res = dummyNode;
        temp = head;
        while (temp != null) {
            res.next = temp.next; // Extract the copy node
            temp.next = temp.next.next; // Restore the original list's next pointer
            res = res.next; // Move to the next node in the copied list
            temp = temp.next; // Move to the next original node
        }

        return dummyNode.next; // Return the head of the copied linked list
    }
}
// Brute Force usign HashMap:
/*
 * // Definition for a Node.
 * class Node {
 * int val; // Value of the node
 * Node next; // Pointer to the next node in the linked list
 * Node random; // Pointer to a random node in the linked list
 * 
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */

class Solution {
    public Node copyRandomList(Node head) {
        Node temp = head;

        // Create a HashMap to store the mapping between original nodes and their copies
        HashMap<Node, Node> mpp = new HashMap<>();

        // First pass: Create a copy of each node and store the original node
        // and its copy in the HashMap
        while (temp != null) {
            Node newNode = new Node(temp.val); // Create a new node with the same value

            mpp.put(temp, newNode); // Map original node to the copied node

            temp = temp.next; // Move to the next node in the original list
        }

        temp = head;

        // Second pass: Set the next and random pointers for each copied node
        while (temp != null) {
            Node copyNode = mpp.get(temp); // Get the copied node corresponding to the current original node

            copyNode.next = mpp.get(temp.next); // Set the next pointer of the copied node
            copyNode.random = mpp.get(temp.random); // Set the random pointer of the copied node

            temp = temp.next; // Move to the next node in the original list
        }

        // Return the head of the copied linked list
        return mpp.get(head);
    }
}
