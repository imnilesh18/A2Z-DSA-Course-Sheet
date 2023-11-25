// Optimal Solution
import java.util.*;

public class Solution {
        // Function to find the intersection of two arrays represented as ArrayLists
        public static ArrayList<Integer> findArrayIntersection(ArrayList<Integer> arr1, int n, ArrayList<Integer> arr2, int m) {
                // Initialize pointers for arr1 (i) and arr2 (j)
                int i = 0;
                int j = 0;

                // Create an ArrayList to store the intersection elements
                ArrayList<Integer> ans = new ArrayList<>();

                // Loop through both arrays while pointers i and j are within their bounds
                while (i < n && j < m) {
                        // If the current element in arr1 is smaller than the current element in arr2
                        if (arr1.get(i) < arr2.get(j)) {
                                // Move the pointer for arr1 to the next element
                                i++;
                        }
                        // If the current element in arr2 is smaller than the current element in arr1
                        else if (arr2.get(j) < arr1.get(i)) {
                                // Move the pointer for arr2 to the next element
                                j++;
                        }
                        // If both elements are equal (intersection found)
                        else {
                                // Add the common element to the intersection list
                                ans.add(arr1.get(i));
                                // Move pointers for both arrays to the next elements
                                i++;
                                j++;
                        }
                }
                // Return the list containing intersection elements
                return ans;
        }
}
