/*
 * 167. Two Sum II - Input Array Is Sorted
 * 
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 * Your solution must use only constant extra space.
 * 
 * Example 1:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * Example 2:
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We
 * return [1, 3].
 * 
 * Example 3:
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * Constraints:
 * 
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 */

// T.C : O(n)
// S.C : O(1)

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                return new int[] { i + 1, j + 1 };
            }
        }
        return new int[] {};
    }
}

// Code with comments for better understanding:

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // n stores the length of the input array
        int n = numbers.length;

        // i is the left pointer starting at the beginning of the array
        int i = 0;

        // j is the right pointer starting at the end of the array
        int j = n - 1;

        // Continue looping while the left pointer is less than the right pointer
        while (i < j) {
            // sum stores the sum of the elements at the left and right pointers
            int sum = numbers[i] + numbers[j];

            // If the sum is greater than the target, move the right pointer leftwards
            if (sum > target) {
                j--;
            }
            // If the sum is less than the target, move the left pointer rightwards
            else if (sum < target) {
                i++;
            }
            // If the sum is equal to the target, return the 1-based indices
            else {
                return new int[] { i + 1, j + 1 };
            }
        }
        // If no solution is found, return an empty array (though it's guaranteed there
        // is one solution)
        return new int[] {};
    }
}
