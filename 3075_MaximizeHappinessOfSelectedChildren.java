/*
 * 3075. Maximize Happiness of Selected Children
 * 
 * You are given an array happiness of length n, and a positive integer k.
 * There are n children standing in a queue, where the ith child has happiness
 * value happiness[i]. You want to select k children from these n children in k
 * turns.
 * In each turn, when you select a child, the happiness value of all the
 * children that have not been selected till now decreases by 1. Note that the
 * happiness value cannot become negative and gets decremented only if it is
 * positive.
 * Return the maximum sum of the happiness values of the selected children you
 * can achieve by selecting k children.
 * 
 * Example 1:
 * Input: happiness = [1,2,3], k = 2
 * Output: 4
 * Explanation: We can pick 2 children in the following way:
 * - Pick the child with the happiness value == 3. The happiness value of the
 * remaining children becomes [0,1].
 * - Pick the child with the happiness value == 1. The happiness value of the
 * remaining child becomes [0]. Note that the happiness value cannot become less
 * than 0.
 * The sum of the happiness values of the selected children is 3 + 1 = 4.
 * 
 * Example 2:
 * Input: happiness = [1,1,1,1], k = 2
 * Output: 1
 * Explanation: We can pick 2 children in the following way:
 * - Pick any child with the happiness value == 1. The happiness value of the
 * remaining children becomes [0,0,0].
 * - Pick the child with the happiness value == 0. The happiness value of the
 * remaining child becomes [0,0].
 * The sum of the happiness values of the selected children is 1 + 0 = 1.
 * 
 * Example 3:
 * Input: happiness = [2,3,4,5], k = 1
 * Output: 5
 * Explanation: We can pick 1 child in the following way:
 * - Pick the child with the happiness value == 5. The happiness value of the
 * remaining children becomes [1,2,3].
 * The sum of the happiness values of the selected children is 5.
 * 
 * Constraints:
 * 1 <= n == happiness.length <= 2 * 105
 * 1 <= happiness[i] <= 108
 * 1 <= k <= n
 */
//Approach-1 (Using Sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        reverseArray(happiness);

        long result = 0;
        int count = 0;

        for (int i = 0; i < k; i++) {
            result += Math.max(happiness[i] - count, 0);
            count++;
        }

        return result;
    }

    private void reverseArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}

class Solution {
    // Method to calculate the maximum happiness sum
    public long maximumHappinessSum(int[] happiness, int k) {
        // Sort the happiness array in ascending order
        Arrays.sort(happiness);

        // Initialize the result to store the sum of maximum happiness
        long result = 0;

        // Counter to keep track of the decrement to apply to each happiness value
        int count = 0;

        // Loop from the end of the sorted array to get the k largest elements
        for (int i = happiness.length - 1; i >= happiness.length - k; i--) {
            // Calculate the adjusted happiness value, ensuring it doesn't go below zero
            result += Math.max(happiness[i] - count, 0);

            // Increment the count for the next iteration
            count++;
        }

        // Return the calculated maximum happiness sum
        return result;
    }
}

//Approach-2 (Using Max Heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long result = 0;
        int count = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // max-heap

        for (int hap : happiness) {
            pq.offer(hap);
        }

        for (int i = 0; i < k; i++) {
            int hap = pq.poll();
            result += Math.max(hap - count, 0);
            count++;
        }

        return result;
    }
}