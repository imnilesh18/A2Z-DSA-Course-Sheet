// Leetcode: Sort Colors red, white, or blue

// Optimal appraoch:

// Dutch National Flag algorithm:

class Solution {
    public void swap(int[] a, int n1, int n2){
        int temp = a[n1];
        a[n1] = a[n2];
        a[n2] = temp;
    }

    public void sortColors(int[] nums) {
        int low = 0, mid = 0 , high = nums.length-1; // 3 pointers

        while(mid <= high){

            if(nums[mid] == 0){
                // swapping arr[low] and arr[mid]
                swap(nums, low, mid);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;                
            }

            else{
                // swapping arr[mid] and arr[high]
                swap(nums, mid, high);
                high--;
            }

        } 
    }
}

// Better appraoch:
class Solution {
    public void sortColors(int[] nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                cnt0 += 1;
            }
            else if(nums[i] == 1){
                cnt1 += 1;
            }
            else{
                cnt2 += 1;
            }
        }

        //Replace the places in the original array:
        for(int i = 0; i < cnt0; i++){
            nums[i] = 0; // replacing 0's
        }

        for(int i = cnt0; i < cnt0 + cnt1; i++){
            nums[i] = 1; // replacing 1's
        }

        for(int i = cnt0 + cnt1; i < nums.length; i++){
            nums[i] = 2; // replacing 2's
        }
    }
}

