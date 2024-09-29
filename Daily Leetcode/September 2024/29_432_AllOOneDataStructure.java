/*
 * 432. All O`one Data Structure
 * 
 * Design a data structure to store the strings' count with the ability to
 * return the strings with minimum and maximum counts.
 * Implement the AllOne class:
 * AllOne() Initializes the object of the data structure.
 * inc(String key) Increments the count of the string key by 1. If key does not
 * exist in the data structure, insert it with count 1.
 * dec(String key) Decrements the count of the string key by 1. If the count of
 * key is 0 after the decrement, remove it from the data structure. It is
 * guaranteed that key exists in the data structure before the decrement.
 * getMaxKey() Returns one of the keys with the maximal count. If no element
 * exists, return an empty string "".
 * getMinKey() Returns one of the keys with the minimum count. If no element
 * exists, return an empty string "".
 * Note that each function must run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * Input
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * Output
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 * Explanation
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "leet"
 * 
 * Constraints:
 * 1 <= key.length <= 10
 * key consists of lowercase English letters.
 * It is guaranteed that for each call to dec, key is existing in the data
 * structure.
 * At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
 */

//Approach (Using map +  dll)
//T.C : O(1)
//S.C : O(n) , map stores n strings
class AllOne {
    // Doubly Linked List node to store count and a set of strings with that count
    private class Node {
        int count;
        LinkedHashSet<String> keys; // LinkedHashSet maintains the order of insertion
        Node prev, next;

        Node(int c) {
            count = c;
            keys = new LinkedHashSet<>();
        }
    }

    // Hash map to store key -> count node
    private Map<String, Node> keyCountMap;

    // Head and tail pointers for the doubly linked list
    private Node head, tail;

    public AllOne() {
        keyCountMap = new HashMap<>();
        // Initialize head and tail dummy nodes for the doubly linked list
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    // Add a new node with count `c` after node `prevNode`
    private Node addNodeAfter(Node prevNode, int count) {
        Node newNode = new Node(count);
        newNode.next = prevNode.next;
        newNode.prev = prevNode;
        prevNode.next.prev = newNode;
        prevNode.next = newNode;
        return newNode;
    }

    // Remove the node from the doubly linked list
    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void inc(String key) {
        if (!keyCountMap.containsKey(key)) {
            // Key doesn't exist, add it to the list after the head with count 1
            if (head.next == tail || head.next.count != 1) {
                addNodeAfter(head, 1);
            }
            head.next.keys.add(key);
            keyCountMap.put(key, head.next);
        } else {
            // Key exists, move it to the next count
            Node curNode = keyCountMap.get(key);
            int curCount = curNode.count;
            if (curNode.next == tail || curNode.next.count != curCount + 1) {
                addNodeAfter(curNode, curCount + 1);
            }
            curNode.next.keys.add(key);
            keyCountMap.put(key, curNode.next);
            curNode.keys.remove(key);
            if (curNode.keys.isEmpty()) {
                removeNode(curNode);
            }
        }
    }

    public void dec(String key) {
        if (!keyCountMap.containsKey(key)) {
            return;
        }

        Node curNode = keyCountMap.get(key);
        int curCount = curNode.count;

        // Remove the key from the current node
        curNode.keys.remove(key);

        if (curCount == 1) {
            // Remove the key entirely if the count is 1
            keyCountMap.remove(key);
        } else {
            // Move the key to the previous count node
            if (curNode.prev == head || curNode.prev.count != curCount - 1) {
                addNodeAfter(curNode.prev, curCount - 1);
            }
            curNode.prev.keys.add(key);
            keyCountMap.put(key, curNode.prev);
        }

        // Remove the current node if it has no more keys
        if (curNode.keys.isEmpty()) {
            removeNode(curNode);
        }
    }

    public String getMaxKey() {
        return tail.prev == head ? "" : tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        return head.next == tail ? "" : head.next.keys.iterator().next();
    }
}