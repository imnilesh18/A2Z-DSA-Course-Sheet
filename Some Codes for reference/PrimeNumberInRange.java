import java.util.*;

public class PrimeNumberInRange {
    public static void main(String args[]) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Create an ArrayList to store the prime numbers
        ArrayList<Integer> result = new ArrayList<>();

        // Read two integers from the user: the start and end of the range
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        // Variable to indicate if a number is not prime
        int flag = 0;

        // Loop through each number in the range from n1 to n2
        for (int i = n1; i <= n2; i++) {
            // Check if the current number i is divisible by any number less than itself
            for (int j = 2; j < i; j++) {
                // If i is divisible by j, then it's not a prime number
                if (i % j == 0) {
                    flag = 1; // Set flag to indicate non-prime
                    break; // Exit the inner loop
                }
            }
            // If flag is still 0, i is a prime number
            if (flag == 0 && i > 1) { // Also ensure i > 1 (1 is not considered a prime number)
                result.add(i); // Add the prime number to the result list
            }
            // Reset flag for the next number
            flag = 0;
        }

        // Print the list of prime numbers
        System.out.print(result);
    }
}
