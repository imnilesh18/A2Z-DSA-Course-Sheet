// LeetCode Solution
class Solution {
        public int findMaxConsecutiveOnes(int[] nums) {
                int cnt = 0;
                int maxi = 0;
                for (int i = 0; i < nums.length; i++) {
                        if (nums[i] == 1) {
                                cnt++;
                        } else {
                                cnt = 0;
                        }

                        maxi = Math.max(maxi, cnt);
                }
                return maxi;
        }
}


// Coding Ninjas Solution
// Sliding Window

public class Solution {
        public static int traffic(int n, int m, int []vehicle) {

                int i = 0, j = 0, countZeros = 0, ans = 0;

                while(j < n){

                        if(vehicle[j] == 0){
                                countZeros++;
                        }
                        while(countZeros > m){

                                if(vehicle[i] == 0){

                                        countZeros--;
                                }

                                i++;
                        }

                        ans = Math.max(ans, j - i + 1);

                        j++;

                }

                return ans;
        }
}
