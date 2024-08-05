/*
 * 142. Linked List Cycle II
 * Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is connected
 * to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as
 * a parameter.
 * Do not modify the linked list.
 * 
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 */

//Optimal Approach using Tortoise and Hare Algorithm:

/**
 * Definition for singly-linked list.
 * class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */

public class Solution {

    // Method to detect a cycle in a linked list and return the node where the cycle
    // begins
    public ListNode detectCycle(ListNode head) {
        // Initialize two pointers, slow and fast, both starting at the head
        ListNode slow = head;
        ListNode fast = head;

        // Traverse the list with two pointers
        // Fast pointer moves two steps at a time, slow pointer moves one step at a time
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            // If slow and fast meet, a cycle is detected
            if (slow == fast) {
                // Move slow pointer to the head and keep fast at the meeting point
                slow = head;
                // Move both pointers one step at a time until they meet again
                // The meeting point is the start of the cycle
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow; // Return the start node of the cycle
            }
        }

        // If no cycle is detected, return null
        return null;
    }
}

// Brute Force using HashMap:
/**
 * Definition for singly-linked list.
 * class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        HashMap<ListNode, Integer> mpp = new HashMap<>();
        ListNode temp = head;
        while (temp != null) {
            if (mpp.containsKey(temp)) {
                return temp;
            }
            mpp.put(temp, 1);
            temp = temp.next;
        }
        return null;
    }
}
