/*
 * 61. Rotate List
 * 
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * Example 2:
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
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
    public ListNode rotateRight(ListNode head, int k) {
        // If the list is empty or has only one node, return it as is
        if (head == null || head.next == null) {
            return head;
        }

        // Calculate the length of the list
        int length = 1;
        ListNode tail = head;
        while (tail.next != null) {
            length++;
            tail = tail.next;
        }

        // If k is a multiple of the length, the list remains unchanged
        if (k % length == 0) {
            return head;
        }

        // Connect the tail to the head to form a circular list
        tail.next = head;

        // Calculate the effective number of rotations needed
        k = k % length;
        int move = length - k;

        // Find the new head and break the circular list
        ListNode temp = head;
        while (move > 0) {
            move--;
            if (move == 0) {
                head = temp.next; // New head of the rotated list
                temp.next = null; // Break the circular list
            }
            temp = temp.next;
        }
        return head;
    }
}
