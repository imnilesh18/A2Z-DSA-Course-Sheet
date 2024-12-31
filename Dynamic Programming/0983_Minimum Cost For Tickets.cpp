/*
 * 983. Minimum Cost For Tickets
 *
 * You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
 *
 * Train tickets are sold in three different ways:
 *
 * a 1-day pass is sold for costs[0] dollars,
 * a 7-day pass is sold for costs[1] dollars, and
 * a 30-day pass is sold for costs[2] dollars.
 * The passes allow that many days of consecutive travel.
 *
 * For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
 * Return the minimum number of dollars you need to travel every day in the given list of days.
 *
 * Example 1:
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total, you spent $11 and covered all the days of your travel.
 *
 * Example 2:
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total, you spent $17 and covered all the days of your travel.
 *
 * Constraints:
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 */

// Approach 1: Dynamic Programming (Top-down) with memoization to find minimum cost by trying all 3 ticket options (1-day, 7-day, 30-day) at each day and caching results.
// Time Complexity: O(N) where N is the number of travel days since each day is processed once due to memoization.
// Space Complexity: O(N) for the recursive call stack and memoization array, though array size is fixed at 366.
class Solution {
public:
   // DP array to store minimum cost for each day index
   int t[366];

   // Recursive function to find minimum cost starting from index i
   int solve(vector<int>& days, vector<int>& costs, int n, int i){
      // Base case: if we've processed all days, no more cost needed
      if (i >= n) {
         return 0;
      }

      // If this state has already been computed, return cached result
      if (t[i] != -1) {
         return t[i];
      }

      // Option 1: Buy 1-day pass for current day
      // Cost = price of 1-day pass + min cost for remaining days
      int cost_1 = costs[0] + solve(days, costs, n, i + 1);

      // Option 2: Buy 7-day pass starting from current day
      int j       = i;
      int max_day = days[i] + 7;    // Calculate the last day covered by 7-day pass

      // Find the first day not covered by this 7-day pass
      while (j < n && days[j] < max_day) {
         j++;
      }
      // Cost = price of 7-day pass + min cost for remaining days
      int cost_7 = costs[1] + solve(days, costs, n, j);

      // Option 3: Buy 30-day pass starting from current day
      j       = i;
      max_day = days[i] + 30;    // Calculate the last day covered by 30-day pass

      // Find the first day not covered by this 30-day pass
      while (j < n && days[j] < max_day) {
         j++;
      }
      // Cost = price of 30-day pass + min cost for remaining days
      int cost_30 = costs[2] + solve(days, costs, n, j);

      // Store and return minimum of all three options
      return t[i] = min({ cost_1, cost_7, cost_30 });
   }

   int mincostTickets(vector<int>& days, vector<int>& costs){
      int n = days.size();

      // Initialize DP array with -1 to indicate uncomputed states
      memset(t, -1, sizeof(t));
      // Start the recursion from index 0
      return solve(days, costs, n, 0);
   }
};

// Approach 2: Bottom-up Dynamic Programming with a DP array to store minimum cost till each day, trying all 3 ticket options at each travel day.
// Time Complexity: O(N) where N is the last day of travel since we process each day once.
// Space Complexity: O(N) for the DP array and O(D) for set where D is number of travel days, so overall O(N)
class Solution {
public:
   int mincostTickets(vector<int>& days, vector<int>& costs){
      // Store all travel days in a set for O(1) lookup
      unordered_set<int> st(begin(days), end(days));

      // Get the last day of travel to determine DP array size
      int last_day = days.back();

      // DP array where t[i] represents min cost to travel till day i
      vector<int> t(last_day + 1, 0);

      // Base case: no cost for day 0
      t[0] = 0;

      // Iterate through each day up to last travel day
      for (int i = 1; i <= last_day; i++) {
         // If current day is not a travel day
         // Cost remains same as previous day
         if (st.find(i) == st.end()) {
            t[i] = t[i - 1];
            continue;
         }

         // Initialize current day's cost as maximum
         t[i] = INT_MAX;

         // Option 1: Buy 1-day pass for today
         // Cost = 1-day pass price + cost till previous day
         int day_1_pass = costs[0] + t[max(i - 1, 0)];

         // Option 2: Buy 7-day pass valid from (i-7) to i
         // Cost = 7-day pass price + cost till 7 days ago
         int day_7_pass = costs[1] + t[max(i - 7, 0)];

         // Option 3: Buy 30-day pass valid from (i-30) to i
         // Cost = 30-day pass price + cost till 30 days ago
         int day_30_pass = costs[2] + t[max(i - 30, 0)];

         // Take minimum of all three options
         t[i] = min({ day_1_pass, day_7_pass, day_30_pass });
      }
      return t[last_day];
   }
};
