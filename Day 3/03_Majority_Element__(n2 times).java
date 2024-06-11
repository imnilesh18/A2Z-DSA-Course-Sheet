// Optimal appraoch:
class Solution {
    public int majorityElement(int[] v) {
        int n = v.length;
        int cnt = 0;
        int el = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                el = v[i];
                cnt = 1;
            }
            else if(el == v[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }   
        return el;
    }
}

// Better appraoch:
class Solution {
    public int majorityElement(int[] v) {
        int n = v.length;
        HashMap<Integer, Integer> mpp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int value = mpp.getOrDefault(v[i], 0);
            mpp.put(v[i], value + 1);
        }
        for (Map.Entry<Integer, Integer> it : mpp.entrySet()) {
            if (it.getValue() > (n / 2)) {
                return it.getKey();
            }
        }
        return -1;
    }
}

//Brute Force
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt > (n/2)){
                return nums[i];
            }
        }
        return -1;        
    }
}