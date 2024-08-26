/*
 * Job Sequencing Problem
 * 
 * Given a set of n jobs where each jobi has a deadline and profit associated
 * with it.
 * Each job takes 1 unit of time to complete and only one job can be scheduled
 * at a time. We earn the profit associated with a job if and only if the job is
 * completed by its deadline.
 * 
 * Find the number of jobs done and the maximum profit.
 * 
 * Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated
 * with that Job. Deadline of the job is the time on or before which job needs
 * to be completed to earn the profit.
 * 
 * Examples :
 * 
 * Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
 * Output: 2 60
 * Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
 * 
 * Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
 * Output: 2 127
 * Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
 * 
 * Expected Time Complexity: O(nlogn)
 * Expected Auxilliary Space: O(n)
 * 
 * Constraints:
 * 1 <= n <= 105
 * 1 <= Deadline,id <= n
 * 1 <= Profit <= 500
 */

 class Solution {
    // Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n) {
        // Sort jobs in descending order of profit
        Arrays.sort(arr, (a, b) -> (b.profit - a.profit));
        
        // Find the maximum deadline to determine the size of the hash array
        int maxDeadline = -1;
        for (int i = 0; i < n; i++) {
            maxDeadline = Math.max(maxDeadline, arr[i].deadline);
        }
        
        // Initialize hash array to keep track of free time slots
        // Size of hash array is maxDeadline + 1 to accommodate all possible deadlines
        int hash[] = new int[maxDeadline + 1];
        for (int i = 0; i <= maxDeadline; i++) {
            hash[i] = -1; // -1 indicates that the slot is free
        }
        
        // Initialize counters for number of jobs done and total profit
        int cnt = 0;
        int totalProfit = 0;
        
        // Iterate through sorted jobs
        for (int i = 0; i < n; i++) {
            // Try to find a free slot for the current job, starting from its deadline
            for (int j = arr[i].deadline; j > 0; j--) {
                // If the slot is free, schedule the job
                if (hash[j] == -1) {
                    hash[j] = arr[i].id; // Mark the slot as occupied by the current job's ID
                    cnt++; // Increment the count of jobs done
                    totalProfit += arr[i].profit; // Add the profit of the current job
                    break; // Move to the next job
                }
            }
        }
        
        // Prepare the result array with the number of jobs done and total profit
        int ans[] = new int[2];
        ans[0] = cnt; // Number of jobs done
        ans[1] = totalProfit; // Total profit
        return ans; // Return the result array
    }
}

/*
class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}
*/