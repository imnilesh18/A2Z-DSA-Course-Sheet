import java.util.Scanner;

public class ReverseLastName {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Prompt user to enter the full name
        System.out.println("Enter your full name (first, middle, last):");
        String fullName = sc.nextLine();

        // Split the full name into parts
        String[] nameParts = fullName.trim().split("\\s+");

        // Check if there is at least one part (last name)
        if (nameParts.length > 0) {
            // Get the last name (last part of the array)
            String lastName = nameParts[nameParts.length - 1];

            // Reverse the last name and print each letter
            System.out.println("Last name in reverse order:");
            for (int i = lastName.length() - 1; i >= 0; i--) {
                System.out.print(lastName.charAt(i));
            }
            System.out.println(); // Move to the next line after printing the reversed last name
        } else {
            System.out.println("No last name found.");
        }
    }
}
