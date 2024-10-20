/*
 * 976. Largest Perimeter Triangle
 * 
 * Given an integer array nums, return the largest perimeter of a triangle with
 * a non-zero area, formed from three of these lengths. If it is impossible to
 * form any triangle of a non-zero area, return 0.
 * 
 * Example 1:
 * Input: nums = [2,1,2]
 * Output: 5
 * Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
 * 
 * Example 2:
 * Input: nums = [1,2,1,10]
 * Output: 0
 * Explanation:
 * You cannot use the side lengths 1, 1, and 2 to form a triangle.
 * You cannot use the side lengths 1, 1, and 10 to form a triangle.
 * You cannot use the side lengths 1, 2, and 10 to form a triangle.
 * As we cannot use any three side lengths to form a triangle of non-zero area,
 * we return 0.
 * 
 * Constraints:
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 */

// T.C : O(nlogn)
// S.C : O(1)

class Solution {
    public int largestPerimeter(int[] nums) {

        int n = nums.length;
        Arrays.sort(nums);
        // if we're sorting then directly we can say
        // b + c > a
        // a + c > b
        for (int i = n - 3; i >= 0; i--) {
            // nums[i] < nums[i + 1] < nums[i + 2]
            if (nums[i] + nums[i + 1] > nums[i + 2]) { // a + b > c
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
}

// Code with comments for better understanding:
// T.C : O(nlogn)
// S.C : O(1)

class Solution {
    public int largestPerimeter(int[] nums) {

        // Step 1: Get the length of the array
        int n = nums.length;

        // Step 2: Sort the array in ascending order
        // Sorting helps to easily apply the triangle inequality theorem
        // where we check for the largest possible triangle by considering
        // the three largest consecutive elements.
        Arrays.sort(nums);

        // Step 3: Loop from the third-to-last element down to the start of the array
        // We're iterating backwards because the largest possible perimeter
        // would be formed by the largest three numbers.
        for (int i = n - 3; i >= 0; i--) {

            // nums[i] is the smallest side of the triangle among the three we are
            // considering
            // nums[i + 1] and nums[i + 2] are the two larger sides

            // Step 4: Apply the triangle inequality theorem
            // A valid triangle can be formed if the sum of the two smaller sides is greater
            // than the largest side, which in this sorted array is nums[i + 2].
            if (nums[i] + nums[i + 1] > nums[i + 2]) { // a + b > c

                // Step 5: If a valid triangle is found, return its perimeter
                // The perimeter is the sum of the three side lengths.
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        // Step 6: If no valid triangle can be formed, return 0
        return 0;
    }
}
