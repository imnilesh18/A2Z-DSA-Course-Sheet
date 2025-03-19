/*
 * 995. Minimum Number of K Consecutive Bit Flips
 *  (After this solve LeetCode: 3191. Minimum Operations to Make Binary Array Elements Equal to One I
 *   Same code just put k = 3 there)
 *
 * You are given a binary array nums and an integer k.
 * A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
 * Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
 * A subarray is a contiguous part of an array.
 *
 * Example 1:
 * Input: nums = [0,1,0], k = 1
 * Output: 2
 * Explanation: Flip nums[0], then flip nums[2].
 *
 * Example 2:
 * Input: nums = [1,1,0], k = 2
 * Output: -1
 * Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
 *
 * Example 3:
 * Input: nums = [0,0,0,1,0,1,1,0], k = 3
 * Output: 3
 * Explanation:
 * Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
 * Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
 * Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= k <= nums.length
 */

// Approach 1: Greedy algorithm that iterates through the array, using an auxiliary boolean array to track the start of flip operations and a counter to keep track of active flips affecting the current index.
// Time Complexity: O(n) - We traverse the array only once.
// Space Complexity: O(n) - We use an extra boolean vector of size n to record flip start positions.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int          n         = nums.size();     // Total number of elements in nums.
        int          flips     = 0;               // Counts the total number of flips made.
        int          flipCount = 0;               // Tracks the number of active flips affecting the current position.
        vector<bool> isFlipped(n, false);         // Marks the indices where a flip operation starts.

        for (int i = 0; i < n; i++) {
            // If we have moved past the window of a previous flip, remove its effect.
            if (i >= k && isFlipped[i - k]) {
                flipCount--;
            }

            // If the current bit, after considering the number of flips (even or odd), is still 0, we need to flip.
            if (flipCount % 2 == nums[i]) {
                // If there are not enough bits left to flip, it's impossible to achieve all 1's.
                if (i + k > n) {
                    return -1;
                }
                // Start a new flip operation at index i.
                flipCount++;
                flips++;
                isFlipped[i] = true;
            }
        }
        return flips;
    }
};

/*
 * Dry Run
 * Example: nums = [0, 0, 0, 1, 0, 1, 1, 0], k = 3
 * Initial State: flips = 0, flipCount = 0, isFlipped = [false, false, false, false, false, false, false, false]
 *
 * i = 0:
 * flipCount = 0, nums[0] = 0, condition (0 % 2 == 0) holds -> flip needed.
 * Check: 0 + 3 <= 8 is valid.
 * Perform flip: flipCount becomes 1, flips becomes 1, isFlipped[0] = true.
 *
 * i = 1:
 * flipCount = 1, nums[1] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * i = 2:
 * flipCount = 1, nums[2] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * i = 3:
 * i >= k, so check isFlipped[0] (true): reduce flipCount to 0.
 * flipCount = 0, nums[3] = 1, condition (0 % 2 == 1) fails -> no flip.
 *
 * i = 4:
 * flipCount = 0, nums[4] = 0, condition (0 % 2 == 0) holds -> flip needed.
 * Check: 4 + 3 <= 8 is valid.
 * Perform flip: flipCount becomes 1, flips becomes 2, isFlipped[4] = true.
 *
 * i = 5:
 * flipCount = 1, nums[5] = 1, condition (1 % 2 == 1) holds -> flip needed.
 * Check: 5 + 3 <= 8 is valid.
 * Perform flip: flipCount becomes 2, flips becomes 3, isFlipped[5] = true.
 *
 * i = 6:
 * i >= k, check isFlipped[3] (false): flipCount remains 2.
 * flipCount = 2, nums[6] = 1, condition (2 % 2 == 1) i.e., (0 == 1) fails -> no flip.
 *
 * i = 7:
 * i >= k, check isFlipped[4] (true): reduce flipCount to 1.
 * flipCount = 1, nums[7] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * Final Result: flips = 3
 */

// Approach 2: Greedy algorithm that uses the input array to mark where a flip operation starts by setting the value to 5, and maintains a counter for active flips affecting each index.
// Time Complexity: O(n) - Only one pass through the array.
// Space Complexity: O(1) - In-place modifications with a few extra variables.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n                 = nums.size();       // Total number of elements in the array.
        int flips             = 0;                 // Counter for the total number of flips performed.
        int flipCountFromPast = 0;                 // Counter for the number of flips affecting the current index.

        for (int i = 0; i < n; i++) {
            // If we've moved past the window of a flip started at index i - k, remove its effect.
            if (i >= k && nums[i - k] == 5) {
                flipCountFromPast--;
            }

            // Determine if the current bit (after accounting for previous flips) is 0.
            if (flipCountFromPast % 2 == nums[i]) {
                // If there aren't enough remaining bits to flip, return -1.
                if (i + k > n) {
                    return -1;
                }
                // Start a new flip operation at index i.
                flipCountFromPast++;
                flips++;
                nums[i] = 5;      // Mark the start of a flip by setting the element to 5.
            }
        }
        return flips;
    }
};

