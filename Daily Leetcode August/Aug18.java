/*
 * 264. Ugly Number II
 * 
 * An ugly number is a positive integer whose prime factors are limited to 2, 3,
 * and 5.
 * Given an integer n, return the nth ugly number.
 * 
 * Example 1:
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10
 * ugly numbers.
 * 
 * Example 2:
 * Input: n = 1
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 */

// Optimal Approach: Using DP concept

class Solution {
    public int nthUglyNumber(int n) {
        int[] arr = new int[n + 1];
        // arr[i] = ith ugly number
        // arr[n] = nth ugly number
        // return arr[n]

        int i2;
        int i3;
        int i5;

        i2 = i3 = i5 = 1;

        // 1st Ugly number is 1
        arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            int i2UglyNum = arr[i2] * 2; // 6

            int i3UglyNum = arr[i3] * 3; // 6

            int i5UglyNum = arr[i5] * 5; // 8

            int minUglyNum = Math.min(i2UglyNum, Math.min(i3UglyNum, i5UglyNum));

            arr[i] = minUglyNum;

            // increase the pointer of the minimum
            if (minUglyNum == i2UglyNum) {
                i2++;
            }
            if (minUglyNum == i3UglyNum) {
                i3++;
            }
            if (minUglyNum == i5UglyNum) {
                i5++;
            }

        }
        return arr[n];
    }
}

// Brute Force: Time Limit Exceeded 500 / 596 testcases passed

class Solution {
    public boolean isUgly(int n) {
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else if (n % 3 == 0) {
                n = n / 3;
            } else if (n % 5 == 0) {
                n = n / 5;
            } else {
                return false;
            }
        }
        // if(n == 1) return true; // 1 = 2^0 * 3^0 * 5^0 so 1 is a ugly number

        // return false;
        // OR
        return n == 1;
    }

    public int nthUglyNumber(int n) {
        int cnt = 0;
        int i = 1;
        for (i = 1; cnt <= n; i++) {
            if (isUgly(i)) {
                cnt++;
                if (cnt == n) {
                    return i;
                }
            }
        }
        return i;
    }
}