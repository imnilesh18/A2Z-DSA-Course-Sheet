// Problem Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1

/*
 * Reverse a Stack
 *
 * You are given a stack St. You have to reverse the stack using recursion.
 *
 * Example 1:
 * Input:
 * St = {3,2,1,7,6}
 * Output:
 * {6,7,1,2,3}
 * Explanation:
 * Input stack after reversing will look like the stack in the output.
 *
 * Example 2:
 * Input:
 * St = {4,3,9,6}
 * Output:
 * {6,9,3,4}
 * Explanation:
 * Input stack after reversing will look like the stack in the output.
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and reverses the given stack.
 *
 * Expected Time Complexity: O(N2)
 * Expected Auxiliary Space: O(1)
 * Constraints:
 * 1 <= size of the stack <= 10^4
 * -10^9 <= Each element of the stack <= 10^9
 * Sum of N over all test cases doesn't exceeds 10^6
 * Array may contain duplicate elements.
 */

// Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
// T.C : O(n^2)
// S.C : O(n) Auxiliary Space (we took extra one temp stack)
class Solution {
public:
   void Reverse(stack<int>&St){
      if (St.empty()) {
         return;
      }

      int top = St.top();
      St.pop();

      Reverse(St);

      stack<int> temp;
      while (!St.empty()) {
         temp.push(St.top());
         St.pop();
      }

      St.push(top);

      while (!temp.empty()) {
         St.push(temp.top());
         temp.pop();
      }
   }
};

// Code with comments for better understanding:
// Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
// T.C : O(n^2)
// S.C : O(n) Auxiliary Space (we took extra one temp stack):
class Solution {
public:
   void Reverse(stack<int>& St){
      // Base case: if the stack is empty, there is nothing to reverse
      if (St.empty()) {
         return;
      }

      // Step 1: Store the top element and remove it from the stack
      int top = St.top();
      St.pop();

      // Recursive call: Reverse the remaining elements in the stack
      Reverse(St);

      // Step 2: Temporary stack to hold the reversed elements
      stack<int> temp;

      // Move all elements from St to temp to reach the bottom position
      // where we can place 'top' as the first element in the reversed stack
      while (!St.empty()) {
         temp.push(St.top());
         St.pop();
      }

      // Insert the stored 'top' element at the bottom of St
      St.push(top);

      // Move elements back from temp to St to maintain the order
      while (!temp.empty()) {
         St.push(temp.top());
         temp.pop();
      }
   }
};
