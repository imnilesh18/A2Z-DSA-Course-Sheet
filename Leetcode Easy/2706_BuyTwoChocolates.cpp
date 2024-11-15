/*
 * 2706. Buy Two Chocolates
 *
 * You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.
 * You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.
 * Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.
 *
 * Example 1:
 * Input: prices = [1,2,2], money = 3
 * Output: 0
 * Explanation: Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
 *
 * Example 2:
 * Input: prices = [3,2,3], money = 3
 * Output: 3
 * Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.
 *
 * Constraints:
 * 2 <= prices.length <= 50
 * 1 <= prices[i] <= 100
 * 1 <= money <= 100
 */

// T.C: O(n)
// S.C: O(1)
class Solution {
public:
   int buyChoco(vector<int>& prices, int money){
      int minPrice       = INT_MAX;
      int secondMinPrice = INT_MAX;

      for (int&price : prices) {
         if (price < minPrice) {
            secondMinPrice = minPrice;
            minPrice       = price;
         } else {
            secondMinPrice = min(secondMinPrice, price);
         }
      }

      if (minPrice + secondMinPrice > money) {
         return money;
      }

      return money - (minPrice + secondMinPrice);
   }
};

// Code with comments for better understanding:

// T.C: O(n) because we iterate through the prices once.
// S.C: O(1) because we use a constant amount of space.
class Solution {
public:
   int buyChoco(vector<int>& prices, int money){
      // Initialize variables to hold the lowest and second lowest chocolate prices.
      int minPrice       = INT_MAX;
      int secondMinPrice = INT_MAX;

      // Iterate through each price in the prices array to find the two lowest prices.
      for (int&price : prices) {
         if (price < minPrice) {
            // Update secondMinPrice and minPrice when a new minimum price is found.
            secondMinPrice = minPrice;
            minPrice       = price;
         } else {
            // If price is not the lowest but is smaller than the current secondMinPrice, update secondMinPrice.
            secondMinPrice = min(secondMinPrice, price);
         }
      }

      // Check if buying the two cheapest chocolates exceeds the money we have.
      if (minPrice + secondMinPrice > money) {
         return money; // If we can't afford both, return the original amount of money.
      }

      // Otherwise, calculate and return the leftover money after buying the two cheapest chocolates.
      return money - (minPrice + secondMinPrice);
   }
};

/*
 * Initialize Minimum Prices: We set minPrice and secondMinPrice to the highest possible integer value (INT_MAX) to start the comparison.
 * Find Two Minimum Prices: We loop through prices, updating minPrice and secondMinPrice to capture the two smallest values.
 * Check Affordability: After finding the two minimum prices, we check if their sum is within the available money.
 * Calculate Leftover: If we can afford both chocolates, we subtract their total cost from money and return the leftover; otherwise, we return money.
 */