/*
 * Dry Run
 * Example: nums = [0, 0, 0, 1, 0, 1, 1, 0], k = 3
 * Initial State: flips = 0, flipCountFromPast = 0, nums = [0, 0, 0, 1, 0, 1, 1, 0]
 *
 * i = 0:
 * flipCountFromPast = 0, nums[0] = 0, condition (0 % 2 == 0) holds -> need to flip.
 * Check: 0 + 3 <= 8 is valid.
 * Perform flip: flipCountFromPast becomes 1, flips becomes 1, nums[0] set to 5.
 *
 * i = 1:
 * flipCountFromPast = 1, nums[1] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * i = 2:
 * flipCountFromPast = 1, nums[2] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * i = 3:
 * i >= k, so check nums[0] (which is 5): decrement flipCountFromPast to 0.
 * flipCountFromPast = 0, nums[3] = 1, condition (0 % 2 == 1) fails -> no flip.
 *
 * i = 4:
 * flipCountFromPast = 0, nums[4] = 0, condition (0 % 2 == 0) holds -> need to flip.
 * Check: 4 + 3 <= 8 is valid.
 * Perform flip: flipCountFromPast becomes 1, flips becomes 2, nums[4] set to 5.
 *
 * i = 5:
 * flipCountFromPast = 1, nums[5] = 1, condition (1 % 2 == 1) holds -> need to flip.
 * Check: 5 + 3 <= 8 is valid.
 * Perform flip: flipCountFromPast becomes 2, flips becomes 3, nums[5] set to 5.
 *
 * i = 6:
 * i >= k, so check nums[3] (which is not 5): flipCountFromPast remains 2.
 * flipCountFromPast = 2, nums[6] = 1, condition (2 % 2 == 1) i.e., (0 == 1) fails -> no flip.
 *
 * i = 7:
 * i >= k, so check nums[4] (which is 5): decrement flipCountFromPast to 1.
 * flipCountFromPast = 1, nums[7] = 0, condition (1 % 2 == 0) fails -> no flip.
 *
 * Final Result: flips = 3
 */

// Approach 3: Greedy algorithm that uses a deque to track the effect of past flips over a sliding window, maintaining a running count of active flips affecting the current index.
// Time Complexity: O(n) - The array is traversed once, with deque operations in O(1) each.
// Space Complexity: O(k) - The deque stores at most k elements representing the flip effect.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int        n                 = nums.size(); // Number of elements in the input array.
        int        flips             = 0;           // Total count of flips performed.
        int        flipCountFromPast = 0;           // Running count of flips affecting the current index.
        deque<int> flipQue;                         // Queue to keep track of the flip operations in the last k indices.

        for (int i = 0; i < n; i++) {
            // If the current index is beyond the window of the earliest flip in the deque,
            // remove its effect.
            if (i >= k) {
                flipCountFromPast -= flipQue.front();
                flipQue.pop_front();
            }

            // If the current bit (after accounting for previous flips) is 0 (needs to be flipped)
            // then perform a flip operation.
            if (flipCountFromPast % 2 == nums[i]) {
                // Check if there are enough elements left to perform a flip.
                if (i + k > n) {
                    return -1;
                }
                // Perform a new flip starting at index i.
                flipCountFromPast++;
                flips++;
                flipQue.push_back(1);           // Mark that a flip is started at index i.
            } else {
                // No flip is needed at index i; record a 0 in the queue.
                flipQue.push_back(0);
            }
        }
        return flips;
    }
};

/*
 * Dry Run
 * Example: nums = [0, 0, 0, 1, 0, 1, 1, 0], k = 3
 * Initial State: flips = 0, flipCountFromPast = 0, flipQue = []
 *
 * i = 0:
 * - i < k, so no deque removal.
 * - nums[0] = 0, flipCountFromPast = 0, so (0 % 2 == 0) holds -> need to flip.
 * - Check: 0 + 3 <= 8 (valid).
 * - Perform flip: flipCountFromPast becomes 1, flips becomes 1, push_back(1) → flipQue = [1].
 *
 * i = 1:
 * - i < k, so no deque removal.
 * - nums[1] = 0, flipCountFromPast = 1, so (1 % 2 == 0) false -> no flip.
 * - Push 0 → flipQue = [1, 0].
 *
 * i = 2:
 * - i < k, so no deque removal.
 * - nums[2] = 0, flipCountFromPast = 1, (1 % 2 == 0) false -> no flip.
 * - Push 0 → flipQue = [1, 0, 0].
 *
 * i = 3:
 * - i >= k, remove effect: subtract flipQue.front() (1) → flipCountFromPast becomes 0, pop front → flipQue = [0, 0].
 * - nums[3] = 1, flipCountFromPast = 0, (0 % 2 == 1) false -> no flip.
 * - Push 0 → flipQue = [0, 0, 0].
 *
 * i = 4:
 * - i >= k, remove effect: subtract flipQue.front() (0) → flipCountFromPast remains 0, pop front → flipQue = [0, 0].
 * - nums[4] = 0, flipCountFromPast = 0, (0 % 2 == 0) holds -> need to flip.
 * - Check: 4 + 3 <= 8 (valid).
 * - Perform flip: flipCountFromPast becomes 1, flips becomes 2, push_back(1) → flipQue = [0, 0, 1].
 *
 * i = 5:
 * - i >= k, remove effect: subtract flipQue.front() (0) → flipCountFromPast remains 1, pop front → flipQue = [0, 1].
 * - nums[5] = 1, flipCountFromPast = 1, (1 % 2 == 1) holds -> need to flip.
 * - Check: 5 + 3 <= 8 (valid).
 * - Perform flip: flipCountFromPast becomes 2, flips becomes 3, push_back(1) → flipQue = [0, 1, 1].
 *
 * i = 6:
 * - i >= k, remove effect: subtract flipQue.front() (0) → flipCountFromPast remains 2, pop front → flipQue = [1, 1].
 * - nums[6] = 1, flipCountFromPast = 2, (2 % 2 == 1) → (0 == 1) false -> no flip.
 * - Push 0 → flipQue = [1, 1, 0].
 *
 * i = 7:
 * - i >= k, remove effect: subtract flipQue.front() (1) → flipCountFromPast becomes 1, pop front → flipQue = [1, 0].
 * - nums[7] = 0, flipCountFromPast = 1, (1 % 2 == 0) false -> no flip.
 * - Push 0 → flipQue = [1, 0, 0].
 *
 * Final Result: flips = 3
 */
