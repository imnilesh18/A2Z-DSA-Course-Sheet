public class Solution {
        public static int[] countFrequency(int n, int x, int []nums){
                //precompute:
                int[] hash = new int[n];

                // Traverse all array elements
                for (int i = 0; i < n; i++) {
                        if (nums[i] >= 1 && nums[i] <= n) {
                                // Update the frequency of array[i]
                                hash[nums[i] - 1]++;
                        }
                }
                return hash;
        }
}