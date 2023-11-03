import java.util.ArrayList;
public class Solution {
        public static int removeDuplicates(ArrayList<Integer> arr, int n) {
                if (n <= 1) {
                        return n; // No duplicates to remove for an empty or single-element list
                }

                int newSize = 1; // Initialize the new size at 1, as the first element is always unique
                for (int i = 1; i < n; i++) {
                        int current = arr.get(i);
                        boolean isDuplicate = false;
                        for (int j = 0; j < newSize; j++) {
                                if (arr.get(j) == current) {
                                        isDuplicate = true;
                                        break;
                                }
                        }

                        if (!isDuplicate) {
                                arr.set(newSize, current);
                                newSize++;
                        }
                }

                arr.subList(newSize, n).clear(); // Remove the elements after newSize
                return newSize;

        }
}

/*
LeetCode Solution

public class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;

        if (n <= 1) {
            return n; // No duplicates to remove for an empty or single-element array
        }

        int newSize = 1; // Initialize the new size at 1, as the first element is always unique

        for (int i = 1; i < n; i++) {
            int current = nums[i];
            boolean isDuplicate = false;

            for (int j = 0; j < newSize; j++) {
                if (nums[j] == current) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                nums[newSize] = current;
                newSize++;
            }
        }

        return newSize;
    }
}

This Code will work only if they are sorted in non-decreasing order👇

import java.util.ArrayList;

public class Solution {
    public static int removeDuplicates(ArrayList<Integer> arr, int n) {
        if (n <= 1) {
            return n; // No duplicates to remove for an empty or single-element list
        }

        int newIndex = 1; // Initialize the new index at 1 since the first element is always unique

        for (int i = 1; i < n; i++) {
            if (!arr.get(i).equals(arr.get(i - 1))) {
                arr.set(newIndex, arr.get(i));
                newIndex++;
            }
        }

        return newIndex;
    }
}
*/