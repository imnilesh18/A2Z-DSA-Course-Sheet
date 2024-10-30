// Problem Link: https://www.geeksforgeeks.org/problems/merge-sort/1

/*
 * Merge Sort
 *
 * Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.
 *
 * Examples:
 * Input: arr[] = [4, 1, 3, 9, 7]
 * Output: [1, 3, 4, 7, 9]
 * Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 * Input: arr[] = [1, 3 , 2]
 * Output: [1, 2, 3]
 * Constraints:
 * 1 <= arr.size() <= 10^5
 * 1 <= arr[i] <= 10^5
 */

// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
   void merge(vector<int>& arr, int l, int m, int r){
      int n1 = m - l + 1;
      int n2 = r - m;
      int k  = l;

      int L[n1], R[n2];

      for (int i = 0; i < n1; i++) {
         L[i] = arr[k];
         k++;
      }

      for (int i = 0; i < n2; i++) {
         R[i] = arr[k];
         k++;
      }

      int i = 0;
      int j = 0;
      k = l;
      while (i < n1 && j < n2) {
         if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
         } else {
            arr[k] = R[j];
            j++;
         }
         k++;
      }

      while (i < n1) {
         arr[k] = L[i];
         i++;
         k++;
      }

      while (j < n2) {
         arr[k] = R[j];
         j++;
         k++;
      }
   }

   void mergeSort(vector<int>& arr, int l, int r){
      if (l >= r) {
         return;
      }

      int mid = l + (r - l) / 2;

      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);

      merge(arr, l, mid, r);
   }
};

// Code with comments for better understanding:
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
   // Function to merge two subarrays
   void merge(vector<int>& arr, int l, int m, int r){
      // Sizes of the two subarrays
      int n1 = m - l + 1;   // Left subarray size
      int n2 = r - m;       // Right subarray size

      // Temporary arrays to hold the two subarrays
      int L[n1], R[n2];

      // Copy data to temporary arrays L[] and R[]
      for (int i = 0; i < n1; i++) {
         L[i] = arr[l + i];    // Copy elements to left subarray
      }

      for (int i = 0; i < n2; i++) {
         R[i] = arr[m + 1 + i];    // Copy elements to right subarray
      }

      // Initial indexes for left, right, and merged subarray
      int i = 0;   // Index for L[]
      int j = 0;   // Index for R[]
      int k = l;   // Index for arr[]

      // Merge the temporary arrays back into arr[l..r]
      while (i < n1 && j < n2) {
         if (L[i] <= R[j]) { // If the element in left subarray is smaller
            arr[k] = L[i];   // Copy it to arr[]
            i++;             // Move to the next element in L[]
         } else {            // If the element in right subarray is smaller
            arr[k] = R[j];   // Copy it to arr[]
            j++;             // Move to the next element in R[]
         }
         k++;                // Move to the next position in arr[]
      }

      // Copy the remaining elements of L[], if any
      while (i < n1) {
         arr[k] = L[i];    // Copy remaining elements from L[]
         i++;
         k++;
      }

      // Copy the remaining elements of R[], if any
      while (j < n2) {
         arr[k] = R[j];    // Copy remaining elements from R[]
         j++;
         k++;
      }
   }

   // Main function to sort arr[l..r] using merge sort
   void mergeSort(vector<int>& arr, int l, int r){
      // Base case: if the subarray has one or no elements
      if (l >= r) {
         return;    // The array is already sorted
      }

      // Find the mid point of the array
      int mid = l + (r - l) / 2;

      // Recursively sort the first and second halves
      mergeSort(arr, l, mid);           // Sort the left half
      mergeSort(arr, mid + 1, r);       // Sort the right half

      // Merge the sorted halves
      merge(arr, l, mid, r);
   }
};
