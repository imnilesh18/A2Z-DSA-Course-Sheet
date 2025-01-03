/*
 * N meetings in one room
 * Difficulty: EasyAccuracy: 45.3%Submissions: 272K+Points: 2
 * You are given timings of n meetings in the form of (start[i], end[i]) where
 * start[i] is the start time of meeting i and end[i] is the finish time of
 * meeting i. Return the maximum number of meetings that can be accommodated in
 * a single meeting room, when only one meeting can be held in the meeting room
 * at a particular time.
 * Note: The start time of one chosen meeting can't be equal to the end time of
 * the other chosen meeting.
 * 
 * Examples :
 * 
 * Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] = [2, 4, 6, 7, 9, 9]
 * Output: 4
 * Explanation: Maximum four meetings can be held with given start and end
 * timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
 * 
 * Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
 * Output: 1
 * Explanation: Only one meetings can be held with given start and end timings.
 * Expected Time Complexity: O(n*logn)
 * Expected Auxilliary Space: O(n)
 */
class Data {
    int start;
    int end;
    int pos;

    Data(int start, int end, int pos) {
        this.start = start;
        this.end = end;
        this.pos = pos;
    }
}

class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maxMeetings(int n, int start[], int end[]) {
        ArrayList<Data> arr = new ArrayList<>();

        // Create a list of meetings with start, end times and positions
        for (int i = 0; i < n; i++) {
            arr.add(new Data(start[i], end[i], i + 1));
        }

        // Sort meetings by their end times
        Collections.sort(arr, new Comparator<Data>() {
            @Override
            public int compare(Data val1, Data val2) {
                return Integer.compare(val1.end, val2.end);
            }
        });

        // Initialize count of meetings and the end time of the last selected meeting
        int cnt = 1;
        int freeTime = arr.get(0).end;
        ArrayList<Integer> ds = new ArrayList<>();
        ds.add(arr.get(0).pos);

        // Iterate through the meetings
        for (int i = 1; i < n; i++) {
            if (arr.get(i).start > freeTime) {
                cnt++;
                freeTime = arr.get(i).end;
                ds.add(arr.get(i).pos);
            }
        }

        // Optionally, you could print the selected meetings' positions
        // System.out.println(ds);

        return cnt;
    }
}