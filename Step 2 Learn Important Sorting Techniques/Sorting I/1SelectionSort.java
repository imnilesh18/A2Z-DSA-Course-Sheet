public class Solution {
        public static void selectionSort(int[] arr) {
                int n = arr.length; // Get the length of the array

                for (int i = 0; i < n - 1; i++) {
                        int min = i;
                        for (int j = i + 1; j < n; j++) {
                                if (arr[j] < arr[min]) {
                                        min = j;
                                }
                        }
                        swap(arr, i, min);
                }
        }

        public static void swap(int[] arr, int i, int j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}
