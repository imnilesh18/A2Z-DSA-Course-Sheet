// Problem Link: https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

/*
 * Tower Of Hanoi
 *
 * The tower of Hanoi is a famous puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs n. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
 *
 * You only need to complete the function toh() that takes following parameters: n (number of discs), from (The rod number from which we move the disc), to (The rod number to which we move the disc), aux (The rod that is used as an auxiliary rod) and prints the required moves inside function body (See the example for the format of the output) as well as return the count of total moves made.
 *
 * Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered n. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.
 *
 * Examples:
 * Input: n = 2
 * Output:
 * move disk 1 from rod 1 to rod 2
 * move disk 2 from rod 1 to rod 3
 * move disk 1 from rod 2 to rod 3
 * 3
 * Explanation: For N=2 , steps will be as follows in the example and total 3 steps will be taken.
 *
 * Input: n = 3
 * Output:
 * move disk 1 from rod 1 to rod 3
 * move disk 2 from rod 1 to rod 2
 * move disk 1 from rod 3 to rod 2
 * move disk 3 from rod 1 to rod 3
 * move disk 1 from rod 2 to rod 1
 * move disk 2 from rod 2 to rod 3
 * move disk 1 from rod 1 to rod 3
 * 7
 * Explanation: For N=3 , steps will be as follows in the example and total 7 steps will be taken.
 *
 * Expected Time Complexity: O(2n).
 * Expected Auxiliary Space: O(n).
 *
 * Constraints:
 * 0 <= n <= 16
 */


// T.C : O(2^n)
// S.C : O(n) {Recursion Stack Space}
class Solution {
public:
   long long toh(int n, int from, int to, int aux){
      if (n == 1) {
         cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
         return 1;
      }

      int count = toh(n - 1, from, aux, to);

      cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
      count++;

      count += toh(n - 1, aux, to, from);

      return count;
   }
};

// Code with comments for better understanding:
// T.C : O(2^n)
// S.C : O(n) {Recursion Stack Space}
class Solution {
public:
   // The function toh takes in:
   // n: number of disks
   // from: the rod number from which we move the disk
   // to: the rod number to which we move the disk
   // aux: the auxiliary rod used for moving disks
   long long toh(int n, int from, int to, int aux){
      // Base case: When there is only one disk, we can move it directly from 'from' to 'to'
      if (n == 1) {
         cout << "move disk " << n << " from rod " << from << " to rod " << to << endl; // Print the move
         return 1;                                                                      // Return 1 move made
      }

      // Step 1: Move the top (n-1) disks from 'from' to 'aux', using 'to' as auxiliary
      int count = toh(n - 1, from, aux, to);

      // Step 2: Move the nth disk (largest disk) from 'from' to 'to'
      cout << "move disk " << n << " from rod " << from << " to rod " << to << endl; // Print the move
      count++;                                                                       // Increment the move count for this move

      // Step 3: Move the (n-1) disks from 'aux' to 'to', using 'from' as auxiliary
      count += toh(n - 1, aux, to, from); // Add the moves from the recursive call to count

      return count;                       // Return the total count of moves made
   }
};
