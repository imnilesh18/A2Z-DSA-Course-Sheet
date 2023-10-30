// Coding Ninjas Solution
public class Solution {
        public static boolean isPalindrome(String str) {
                int i = 0;
                int length = str.length(); // Calculate the length once

                while (i < length / 2) {
                        if (str.charAt(i) != str.charAt(length - i - 1)) {
                                return false;
                        }
                        i++;
                }

                return true;
        }
}

// Leetcode Solution
/*
public class Solution {
    public static boolean isPalindrome(String str) {
        str = str.toLowerCase().replaceAll("[^a-z0-9]", "");
        int i = 0;
        int length = str.length(); // Calculate the length once

        while (i < length / 2) {
            if (str.charAt(i) != str.charAt(length - i - 1)) {
                return false;
            }
            i++;
        }

        return true;
    }
}
*/
