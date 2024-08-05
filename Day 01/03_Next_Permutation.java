// Leetcode:

class Solution {
    public void reverseArray(int[] a, int start, int end){
        while (start < end) {
        // Swap elements at start and end indices
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        // Move start index forward and end index backward
        start++;
        end--;
        }
    }

    public void swap(int[] a, int t1, int t2){
        // Store the value at index t1 in a temporary variable
        int temp = a[t1];
        // Assign the value at index t2 to index t1
        a[t1] = a[t2];
        // Assign the value stored in the temporary variable to index t2
        a[t2] = temp;
    }
    public void nextPermutation(int[] nums) {
        int n = nums.length; // size of the array.

        // Step 1: Find the break point:
        int ind = -1; // break point
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                // index i is the break point
                ind = i;
                break;
            }
        }
        // If break point does not exist:
        if(ind == -1){
            // reverse the whole array:
            reverseArray(nums, 0, n-1);
            return;
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[ind]:
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums, i, ind);
                break;
            }
        }

        // Step 3: reverse the right half:
        reverseArray(nums, ind+1, n-1);
    }
}


// Coding Ninjas:
import java.util.* ;
import java.io.*; 
import java.util.ArrayList;
import java.util.Collections;

public class Solution 
{
	public static ArrayList<Integer> nextPermutation(ArrayList<Integer> A) 
	{
		int n = A.size(); // size of the array.
		
		// Step 1: Find the break point:
        int ind = -1; // break point
		for(int i = n-2; i >= 0; i--){
			if(A.get(i) < A.get(i+1)){
				// index i is the break point
				ind = i;
				break;
			}
		}
		
		// If break point does not exist:
		if(ind == -1){
			// reverse the whole array:
			Collections.reverse(A);
			return A;
		}

		// Step 2: Find the next greater element
        //         and swap it with arr[ind]:
		for(int i = n-1; i > ind; i--){
			if(A.get(i) > A.get(ind)){
				int temp = A.get(i);
                A.set(i, A.get(ind));
                A.set(ind, temp);
                break;
			}
		}

		// Step 3: reverse the right half:
		List<Integer> sublist = A.subList(ind + 1, n);
        Collections.reverse(sublist);

        return A;

	}
}
