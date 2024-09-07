/*
 * 134. Gas Station
 * 
 * There are n gas stations along a circular route, where the amount of gas at
 * the ith station is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from the ith station to its next (i + 1)th station. You begin the
 * journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is guaranteed to be
 * unique.
 * 
 * Example 1:
 * Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * Output: 3
 * Explanation:
 * Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
 * 4 = 4
 * Travel to station 4. Your tank = 4 - 1 + 5 = 8
 * Travel to station 0. Your tank = 8 - 2 + 1 = 7
 * Travel to station 1. Your tank = 7 - 3 + 2 = 6
 * Travel to station 2. Your tank = 6 - 4 + 3 = 5
 * Travel to station 3. The cost is 5. Your gas is just enough to travel back to
 * station 3.
 * Therefore, return 3 as the starting index.
 * 
 * Example 2:
 * Input: gas = [2,3,4], cost = [3,4,3]
 * Output: -1
 * Explanation:
 * You can't start at station 0 or 1, as there is not enough gas to travel to
 * the next station.
 * Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 =
 * 4
 * Travel to station 0. Your tank = 4 - 3 + 2 = 3
 * Travel to station 1. Your tank = 3 - 3 + 3 = 3
 * You cannot travel back to station 2, as it requires 4 unit of gas but you
 * only have 3.
 * Therefore, you can't travel around the circuit once no matter where you
 * start.
 * 
 * Constraints:
 * n == gas.length == cost.length
 * 1 <= n <= 105
 * 0 <= gas[i], cost[i] <= 104
 */

// Brute Force:
// Time Limit Exceeded: 34 / 39 testcases passed

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length; // Get the number of gas stations

        // Loop through each gas station
        for (int i = 0; i < n; i++) {

            // If the gas at the current station is less than the cost to reach the next,
            // skip this station
            if (gas[i] < cost[i]) {
                continue;
            }

            // Start at the next station in a circular manner
            int j = (i + 1) % n; // Move to the next station circularly

            // Calculate the current gas after moving from station i
            int costForMovingFromThisStation = cost[i]; // Cost to move from station i to i+1
            int gasEarnInNextStation = gas[j]; // Gas earned at the next station j
            int currGas = gas[i] - costForMovingFromThisStation + gasEarnInNextStation; // Remaining gas after moving to
                                                                                        // j

            // Continue moving to the next station in the circle
            while (j != i) { // Stop if we reach the starting station

                // If at any point the remaining gas is less than the cost to move, stop the
                // loop
                if (currGas < cost[j]) {
                    break; // Not enough gas to move from station j
                }

                // Update for the next move
                int costForMovingFromThisj = cost[j]; // Cost to move from station j to j+1
                j = (j + 1) % n; // Move to the next station
                int gasEarnedInNextStationj = gas[j]; // Gas earned at the next station j

                // Update current gas after the move
                currGas = currGas - costForMovingFromThisj + gasEarnedInNextStationj;
            }

            // If we have successfully completed the circuit
            if (j == i) {
                return i; // Return the starting station
            }
        }
        // If no solution found, return -1
        return -1;
    }
}

// Greedy Approach:
