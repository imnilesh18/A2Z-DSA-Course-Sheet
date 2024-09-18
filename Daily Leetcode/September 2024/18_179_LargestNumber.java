/*
 * 179. Largest Number
 * 
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of
 * an integer.
 * 
 * Example 1:
 * Input: nums = [10,2]
 * Output: "210"
 * 
 * Example 2:
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 109
 */

//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
public class Solution {
    public String largestNumber(int[] nums) {
        // Convert int array to Integer array for sorting with custom comparator
        Integer[] numsAsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        // Sort the array based on which combination of numbers forms a larger number
        Arrays.sort(numsAsInteger, (a, b) -> {
            String s1 = a + "" + b; // Combine as a string: a followed by b
            String s2 = b + "" + a; // Combine as a string: b followed by a
            return s2.compareTo(s1); // Sort in descending order by comparing the two combinations
        });

        // If the largest number is 0, the result should be "0" (handle cases like [0, 0])
        if (numsAsInteger[0] == 0) {
            return "0";
        }

        // Build the largest number by appending each number to a string
        StringBuilder result = new StringBuilder();
        for (int num : numsAsInteger) {
            result.append(num);
        }

        return result.toString(); // Return the final largest number
    }
}
