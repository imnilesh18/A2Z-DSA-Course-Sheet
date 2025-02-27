/*
 * 155. Min Stack
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * Implement the MinStack class:
 *
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 *
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 * Constraints:
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 * At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 */

// Approach 1: Use a stack of pairs (value, current minimum) to get O(1) operations.
// TC: O(1) per operation
// SC: O(n) in worst-case.
class MinStack {
public:
   stack<pair<int, int> > st;     // Each pair contains {value, current minimum}

   MinStack() {
      // Constructor initializes the stack.
   }

   void push(int val) {
      if (st.empty()) {
         st.push({ val, val });
      }else{
         st.push({ val, min(val, st.top().second) });
      }
   }

   void pop() {
      if (!st.empty()) {
         st.pop();
      }
   }

   int top() {
      return st.empty() ? -1 : st.top().first;
   }

   int getMin() {
      return st.empty() ? -1 : st.top().second;
   }
};

/*
 * Dry Run:
 *
 * push(2): Stack becomes [(2,2)]
 * push(3): Stack becomes [(2,2), (3,2)]
 * top(): returns 3
 * pop(): removes (3,2); Stack becomes [(2,2)]
 * getMin(): returns 2
 * push(1): Stack becomes [(2,2), (1, min(1,2)=1)]
 * getMin(): returns 1
 *
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Approach 2: Use one stack to store encoded values and maintain a variable minElement for O(1) operations.
// TC: O(1) per operation
// SC: O(n) in worst-case.
class MinStack {
public:
   stack<long long> st;      // Stack to store encoded values
   long long minElement;     // Variable to store the current minimum element

   MinStack() {
      // Constructor initializes the stack.
   }

   void push(int val) {
      if (st.empty()) {
         st.push(val);
         minElement = val;
      } else {
         if (val < minElement) {
            st.push(2LL * val - minElement);
            minElement = val;
         } else {
            st.push(val);
         }
      }
   }

   void pop() {
      if (st.empty()) {
         return;
      }
      long long topVal = st.top();
      st.pop();
      if (topVal < minElement) {
         // Decode the previous minimum value.
         minElement = 2 * minElement - topVal;
      }
   }

   int top() {
      if (st.empty()) {
         return -1;
      }
      long long topVal = st.top();
      if (topVal < minElement) {
         return (int)minElement;
      }else{
         return (int)topVal;
      }
   }

   int getMin() {
      return st.empty() ? -1 : (int)minElement;
   }
};

/*
 * Dry Run:
 *
 * push(2): Stack becomes [2], minElement = 2
 * push(3): Stack becomes [2, 3], minElement remains 2
 * top(): returns 3
 * pop(): removes 3; Stack becomes [2], minElement remains 2
 * getMin(): returns 2
 * push(1): since 1 < minElement, push encoded value = 2*1 - 2 = 0; Stack becomes [2, 0], minElement becomes 1
 * getMin(): returns 1
 *
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
