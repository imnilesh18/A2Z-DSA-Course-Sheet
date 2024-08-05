/*
 * 234. Palindrome Linked List
 * Given the head of a singly linked list, return true if it is a
 * palindrome or false otherwise.
 * 
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 */

// Optimal Appraoch:
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
    // Method to reverse a singly-linked list
    public ListNode reverseLinkedList(ListNode head) {
        // Base case: if the list is empty or has only one node
        if (head == null || head.next == null) {
            return head;
        }

        // Recursively reverse the rest of the list
        ListNode newHead = reverseLinkedList(head.next);
        // Adjust the next pointers to reverse the current pair of nodes
        ListNode front = head.next;
        front.next = head;
        head.next = null;

        // Return the new head of the reversed list
        return newHead;
    }

    // Method to check if a singly-linked list is a palindrome
    public boolean isPalindrome(ListNode head) {
        // Base case: if the list is empty or has only one node
        if (head == null || head.next == null) {
            return true;
        }

        // Use two pointers to find the middle of the list
        ListNode slow = head;
        ListNode fast = head;

        // Move slow pointer one step and fast pointer two steps at a time
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the list
        ListNode newHead = reverseLinkedList(slow.next);
        // Pointers to compare nodes from the start and the middle
        ListNode first = head;
        ListNode second = newHead;

        // Compare nodes from the start and the reversed second half
        while (second != null) {
            // If any values do not match, it's not a palindrome
            if (first.val != second.val) {
                // Restore the original list structure before returning
                reverseLinkedList(newHead);
                return false;
            }
            first = first.next;
            second = second.next;
        }

        // Restore the original list structure
        reverseLinkedList(newHead);
        // If all values match, it's a palindrome
        return true;
    }
}

// Brute Force using Stack:

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
    public boolean isPalindrome(ListNode head) {
        ListNode temp = head;
        Stack<Integer> stack = new Stack<>();

        while (temp != null) {
            stack.push(temp.val);
            temp = temp.next;
        }

        temp = head;
        while (temp != null) {
            if (temp.val != stack.peek()) {
                return false;
            }
            stack.pop();
            temp = temp.next;
        }
        return true;
    }
}