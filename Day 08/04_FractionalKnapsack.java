/*
 * Fractional Knapsack
 * 
 * Given weights and values of n items, we need to put these items in a knapsack
 * of capacity w to get the maximum total value in the knapsack. Return a double
 * value representing the maximum value in knapsack.
 * Note: Unlike 0/1 knapsack, you are allowed to break the item here. The
 * details of structure/class is defined in the comments above the given
 * function.
 * 
 * Examples :
 * Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
 * Output: 240.000000
 * Explanation: Take the item with value 60 and weight 10, value 100 and weight
 * 20 and split the third item with value 120 and weight 30, to fit it into
 * weight 20. so it becomes (120/30)*20=80, so the total value becomes
 * 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00
 * from the given capacity of sack.
 * 
 * Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
 * Output: 160.000000
 * Explanation: Take both the items completely, without breaking. Total maximum
 * value of item we can have is 160.00 from the given capacity of sack.
 * 
 * Expected Time Complexity : O(n log n)
 * Expected Auxilliary Space: O(1)
 * 
 * Constraints:
 * 1 <= n <= 105
 * 1 <= w <= 109
 * 1 <= valuei, weighti <= 10
 */

import java.util.Arrays;

class Item {
    int value;
    int weight;

    public Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }
}

class Solution {
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sorting items by value-to-weight ratio in descending order
        Arrays.sort(arr, (a, b) -> {
            double r1 = (double) a.value / a.weight;
            double r2 = (double) b.value / b.weight;
            return Double.compare(r2, r1);
        });

        double totalValue = 0.0; // Total value of knapsack
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= W) {
                // If the item can be included completely
                totalValue += arr[i].value;
                W -= arr[i].weight;
            } else {
                // If the item can't be included completely, include fractionally
                totalValue += ((double) arr[i].value / arr[i].weight) * W;
                break; // Since we can't include any more items
            }
        }
        return totalValue;
    }
}

// Example usage
public class Main {
    public static void main(String[] args) {
        Item[] items = {
                new Item(8, 10),
                new Item(2, 1),
                new Item(10, 7),
                new Item(1, 7),
                new Item(9, 5),
                new Item(7, 1),
                new Item(2, 8),
                new Item(6, 6),
                new Item(6, 4),
                new Item(8, 9),
                new Item(7, 7)
        };
        Solution sol = new Solution();
        double maxValue = sol.fractionalKnapsack(10, items, items.length);
        System.out.println("Maximum value we can obtain = " + maxValue);
    }
}