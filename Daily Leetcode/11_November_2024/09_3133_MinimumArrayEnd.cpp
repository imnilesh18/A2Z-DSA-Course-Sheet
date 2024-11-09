/*
 * 3133. Minimum Array End
 *
 * You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
 * Return the minimum possible value of nums[n - 1].
 *
 * Example 1:
 * Input: n = 3, x = 4
 * Output: 6
 * Explanation:
 * nums can be [4,5,6] and its last element is 6.
 *
 * Example 2:
 * Input: n = 2, x = 7
 * Output: 15
 * Explanation:
 * nums can be [7,15] and its last element is 15.
 *
 * Constraints:
 * 1 <= n, x <= 10^8
 */

// Approach - Simple using AND and OR
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
   long long minEnd(int n, int x){
      long long num = x;

      for (int i = 1; i < n; i++) {
         num = (num + 1) | x;
      }
      return num;
   }
};

// Code with comments for better understanding:

// Approach - Simple using AND and OR
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
   long long minEnd(int n, int x){
      // Initialize the starting point of our array with the given x value.
      // Since all elements should be greater than the previous one and bitwise AND of all elements should give x,
      // we start with x and try to keep the minimum increase each time.
      long long num = x;

      // Iterate to determine the minimum value of the last element (nums[n-1]).
      for (int i = 1; i < n; i++) {
         // We increment 'num' by 1 to ensure the next number is strictly greater.
         // By applying bitwise OR with x, we ensure that x remains as part of the AND result across all elements.
         num = (num + 1) | x;
      }
      // Return the minimum possible value of the last element in the array.
      return num;
   }
};


/*
 * Dry Run
 * Input: n = 3, x = 37
 *
 * Initialization: num = x = 37
 *
 * First iteration (i = 1):
 *
 * Increment num by 1: num = 37 + 1 = 38
 * Apply bitwise OR with x: num = 38 | 37
 * Binary of 38: 100110
 * Binary of 37: 100101
 * Result of 38 | 37: 100111 (in binary), which is 39 in decimal.
 * So, num becomes 39 after this iteration.
 * Second iteration (i = 2):
 *
 * Increment num by 1: num = 39 + 1 = 40
 * Apply bitwise OR with x: num = 40 | 37
 * Binary of 40: 101000
 * Binary of 37: 100101
 * Result of 40 | 37: 101101 (in binary), which is 45 in decimal.
 * So, num becomes 45 after this iteration.
 * Final output: num = 45.
 *
 * Final Array
 * The array nums could be [37, 39, 45], where:
 *
 * nums[2] (the last element) is 45, and
 * The bitwise AND of all elements, [37 & 39 & 45], equals 37 (satisfying the condition).
 * So, the minimum possible value of nums[n - 1] for n = 3 and x = 37 is 45.
 */
