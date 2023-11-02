public class Solution {
        public static void mergeSort(int[] arr, int low, int high) {
                if (low < high) {
                        int mid = (low + high) / 2;
                        mergeSort(arr, low, mid);
                        mergeSort(arr, mid + 1, high);
                        simpleMerge(arr, low, mid, high);
                }
        }

        public static void simpleMerge(int[] arr, int low, int mid, int high) {
                int[] c = new int[arr.length]; // Create a temporary array to hold merged values
                int i = low;
                int j = mid + 1;
                int k = low;

                while (i <= mid && j <= high) {
                        if (arr[i] < arr[j]) {
                                c[k] = arr[i];
                                i++;
                        } else {
                                c[k] = arr[j];
                                j++;
                        }
                        k++;
                }

                while (i <= mid) {
                        c[k] = arr[i];
                        i++;
                        k++;
                }

                while (j <= high) {
                        c[k] = arr[j];
                        j++;
                        k++;
                }

                for (i = low; i <= high; i++) {
                        arr[i] = c[i];
                }
        }
}