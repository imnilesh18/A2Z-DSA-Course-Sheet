public class Solution {
        public static void bubbleSort(int[] arr, int n) {
                if (n == 1) {
                        return; // Base case: If the array is already sorted or has only one element, return.
                }

                for (int i = 0; i < n - 1; i++) {
                        if (arr[i] > arr[i + 1]) {
                                swap(arr, i, i + 1);
                        }
                }

                // Recursively sort the first n-1 elements.
                bubbleSort(arr, n - 1);
        }

        public static void swap(int[] arr, int i, int j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}

// Iterative Method
/*
public class Solution {
        public static void bubbleSort(int[] arr, int n) {
                for(int i = 0; i < n-1; i++){
                        for(int j = 0; j < n-1-i ; j++){
                                if(arr[j+1] < arr[j]){
                                        swap(arr, j, j+1);
                                }
                        }
                }
        }
        public static void swap(int[] arr, int i, int j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}
*/