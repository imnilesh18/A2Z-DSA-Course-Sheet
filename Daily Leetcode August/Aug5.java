/*
 * 2053. Kth Distinct String in an Array
 * 
 * A distinct string is a string that is present only once in an array.
 * Given an array of strings arr, and an integer k, return the kth distinct
 * string present in arr. If there are fewer than k distinct strings, return an
 * empty string "".
 * Note that the strings are considered in the order in which they appear in the
 * array.
 * 
 * Example 1:
 * Input: arr = ["d","b","c","b","c","a"], k = 2
 * Output: "a"
 * Explanation:
 * The only distinct strings in arr are "d" and "a".
 * "d" appears 1st, so it is the 1st distinct string.
 * "a" appears 2nd, so it is the 2nd distinct string.
 * Since k == 2, "a" is returned.
 * 
 * Example 2:
 * Input: arr = ["aaa","aa","a"], k = 1
 * Output: "aaa"
 * Explanation:
 * All strings in arr are distinct, so the 1st string "aaa" is returned.
 * 
 * Example 3:
 * Input: arr = ["a","b","a"], k = 3
 * Output: ""
 * Explanation:
 * The only distinct string is "b". Since there are fewer than 3 distinct
 * strings, we return an empty string "".
 */

// Optimising Extra Array Created:
class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String, Integer> map = new HashMap<>();

        for (String str : arr) {
            if (map.containsKey(str)) {
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
        }

        for (String str : arr) {
            if (map.get(str) == 1) {
                k -= 1;
            }
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
}

// Can create extra array to store distinct elements:
class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String, Integer> map = new HashMap<>();
        ArrayList<String> orderList = new ArrayList<>();

        for (String str : arr) {
            if (map.containsKey(str)) {
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
        }

        for (String str : arr) {
            if (map.get(str) == 1) {
                orderList.add(str);
            }
        }

        return (k <= orderList.size()) ? orderList.get(k - 1) : "";
    }
}

// Brute Force:
// TC- O(n2)
// SC - O(1)
class Solution {
    public String kthDistinct(String[] arr, int k) {
        for (int i = 0; i < arr.length; i++) {
            boolean distinct_flag = true;
            for (int j = 0; j < arr.length; j++) {
                if (i == j) {
                    continue;
                }
                if (arr[i].equals(arr[j])) {
                    distinct_flag = false;
                    break;
                }
            }
            if (distinct_flag) {
                k -= 1;
                if (k == 0) {
                    return arr[i];
                }
            }
        }
        return "";
    }
}