public class Solution {
        public static void quickSort(int[] arr, int low, int high) {
                if (low < high) {
                        int mid = partition(arr, low, high);
                        quickSort(arr, low, mid - 1);
                        quickSort(arr, mid + 1, high);
                }
        }

        public static int partition(int[] arr, int low, int high) {
                int key = arr[low];
                int i = low;
                int j = high;

                while (i < j) {
                        while (i <= high && arr[i] <= key) {
                                i++;
                        }
                        while (arr[j] > key) {
                                j--;
                        }
                        if (i < j) {
                                swap(arr, i, j);
                        }
                }

                swap(arr, low, j);
                return j;
        }

        public static void swap(int[] arr, int i, int j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}
