public class Solution {
        public static void insertionSort(int[] arr, int n) {
                if (n <= 1) {
                        return; // Base case: An array of 1 or fewer elements is already sorted.
                }
                insertionSort(arr, n - 1);
                // Insert the last element at its correct position in the sorted part of the array.
                int item = arr[n - 1];
                int j = n - 2;
                while (j >= 0 && item < arr[j]) {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                }
                arr[j + 1] = item;
        }
}

// Iterative Method
/*
 public class Solution {
     public static void insertionSort(int[] arr, int n) {
         for(int i = 1; i < n; i++){
             int item = arr[i];
             int j = i - 1;
             while(j >= 0 && item < arr[j]){
                 arr[j+1] = arr[j];
                 j = j-1;
             }
             arr[j+1] = item;
         }
     }
 }
*/