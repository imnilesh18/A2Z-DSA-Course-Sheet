// GeeksforGeeks

/*
 * Given a Linked List, where every node represents a sub-linked-list and
 * contains two pointers:
 * (i) a next pointer to the next node,
 * (ii) a bottom pointer to a linked list where this node is head.
 * Each of the sub-linked lists is in sorted order.
 * Flatten the Link List so all the nodes appear in a single level while
 * maintaining the sorted order.
 * 
 * Note: The flattened list will be printed using the bottom pointer instead of
 * the next pointer. Look at the printList() function in the driver code for
 * more clarity.
 * 
 * Examples:
 * 
 * Input:
 * Output: 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
 * Explanation: The resultant linked lists has every node in a single
 * level.(Note: | represents the bottom pointer.)
 * 
 * Input:
 * Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
 * Explanation: The resultant linked lists has every node in a single
 * level.(Note: | represents the bottom pointer.)
 * Note: In the output section of the above examples, the -> represents the
 * bottom pointer.
 */

/*
class Node {
    int data;
    Node next;
    Node bottom;
 
    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
*/

// Optimal Approach:

class Solution {
    // Function to flatten a linked list
    Node merge(Node list1, Node list2) {
        Node dummyNode = new Node(-1);
        Node res = dummyNode;

        while (list1 != null && list2 != null) {
            if (list1.data < list2.data) {
                res.bottom = list1;
                res = list1;
                list1 = list1.bottom;
            } else {
                res.bottom = list2;
                res = list2;
                list2 = list2.bottom;
            }
            res.next = null;
        }
        if (list1 != null) {
            res.bottom = list1;
        } else {
            res.bottom = list2;
        }
        if (dummyNode.bottom != null) {
            dummyNode.bottom.next = null;
        }

        return dummyNode.bottom;
    }

    Node flatten(Node root) {
        if (root == null || root.next == null) {
            return root;
        }
        Node mergeHead = flatten(root.next);
        root = merge(root, mergeHead);
        return root;
    }
}

// Brute Force usign ArrayList:
class Solution {
    // Function to flatten a linked list
    Node convert(ArrayList<Integer> arr) {
        if (arr.size() == 0) {
            return null;
        }

        Node head = new Node(arr.get(0));
        Node temp = head;
        for (int i = 1; i < arr.size(); i++) {
            Node newNode = new Node(arr.get(i));
            temp.bottom = newNode;
            temp = newNode;
        }
        return head;
    }

    Node flatten(Node root) {
        ArrayList<Integer> arr = new ArrayList<>();
        Node temp = root;

        while (temp != null) {
            Node t2 = temp;
            while (t2 != null) {
                arr.add(t2.data);
                t2 = t2.bottom;
            }
            temp = temp.next;
        }
        Collections.sort(arr);

        Node head = convert(arr);

        return head;
    }
}