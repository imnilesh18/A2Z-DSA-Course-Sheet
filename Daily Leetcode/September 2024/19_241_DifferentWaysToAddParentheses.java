/*
 * 241. Different Ways to Add Parentheses
 * 
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 * The test cases are generated such that the output values fit in a 32-bit
 * integer and the number of different results does not exceed 104.
 * 
 * Example 1:
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * 
 * Constraints:
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 * All the integer values in the input expression are in the range [0, 99].
 * The integer values in the input expression do not have a leading '-' or '+'
 * denoting the sign.
 */

//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(n*2^n)
//S.C : O(2^n) //The result vector stores all possible outcomes. The number of results is at most exponential in terms of the number of operators, so the space required to store the results is O(2^n).
class Solution {
    // Recursive method to compute all possible results of the expression by adding
    // parentheses
    public List<Integer> solve(String s) {
        List<Integer> result = new ArrayList<>(); // List to store the computed results
        int n = s.length(); // Length of the input string

        // Loop through each character of the string
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i); // Current character

            // If the current character is an operator
            if (ch == '+' || ch == '-' || ch == '*') {
                // Recursively solve for the left and right parts of the string divided by the
                // operator
                List<Integer> left = solve(s.substring(0, i)); // Left side of the expression
                List<Integer> right = solve(s.substring(i + 1)); // Right side of the expression

                // Combine the results from the left and right parts
                for (int x : left) {
                    for (int y : right) {
                        // Compute based on the operator
                        if (ch == '+') {
                            result.add(x + y); // Add if the operator is '+'
                        } else if (ch == '-') {
                            result.add(x - y); // Subtract if the operator is '-'
                        } else {
                            result.add(x * y); // Multiply if the operator is '*'
                        }
                    }
                }
            }
        }

        // Base case: if no operators are found in the string, parse it as an integer
        if (result.isEmpty()) {
            result.add(Integer.parseInt(s)); // Add the number to the result
        }

        return result; // Return the list of results
    }

    // Main method to start the computation process
    public List<Integer> diffWaysToCompute(String expression) {
        return solve(expression); // Call the recursive solve method
    }
}
