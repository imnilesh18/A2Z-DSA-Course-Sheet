// Optimal Two Pointer
import java.util.*;
public class Solution {
        public static String read(int n, int []arr, int target){
                Arrays.sort(arr);
                int left = 0, right = n-1;
                while(left < right){
                        int sum = arr[left] + arr[right];
                        if(sum == target){
                                return "YES";
                        }
                        else if(sum < target){
                                left++;
                        }
                        else{
                                right--;
                        }
                }
                return "NO";
        }
}

// Better 1
import java.util.HashMap;

public class Solution {
        public static String read(int n, int []arr, int target){
                HashMap<Integer, Integer> mpp = new HashMap<>();
                for(int i = 0; i< n; i++){
                        int num = arr[i];
                        int moreNeeded = target - num;
                        if(mpp.containsKey(moreNeeded)){
                                return "YES";
                        }

                        mpp.put(arr[i], i);
                }
                return "NO";
        }
}


// Brute Force 2
public class Solution {
        public static int[] twoSum(int n, int[] arr, int target) {
                int[] ans = new int[2];
                ans[0] = ans[1] = -1;
                for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                                if (arr[i] + arr[j] == target) {
                                        ans[0] = i;
                                        ans[1] = j;
                                        return ans;
                                }
                        }
                }
                return ans;
        }
}


// Brute Force 1
public class Solution {
        public static String read(int n, int []arr, int target){

                for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                                if (arr[i] + arr[j] == target) return "YES";
                        }
                }
                return "NO";
        }
}