public class Solution {
        public static int[] getSecondOrderElements(int n, int[] a) {
                int secondSmallest = secondSmallest(a, n);
                int secondLargest = secondLargest(a, n);

                int[] result = new int[2];
                result[1] = secondSmallest;
                result[0] = secondLargest;
                return result;
        }

        private static int secondSmallest(int[] arr, int n) {
                if (n < 2) {
                        return -1;
                }
                int small = Integer.MAX_VALUE;
                int second_small = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                        if (arr[i] < small) {
                                second_small = small;
                                small = arr[i];
                        } else if (arr[i] < second_small && arr[i] != small) {
                                second_small = arr[i];
                        }
                }
                return second_small;
        }

        private static int secondLargest(int[] arr, int n) {
                if (n < 2) {
                        return -1;
                }
                int large = Integer.MIN_VALUE;
                int second_large = Integer.MIN_VALUE;
                for (int i = 0; i < n; i++) {
                        if (arr[i] > large) {
                                second_large = large;
                                large = arr[i];
                        } else if (arr[i] > second_large && arr[i] != large) {
                                second_large = arr[i];
                        }
                }
                return second_large;
        }
}

// Brute Force
/*
import java.util.Arrays;
public class Solution {
        public static int[] getSecondOrderElements(int n, int[] a) {
                Arrays.sort(a);
                int small = a[1];
                int large = a[n - 2];
                return new int[]{large, small};
        }
}
*/
