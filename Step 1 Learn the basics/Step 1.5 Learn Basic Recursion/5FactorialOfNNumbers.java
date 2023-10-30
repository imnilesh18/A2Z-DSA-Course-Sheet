import java.util.List;
import java.util.ArrayList;
public class Solution {
        public static List<Long> factorialNumbers(long n) {
                List<Long> factorialList = new ArrayList<>();
                long factorial = 1;
                long i = 1;

                while (factorial <= n) {
                        factorialList.add(factorial);
                        i++;
                        factorial = computeFactorial(i);
                }

                return factorialList;
        }

        private static long computeFactorial(long num) {
                if (num == 0 || num == 1){
                        return 1;
                }
                return num*computeFactorial(num-1);
        }
}