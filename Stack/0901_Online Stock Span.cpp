/*
 * 901. Online Stock Span
 * (Solve 739. Daily Temperatures)
 *
 * Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
 *
 * The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
 *
 * For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
 * Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
 * Implement the StockSpanner class:
 *
 * StockSpanner() Initializes the object of the class.
 * int next(int price) Returns the span of the stock's price given that today's price is price.
 *
 *
 * Example 1:
 *
 * Input
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * Output
 * [null, 1, 1, 1, 2, 1, 4, 6]
 * Explanation
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // return 1
 * stockSpanner.next(80);  // return 1
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(70);  // return 2
 * stockSpanner.next(60);  // return 1
 * stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
 * stockSpanner.next(85);  // return 6
 *
 *
 * Constraints:
 * 1 <= price <= 10^5
 * At most 10^4 calls will be made to next.
 */

// Approach: Use a stack to store pairs (price, span) and calculate the span for the current price by summing spans of previous prices less than or equal to the current price.
// Time Complexity: O(n) because each element is pushed and popped at most once.
// Space Complexity: O(n) for the stack storing price-span pairs.
class StockSpanner {
public:
   stack<pair<int, int> > st; // stack to store pairs of (price, span)

   StockSpanner() {
      // Constructor to initialize the StockSpanner object
   }

   int next(int price) {
      int span = 1;   // initialize span for the current price

      // While the stack is not empty and the top element's price is less than or equal to current price
      while (!st.empty() && st.top().first <= price) {
         span += st.top().second; // add the span of the popped element to current span
         st.pop();                // remove the element since its span is merged into the current price's span
      }
      st.push({ price, span });   // push current price and its span into the stack
      return span;                // return the computed span for the current price
   }
};

/*
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
 * Dry Run
 * Input: [100, 80, 60, 70, 60, 75, 85]
 * Operation: next(100) -> span = 1; push (100, 1)
 * Operation: next(80)  -> span = 1; push (80, 1)
 * Operation: next(60)  -> span = 1; push (60, 1)
 * Operation: next(70)  -> pop (60, 1) since 60 <= 70, span becomes 2; push (70, 2)
 * Operation: next(60)  -> span = 1; push (60, 1)
 * Operation: next(75)  -> pop (60, 1) then pop (70, 2) since both <= 75, span becomes 4; push (75, 4)
 * Operation: next(85)  -> pop (75, 4), then pop (80, 1), then pop (100, 1) since all <= 85, span becomes 6; push (85, 6)
 * End Dry Run
 */
