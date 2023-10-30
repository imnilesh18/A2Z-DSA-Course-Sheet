public class Solution {
        public static void printNtimes(int n) {
                // Calling recursive function
                String[] ans = new String[n];
                recursiveFunction(n, ans);

                // Print the contents of the array
                for (int i = 0; i < ans.length; i++) {
                        System.out.print(ans[i]);
                }
        }

        public static void recursiveFunction(int n, String[] ans) {
                if (n == 0) {
                        return;
                }

                // Call recursive function
                recursiveFunction(n - 1, ans);

                // Insert element in the array
                ans[n - 1] = "Coding Ninjas ";
        }
}


//Other Solution
/*
public class Solution {
    public static void printNtimes(int n){
        System.out.print("Coding Ninjas ");

        // Recursively calling printNtimes as long as 'n' > 1.
        if(n>1)
            printNtimes(n-1);
    }
}
*/