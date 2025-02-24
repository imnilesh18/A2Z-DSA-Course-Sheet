/*
 * 739. Daily Temperatures
 * (Solve 901. Online Stock Span)
 *
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 *
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 *
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 * Constraints:
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 */

// Approach: Use a stack to store indices of days. For each day, pop indices with lower temperatures and update the answer with the difference.
// Time Complexity: O(n) because every index is pushed and popped at most once.
// Space Complexity: O(n) for the answer array and stack.
class Solution {
public:
   vector<int> dailyTemperatures(vector<int>& temperatures) {
      int         n = temperatures.size();
      vector<int> answer(n, 0); // initialize answer vector with 0's for each day
      stack<int>  st;           // stack to store indices of temperatures

      for (int i = 0; i < n; i++) {
         // while the stack is not empty and current temperature is greater than the temperature at index st.top()
         while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx; // calculate the number of days between current day and day at idx
         }
         st.push(i);               // push current index onto the stack
      }
      return answer;               // return the computed answer vector
   }
};

/*
 * Dry Run
 * Input: [73,74,75,71,69,72,76,73]
 * i=0: push index 0 (73)
 * i=1: 74 > 73, pop index 0, answer[0] = 1; push index 1 (74)
 * i=2: 75 > 74, pop index 1, answer[1] = 1; push index 2 (75)
 * i=3: 71 is not > 75, push index 3 (71)
 * i=4: 69 is not > 71, push index 4 (69)
 * i=5: 72 > 69, pop index 4, answer[4] = 1; 72 > 71, pop index 3, answer[3] = 2; push index 5 (72)
 * i=6: 76 > 72, pop index 5, answer[5] = 1; 76 > 75, pop index 2, answer[2] = 4; push index 6 (76)
 * i=7: 73 is not > 76, push index 7 (73)
 * Remaining indices (6 and 7) remain with answer = 0.
 * End Dry Run
 */
