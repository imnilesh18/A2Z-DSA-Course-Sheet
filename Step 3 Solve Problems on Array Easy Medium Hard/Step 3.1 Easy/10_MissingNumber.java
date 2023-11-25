//Optimal Solution 2
class Solution {
        public int missingNumber(int[] nums) {
                int n = nums.length;
                int xor1 = 0, xor2 = 0;

                // XOR of elements in the array and numbers from 1 to n (inclusive)
                for (int i = 0; i < n; i++) {
                        xor2 = xor2 ^ nums[i];   // XOR of elements in the nums array
                        xor1 = xor1 ^ (i + 1);   // XOR of numbers from 1 to n
                }

                // XOR of (XOR of numbers from 1 to n) and (XOR of array elements)
                // will result in the missing number
                return (xor1 ^ xor2); // The missing number
        }
}



// Optimal Solution 1
class Solution {
        public int missingNumber(int[] nums) {
                int n = nums.length;

                // Calculate the sum of a consecutive sequence from 0 to n
                int sum1 = (n * (n + 1)) / 2;

                // Initialize sum2 to accumulate the elements in the nums array
                int sum2 = 0;

                // Iterate through the elements in the nums array
                for (int i = 0; i < n; i++) {
                        sum2 += nums[i]; // Accumulate the elements in nums array
                }

                // Return the missing number by finding the difference between
                // the expected sum and the actual sum of the elements in nums
                return (sum1 - sum2);
        }
}



// Better Approach (using Hashing):
class Solution {
        public int missingNumber(int[] nums) {
                int N = nums.length;
                int hash[] = new int[N + 1]; // hash array

                // storing the frequencies:
                for (int i = 0; i < N; i++) // Loop through the entire nums array
                        hash[nums[i]]++; // Increment frequency of nums[i] in hash array

                // checking the frequencies for numbers 0 to N:
                for (int i = 0; i <= N; i++) {
                        if (hash[i] == 0) {
                                return i; // Return the missing number
                        }
                }

                return -1; // This line will never execute if there's no missing number
        }
}


// Brute Force
class Solution {
        public int missingNumber(int[] nums) {
                int i, j, flag;
                int n = nums.length;
                for(i =0; i<=n; i++){
                        flag = 0;
                        for(j=0; j<n; j++){
                                if(nums[j] == i){
                                        flag = 1;
                                }
                        }
                        if(flag == 0){
                                return i;
                        }
                }
                return i;
        }
}