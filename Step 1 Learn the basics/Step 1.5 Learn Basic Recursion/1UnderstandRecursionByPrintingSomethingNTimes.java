/*
    Time Complexity: O( n )
    Space Complexity: O( n )

    where n is the integer.
*/
public class Solution {
        public static int[] printNos(int x) {
                // Declaring empty integer array
                int []ans = new int[x];

                // Calling recursive function
                recursiveFunction(x, ans);

                return ans;
        }

        public static void recursiveFunction(int x, int []ans) {
                if(x == 0) {
                        return;
                }

                // Call recursive function
                recursiveFunction(x - 1, ans);

                // Insert element in the array
                ans[x - 1] =x;
        }
}


//Iterative method
/*
public static int[] printNos(int x) {
        int[] result = new int[x];
        for (int i = 0; i < x; i++) {
            result[i] = i + 1;
        }
        return result;
    }
*/