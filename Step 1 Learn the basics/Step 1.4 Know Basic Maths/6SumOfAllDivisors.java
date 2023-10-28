public class Solution {
        public static int sumOfAllDivisors(int n) {
                int allSum = 0;

                for (int i = 1; i <= n; i++) {
                        allSum += sumOfDivisor(i);
                }

                return allSum;
        }

        public static int sumOfDivisor(int x) {
                int sum = 0;
                int sqrtX = (int) Math.sqrt(x); // Calculate the square root of x

                for (int i = 1; i <= sqrtX; i++) {
                        if (x % i == 0) {
                                sum += i; // Add the divisor to the sum
                                if (i != x / i) {
                                        sum += x / i; // Add the corresponding divisor
                                }
                        }
                }

                return sum;
        }
}

/*
Suppose we want to find the sum of divisors for x = 16.

We iterate through potential divisors from 1 to the square root of 16, which is 4 (i <= sqrt(x)).
The divisors of 16 are pairs of numbers where the product equals 16:

When i = 1, x / i = 16. So, we add both 1 and 16 to the sum because both are divisors of 16.
When i = 2, x / i = 8. We add both 2 and 8 to the sum.
When i = 3 not divisible by 16 will not go inside if statement.
When i = 4, x / i = 4. We add 4 to the sum.
Now, consider the if (i != x / i) condition.
It ensures that when i and x / i are the same (as in the last case when i = 4),
we don't add the same divisor twice to the sum. This is because we've already added it when i = 2.
So, the condition prevents duplicate additions and ensures that each divisor is counted only once in the sum.

The sum of divisors for 16 is 1 + 16 + 2 + 8 + 4 = 31.
The condition if (i != x / i) helps avoid counting the same divisor twice, ensuring the correct sum of divisors.
*/