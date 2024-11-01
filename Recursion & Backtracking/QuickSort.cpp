// Problem Link: https://www.geeksforgeeks.org/problems/quick-sort/1

/*
 * Quick Sort
 *
 * Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
 * Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).
 * Note: The low and high are inclusive.
 * Implement the partition() and quickSort() functions to sort the array.
 *
 * Example 1:
 * Input:
 * N = 5
 * arr[] = { 4, 1, 3, 9, 7}
 * Output:
 * 1 3 4 7 9
 *
 * Example 2:
 * Input:
 * N = 9
 * arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
 * Output:
 * 1 1 2 3 4 6 7 9 10
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the functions partition()  and quickSort() which takes the array arr[], low and high as input parameters and partitions the array. Consider the last element as the pivot such that all the elements less than(or equal to) the pivot lie before it and the elements greater than it lie after the pivot.
 *
 * Expected Time Complexity: O(N*logN)
 * Expected Auxiliary Space: O(logN)
 *
 * Constraints:
 * 1 <= N <= 10^3
 * 1 <= arr[i] <= 10^4
 */

class Solution {
public:
   //Function to sort an array using quick sort algorithm.
   void quickSort(int arr[], int low, int high){
      if (low >= high) {
         return;
      }

      int Pi = partition(arr, low, high);
      quickSort(arr, low, Pi - 1);
      quickSort(arr, Pi + 1, high);
   }

public:
   int partition(int arr[], int low, int high){
      int pivot = arr[high];
      int Pi    = low;

      for (int i = low; i < high; i++) {
         if (arr[i] < pivot) {
            swap(arr[i], arr[Pi]);
            Pi++;
         }
      }

      swap(arr[Pi], arr[high]);
      return Pi;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   // Main QuickSort function that recursively sorts the array
   void quickSort(int arr[], int low, int high){
      // Base case: if low >= high, array has 1 or 0 elements
      if (low >= high) {
         return;
      }

      // Partition the array and get the pivot's final position
      // After partition:
      // - Elements smaller than pivot are on left side of Pi
      // - Elements larger than pivot are on right side of Pi
      int Pi = partition(arr, low, high);

      // Recursively sort the left part (before pivot)
      quickSort(arr, low, Pi - 1);

      // Recursively sort the right part (after pivot)
      quickSort(arr, Pi + 1, high);
   }

public:
   // Partition function that places pivot in its correct position
   int partition(int arr[], int low, int high){
      // Choose the rightmost element as pivot
      int pivot = arr[high];

      // Pi represents the boundary between elements smaller and larger than pivot
      // Initially set to low (leftmost position)
      int Pi = low;

      // Iterate through array from low to high-1
      for (int i = low; i < high; i++) {
         // If current element is smaller than pivot
         if (arr[i] < pivot) {
            // Swap current element with element at Pi
            // This moves smaller element to left side
            swap(arr[i], arr[Pi]);
            // Move boundary one position right
            Pi++;
         }
      }

      // Place pivot in its final position by swapping with boundary element
      swap(arr[Pi], arr[high]);

      // Return pivot's final position
      return Pi;
   }
};

/*
 * Time Complexity Analysis:
 * ------------------------
 * Total Time Complexity: O(N*logN) // T(n) = T(n/2) + T(n/2) + n
 * - The partition process takes O(N) time
 * - The recursion tree has logN levels in average case
 * - In worst case (already sorted array), time complexity becomes O(N²) // T(n) = T(n - 1) + n
 *
 * Space Complexity Analysis:
 * -------------------------
 * Total Space Complexity: O(logN)
 * - Space is used by the recursion stack
 * - In average case, recursion depth is logN
 * - In worst case (already sorted array), space complexity becomes O(N)
 *
 * Key Points of the Algorithm:
 * --------------------------
 * 1. Uses divide-and-conquer strategy
 * 2. In-place sorting algorithm
 * 3. Not stable (may change order of equal elements)
 * 4. Performance depends heavily on pivot selection
 * 5. Current implementation uses last element as pivot
 *
 * where N is the number of elements in the array
 *
 * Partition Process Visualization:
 * ------------------------------
 * Initial: [4, 1, 3, 9, 7], pivot = 7
 * Step 1: [4, 1, 3, 9, 7], Pi = 0 (4 < 7, swap with self)
 * Step 2: [4, 1, 3, 9, 7], Pi = 1 (1 < 7)
 * Step 3: [4, 1, 3, 9, 7], Pi = 2 (3 < 7)
 * Step 4: [4, 1, 3, 9, 7], Pi = 2 (9 > 7, no swap)
 * Final:  [4, 1, 3, 7, 9], Pi = 3 (pivot placed)
 */
