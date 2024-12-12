/*
 * 2558. Take Gifts From the Richest Pile
 *
 * You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
 * Choose the pile with the maximum number of gifts.
 * If there is more than one pile with the maximum number of gifts, choose any.
 * Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
 * Return the number of gifts remaining after k seconds.
 *
 * Example 1:
 * Input: gifts = [25,64,9,4,100], k = 4
 * Output: 29
 * Explanation:
 * The gifts are taken in the following way:
 * - In the first second, the last pile is chosen and 10 gifts are left behind.
 * - Then the second pile is chosen and 8 gifts are left behind.
 * - After that the first pile is chosen and 5 gifts are left behind.
 * - Finally, the last pile is chosen again and 3 gifts are left behind.
 * The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
 *
 * Example 2:
 * Input: gifts = [1,1,1,1], k = 4
 * Output: 4
 * Explanation:
 * In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile.
 * That is, you can't take any pile with you.
 * So, the total gifts remaining are 4.
 *
 * Constraints:
 * 1 <= gifts.length <= 10^3
 * 1 <= gifts[i] <= 10^9
 * 1 <= k <= 10^3
 */

// Approach (Using max-heap)
// T.C : O(n + k*logn)
// S.C : O(n)
class Solution {
public:
   long long pickGifts(vector<int>& gifts, int k){
      // Heapify - O(n)
      // Create a max-heap from the input vector `gifts`
      priority_queue<int> pq(begin(gifts), end(gifts));   // max-heap

      // Calculate the initial sum of all elements in the array - O(n)
      long long sum = 0;

      for (int&gift : gifts) {    // O(n)
         sum += gift;
      }

      // Perform the operation `k` times
      while (k--) {            // O(k)
         int maxEl = pq.top(); // Get the largest element - O(1)
         pq.pop();             // Remove the largest element - O(log(n))

         // Compute the reduced value after taking the square root
         int remaining = sqrt(maxEl);    // Ignoring this time complexity
         // Adjust the total sum by subtracting the difference
         sum -= (maxEl - remaining);
         pq.push(remaining);    // Push the reduced value back into the heap - O(log(n))
      }

      // Return the final sum after `k` operations
      return sum;
   }
};
