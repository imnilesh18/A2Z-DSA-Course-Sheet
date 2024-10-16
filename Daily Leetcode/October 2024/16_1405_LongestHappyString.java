/*
 * 1405. Longest Happy String
 * 
 * A string s is called happy if it satisfies the following conditions:
 * 
 * s only contains the letters 'a', 'b', and 'c'.
 * s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * s contains at most a occurrences of the letter 'a'.
 * s contains at most b occurrences of the letter 'b'.
 * s contains at most c occurrences of the letter 'c'.
 * Given three integers a, b, and c, return the longest possible happy string.
 * If there are multiple longest happy strings, return any of them. If there is
 * no such string, return the empty string "".
 * 
 * A substring is a contiguous sequence of characters within a string.
 * 
 * Example 1:
 * Input: a = 1, b = 1, c = 7
 * Output: "ccaccbcc"
 * Explanation: "ccbccacc" would also be a correct answer.
 * 
 * Example 2:
 * Input: a = 7, b = 1, c = 0
 * Output: "aabaa"
 * Explanation: It is the only correct answer in this case.
 * 
 * Constraints:
 * 0 <= a, b, c <= 100
 * a + b + c > 0
 */

// T.C : O(a + b + c)
// S.C : O(1)
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);

        if (a > 0) {
            pq.offer(new int[] { a, 'a' });
        }

        if (b > 0) {
            pq.offer(new int[] { b, 'b' });
        }

        if (c > 0) {
            pq.offer(new int[] { c, 'c' });
        }

        StringBuilder result = new StringBuilder();

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currCount = curr[0];
            char currChar = (char) curr[1];

            if (result.length() >= 2 && result.charAt(result.length() - 1) == currChar
                    && result.charAt(result.length() - 2) == currChar) {
                if (pq.isEmpty()) {
                    break;
                }

                int[] next = pq.poll();
                int nextCount = next[0];
                char nextChar = (char) next[1];

                result.append(nextChar);
                nextCount--;

                if (nextCount > 0) {
                    pq.offer(new int[] { nextCount, nextChar });
                }

                pq.offer(curr);
            } else {
                result.append(currChar);
                currCount--;

                if (currCount > 0) {
                    pq.offer(new int[] { currCount, currChar });
                }
            }
        }
        return result.toString();
    }
}

// Code with comments for better understanding:
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        // PriorityQueue to store characters and their counts. The queue is sorted
        // in descending order of character count (largest count first).
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);

        // Add 'a' to the priority queue if its count is greater than 0
        if (a > 0) {
            pq.offer(new int[] { a, 'a' });
        }

        // Add 'b' to the priority queue if its count is greater than 0
        if (b > 0) {
            pq.offer(new int[] { b, 'b' });
        }

        // Add 'c' to the priority queue if its count is greater than 0
        if (c > 0) {
            pq.offer(new int[] { c, 'c' });
        }

        // StringBuilder to build the resulting happy string
        StringBuilder result = new StringBuilder();

        // Process the priority queue until it's empty
        while (!pq.isEmpty()) {
            // Get the character with the largest remaining count
            int[] curr = pq.poll();
            int currCount = curr[0];
            char currChar = (char) curr[1];

            // Check if the last two characters in the result are the same as the current
            // character
            if (result.length() >= 2 && result.charAt(result.length() - 1) == currChar
                    && result.charAt(result.length() - 2) == currChar) {

                // If the queue is empty, we cannot place any more characters, so break the loop
                if (pq.isEmpty()) {
                    break;
                }

                // Get the next character with the second-highest remaining count
                int[] next = pq.poll();
                int nextCount = next[0];
                char nextChar = (char) next[1];

                // Append the next character to the result
                result.append(nextChar);
                nextCount--;

                // If there are more occurrences of the next character, add it back to the queue
                if (nextCount > 0) {
                    pq.offer(new int[] { nextCount, nextChar });
                }

                // Put the current character back into the queue since we couldn't use it yet
                pq.offer(curr);
            } else {
                // If the last two characters are not the same as the current character,
                // append the current character to the result
                result.append(currChar);
                currCount--;

                // If there are more occurrences of the current character, add it back to the
                // queue
                if (currCount > 0) {
                    pq.offer(new int[] { currCount, currChar });
                }
            }
        }
        // Return the built happy string as the result
        return result.toString();
    }
}