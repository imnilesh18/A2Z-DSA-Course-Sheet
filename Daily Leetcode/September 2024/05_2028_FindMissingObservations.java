/*
 * 2028. Find Missing Observations
 * 
 * You have observations of n + m 6-sided dice rolls with each face numbered
 * from 1 to 6. n of the observations went missing, and you only have the
 * observations of m rolls. Fortunately, you have also calculated the average
 * value of the n + m rolls.
 * You are given an integer array rolls of length m where rolls[i] is the value
 * of the ith observation. You are also given the two integers mean and n.
 * Return an array of length n containing the missing observations such that the
 * average value of the n + m rolls is exactly mean. If there are multiple valid
 * answers, return any of them. If no such array exists, return an empty array.
 * The average value of a set of k numbers is the sum of the numbers divided by
 * k.
 * Note that mean is an integer, so the sum of the n + m rolls should be
 * divisible by n + m.
 * 
 * Example 1:
 * Input: rolls = [3,2,4,3], mean = 4, n = 2
 * Output: [6,6]
 * Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
 * 
 * Example 2:
 * Input: rolls = [1,5,6], mean = 3, n = 4
 * Output: [2,3,2,2]
 * Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 =
 * 3.
 * 
 * Example 3:
 * Input: rolls = [1,2,3,4], mean = 6, n = 4
 * Output: []
 * Explanation: It is impossible for the mean to be 6 no matter what the 4
 * missing rolls are.
 * 
 * Constraints:
 * m == rolls.length
 * 1 <= n, m <= 105
 * 1 <= rolls[i], mean <= 6
 * 
 */

class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length; // Get the number of observed rolls
        int mSum = 0; // Initialize sum of observed rolls to 0
        for (int i = 0; i < m; i++) { // Loop through observed rolls
            mSum += rolls[i]; // Add each roll to mSum
        }
        int nSum = 0; // Initialize sum of missing rolls

        int totalObs = n + m; // Calculate the total number of observations (observed + missing)
        // we know mean = nSum + mSum/ totalObs
        // so mean * totalObs = nSum + mSum
        // nSum = (mean * totalObs) - mSum;

        nSum = (mean * totalObs) - mSum; // Calculate the sum of missing rolls

        // Check if the sum of missing rolls is valid (between n and 6*n)
        if (nSum > 6 * n || nSum < n) {
            return new int[0]; // If not possible, return an empty array
        }

        int[] missing = new int[n]; // Initialize the missing rolls array
        int parts = nSum / n; // Calculate the base value for each missing roll
        int remainder = nSum % n; // Calculate the remainder that needs to be distributed

        for (int i = 0; i < n; i++) { // Fill the missing array with the base value
            missing[i] = parts;
        }

        for (int i = 0; i < remainder; i++) { // Distribute the remainder by adding 1 to the first 'remainder' elements
            missing[i] = missing[i] + 1;
        }

        return missing; // Return the array of missing rolls
    }
}

// dry run:
/*
Goal:
We need to find the values of the 4 missing rolls such that the mean of all n + m = 7 rolls is exactly 3.

Step-by-Step Solution:

1. Calculate the total number of rolls:
   n + m = 4 + 3 = 7

2. Calculate the total sum for all the rolls:
   Since the mean of all the rolls is 3, the total sum of all 7 rolls should be:
   Total Sum = mean × (n + m) = 3 × 7 = 21

3. Calculate the sum of the known rolls:
   The observed rolls are [1, 5, 6]. So, the sum of the observed rolls is:
   Sum of known rolls = 1 + 5 + 6 = 12

4. Calculate the sum of the missing rolls:
   To find the sum of the missing rolls, subtract the sum of the known rolls from the total sum:
   Sum of missing rolls = 21 − 12 = 9
   So, the four missing rolls need to sum to 9.

5. Distribute the sum over the missing rolls:
   We need to distribute the sum 9 across 4 missing rolls.
   The base value for each roll is calculated as:
   Base value = 9 / 4 = 2 (integer division)
   So, each missing roll will be at least 2.

6. Distribute the remainder:
   The remainder when dividing 9 by 4 is:
   Remainder = 9 % 4 = 1
   This means we have to distribute this remainder (1) by incrementing one of the missing rolls by 1.
   Thus, the missing rolls start as [2, 2, 2, 2]. We increment one of these values to make the sum exactly 9.

7. Final Distribution:
   After incrementing one of the 2s by 1, the missing rolls become [3, 2, 2, 2].

8. Check the result:
   Now, the complete set of rolls is [1, 5, 6, 3, 2, 2, 2].
   The sum of all rolls is:
   1 + 5 + 6 + 3 + 2 + 2 + 2 = 21

   The mean of these rolls is:
   21 / 7 = 3

   So the solution satisfies the condition of the mean being 3.

Output:
The missing rolls are [3, 2, 2, 2] or any valid permutation of this, such as [2, 3, 2, 2].
*/
