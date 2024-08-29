import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println(isPalindrome(x));
    }

    public static boolean isPalindrome(int x) {
        // Convert the number to a string
        String str = Integer.toString(x);

        // Check if the string reads the same forward and backward
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}

// Java code snippet to reverse a number and check if it is a palindrome

public class PalindromeNumber {
    public static void main(String[] args) {
        int x = 121; // You can change this value to test other cases
        System.out.println(isPalindrome(x));
    }

    public static boolean isPalindrome(int x) {
        // Negative numbers and numbers ending with zero (except zero itself) are not
        // palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // Reverse the number
        int original = x;
        int reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Check if the reversed number is equal to the original number
        return original == reversed;
    }
}
