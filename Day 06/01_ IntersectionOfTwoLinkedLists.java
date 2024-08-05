/*
 * 160. Intersection of Two Linked Lists
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 * For example, the following two linked lists begin to intersect at node c1:
 * The test cases are generated such that there are no cycles anywhere in the
 * entire linked structure.
 * Note that the linked lists must retain their original structure after the
 * function returns.
 * Custom Judge:
 * The inputs to the judge are given as follows (your program is not given these
 * inputs):
 * intersectVal - The value of the node where the intersection occurs. This is 0
 * if there is no intersected node.
 * listA - The first linked list.
 * listB - The second linked list.
 * skipA - The number of nodes to skip ahead in listA (starting from the head)
 * to get to the intersected node.
 * skipB - The number of nodes to skip ahead in listB (starting from the head)
 * to get to the intersected node.
 * The judge will then create the linked structure based on these inputs and
 * pass the two heads, headA and headB to your program. If you correctly return
 * the intersected node, then your solution will be accepted.
 * 
 * Example 1:
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Intersected at '8'
 * Explanation: The intersected node's value is 8 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as
 * [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are
 * 3 nodes before the intersected node in B.
 * - Note that the intersected node's value is not 1 because the nodes with
 * value 1 in A and B (2nd node in A and 3rd node in B) are different node
 * references. In other words, they point to two different locations in memory,
 * while the nodes with value 8 in A and B (3rd node in A and 4th node in B)
 * point to the same location in memory.
 * 
 * Example 2:
 * Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Intersected at '2'
 * Explanation: The intersected node's value is 2 (note that this must not be 0
 * if the two lists intersect).
 * From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as
 * [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node
 * before the intersected node in B.
 * 
 * Example 3:
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * Output: No intersection
 * Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it
 * reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0,
 * while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 */

// Optimal Approach:
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // If either headA or headB is null, there is no intersection
        if (headA == null || headB == null) {
            return null;
        }

        // Initialize two pointers to traverse the lists
        ListNode t1 = headA;
        ListNode t2 = headB;

        // Traverse the lists until the two pointers meet
        while (t1 != t2) {

            // Move t1 to the next node in list A
            t1 = t1.next;
            // Move t2 to the next node in list B
            t2 = t2.next;

            // If t1 equals t2, it means the intersection is found
            if (t1 == t2) {
                return t1;
            }

            // If t1 reaches the end of list A, start from the beginning of list B
            if (t1 == null) {
                t1 = headB;
            }
            // If t2 reaches the end of list B, start from the beginning of list A
            if (t2 == null) {
                t2 = headA;
            }
        }
        // When t1 equals t2, they either point to the intersection node or both are
        // null (no intersection)
        return t1;
    }
}

// Difference in length Approach:
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {

    // Helper method to find the collision point of two linked lists.
    // t1 and t2 are the heads of the linked lists, and d is the difference in
    // lengths.
    public ListNode collisionPoint(ListNode t1, ListNode t2, int d) {
        // Move the pointer t2 ahead by d steps.
        while (d > 0) {
            d--;
            t2 = t2.next;
        }
        // Move both pointers until they collide (point to the same node).
        while (t1 != t2) {
            t1 = t1.next;
            t2 = t2.next;
        }
        // Return the collision point (intersection node).
        return t1;
    }

    // Main method to get the intersection node of two linked lists.
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode t1 = headA;
        int n1 = 0;
        ListNode t2 = headB;
        int n2 = 0;

        // Calculate the length of the first linked list.
        while (t1 != null) {
            n1++;
            t1 = t1.next;
        }

        // Calculate the length of the second linked list.
        while (t2 != null) {
            n2++;
            t2 = t2.next;
        }

        // Use the collisionPoint method to find the intersection node.
        // If the first list is shorter, move the head of the second list ahead by the
        // length difference.
        if (n1 < n2) {
            return collisionPoint(headA, headB, n2 - n1);
        }
        // If the second list is shorter, move the head of the first list ahead by the
        // length difference.
        else {
            return collisionPoint(headB, headA, n1 - n2);
        }
    }
}

// Brure Force: Using HashSet:
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> mpp = new HashSet<>();

        ListNode temp = headA;
        while (temp != null) {
            mpp.add(temp);
            temp = temp.next;
        }
        temp = headB;
        while (temp != null) {
            if (mpp.contains(temp)) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }
}

// Brute Force: Using HashMap
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashMap<ListNode, Integer> mpp = new HashMap<>();

        ListNode temp = headA;
        while (temp != null) {
            mpp.put(temp, 1);
            temp = temp.next;
        }
        temp = headB;
        while (temp != null) {
            if (mpp.containsKey(temp)) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }
}
