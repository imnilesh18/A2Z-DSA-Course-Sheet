// Optimal Solution: select smallest from left side to get the max profit.

// Leetcode:

class Solution {
    public int maxProfit(int[] prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.length;

        for(int i = 1; i < n; i++){
            int cost = prices[i] - mini;
            maxProfit = Math.max(maxProfit, cost);
            mini = Math.min(mini, prices[i]);
        } 

        return maxProfit;       
    }
}

// Coding Ninjas:

import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution{
    public static int maximumProfit(ArrayList<Integer> prices){
        int mini = prices.get(0);
        int maxProfit = 0;
        int n = prices.size();

        for(int i =1; i < n; i++){
            int cost = prices.get(i) - mini;
            maxProfit = Math.max(maxProfit, cost);
            mini = Math.min(mini, prices.get(i));
        }
        return maxProfit;
    }
}