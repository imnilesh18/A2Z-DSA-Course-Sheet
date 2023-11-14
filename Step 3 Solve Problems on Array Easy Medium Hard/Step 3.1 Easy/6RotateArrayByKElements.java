// Optimal Solution
import java.util.ArrayList;

public class Solution {
        public static void Reverse(ArrayList<Integer> arr, int start, int end) {
                while (start < end) {
                        int temp = arr.get(start);
                        arr.set(start, arr.get(end));
                        arr.set(end, temp);
                        start++;
                        end--;
                }
        }

        public static ArrayList<Integer> rotateArray(ArrayList<Integer> arr, int k) {
                int n = arr.size();
                k = k % n; // Adjust k if it's greater than the array size to avoid redundant rotations

                // Reverse first k elements
                Reverse(arr, 0, k - 1);
                // Reverse last n-k elements
                Reverse(arr, k, n - 1);
                // Reverse whole array
                Reverse(arr, 0, n - 1);

                return arr;
        }
}

// Brute Force
/*
import java.util.ArrayList;

public class Solution {
        public static ArrayList<Integer> rotateArray(ArrayList<Integer> arr, int k) {
                ArrayList<Integer> temp = new ArrayList<Integer>();
                int n = arr.size();
                for(int i = 0; i < k; i++){
                        temp.add(arr.get(i));
                }

                for(int i = k; i < n; i++){
                        arr.set(i - k, arr.get(i));
                }

                for(int i = n - k; i < n; i++){
                        arr.set(i, temp.get(i - (n - k)));
                }

                return arr;
        }
}
*/
