import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int SumEven = 0;
        int SumOdd = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit % 2 == 0){
                SumEven += digit;
            }
            else{
                SumOdd += digit;
            }
        }
        System.out.println(SumEven + " " + SumOdd);
    }
}
