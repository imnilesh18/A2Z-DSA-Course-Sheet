/*
 * 2070. Most Beautiful Item for Each Query
 *
 * You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
 * You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.
 * Return an array answer of the same length as queries where answer[j] is the answer to the jth query.
 *
 * Example 1:
 * Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
 * Output: [2,4,5,5,6,6]
 * Explanation:
 * - For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
 * - For queries[1]=2, the items which can be considered are [1,2] and [2,4].
 * The maximum beauty among them is 4.
 * - For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
 * The maximum beauty among them is 5.
 * - For queries[4]=5 and queries[5]=6, all items can be considered.
 * Hence, the answer for them is the maximum beauty of all items, i.e., 6.
 *
 * Example 2:
 * Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
 * Output: [4]
 * Explanation:
 * The price of every item is equal to 1, so we choose the item with the maximum beauty 4.
 * Note that multiple items can have the same price and/or beauty.
 *
 * Example 3:
 * Input: items = [[10,1000]], queries = [5]
 * Output: [0]
 * Explanation:
 * No item has a price less than or equal to 5, so no item can be chosen.
 * Hence, the answer to the query is 0.
 *
 * Constraints:
 * 1 <= items.length, queries.length <= 10^5
 * items[i].length == 2
 * 1 <= pricei, beautyi, queries[j] <= 10^9
 */

class Solution {
public:
   // T.C : log(n)
   int customBinarySearch(vector<vector<int> >& items, int queryPrice){
      int l = 0;
      int r = items.size() - 1;
      int mid;

      int maxBeauty = 0;

      while (l <= r) {
         mid = l + (r - l) / 2;

         if (items[mid][0] > queryPrice) {
            r = mid - 1;     // ignore the current and right items, move to the left now
         } else {
            maxBeauty = max(maxBeauty, items[mid][1]);
            l         = mid + 1;
         }
      }

      return maxBeauty;
   }

   vector<int> maximumBeauty(vector<vector<int> >& items, vector<int>& queries){
      int n = items.size();
      int m = queries.size();

      vector<int> result(m);

      // Step 1: Sort the array based of price in ascending order:
      sort(begin(items), end(items));   // {pricei, beautyi} // T.C : nlogn

      int maxBeautySeen = items[0][1];

      for (int i = 1; i < n; i++) {  // O(n)
         maxBeautySeen = max(maxBeautySeen, items[i][1]);
         items[i][1]   = maxBeautySeen;
      }

      for (int i = 0; i < m; i++) {                         // T.C: O(m)
         int queryPrice = queries[i];
         result[i] = customBinarySearch(items, queryPrice); // T.C: log(n)
      }
      // Overal T.C : O(nlogn + n + mlogn)
      // Overal T.C : O(n + (n + m)logn)
      return result;
   }
};


// Code with comments for better understanding:

/*
 * 2070. Most Beautiful Item for Each Query
 *
 * Intuition:
 * 1. For each query price, we need to find the maximum beauty among all items with price <= query price
 * 2. To optimize the search, we can:
 *    - Sort items by price (allows binary search)
 *    - Preprocess beauty values to maintain running maximum (avoids checking all items <= query price)
 * 3. Use binary search to find the rightmost item with price <= query price
 *
 * Example: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
 * After sorting: [[1,2],[2,4],[3,2],[3,5],[5,6]]
 * After beauty preprocessing: [[1,2],[2,4],[3,4],[3,5],[5,6]]
 */

class Solution {
public:
   // Binary search to find maximum beauty for items with price <= queryPrice
   // Time Complexity: O(log n)
   int customBinarySearch(vector<vector<int> >& items, int queryPrice){
      int l = 0;
      int r = items.size() - 1;
      int mid;
      int maxBeauty = 0;

      while (l <= r) {
         mid = l + (r - l) / 2;

         if (items[mid][0] > queryPrice) {
            // Current price is too high, look in left half
            r = mid - 1;
         } else {
            // Price is <= queryPrice
            // Update maxBeauty and look for potentially better items in right half
            maxBeauty = max(maxBeauty, items[mid][1]);
            l         = mid + 1;
         }
      }
      return maxBeauty;
   }

   vector<int> maximumBeauty(vector<vector<int> >& items, vector<int>& queries){
      int         n = items.size();
      int         m = queries.size();
      vector<int> result(m);

      // Step 1: Sort items by price to enable binary search
      // Time Complexity: O(n log n)
      sort(begin(items), end(items));

      // Step 2: Preprocess beauty values
      // For each position, store the maximum beauty seen so far
      // This ensures we don't miss any higher beauty values from items with lower prices
      // Time Complexity: O(n)
      int maxBeautySeen = items[0][1];
      for (int i = 1; i < n; i++) {
         maxBeautySeen = max(maxBeautySeen, items[i][1]);
         items[i][1]   = maxBeautySeen;
      }

      // Step 3: Process each query using binary search
      // Time Complexity: O(m log n)
      for (int i = 0; i < m; i++) {
         int queryPrice = queries[i];
         result[i] = customBinarySearch(items, queryPrice);
      }

      // Overall Time Complexity: O(n log n + n + m log n) = O(n log n + m log n) = O((n + m) log n)
      // Space Complexity: O(1) excluding the output array
      return result;
   }
};
