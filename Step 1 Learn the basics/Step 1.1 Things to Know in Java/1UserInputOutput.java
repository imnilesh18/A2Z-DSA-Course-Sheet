import java.util.Scanner;
public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char c = sc.next().charAt(0);
        sc.close();
        if(Character.isUpperCase(c)) {
            System.out.println("1"); // Uppercase alphabet
        } else if (Character.isLowerCase(c)) {
            System.out.println("0"); // Lowercase alphabet
        }else {
            System.out.println("-1"); // Not an alphabet
        }
    }
}



