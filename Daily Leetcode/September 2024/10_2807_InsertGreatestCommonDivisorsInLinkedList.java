/*
 * 2807. Insert Greatest Common Divisors in Linked List
 * 
 * Given the head of a linked list head, in which each node contains an integer
 * value.
 * Between every pair of adjacent nodes, insert a new node with a value equal to
 * the greatest common divisor of them.
 * Return the linked list after insertion.
 * The greatest common divisor of two numbers is the largest positive integer
 * that evenly divides both numbers.
 * 
 * Example 1:
 * Input: head = [18,6,10,3]
 * Output: [18,6,6,2,10,1,3]
 * Explanation: The 1st diagram denotes the initial linked list and the 2nd
 * diagram denotes the linked list after inserting the new nodes (nodes in blue
 * are the inserted nodes).
 * - We insert the greatest common divisor of 18 and 6 = 6 between the 1st and
 * the 2nd nodes.
 * - We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and
 * the 3rd nodes.
 * - We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and
 * the 4th nodes.
 * There are no more adjacent nodes, so we return the linked list.
 * 
 * Example 2:
 * Input: head = [7]
 * Output: [7]
 * Explanation: The 1st diagram denotes the initial linked list and the 2nd
 * diagram denotes the linked list after inserting the new nodes.
 * There are no pairs of adjacent nodes, so we return the initial linked list.
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 5000].
 * 1 <= Node.val <= 1000
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    public static int findGCD(int M, int N) {
        while (N != 0) {
            int R = M % N;
            M = N;
            N = R;
        }
        return M;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode prevNode = head;
        ListNode nextNode = head.next;

        while (nextNode != null) {
            ListNode gcdNode = new ListNode(findGCD(prevNode.val, nextNode.val));

            prevNode.next = gcdNode;
            gcdNode.next = nextNode;
            prevNode = nextNode;
            nextNode = nextNode.next;
        }

        return head;
    }
}

// Code with comments for better understanding:

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
class Solution {

    /**
     * Method to find the Greatest Common Divisor (GCD) of two integers using the Euclidean algorithm.
     * @param M - First integer
     * @param N - Second integer
     * @return GCD of M and N
     */
    public static int findGCD(int M, int N) {
        while (N != 0) {
            int R = M % N;  // Remainder when M is divided by N
            M = N;  // Update M to N
            N = R;  // Update N to the remainder
        }
        return M;  // GCD is found when N becomes 0
    }

    /**
     * Method to insert a new node between each pair of consecutive nodes in the linked list.
     * The new node contains the GCD of the values of the consecutive nodes.
     * @param head - The head of the singly linked list
     * @return The modified linked list with GCD nodes inserted
     */
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        // If the list is empty or has only one node, return the head (no insertion needed)
        if (head == null || head.next == null) {
            return head;
        }

        // Initialize pointers for the current node (prevNode) and the next node (nextNode)
        ListNode prevNode = head;
        ListNode nextNode = head.next;

        // Traverse the list while there are pairs of nodes to process
        while (nextNode != null) {
            // Create a new node with the GCD of the current and next node's values
            ListNode gcdNode = new ListNode(findGCD(prevNode.val, nextNode.val));

            // Insert the GCD node between prevNode and nextNode
            prevNode.next = gcdNode;
            gcdNode.next = nextNode;

            // Move the pointers forward in the list
            prevNode = nextNode;
            nextNode = nextNode.next;
        }

        // Return the modified list
        return head;
    }
}

// Approach 2 Recursion Leap of Faith: :)

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
class Solution {

    public static int findGCD(int M, int N) {
        while (N != 0) {
            int R = M % N;
            M = N;
            N = R;
        }
        return M;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        // Base case: if the list is empty or has only one element, return the head as is
        if (head == null || head.next == null) {
            return head;
        }

        // Insert the GCD node recursively
        ListNode temp = insertGreatestCommonDivisors(head.next);

        // Create a new node with the GCD of current and next node values
        ListNode gcdNode = new ListNode(findGCD(head.val, head.next.val));
        
        // Insert the new node between current node and next node
        gcdNode.next = temp;
        head.next = gcdNode;

        return head;
    }
}
