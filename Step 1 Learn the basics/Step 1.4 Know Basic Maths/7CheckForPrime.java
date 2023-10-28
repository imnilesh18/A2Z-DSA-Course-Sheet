public class Solution {
        public static String isPrime(int num) {
                if (num <= 1) {
                        return "NO"; // Numbers less than or equal to 1 are not prime.
                }

                for (int i = 2; i < Math.sqrt(num); i++) {
                        if (num % i == 0) {
                                return "NO"; // If a divisor is found, the number is not prime.
                        }
                }

                return "YES"; // If no divisors are found, the number is prime.
        }

}