/*
 * 2554. Maximum Number of Integers to Choose From a Range I
 *
 * You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
 * The chosen integers have to be in the range [1, n].
 * Each integer can be chosen at most once.
 * The chosen integers should not be in the array banned.
 * The sum of the chosen integers should not exceed maxSum.
 * Return the maximum number of integers you can choose following the mentioned rules.
 *
 * Example 1:
 * Input: banned = [1,6,5], n = 5, maxSum = 6
 * Output: 2
 * Explanation: You can choose the integers 2 and 4.
 * 2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
 *
 * Example 2:
 * Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
 * Output: 0
 * Explanation: You cannot choose any integer while following the mentioned conditions.
 *
 * Example 3:
 * Input: banned = [11], n = 7, maxSum = 50
 * Output: 7
 * Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
 * They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 *
 * Constraints:
 * 1 <= banned.length <= 10^4
 * 1 <= banned[i], n <= 10^4
 * 1 <= maxSum <= 10^9
 */

// T.C: O(n)
// S.C: O(n)
class Solution {
public:
   int maxCount(vector<int>& banned, int n, int maxSum){
      unordered_set<int> st(begin(banned), end(banned));
      int count = 0;
      int sum   = 0;

      for (int num = 1; num <= n; num++) {
         if (st.count(num)) {
            continue;
         }
         if (sum + num <= maxSum) {
            sum += num;
            count++;
         } else {
            break;
         }
      }
      return count;
   }
};

/************************************************************
*                   Code with Comments                    *
* This section contains code with detailed explanations   *
* to improve understanding of the logic and functionality.*
************************************************************/

// T.C: O(n)
// S.C: O(n)
class Solution {
public:
   int maxCount(vector<int>& banned, int n, int maxSum){
      // Create a set to store banned numbers for quick lookup
      unordered_set<int> st(begin(banned), end(banned));

      // Initialize counters for the number of selected integers and their sum
      int count = 0;
      int sum   = 0;

      // Iterate through numbers in the range [1, n]
      for (int num = 1; num <= n; num++) {
         // If the current number is in the banned set, skip it
         if (st.count(num)) {
            continue;
         }

         // Check if adding the current number exceeds the maxSum
         if (sum + num <= maxSum) {
            sum += num;     // Add the number to the current sum
            count++;        // Increment the count of selected numbers
         } else {
            // If maxSum is exceeded, stop the iteration
            break;
         }
      }

      // Return the total number of integers that can be chosen
      return count;
   }
};
