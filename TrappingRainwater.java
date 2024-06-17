// Leetcode : Optimal approach:
class Solution {
    public int trap(int[] a) {
        int n = a.length;
        int l = 0, r = n - 1, leftMax = 0, rightMax = 0;
        int res = 0;

        while(l <= r){
            if(a[l] <= a[r]){
                if(a[l] >= leftMax){
                    leftMax = a[l];
                }
                else{
                    res += leftMax - a[l];
                }
                l++;
            }

            else{
                if(a[r] >= rightMax){
                    rightMax = a[r];
                }
                else{
                    res += rightMax - a[r];
                }
                r--;
            }
        }
        return res;
    }
}

// Leetcode: Better approach:
class Solution {
    public int trap(int[] a) {
        int n = a.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];

        prefix[0] = a[0];
        for(int i = 1; i < n; i++){
            prefix[i] = Math.max(prefix[i - 1], a[i]);
        }

        suffix[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = Math.max(suffix[i + 1], a[i]);
        }

        int waterTrapped = 0;
        for(int i = 0; i < n; i++){
            waterTrapped += Math.min(prefix[i], suffix[i]) - a[i];
        }
        return waterTrapped;
    }
}


// Leetcode: Brute force

class Solution {
    public int trap(int[] a) {
        int n = a.length;
        int waterTrapped = 0;

        for(int i = 0; i < n; i++){
            int leftMax = 0;
            int rightMax = 0;

            int j = i;

            while(j >= 0){

                leftMax = Math.max(leftMax, a[j]);
                j--;
            }

            j = i;

            while(j < n){

                rightMax = Math.max(rightMax, a[j]);
                j++;
            }

            waterTrapped += Math.min(leftMax, rightMax) - a[i];

        }
        return waterTrapped;
    }   
}