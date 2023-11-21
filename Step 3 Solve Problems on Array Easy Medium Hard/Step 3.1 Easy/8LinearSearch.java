import java.util.*;

public class Solution {
        // Method to perform linear search
        public static int linearSearch(int n, int num, int[] a) {
                // Loop through the array elements
                for (int i = 0; i < n; i++) {
                        // If the current element matches the number being searched
                        if (a[i] == num) {
                                // Return the index at which the number is found
                                return i;
                        }
                }
                // If the number is not found, return -1
                return -1;
        }
}
