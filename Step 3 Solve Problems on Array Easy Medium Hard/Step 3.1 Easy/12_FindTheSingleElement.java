// Optimal Solution
public class Solution {
        public static int getSingleElement(int []arr){
                int xorr = 0;
                for(int i = 0; i < arr.length; i++){
                        xorr = xorr ^ arr[i];
                }
                return xorr;
        }
}


// Hashing using the map data structure:
import java.util.*;
public class Solution {
        public static int getSingleElement(int []arr){
                //size of the array:
                int n = arr.length;

                // Declare the hashmap.
                // And hash the given array:
                HashMap<Integer, Integer> mpp = new HashMap<>();
                for (int i = 0; i < n; i++) {
                        int value = mpp.getOrDefault(arr[i], 0);
                        mpp.put(arr[i], value + 1);
                }

                //Find the single element and return the answer:
                for (Map.Entry<Integer, Integer> it : mpp.entrySet()) {
                        if (it.getValue() == 1) {
                                return it.getKey();
                        }
                }

                //This line will never execute
                //if the array contains a single element.
                return -1;
        }
}


// Better Approach(Using Hashing):
public class Solution {
        public static int getSingleElement(int []arr){
                //size of the array:
                int n = arr.length;

                // Find the maximum element:
                int maxi = arr[0];
                for (int i = 0; i < n; i++) {
                        maxi = Math.max(maxi, arr[i]);
                }

                // Declare hash array of size maxi+1
                // And hash the given array:
                int[] hash = new int[maxi + 1];
                for (int i = 0; i < n; i++) {
                        hash[arr[i]]++;
                }

                //Find the single element and return the answer:
                for (int i = 0; i < n; i++) {
                        if (hash[arr[i]] == 1)
                                return arr[i];
                }

                //This line will never execute
                //if the array contains a single element.
                return -1;
        }
}


// Brute Force
public class Solution {
        public static int getSingleElement(int []arr){

                for(int i = 0; i < arr.length; i++){
                        int num = arr[i];
                        int cnt = 0;
                        for(int j = 0; j <arr.length; j++){
                                if(arr[j] == num){
                                        cnt++;
                                }
                        }
                        if(cnt == 1){
                                return num;
                        }
                }
                return -1;
        }
}

