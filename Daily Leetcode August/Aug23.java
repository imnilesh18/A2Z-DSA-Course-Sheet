/*
 * 592. Fraction Addition and Subtraction
 * 
 * Given a string expression representing an expression of fraction addition and
 * subtraction, return the calculation result in string format.
 * The final result should be an irreducible fraction. If your final result is
 * an integer, change it to the format of a fraction that has a denominator 1.
 * So in this case, 2 should be converted to 2/1.
 * 
 * Example 1:
 * Input: expression = "-1/2+1/2"
 * Output: "0/1"
 * 
 * Example 2:
 * Input: expression = "-1/2+1/2+1/3"
 * Output: "1/3"
 * 
 * Example 3:
 * Input: expression = "1/3-1/2"
 * Output: "-1/6"
 */

class Solution {
    // Helper method to calculate the greatest common divisor (GCD) using Euclidean
    // algorithm
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public String fractionAddition(String expression) {
        int nume = 0; // Numerator
        int deno = 1; // Denominator

        int i = 0;
        int n = expression.length();

        while (i < n) {
            int currNume = 0; // Current fraction numerator
            int currDeno = 0; // Current fraction denominator

            boolean isNegative = (expression.charAt(i) == '-');

            // Skip '+' or '-'
            if (expression.charAt(i) == '-' || expression.charAt(i) == '+') {
                i++;
            }

            // Build the current numerator
            while (i < n && Character.isDigit(expression.charAt(i))) {
                int val = expression.charAt(i) - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++; // Skip the division character '/'

            if (isNegative) {
                currNume *= -1; // Apply negative sign if needed or if numerator is negative
            }

            // Build the current denominator
            while (i < n && Character.isDigit(expression.charAt(i))) {
                int val = expression.charAt(i) - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            // Update the accumulated numerator and denominator
            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        int gcd = gcd(Math.abs(nume), deno);
        nume /= gcd;
        deno /= gcd;

        return nume + "/" + deno;
    }
}