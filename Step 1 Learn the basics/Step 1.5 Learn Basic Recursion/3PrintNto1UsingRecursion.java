/*
    Time Complexity: O( n )
    Space Complexity: O( n )

    where n is the integer.
*/
public class Solution
{
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
                // Insert element in the array
                ans[ans.length - x] = x;

                // Call recursive function
                recursiveFunction(x - 1, ans);
        }
}