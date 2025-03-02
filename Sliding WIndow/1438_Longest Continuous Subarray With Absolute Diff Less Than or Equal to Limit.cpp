/*
 * 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 *
 * Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
 *
 * Example 1:
 * Input: nums = [8,2,4,7], limit = 4
 * Output: 2
 * Explanation: All subarrays are:
 * [8] with maximum absolute diff |8-8| = 0 <= 4.
 * [8,2] with maximum absolute diff |8-2| = 6 > 4.
 * [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
 * [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
 * [2] with maximum absolute diff |2-2| = 0 <= 4.
 * [2,4] with maximum absolute diff |2-4| = 2 <= 4.
 * [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
 * [4] with maximum absolute diff |4-4| = 0 <= 4.
 * [4,7] with maximum absolute diff |4-7| = 3 <= 4.
 * [7] with maximum absolute diff |7-7| = 0 <= 4.
 * Therefore, the size of the longest subarray is 2.
 *
 * Example 2:
 * Input: nums = [10,1,2,4,7,2], limit = 5
 * Output: 4
 * Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
 *
 * Example 3:
 * Input: nums = [4,2,2,2,4,4,2,2], limit = 0
 * Output: 3
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= limit <= 10^9
 */

// Approach 1: Use a sliding window with two heaps (max and min) to track the current window's maximum and minimum values; when their difference exceeds the limit, adjust the window.
// Time Complexity: O(n log n) - Each element is pushed and popped from the heaps at most once.
// Space Complexity: O(n) - In the worst-case scenario, the heaps may contain all elements of the array.
class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        // n stores the size of the input array
        int n = nums.size();

        // maxPq: max heap to get the current maximum in the window
        // minPq: min heap to get the current minimum in the window
        priority_queue<P, vector<P>>             maxPq;
        priority_queue<P, vector<P>, greater<P>> minPq;

        int i         = 0; // start pointer of the sliding window
        int j         = 0; // end pointer of the sliding window
        int maxLength = 0; // stores the maximum valid subarray length found

        // Iterate over the array with the end pointer j
        while (j < n) {
            // Push the current element and its index into both heaps
            maxPq.push({ nums[j], j });
            minPq.push({ nums[j], j });

            // Check if the current window is valid
            while (maxPq.top().first - minPq.top().first > limit) {
                // Move the start pointer i to one position after the minimum index of the current max or min
                i = min(maxPq.top().second, minPq.top().second) + 1;

                // Remove elements from maxPq that are no longer in the window
                while (maxPq.top().second < i) {
                    maxPq.pop();
                }

                // Remove elements from minPq that are no longer in the window
                while (minPq.top().second < i) {
                    minPq.pop();
                }
            }

            // Update the maximum length with the current window size if it is larger
            maxLength = max(maxLength, j - i + 1);
            // Move to the next element in the array
            j++;
        }
        return maxLength;
    }
};

/*
 * Dry Run:
 * Input: nums = [8,2,4,7], limit = 4
 * Initial state: i = 0, j = 0, maxLength = 0, maxPq = [], minPq = []
 * Iteration 1: j = 0, element = 8
 * maxPq = [(8,0)], minPq = [(8,0)]
 * Difference = 8 - 8 = 0 <= 4  --> Valid window [8]
 * maxLength updated to 1 (window size = 1)
 * Iteration 2: j = 1, element = 2
 * maxPq = [(8,0), (2,1)], minPq = [(2,1), (8,0)]
 * Difference = 8 - 2 = 6 > 4  --> Window invalid
 * Adjust i: i = min(0,1) + 1 = 1
 * Remove elements with index < i: Remove (8,0) from heaps
 * New window: [2]
 * maxLength remains 1
 * Iteration 3: j = 2, element = 4
 * maxPq = [(4,2), (2,1)], minPq = [(2,1), (4,2)]
 * Difference = 4 - 2 = 2 <= 4  --> Valid window [2,4]
 * maxLength updated to 2 (window size = 2)
 * Iteration 4: j = 3, element = 7
 * maxPq = [(7,3), (2,1), (4,2)], minPq = [(2,1), (4,2), (7,3)]
 * Difference = 7 - 2 = 5 > 4  --> Window invalid
 * Adjust i: i = min(1,1) + 1 = 2
 * Remove elements with index < i: Remove (2,1) from heaps
 * New window: [4,7]
 * Difference = 7 - 4 = 3 <= 4  --> Valid window [4,7]
 * maxLength remains 2 (window size = 2)
 * Final Output: 2
 */

// Approach 2: Use a sliding window with a multiset to maintain the current window's sorted elements; shrink the window if the difference between the maximum and minimum exceeds the limit.
// Time Complexity: O(n log n) - each insertion/deletion in the multiset takes O(log n) over n elements.
// Space Complexity: O(n) - in the worst-case the multiset stores all elements.
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();     // size of the input array

        // multiset to maintain a sorted window of elements for quick access to min and max
        multiset<int> st;

        int i         = 0;      // start pointer of the sliding window
        int j         = 0;      // end pointer of the sliding window
        int maxLength = 0;      // variable to store the maximum valid subarray length

        while (j < n) {         // iterate over the array
            st.insert(nums[j]); // insert current element into the multiset

            // while the current window is invalid (difference between max and min exceeds limit)
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i])); // remove the element at index i from the multiset
                i++;                        // move the start pointer to shrink the window
            }

            // update maximum subarray length if the current window is larger
            maxLength = max(maxLength, j - i + 1);
            j++;          // move end pointer to the next element
        }
        return maxLength; // return the maximum subarray length found
    }
};

/*
 * Dry Run:
 * Input: nums = [8,2,4,7], limit = 4
 * Initial state: i = 0, j = 0, maxLength = 0, st = {}
 *
 * Iteration 1:
 *   j = 0, element = 8
 *   st becomes {8}
 *   Difference = 8 - 8 = 0 <= 4, window valid: [8]
 *   maxLength updated to 1 (window size = 1)
 *
 * Iteration 2:
 *   j = 1, element = 2
 *   st becomes {2,8}
 *   Difference = 8 - 2 = 6 > 4, window invalid
 *   Remove nums[i] = 8, increment i to 1, st becomes {2}
 *   Now window valid: [2]
 *   maxLength remains 1 (window size = 1)
 *
 * Iteration 3:
 *   j = 2, element = 4
 *   st becomes {2,4}
 *   Difference = 4 - 2 = 2 <= 4, window valid: [2,4]
 *   maxLength updated to 2 (window size = 2)
 *
 * Iteration 4:
 *   j = 3, element = 7
 *   st becomes {2,4,7}
 *   Difference = 7 - 2 = 5 > 4, window invalid
 *   Remove nums[i] = 2, increment i to 2, st becomes {4,7}
 *   Now difference = 7 - 4 = 3 <= 4, window valid: [4,7]
 *   maxLength remains 2 (window size = 2)
 *
 * Final Output:
 *   Maximum subarray length = 2
 */
