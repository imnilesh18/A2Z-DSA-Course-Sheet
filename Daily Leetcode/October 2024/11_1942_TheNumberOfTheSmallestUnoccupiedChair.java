/*
 * 1942. The Number of the Smallest Unoccupied Chair
 * 
 * There is a party where n friends numbered from 0 to n - 1 are attending.
 * There is an infinite number of chairs in this party that are numbered from 0
 * to infinity. When a friend arrives at the party, they sit on the unoccupied
 * chair with the smallest number.
 * 
 * For example, if chairs 0, 1, and 5 are occupied when a friend comes, they
 * will sit on chair number 2.
 * When a friend leaves the party, their chair becomes unoccupied at the moment
 * they leave. If another friend arrives at that same moment, they can sit in
 * that chair.
 * 
 * You are given a 0-indexed 2D integer array times where times[i] = [arrivali,
 * leavingi], indicating the arrival and leaving times of the ith friend
 * respectively, and an integer targetFriend. All arrival times are distinct.
 * 
 * Return the chair number that the friend numbered targetFriend will sit on.
 * 
 * Example 1:
 * Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
 * Output: 1
 * Explanation:
 * - Friend 0 arrives at time 1 and sits on chair 0.
 * - Friend 1 arrives at time 2 and sits on chair 1.
 * - Friend 1 leaves at time 3 and chair 1 becomes empty.
 * - Friend 0 leaves at time 4 and chair 0 becomes empty.
 * - Friend 2 arrives at time 4 and sits on chair 0.
 * Since friend 1 sat on chair 1, we return 1.
 * 
 * Example 2:
 * Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
 * Output: 2
 * Explanation:
 * - Friend 1 arrives at time 1 and sits on chair 0.
 * - Friend 2 arrives at time 2 and sits on chair 1.
 * - Friend 0 arrives at time 3 and sits on chair 2.
 * - Friend 1 leaves at time 5 and chair 0 becomes empty.
 * - Friend 2 leaves at time 6 and chair 1 becomes empty.
 * - Friend 0 leaves at time 10 and chair 2 becomes empty.
 * Since friend 0 sat on chair 2, we return 2.
 * 
 * Constraints:
 * n == times.length
 * 2 <= n <= 10^4
 * times[i].length == 2
 * 1 <= arrivali < leavingi <= 10^5
 * 0 <= targetFriend <= n - 1
 * Each arrivali time is distinct.
 */

//Approach-1 (Naive O(n^2) approach that comes to mind first)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;

        int[] chairs = new int[n]; // At max, we will have 0 to n-1 chairs
        Arrays.fill(chairs, -1);

        /*
         * We need to sort the times based on arrival time but we don't want to
         * lose the friend number after sorting. So, store the arrival time
         * of targetFriend because it's given in the question that
         * Each arrival time is distinct.
         */

        int targetFriendArrivalTime = times[targetFriend][0];

        // Sort the times based on arrival time
        Arrays.sort(times, (a, b) -> Integer.compare(a[0], b[0]));

        for (int[] time : times) {
            int arrival = time[0];
            int depart = time[1];
            // Find the first unoccupied chair
            for (int i = 0; i < n; i++) {
                if (chairs[i] <= arrival) {
                    chairs[i] = depart; // update with current friend depart time

                    if (arrival == targetFriendArrivalTime) {
                        return i;
                    }
                    break;
                }
            }
        }

        return -1;
    }
}

// Approach-2 (Using min-heaps)
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;
        // Min-heap for occupied chairs: {departTime, chairNo}
        PriorityQueue<int[]> occupied = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        // Min-heap for free chairs (keeps track of available chair numbers)
        PriorityQueue<Integer> free = new PriorityQueue<>();

        int targetFriendArrivalTime = times[targetFriend][0];

        int chairNo = 0;
        // Sort the times array based on arrival times
        Arrays.sort(times, (a, b) -> a[0] - b[0]);

        for (int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int depart = times[i][1];

            // Free chairs accordingly if their departure time is <= current arrival time
            while (!occupied.isEmpty() && occupied.peek()[0] <= arrival) {
                free.offer(occupied.poll()[1]); // This chair is now free
            }

            if (free.isEmpty()) {
                // No free chairs, assign a new chair
                occupied.offer(new int[] { depart, chairNo });

                // Check if this is the target friend
                if (arrival == targetFriendArrivalTime) {
                    return chairNo;
                }

                chairNo++; // Increment chair number for the next friend
            } else {
                // Assign the least available free chair
                int leastChairAvailable = free.poll();
                if (arrival == targetFriendArrivalTime) {
                    return leastChairAvailable;
                }
                occupied.offer(new int[] { depart, leastChairAvailable });
            }
        }
        return -1;
    }
}