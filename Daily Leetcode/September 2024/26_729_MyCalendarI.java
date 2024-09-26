/*
 * 729. My Calendar I
 * 
 * You are implementing a program to use as your calendar. We can add a new
 * event if adding the event will not cause a double booking.
 * A double booking happens when two events have some non-empty intersection
 * (i.e., some moment is common to both events.).
 * The event can be represented as a pair of integers start and end that
 * represents a booking on the half-open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 * Implement the MyCalendar class:
 * MyCalendar() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to
 * the calendar successfully without causing a double booking. Otherwise, return
 * false and do not add the event to the calendar.
 * 
 * Example 1:
 * Input
 * ["MyCalendar", "book", "book", "book"]
 * [[], [10, 20], [15, 25], [20, 30]]
 * Output
 * [null, true, false, true]
 * Explanation
 * MyCalendar myCalendar = new MyCalendar();
 * myCalendar.book(10, 20); // return True
 * myCalendar.book(15, 25); // return False, It can not be booked because time
 * 15 is already booked by another event.
 * myCalendar.book(20, 30); // return True, The event can be booked, as the
 * first event takes every time less than 20, but not including 20.
 * 
 * Constraints:
 * 0 <= start < end <= 109
 * At most 1000 calls will be made to book.
 */

//Approach-1 : Brute Force 
//T.C : O(n^2)
//S.C : O(n)
// Class to represent a calendar where you can book time slots
class MyCalendar {

    // List to store booked time slots as integer arrays
    List<int[]> calender;

    // Constructor to initialize the calendar
    public MyCalendar() {
        calender = new ArrayList<>();
    }

    // Method to book a new time slot from 'a' to 'b'
    public boolean book(int a, int b) {
        // Iterate through each booked time slot in the calendar
        for (int[] curr : calender) {
            // Retrieve the start and end of the current time slot
            int start = curr[0];
            int end = curr[1];
            // Check if the new time slot overlaps with the current time slot
            if (a < end && start < b) {
                // If there is an overlap, booking is not possible
                return false;
            }
        }

        // If no overlap is found, add the new time slot to the calendar
        calender.add(new int[] { a, b });
        // Return true indicating the booking was successful
        return true;
    }
}
/**
 * Usage example:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */


// Approach - 2 (set : lower_bound) : O(nlog(n))
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class MyCalendar {

    // TreeSet to store the booked intervals
    TreeSet<int[]> st;

    public MyCalendar() {
        // Initialize the TreeSet with a custom comparator
        // The comparator sorts the intervals primarily by start time
        // If start times are the same, it sorts by end time
        st = new TreeSet<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
    }

    public boolean book(int start, int end) {
        // Create an event array to represent the new booking
        int[] event = new int[] { start, end };

        // Find the first event that starts after or at the same time as the new event
        // This is done using the ceiling method which finds the least element greater
        // than or equal to the given element
        int[] next = st.ceiling(event); // O(logN)

        // Check if the current event overlaps with the next event
        // Overlap occurs if the next event starts before the current event ends
        if (next != null && next[0] < end) {
            return false; // Return false as booking cannot be made due to overlap
        }

        // Check if the current event overlaps with the previous event
        // This is done using the floor method which finds the greatest element less
        // than or equal to the given element
        int[] prev = st.floor(event);
        // Overlap occurs if the current event starts before the previous event ends
        if (prev != null && start < prev[1]) {
            return false; // Return false as booking cannot be made due to overlap
        }

        // If no overlap, add the booking to the set
        st.add(new int[] { start, end });
        return true; // Return true indicating the booking was successful
    }
}