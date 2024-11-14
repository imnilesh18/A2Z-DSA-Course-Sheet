/*
 * 2064. Minimized Maximum of Products Distributed to Any Store
 *
 * You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
 * You need to distribute all products to the retail stores following these rules:
 * A store can only be given at most one product type but can be given any amount of it.
 * After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
 * Return the minimum possible x.
 *
 * Example 1:
 * Input: n = 6, quantities = [11,6]
 * Output: 3
 * Explanation: One optimal way is:
 * - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
 * - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
 * The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
 *
 * Example 2:
 * Input: n = 7, quantities = [15,10,10]
 * Output: 5
 * Explanation: One optimal way is:
 * - The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
 * - The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
 * - The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
 * The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
 *
 * Example 3:
 * Input: n = 1, quantities = [100000]
 * Output: 100000
 * Explanation: The only optimal way is:
 * - The 100000 products of type 0 are distributed to the only store.
 * The maximum number of products given to any store is max(100000) = 100000.
 *
 * Constraints:
 * m == quantities.length
 * 1 <= m <= n <= 10^5
 * 1 <= quantities[i] <= 10^5
 */

// T.C : O(m*log(maxValue))
// S.C :O(1)
class Solution {
public:

   bool possibleToDistr(int x, vector<int>& quantities, int shops){
      for (int&products : quantities) {
         shops -= (products + x - 1) / x;
         // shops -= ceil(products / (double)x);
         if (shops < 0) {
            return false;
         }
      }
      return true;
   }

   int minimizedMaximum(int n, vector<int>& quantities){
      int l = 1;
      int r = *max_element(begin(quantities), end(quantities));

      int result = 0;

      // O(m*log(maxValue))
      while (l <= r) {  // log(maxValue)
         int mid = l + (r - l) / 2;

         if (possibleToDistr(mid, quantities, n)) {   // m
            result = mid;
            r      = mid - 1;
         } else {
            l = mid + 1;
         }
      }
      return result;
   }
};

// Code with comments for better understanding:

// T.C : O(m * log(maxValue))
// S.C : O(1)
class Solution {
public:

   // Helper function to check if it’s possible to distribute products
   // such that no store receives more than `x` products
   // Input:
   //    - x: the maximum number of products any single store should receive
   //    - quantities: vector containing the number of each product type
   //    - shops: total number of stores available
   // Returns:
   //    - true if it’s possible to distribute all products under these constraints,
   //      false otherwise
   bool possibleToDistr(int x, vector<int>& quantities, int shops){
      for (int& products : quantities) {
         // Calculate the minimum number of stores needed for this product type
         // Divide `products` by `x` and take the ceiling to ensure each store
         // receives at most `x` products
         shops -= (products + x - 1) / x;
         // This is equivalent to:
         // shops -= ceil(products / (double)x);

         // If shops fall below zero, it means it’s not possible to distribute
         // products within the current `x` limit
         if (shops < 0) {
            return false;
         }
      }
      return true; // All products distributed successfully with the given `x` limit
   }

   // Main function to minimize the maximum number of products any store receives
   int minimizedMaximum(int n, vector<int>& quantities){
      int l = 1;                                                // Lower bound of `x`, minimum possible maximum per store
      int r = *max_element(begin(quantities), end(quantities)); // Upper bound of `x`, maximum quantity

      int result = 0;                                           // Result to store the minimized maximum value

      // Binary search to find the minimum possible maximum products per store
      // T.C of binary search loop: O(log(maxValue))
      while (l <= r) {
         int mid = l + (r - l) / 2; // Calculate mid to avoid overflow

         // Check if it’s possible to distribute with `mid` as the max products per store
         // T.C of possibleToDistr: O(m)
         if (possibleToDistr(mid, quantities, n)) {
            // If distribution is possible, try for a smaller maximum (move left)
            result = mid;
            r      = mid - 1;
         } else {
            // If not possible, increase the minimum limit (move right)
            l = mid + 1;
         }
      }
      return result; // Return the minimized maximum possible `x`
   }
};
