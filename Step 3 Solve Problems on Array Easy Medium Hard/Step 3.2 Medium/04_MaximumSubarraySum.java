// Optimal Solution
// Kadane’s Algorithm
// Leetcode
class Solution {
        public int maxSubArray(int[] arr) {
                int n = arr.length;
                int sum = 0;
                int maxi =  arr[0];
                for(int i = 0; i < n; i++){
                        sum += arr[i];
                        if(sum > maxi){
                                maxi = sum;
                        }
                        if(sum < 0){
                                sum = 0;
                        }
                }
                return maxi;
        }
}

// Coding Ninjas
// Optimal Solution
// Kadane’s Algorithm
import java.util.* ;
import java.io.*;
public class Solution {

        public static long maxSubarraySum(int[] arr, int n) {
                long maxi = arr[0]; // maximum sum
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



// Better Solution
import java.util.* ;
import java.io.*;
public class Solution {

        public static long maxSubarraySum(int[] arr, int n) {
                int maxi = Integer.MIN_VALUE; // maximum sum

                for (int i = 0; i < n; i++) {
                        int sum = 0;
                        for (int j = i; j < n; j++) {
                                // current subarray = arr[i.....j]

                                //add the current element arr[j]
                                // to the sum i.e. sum of arr[i...j-1]
                                sum += arr[j];

                                maxi = Math.max(maxi, sum); // getting the maximum
                        }
                }
                return maxi;
        }

}


// Brute Force
import java.util.* ;
import java.io.*;
public class Solution {

        public static long maxSubarraySum(int[] arr, int n) {
                int maxi = Integer.MIN_VALUE; // maximum sum

                for (int i = 0; i < n; i++) {
                        for (int j = i; j < n; j++) {
                                // subarray = arr[i.....j]
                                int sum = 0;

                                //add all the elements of subarray:
                                for (int k = i; k <= j; k++) {
                                        sum += arr[k];
                                }

                                maxi = Math.max(maxi, sum);
                        }
                }

                return maxi;
        }

}
