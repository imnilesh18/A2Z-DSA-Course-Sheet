/*
 * 1331. Rank Transform of an Array
 * 
 * Given an array of integers arr, replace each element with its rank.
 * The rank represents how large the element is. The rank has the following
 * rules:
 * Rank is an integer starting from 1.
 * The larger the element, the larger the rank. If two elements are equal, their
 * rank must be the same.
 * Rank should be as small as possible.
 * 
 * Example 1:
 * Input: arr = [40,10,20,30]
 * Output: [4,1,2,3]
 * Explanation: 40 is the largest element. 10 is the smallest. 20 is the second
 * smallest. 30 is the third smallest.
 * 
 * Example 2:
 * Input: arr = [100,100,100]
 * Output: [1,1,1]
 * Explanation: Same elements share the same rank.
 * 
 * Example 3:
 * Input: arr = [37,12,28,9,100,56,80,5,12]
 * Output: [5,3,4,2,8,6,7,1,3]
 * 
 * Constraints:
 * 0 <= arr.length <= 10^5
 * -10^9 <= arr[i] <= 10^9
 */

//T.C : O(n*logn)
//S.C : O(n)
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        TreeSet<Integer> sortedSet = new TreeSet<>();

        for (int num : arr) {
            sortedSet.add(num);
        }

        int rank = 1;
        for (int num : sortedSet) {
            mp.put(num, rank);
            rank++;
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = mp.get(arr[i]);
        }

        return arr;
    }
}

// Code with comments for better understanding:
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        // Create a HashMap to store the mapping of each element to its rank
        HashMap<Integer, Integer> mp = new HashMap<>();

        // Create a TreeSet to store the elements of the array in sorted order (without
        // duplicates)
        TreeSet<Integer> sortedSet = new TreeSet<>();

        // Add all elements from the array to the TreeSet, which automatically sorts
        // them
        for (int num : arr) {
            sortedSet.add(num);
        }

        // Initialize rank starting from 1
        int rank = 1;

        // Assign a rank to each element in the sorted set
        for (int num : sortedSet) {
            mp.put(num, rank); // Map the element to its rank
            rank++; // Increment rank for the next element
        }

        // Replace each element in the original array with its rank from the map
        for (int i = 0; i < arr.length; i++) {
            arr[i] = mp.get(arr[i]);
        }

        // Return the transformed array with ranks
        return arr;
    }
}
