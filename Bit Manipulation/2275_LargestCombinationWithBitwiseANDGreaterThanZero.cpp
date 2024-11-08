/*
 * 2275. Largest Combination With Bitwise AND Greater Than Zero
 *
 * The bitwise AND of an array nums is the bitwise AND of all integers in nums.
 * For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
 * Also, for nums = [7], the bitwise AND is 7.
 * You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
 * Return the size of the largest combination of candidates with a bitwise AND greater than 0.
 *
 * Example 1:
 * Input: candidates = [16,17,71,62,12,24,14]
 * Output: 4
 * Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
 * The size of the combination is 4.
 * It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
 * Note that more than one combination may have the largest size.
 * For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
 *
 * Example 2:
 * Input: candidates = [8,8]
 * Output: 2
 * Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
 * The size of the combination is 2, so we return 2.
 *
 * Constraints:
 * 1 <= candidates.length <= 10^5
 * 1 <= candidates[i] <= 10^7
 */

//Approach-1 (Using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(24) ~= O(1)

class Solution {
public:
   int largestCombination(vector<int>& candidates){
      int         result = 0;
      vector<int> count(24, 0);   // O(24)

      // count[i] = how many numbers have ith bit set

      for (int i = 0; i < 24; i++) {  // why till 24 because constraint is 10^7 which means we need bits = floor(log2(10^7)) + 1 = 23 + 1 = 24
         for (int&num : candidates) { // O(n)
            if ((num & (1 << i)) != 0) {
               count[i]++;
            }
         }

         result = max(result, count[i]);
      }
      return result;
   }
};

//Approach-2 (without using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(1)

class Solution {
public:
   int largestCombination(vector<int>& candidates){
      int result = 0;

      // vector<int> count(24, 0); // O(24)
      // count[i] = how many numbers have ith bit set

      for (int i = 0; i < 24; i++) {  // why till 24 because constraint is 10^7 which means we need bits = floor(log2(10^7)) + 1 = 23 + 1 = 24
         int count_ith = 0;
         for (int&num : candidates) { // O(n)
            if ((num & (1 << i)) != 0) {
               // count[i]++;
               count_ith += 1;
            }
         }

         result = max(result, count_ith);
      }
      return result;
   }
};


// Code with comments for better understanding:

//Approach-1 (Using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(24) ~= O(1)

class Solution {
public:
   int largestCombination(vector<int>& candidates){
      int result = 0;

      /*
       * We use an array to count how many numbers have each bit position set (1)
       * Size is 24 because the max number is 10^7, which needs 24 bits to represent
       * Intuition: If K numbers have a particular bit position set to 1,
       * then those K numbers will have a non-zero AND result for that bit
       */
      vector<int> count(24, 0);   // O(24)

      // count[i] = how many numbers have ith bit set

      /*
       * For each bit position (0 to 23), count how many numbers in candidates
       * have that bit set to 1. The maximum count across all bit positions
       * will be our answer because:
       * 1. All numbers with that bit set will have non-zero AND result
       * 2. We want the largest such group of numbers
       */
      for (int i = 0; i < 24; i++) {  // why till 24 because constraint is 10^7 which means we need bits = floor(log2(10^7)) + 1 = 23 + 1 = 24
         for (int&num : candidates) { // O(n)
            /*
             * Check if the ith bit is set in current number
             * (num & (1 << i)) creates a mask with only ith bit set
             * If result is non-zero, it means ith bit was set in num
             */
            if ((num & (1 << i)) != 0) {
               count[i]++;
            }
         }

         /*
          * Keep track of the maximum count found so far
          * This represents the size of largest possible combination
          * that will have a non-zero AND result
          */
         result = max(result, count[i]);
      }
      return result;
   }
};

//Approach-2 (without using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(1)

class Solution {
public:
   int largestCombination(vector<int>& candidates){
      int result = 0;

      /*
       * Instead of using an array to store counts for all bit positions,
       * we'll count one bit position at a time
       * This reduces space complexity from O(24) to O(1)
       * The logic remains same - find the bit position that is set (1)
       * in maximum number of integers
       */

      for (int i = 0; i < 24; i++) {  // why till 24 because constraint is 10^7 which means we need bits = floor(log2(10^7)) + 1 = 23 + 1 = 24
         /*
          * count_ith maintains count of numbers having 1 at ith bit position
          * We reset this for each bit position instead of storing all counts
          */
         int count_ith = 0;

         for (int&num : candidates) {    // O(n)
            /*
             * For current bit position i:
             * 1. (1 << i) creates a mask with only ith bit set
             * 2. (num & mask) checks if ith bit is set in current number
             * 3. If result is non-zero, increment count for this bit position
             */
            if ((num & (1 << i)) != 0) {
               count_ith += 1;
            }
         }

         /*
          * Update result if current bit position has more numbers with 1
          * This count represents a valid combination size because:
          * - All these numbers have 1 in the same bit position
          * - Their AND will be non-zero (at least this bit will be 1)
          * - We can't take more numbers than this max count
          */
         result = max(result, count_ith);
      }
      return result;
   }
};
