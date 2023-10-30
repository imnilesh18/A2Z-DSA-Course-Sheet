public class Solution {

        public static int[] reverseArray(int n, int[] nums) {
                return reverseArrayHelper(0, nums, n);
        }

        private static int[] reverseArrayHelper(int i, int[] nums, int n) {
                if (i >= n / 2) {
                        return nums;
                }

                int temp = nums[i];
                nums[i] = nums[n - i - 1];
                nums[n - i - 1] = temp;

                return reverseArrayHelper(i + 1, nums, n);
        }

}

// Other Solution 
/*

public class Solution {
    public static int[] reverseArray(int n, int []nums) {

        // Create a new vector to store the reversed elements.
        int []reversedArray = new int[n];

        // Traverse the original array in reverse order and store the elements in the new array.
        for (int i = n - 1; i >= 0; i--)
        {
            reversedArray[n - i - 1] = nums[i];
        }

        // Returning the reversed array.
        return reversedArray;
    }
}
*/
