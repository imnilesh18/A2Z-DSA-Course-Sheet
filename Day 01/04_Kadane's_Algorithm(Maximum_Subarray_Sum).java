// Leetcode:

class Solution {
    public int maxSubArray(int[] nums) {
        long sum = 0;
        long maxi = Long.MIN_VALUE; // maximum sum

        for(int i = 0; i < nums.length; i++){
            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
            }

            // If sum < 0: discard the sum calculated
            if(sum < 0){
                sum = 0;
            }
        }

        // To consider the sum of the empty subarray
        // uncomment the following check:

        //if (maxi < 0) maxi = 0;

        return (int)maxi;
    }
}


// Coding Ninjas:

import java.util.* ;
import java.io.*; 

public class Solution {
	
	public static long maxSubarraySum(int[] arr, int n) {
		long maxi = Long.MIN_VALUE; // maximum sum
        long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += arr[i];

            if (sum > maxi) {
                maxi = sum;
            }

            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }

        // To consider the sum of the empty subarray
        // uncomment the following check:

        if (maxi < 0) maxi = 0;

        return maxi;
	}

}

