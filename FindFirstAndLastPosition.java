public class Solution {
    public int[] searchRange(int[] a, int target) {
        int[] result = new int[2];
        result[0] = findFirst(a, target);
        result[1] = findLast(a, target);
        return result;
    }

    private int findFirst(int[] a, int target) {
        int l = 0, r = a.length - 1;
        int first = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == target) {
                first = mid;
                r = mid - 1; // Continue searching in the left half
            } else if (a[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return first;
    }

    private int findLast(int[] a, int target) {
        int l = 0, r = a.length - 1;
        int last = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == target) {
                last = mid;
                l = mid + 1; // Continue searching in the right half
            } else if (a[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return last;
    }
}
