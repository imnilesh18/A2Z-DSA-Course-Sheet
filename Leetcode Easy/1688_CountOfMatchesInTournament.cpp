/*
 * 1688. Count of Matches in Tournament
 *
 * You are given an integer n, the number of teams in a tournament that has strange rules:
 * If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
 * If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
 * Return the number of matches played in the tournament until a winner is decided.
 *
 * Example 1:
 * Input: n = 7
 * Output: 6
 * Explanation: Details of the tournament:
 * - 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
 * - 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
 * - 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
 * Total number of matches = 3 + 2 + 1 = 6.
 *
 * Example 2:
 * Input: n = 14
 * Output: 13
 * Explanation: Details of the tournament:
 * - 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
 * - 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
 * - 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
 * - 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
 * Total number of matches = 7 + 3 + 2 + 1 = 13.
 *
 * Constraints:
 * 1 <= n <= 200
 */

// Approach : 1
class Solution {
public:
   int numberOfMatches(int n){
      return n - 1;
   }
};

// Code with comments for better understanding:
class Solution {
public:
   int numberOfMatches(int n){
      // In any tournament, to get one winner, all other teams must lose exactly once
      // Therefore, number of matches = number of teams that must lose = n-1
      return n - 1;
   }
};

/*
 * Intuition:
 * 1. For a tournament to have one winner:
 * - Every team except the winner must lose exactly one match
 * - Once a team loses, they're eliminated
 * - The winner never loses
 *
 * 2. Example with n = 7 teams:
 * - 6 teams must lose to get 1 winner
 * - Each match eliminates exactly one team
 * - Therefore, we need exactly 6 matches
 *
 * 3. Example with n = 14 teams:
 * - 13 teams must lose to get 1 winner
 * - Each match eliminates exactly one team
 * - Therefore, we need exactly 13 matches
 *
 * Key Observation:
 * - Instead of simulating the tournament process
 * - We can directly calculate that we need (n-1) matches
 * - Because (n-1) teams need to be eliminated
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

// Approach 2 :
class Solution {
public:
   int numberOfMatches(int n){
      // Keep track of total matches played
      int matches = 0;

      // Continue until we have a winner (only 1 team remains)
      while (n > 1) {
         // If number of teams is even
         if (n % 2 == 0) {
            // Each team pairs up, so matches = n/2
            matches += n / 2;
            // Teams advancing to next round = n/2
            n = n / 2;
         }
         // If number of teams is odd
         else {
            // One team gets a bye, rest pair up
            // Matches = (n-1)/2
            matches += (n - 1) / 2;
            // Teams advancing = (n-1)/2 (winners) + 1 (team that got bye)
            n = (n - 1) / 2 + 1;
         }
      }
      return matches;
   }
};

/*
 * Intuition:
 * This solution simulates the actual tournament process round by round
 *
 * For example, with n = 7:
 * Round 1:
 * - Teams = 7 (odd)
 * - 1 team gets bye, 6 teams play
 * - Matches = (7-1)/2 = 3
 * - Teams advancing = 3 (winners) + 1 (bye) = 4
 *
 * Round 2:
 * - Teams = 4 (even)
 * - All teams pair up
 * - Matches = 4/2 = 2
 * - Teams advancing = 2
 *
 * Round 3:
 * - Teams = 2 (even)
 * - Final match
 * - Matches = 1
 * - Winner decided
 *
 * Total matches = 3 + 2 + 1 = 6
 *
 * Time Complexity: O(log n) as teams are halved each round
 * Space Complexity: O(1)
 *
 * Note: While this solution correctly simulates the tournament,
 * there's a more elegant solution using the insight that
 * total matches needed = n-1
 */
