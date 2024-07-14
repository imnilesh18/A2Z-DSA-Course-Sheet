/* GeeksforGeeks
Count Linked List Nodes

Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Examples :
Input: LinkedList : 1->2->3->4->5
Output: 5
Explanation: Count of nodes in the linked list is 5, which is its length.

Input: LinkedList : 2->4->6->7->5->1->0
Output: 7
Explanation: Count of nodes in the linked list is 7. Hence, the output is 7.

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)
*/

/*
class Node{
    int data;
    Node next;
    Node(int a){  data = a; next = null; }
}*/

class Solution {
    // Function to count nodes of a linked list.
    public int getCount(Node head) {
        Node temp = head;
        int cnt = 0;
        while (temp != null) {
            temp = temp.next;
            cnt++;
        }
        return cnt;
    }
}