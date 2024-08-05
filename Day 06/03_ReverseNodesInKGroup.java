/*
 * 25. Reverse Nodes in k-Group
 * Given the head of a linked list, reverse the nodes of the list k at a time,
 * and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked
 * list. If the number of nodes is not a multiple of k then left-out nodes, in
 * the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * Example 2:
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
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
    /**
     * Reverses a linked list starting from the given head.
     * 
     * @param head The head of the linked list to be reversed.
     * @return The new head of the reversed linked list.
     */
    public ListNode reverseLinkedList(ListNode head) {
        // Base case: if the list is empty or has only one node
        if (head == null || head.next == null) {
            return head;
        }

        // Recursive case: reverse the rest of the list
        ListNode newHead = reverseLinkedList(head.next);
        ListNode front = head.next;

        // Reverse the current node
        front.next = head;
        head.next = null;

        return newHead;
    }

    /**
     * Gets the k-th node from the given starting node.
     * 
     * @param temp The starting node of the linked list.
     * @param k    The position of the node to retrieve.
     * @return The k-th node from the starting node.
     */
    public ListNode getKthNode(ListNode temp, int k) {
        k -= 1; // Adjust k to be zero-indexed
        // Traverse the list to find the k-th node
        while (temp != null && k > 0) {
            k--;
            temp = temp.next;
        }
        return temp;
    }

    /**
     * Reverses nodes in k-group in the linked list.
     * 
     * @param head The head of the linked list.
     * @param k    The size of the group to reverse.
     * @return The new head of the linked list after reversing k-groups.
     */
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp = head;
        ListNode prevLast = null; // Keeps track of the end of the previous reversed section

        // Process the list in k-sized chunks
        while (temp != null) {
            // Find the k-th node from the current starting node
            ListNode kthNode = getKthNode(temp, k);

            // If there are less than k nodes remaining, do not reverse
            if (kthNode == null) {
                if (prevLast != null) {
                    prevLast.next = temp; // Connect the last reversed section to the current section
                    break;
                }
            }

            ListNode nextNode = kthNode.next; // Save the next node to process

            // Reverse the current k-sized group
            kthNode.next = null; // Temporarily terminate the list at k-th node
            reverseLinkedList(temp);

            // Connect the previous section to the newly reversed section
            if (temp == head) {
                head = kthNode; // Update head if this is the first reversed section
            } else {
                prevLast.next = kthNode; // Connect the previous section to the new reversed section
            }

            // Update pointers for the next iteration
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
}
