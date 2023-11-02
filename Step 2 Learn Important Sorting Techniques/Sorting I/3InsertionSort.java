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