// Before solving try similar problems like:
// I) 875. Koko Eating Bananas: https://leetcode.com/problems/koko-eating-bananas/description/
// II) 2064. Minimized Maximum of Products Distributed to Any Store: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/
// III) 1011. Capacity To Ship Packages Within D Days: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// IV) 1552. Magnetic Force Between Two Balls: https://leetcode.com/problems/magnetic-force-between-two-balls/description/

// ALl these have same format only isPossible function will change based on the requirement:

/*
 * 1760. Minimum Limit of Balls in a Bag
 *
 * You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.
 *
 * You can perform the following operation at most maxOperations times:
 *
 * Take any bag of balls and divide it into two new bags with a positive number of balls.
 * For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
 * Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
 *
 * Return the minimum possible penalty after performing the operations.
 *
 * Example 1:
 * Input: nums = [9], maxOperations = 2
 * Output: 3
 * Explanation:
 * - Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
 * - Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
 * The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
 *
 * Example 2:
 * Input: nums = [2,4,8,2], maxOperations = 4
 * Output: 2
 * Explanation:
 * - Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
 * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
 * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
 * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
 * The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= maxOperations, nums[i] <= 10^9
 */

// T.C: O(n * log(MAX))
// S.C: O(1)
class Solution {
public:

   bool isPossible(vector<int>& nums, int maxOps, int mid){
      int totalOps = 0;   // to brign each number <= mid

      for (int&num : nums) {
         int ops = num / mid;
         if (num % mid == 0) {
            ops -= 1;
         }

         totalOps += ops;
      }

      return totalOps <= maxOps;
   }

   int minimumSize(vector<int>& nums, int maxOperations){
      int l = 1;
      int r = *max_element(begin(nums), end(nums));

      int result = r;   // we have to minimize this

      while (l <= r) {
         int mid = l + (r - l) / 2;

         if (isPossible(nums, maxOperations, mid)) {
            result = mid;
            r      = mid - 1;
         } else {
            l = mid + 1;
         }
      }

      return result;
   }
};

/************************************************************
*                   Code with Comments                    *
* This section contains code with detailed explanations   *
* to improve understanding of the logic and functionality.*
************************************************************/

// T.C: O(n * log(MAX))
// S.C: O(1
class Solution {
public:
   // Function to check if it's possible to make all bag sizes <= mid using maxOps or fewer operations
   bool isPossible(vector<int>& nums, int maxOps, int mid){
      int totalOps = 0; // Counter for the total number of operations needed

      // Iterate through each bag's ball count
      for (int& num : nums) {
         // Calculate the number of operations required to reduce `num` to <= `mid`
         int ops = num / mid; // Divide balls into groups of size `mid`

         // If `num` is perfectly divisible by `mid`, we need one less operation
         if (num % mid == 0) {
            ops -= 1;
         }

         // Accumulate the operations
         totalOps += ops;
      }

      // Check if the total operations are within the allowed limit
      return totalOps <= maxOps;
   }

   // Main function to find the minimum possible penalty
   int minimumSize(vector<int>& nums, int maxOperations){
      int l = 1;                                    // Minimum possible penalty (1 ball per bag)
      int r = *max_element(begin(nums), end(nums)); // Maximum possible penalty (largest bag size)

      int result = r;                               // Initialize the result to the maximum possible penalty

      // Binary search to minimize the penalty
      while (l <= r) {
         int mid = l + (r - l) / 2; // Calculate the middle value

         // Check if it's possible to achieve penalty <= mid
         if (isPossible(nums, maxOperations, mid)) {
            result = mid;     // Update result to the current minimum penalty
            r      = mid - 1; // Try for a smaller penalty
         } else {
            l = mid + 1;      // Increase the penalty limit and search again
         }
      }

      return result; // Return the minimized penalty
   }
};
