/*
 * 1422. Maximum Score After Splitting a String
 *
 * Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
 * The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
 *
 * Example 1:
 * Input: s = "011101"
 * Output: 5
 * Explanation:
 * All possible ways of splitting s into two non-empty substrings are:
 * left = "0" and right = "11101", score = 1 + 4 = 5
 * left = "01" and right = "1101", score = 1 + 3 = 4
 * left = "011" and right = "101", score = 1 + 2 = 3
 * left = "0111" and right = "01", score = 1 + 1 = 2
 * left = "01110" and right = "1", score = 2 + 1 = 3
 *
 * Example 2:
 * Input: s = "00111"
 * Output: 5
 * Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
 *
 * Example 3:
 * Input: s = "1111"
 * Output: 3
 *
 * Constraints:
 * 2 <= s.length <= 500
 * The string s consists of characters '0' and '1' only.
 */


// Brute Force:
// T.C: O(n²)
// S.C: O(1)
class Solution {
public:
   int maxScore(string s){
      int n = s.length();

      int result = INT_MIN;

      for (int i = 0; i <= n - 2; i++) {
         int zero_count = 0;
         for (int j = 0; j <= i; j++) {
            if (s[j] == '0') {
               zero_count++;
            }
         }

         int one_count = 0;
         for (int j = i + 1; j < n; j++) {
            if (s[j] == '1') {
               one_count++;
            }
         }

         result = max(result, zero_count + one_count);
      }
      return result;
   }
};

// Approach 2: (Two Passes)
// T.C: O(2N)
// S.C: O(1)
class Solution {
public:
   int maxScore(string s){
      int n      = s.length();
      int result = INT_MIN;

      int total_ones = count(begin(s), end(s), '1');   // 1st pass

      int zeros = 0;
      int ones  = 0;

      // right_ones = total_ones - ones;

      for (int i = 0; i <= n - 2; i++) {
         if (s[i] == '1') {
            ones++;
         } else {
            zeros++;
         }

         int right_ones = total_ones - ones;

         result = max(result, zeros + right_ones);
      }
      return result;
   }
};
// Approach 3: (In a Single Pass)
// T.C: O(N)
// S.C: O(1)

// Score = Zl + Or
// Ot = Ol + Or
// Or = (Ot - Ol) substitute this in Score
// Score = Zl + (Ot - Ol)
// Score = (Zl - Ol) + Ot
// So we have to maximize (Zl - Ol)
class Solution {
public:
   int maxScore(string s){
      int n = s.length();

      int score = INT_MIN;

      int zeros = 0;
      int ones  = 0;

      for (int i = 0; i <= n - 2; i++) {
         if (s[i] == '1') {
            ones++;
         } else {
            zeros++;
         }

         score = max(score, zeros - ones);
      }

      if (s[n - 1] == '1') {
         ones++;
      }

      return score + ones;
   }
};

// Code with comments for better understanding:

// Brute Force:
// T.C: O(n²)
// S.C: O(1)
class Solution {
public:
   int maxScore(string s){
      // Get the length of the string
      int n = s.length();

      // Initialize the result to the minimum possible integer
      int result = INT_MIN;

      // Loop to iterate through all possible splitting points
      // (i.e., between index 0 to n-2)
      for (int i = 0; i <= n - 2; i++) {
         // Count zeros in the left substring (0 to i)
         int zero_count = 0;
         for (int j = 0; j <= i; j++) {
            if (s[j] == '0') {
               zero_count++;
            }
         }

         // Count ones in the right substring (i+1 to n-1)
         int one_count = 0;
         for (int j = i + 1; j < n; j++) {
            if (s[j] == '1') {
               one_count++;
            }
         }

         // Update the maximum score
         result = max(result, zero_count + one_count);
      }

      // Return the maximum score
      return result;
   }
};

// Approach 2: (Two Passes)
// T.C: O(2N)
// S.C: O(1)
class Solution {
public:
   int maxScore(string s){
      int n      = s.length(); // Get the length of the string
      int result = INT_MIN;    // Initialize the maximum score to the minimum possible value

      // Calculate the total number of ones in the string (1st pass)
      // This helps us calculate the number of ones in the right substring directly.
      int total_ones = count(begin(s), end(s), '1');

      int zeros = 0;   // To count zeros in the left substring
      int ones  = 0;   // To count ones encountered so far in the left substring

      // Iterate through the string up to n-2, as we need to split into two non-empty parts
      for (int i = 0; i <= n - 2; i++) {
         if (s[i] == '1') {
            ones++;     // Increment the count of ones in the left substring
         } else {
            zeros++;    // Increment the count of zeros in the left substring
         }

         // Calculate the number of ones in the right substring
         int right_ones = total_ones - ones;

         // Update the maximum score (zeros in the left + ones in the right)
         result = max(result, zeros + right_ones);
      }

      return result;   // Return the maximum score obtained
   }
};

// Approach 3: (In a Single Pass)
// T.C: O(N)
// S.C: O(1)

// The goal is to maximize the score after splitting the string, where:
// Score = Zl + Or (Zeros in left + Ones in right)
// Ot = Ol + Or (Total ones = Ones in left + Ones in right)
// => Or = Ot - Ol (Rearrange to express right ones in terms of total and left ones)
// Substitute Or in the Score formula:
// Score = Zl + (Ot - Ol)
// => Score = (Zl - Ol) + Ot
// To maximize Score, we need to maximize (Zl - Ol) since Ot is constant.
class Solution {
public:
   int maxScore(string s){
      int n = s.length();  // Length of the input string

      int score = INT_MIN; // Initialize the score to the smallest possible value

      int zeros = 0;       // Count of zeros in the left substring
      int ones  = 0;       // Count of ones in the left substring

      // Iterate through the string until the second-to-last character (n-2)
      // This ensures both left and right substrings are non-empty
      for (int i = 0; i <= n - 2; i++) {
         if (s[i] == '1') {
            ones++;     // Increment count of ones in the left substring
         } else {
            zeros++;    // Increment count of zeros in the left substring
         }

         // Update the score by maximizing (Zl - Ol)
         score = max(score, zeros - ones);
      }

      // Check the last character (rightmost part of the split)
      // If it's '1', add it to the total count of ones
      if (s[n - 1] == '1') {
         ones++;
      }

      // Final score is the best (Zl - Ol) + total number of ones in the string
      return score + ones;
   }
};
