/*
 * Factorials of large numbers
 * 
 * Given an integer N, find its factorial. return a list of integers denoting
 * the digits that make up the factorial of N.
 * 
 * Example 1:
 * Input: N = 5
 * Output: [1,2,0]
 * Explanation : 5! = 1*2*3*4*5 = 120
 * 
 * Example 2:
 * Input: N = 10
 * Output: [3,6,2,8,8,0,0]
 * Explanation :
 * 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
 * 
 * Your Task:
 * You don't need to read input or print anything. Complete the function
 * factorial() that takes integer N as input parameter and returns a list of
 * integers denoting the digits that make up the factorial of N.
 * 
 * Expected Time Complexity : O(N2)
 * Expected Auxilliary Space : O(1)
 * 
 * Constraints:
 * 1 ≤ N ≤ 1000
 */

class Solution {
    public void multiply(List<Integer> nums, int[] size, int multiplier) {
        int carry = 0;

        for (int i = 0; i < size[0]; i++) {
            int result = (multiplier * nums.get(i)) + carry;

            nums.set(i, result % 10);
            carry = result / 10;
        }

        while (carry != 0) {
            nums.add(size[0], carry % 10);
            size[0]++;
            carry /= 10;
        }
    }

    public ArrayList<Integer> factorial(int N) {
        ArrayList<Integer> nums = new ArrayList<>(Collections.nCopies(10000, 0));
        nums.set(0, 1);
        int[] size = { 1 }; // Using an array to simulate pass-by-reference for size

        for (int multiplier = 2; multiplier <= N; multiplier++) {
            multiply(nums, size, multiplier);
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int i = size[0] - 1; i >= 0; i--) {
            result.add(nums.get(i));
        }
        return result;
    }
}