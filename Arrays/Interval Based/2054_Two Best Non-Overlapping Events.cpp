/*
 * 2054. Two Best Non-Overlapping Events
 *
 * You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
 *
 * Return this maximum sum.
 *
 * Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
 *
 * Example 1:
 * Input: events = [[1,3,2],[4,5,2],[2,4,3]]
 * Output: 4
 * Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
 *
 * Example 2:
 * Input: events = [[1,3,2],[4,5,2],[1,5,5]]
 * Output: 5
 * Explanation: Choose event 2 for a sum of 5.
 *
 * Example 3:
 * Input: events = [[1,5,3],[1,5,1],[6,6,5]]
 * Output: 8
 * Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 *
 * Constraints:
 * 2 <= events.length <= 10^5
 * events[i].length == 3
 * 1 <= startTimei <= endTimei <= 10^9
 * 1 <= valuei <= 10^6
 */

// Approach-1 (Brute Force) - TLE
// T.C : O(n^2)
// S.C : O(1)
class Solution {
public:
   int maxTwoEvents(vector<vector<int> >& events){
      int n      = events.size();
      int result = 0;

      for (int i = 0; i < n; i++) {
         result = max(result, events[i][2]);

         int val = events[i][2];

         for (int j = 0; j < n; j++) {
            if (i == j) {
               continue;
            }

            if (events[j][0] <= events[i][1] && events[j][1] >= events[i][0]) {    // Overlap
               continue;
            }

            result = max(result, val + events[j][2]);
         }
      }
      return result;
   }
};

// Approach-2 (Recursion + Memoization and Sorting)
// T.C : O(n * logn, After memoizing, we will visit at max n states and for binarysearch it will take log(n))
// S.C : O(n*3) ~= O(n)

// Without Memoization: TLE
class Solution {
public:
   int n;

   // upper_bound of endTime
   int binarySearch(vector<vector<int> >& events, int endTime){
      int l      = 0;
      int r      = n - 1;
      int result = n;

      while (l <= r) {
         int mid = l + (r - l) / 2;

         if (events[mid][0] > endTime) {
            result = mid;
            r      = mid - 1;
         } else {
            l = mid + 1;
         }
      }
      return result;
   }

   int solve(vector<vector<int> >& events, int i, int count){
      if (count == 2 || i >= n) {
         return 0;
      }

      int nextValidIndex = binarySearch(events, events[i][1]);

      int take     = events[i][2] + solve(events, nextValidIndex, count + 1);
      int not_take = solve(events, i + 1, count);

      return max(take, not_take);
   }

   int maxTwoEvents(vector<vector<int> >& events){
      n = events.size();
      sort(begin(events), end(events));

      int count = 0;
      return solve(events, 0, count);
   }
};

// With Memoiztation: // Accepted
class Solution {
public:
   int n;
   int t[100001][3];

   // upper_bound of endTime
   int binarySearch(vector<vector<int> >& events, int endTime){
      int l      = 0;
      int r      = n - 1;
      int result = n;

      while (l <= r) {
         int mid = l + (r - l) / 2;

         if (events[mid][0] > endTime) {
            result = mid;
            r      = mid - 1;
         } else {
            l = mid + 1;
         }
      }
      return result;
   }

   int solve(vector<vector<int> >& events, int i, int count){
      if (count == 2 || i >= n) {
         return 0;
      }

      if (t[i][count] != -1) {
         return t[i][count];
      }

      int nextValidIndex = binarySearch(events, events[i][1]);

      int take     = events[i][2] + solve(events, nextValidIndex, count + 1);
      int not_take = solve(events, i + 1, count);

      return t[i][count] = max(take, not_take);
   }

   int maxTwoEvents(vector<vector<int> >& events){
      n = events.size();
      sort(begin(events), end(events));

      memset(t, -1, sizeof(t));
      int count = 0;
      return solve(events, 0, count);
   }
};
