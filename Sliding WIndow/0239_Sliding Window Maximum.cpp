/*
 * 239. Sliding Window Maximum
 *
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * Return the max sliding window.
 *
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * 1 [3  -1  -3] 5  3  6  7       3
 * 1  3 [-1  -3  5] 3  6  7       5
 * 1  3  -1 [-3  5  3] 6  7       5
 * 1  3  -1  -3 [5  3  6] 7       6
 * 1  3  -1  -3  5 [3  6  7]      7
 *
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 */

// Approach: Use a deque to maintain indices of elements in descending order for each sliding window.
// TC: O(n) - Each element is pushed and popped from the deque at most once.
// SC: O(k) - The deque holds at most k elements (indices) at any time.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int         n = nums.size(); // get the number of elements in nums
        deque<int>  deq;             // deque to store indices of potential maximum elements in the current window
        vector<int> result;          // vector to store the maximum of each sliding window

        for (int i = 0; i < n; i++) {
            // Remove indices from the front if they are out of the current window (i - k)
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Remove elements from the back that are smaller than the current element,
            // since they cannot be the maximum for the current or future windows
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // Add current index to the deque
            deq.push_back(i);

            // Once we've processed at least k elements, add the maximum (element at front of deque) to result
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};

/*
 * Dry Run
 * Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
 *
 * i = 0:
 *  deq = [0] (push index 0; nums[0] = 1)
 * i = 1:
 *  deq = [0] -> nums[1] = 3 > nums[0] = 1, so pop index 0;
 *  then push index 1 -> deq = [1]
 * i = 2:
 *  deq = [1] -> nums[2] = -1 is less than nums[1] = 3, so push index 2 -> deq = [1, 2]
 *  i >= k - 1 (2 >= 2) so result = [nums[1]] = [3]
 * i = 3:
 *  deq = [1, 2] -> index 1 is still within window (1 > 3-3 = 0);
 *  nums[3] = -3 is less than nums[2] = -1, so push index 3 -> deq = [1, 2, 3]
 *  result = [3, nums[1]] = [3, 3]
 * i = 4:
 *  deq = [1, 2, 3] -> remove index 1 because deq.front() (1) <= 4-3 = 1; deq becomes [2, 3]
 *  Then, nums[4] = 5 > nums[3] = -3, pop index 3 -> deq = [2]
 *  Also, nums[4] = 5 > nums[2] = -1, pop index 2 -> deq becomes empty
 *  Push index 4 -> deq = [4]
 *  result = [3, 3, nums[4]] = [3, 3, 5]
 * i = 5:
 *  deq = [4] -> nums[5] = 3 is less than nums[4] = 5, so push index 5 -> deq = [4, 5]
 *  result = [3, 3, 5, nums[4]] = [3, 3, 5, 5]
 * i = 6:
 *  deq = [4, 5] -> indices in window are valid; nums[6] = 6 > nums[5] = 3, pop index 5 -> deq = [4]
 *  Then, nums[6] = 6 > nums[4] = 5, pop index 4 -> deq becomes empty
 *  Push index 6 -> deq = [6]
 *  result = [3, 3, 5, 5, nums[6]] = [3, 3, 5, 5, 6]
 * i = 7:
 *  deq = [6] -> index 6 is within window (6 > 7-3 = 4);
 *  nums[7] = 7 > nums[6] = 6, pop index 6 -> deq becomes empty
 *  Push index 7 -> deq = [7]
 *  result = [3, 3, 5, 5, 6, nums[7]] = [3, 3, 5, 5, 6, 7]
 *
 * Final Output: [3, 3, 5, 5, 6, 7]
 */
