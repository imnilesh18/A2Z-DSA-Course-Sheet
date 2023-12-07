// Optimal Solution
// Moore’s Voting Algorithm
public class Solution {
        public static int majorityElement(int []v) {
                //size of the given array:
                int n = v.length;
                int cnt = 0; // count
                int el = 0; // Element

                //applying the algorithm:
                for (int i = 0; i < n; i++) {
                        if (cnt == 0) {
                                cnt = 1;
                                el = v[i];
                        } else if (el == v[i]) cnt++;
                        else cnt--;
                }

                //checking if the stored element
                // is the majority element:
                int cnt1 = 0;
                for (int i = 0; i < n; i++) {
                        if (v[i] == el) cnt1++;
                }

                if (cnt1 > (n / 2)) return el;
                return -1;
        }
}


// Better Solution using HashMap
import java.util.HashMap;
import java.util.Map;

public class Solution {
        public static int majorityElement(int []v) {
                //size of the given array:
                int n = v.length;

                //declaring a map:
                HashMap<Integer, Integer> mpp = new HashMap<>();

                //storing the elements with its occurnce:
                for (int i = 0; i < n; i++) {
                        int value = mpp.getOrDefault(v[i], 0);
                        mpp.put(v[i], value + 1);
                }

                //searching for the majority element:
                for (Map.Entry<Integer, Integer> it : mpp.entrySet()) {
                        if (it.getValue() > (n / 2)) {
                                return it.getKey();
                        }
                }

                return -1;
        }
}


// Brute Force
public class Solution {
        public static int majorityElement(int []v) {
                int n = v.length;


                for(int i = 0; i < n; i++){
                        int cnt = 0;
                        for(int j = 0; j < n; j++){
                                if(v[j] == v[i]){
                                        cnt++;
                                }
                        }
                        if(cnt > (n/2)){
                                return v[i];
                        }
                }
                return -1;
        }
}