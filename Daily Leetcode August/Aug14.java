/*
 * 719. Find K-th Smallest Pair Distance
 * 
 * The distance of a pair of integers a and b is defined as the absolute
 * difference between a and b.
 * 
 * Given an integer array nums and an integer k, return the kth smallest
 * distance among all the pairs nums[i] and nums[j] where 0 <= i < j <
 * nums.length.
 * 
 * Example 1:
 * Input: nums = [1,3,1], k = 1
 * Output: 0
 * Explanation: Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * Example 2:
 * Input: nums = [1,1,1], k = 2
 * Output: 0
 * 
 * Example 3:
 * Input: nums = [1,6,1], k = 3
 * Output: 5
 */

//Approach-2 (Binary Search + Sliding Window)
//T.C : O(nlogn + nlogM), where nlogn is for sorting nums and nlogM is becasue of binary search and sliding window
//S.C : O(1)
class Solution {
    // Find count of pairs having distance <= D
    private int slidingWindowCount(int[] nums, int D) {
        int i = 0;
        int j = 1;
        int n = nums.length;
        int pairCount = 0;

        while (j < n) {
            while (nums[j] - nums[i] > D) {
                i++;
            }
            pairCount += j - i;
            j++;
        }
        return pairCount;
    }

    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int countPair = slidingWindowCount(nums, mid);

            if (countPair < k) {
                l = mid + 1;
            } else {
                result = mid; // stroign the mid as the possible result
                r = mid - 1;
            }
        }
        return result;
    }
}

// Approach-1 (storing the distances and finding the kth smallest)
// T.C : O(n^2)
// S.C : O(maxEl)
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        int maxEl = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > maxEl) {
                maxEl = nums[i];
            }
        }

        int[] vec = new int[maxEl + 1]; // for each distance d, how many pairs are there

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for (int d = 0; d < maxEl + 1; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d;
            }
        }

        return -1;
    }
}