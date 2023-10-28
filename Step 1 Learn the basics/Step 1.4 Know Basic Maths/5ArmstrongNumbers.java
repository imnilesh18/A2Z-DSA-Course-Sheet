import java.util.Scanner;

public class Main {
        public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                int temp = n;
                int sum = 0;
                int numDigits = (int)(Math.log10(n) + 1); // Calculate the number of digits in n or length.
                // Example:
                // Math.log10(n) calculates the base-10 logarithm of n. For n = 1634, it's approximately 3.2138.
                // Math.log10(n) + 1 adds 1 to the logarithm result. For n = 1634, this becomes approximately 4.2138.
                // (int) truncates the decimal part, resulting in 4, representing the number of digits in n.

                while (temp > 0) {
                        int digit = temp % 10;
                        sum += Math.pow(digit, numDigits);
                        temp /= 10;
                }

                System.out.println(sum == n ? "true" : "false");
        }
}

// Other Code:

import java.util.Scanner;
public class Main {

        public static void main(String[] args) {
                // Write your code here
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                String str = Integer.toString(n);
                int power = str.length();
                int temp = n;
                int sum =0;
                while(temp > 0){
                        int digit = temp % 10;
                        temp = temp / 10;

                        sum = sum + (int)Math.pow(digit, power);
                }

                System.out.println(sum == n ? "true" : "false");

        }
}


