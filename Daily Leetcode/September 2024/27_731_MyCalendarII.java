/*
 * 731. My Calendar II
 * 
 * You are implementing a program to use as your calendar. We can add a new
 * event if adding the event will not cause a triple booking.
 * A triple booking happens when three events have some non-empty intersection
 * (i.e., some moment is common to all the three events.).
 * The event can be represented as a pair of integers start and end that
 * represents a booking on the half-open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 * Implement the MyCalendarTwo class:
 * MyCalendarTwo() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to
 * the calendar successfully without causing a triple booking. Otherwise, return
 * false and do not add the event to the calendar.
 * 
 * Example 1:
 * Input
 * ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
 * [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
 * Output
 * [null, true, true, true, false, true, true]
 * 
 * Explanation
 * MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
 * myCalendarTwo.book(10, 20); // return True, The event can be booked.
 * myCalendarTwo.book(50, 60); // return True, The event can be booked.
 * myCalendarTwo.book(10, 40); // return True, The event can be double booked.
 * myCalendarTwo.book(5, 15); // return False, The event cannot be booked,
 * because it would result in a triple booking.
 * myCalendarTwo.book(5, 10); // return True, The event can be booked, as it
 * does not use time 10 which is already double booked.
 * myCalendarTwo.book(25, 55); // return True, The event can be booked, as the
 * time in [25, 40) will be double booked with the third event, the time [40,
 * 50) will be single booked, and the time [50, 55) will be double booked with
 * the second event.
 * 
 * Constraints:
 * 0 <= start < end <= 109
 * At most 1000 calls will be made to book.
 */

//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo {

    // List to store intervals where double bookings occur
    List<int[]> doubleOverlappingRegion;
    // List to store all the bookings made
    List<int[]> overallBookings;

    public MyCalendarTwo() {
        doubleOverlappingRegion = new ArrayList<>();
        overallBookings = new ArrayList<>();
    }

    // Helper method to check if two intervals overlap
    boolean checkOverlap(int start1, int end1, int start2, int end2) {
        return Math.max(start1, start2) < Math.min(end1, end2);
    }

    // Helper method to find the overlapping region between two intervals
    int[] findOverlappedRegion(int start1, int end1, int start2, int end2) {
        return new int[] { Math.max(start1, start2), Math.min(end1, end2) };
    }

    public boolean book(int start, int end) {
        // Check for triple booking by comparing the new event with existing double
        // bookings
        for (int[] region : doubleOverlappingRegion) {
            if (checkOverlap(region[0], region[1], start, end)) {
                return false; // Triple booking detected, return false
            }
        }

        // Check for double booking by comparing the new event with existing bookings
        for (int[] booking : overallBookings) {
            if (checkOverlap(booking[0], booking[1], start, end)) {
                // If overlap found, add the overlapping region to doubleOverlappingRegion
                doubleOverlappingRegion.add(findOverlappedRegion(booking[0], booking[1], start, end));
            }
        }

        // Add the new booking to overallBookings
        overallBookings.add(new int[] { start, end });
        return true; // Booking was successful
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
