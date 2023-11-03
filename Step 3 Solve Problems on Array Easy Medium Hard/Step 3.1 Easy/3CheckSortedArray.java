public class Solution {
        public static int isSorted(int n, int []a) {
                for (int i = 1; i < n; i++) {
                        if (a[i] < a[i - 1])
                                return 0;
                }

                return 1;
        }
}

// Brute Force
/*
public class Solution {
    public static int isSorted(int n, int []arr) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[i])
                    return 0;
            }
        }
        return 1;
    }
}
*/
// LeetCode
/*
class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
            }
        }

        if (nums[n - 1] > nums[0]) {
            cnt++;
        }

        return cnt <= 1;
    }
}

 */