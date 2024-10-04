/*
 * 2491. Divide Players Into Teams of Equal Skill
 * 
 * You are given a positive integer array skill of even length n where skill[i]
 * denotes the skill of the ith player. Divide the players into n / 2 teams of
 * size 2 such that the total skill of each team is equal.
 * The chemistry of a team is equal to the product of the skills of the players
 * on that team.
 * Return the sum of the chemistry of all the teams, or return -1 if there is no
 * way to divide the players into teams such that the total skill of each team
 * is equal.
 * 
 * Example 1:
 * Input: skill = [3,2,5,1,3,4]
 * Output: 22
 * Explanation:
 * Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where
 * each team has a total skill of 6.
 * The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 +
 * 9 = 22.
 * 
 * Example 2:
 * Input: skill = [3,4]
 * Output: 12
 * Explanation:
 * The two players form a team with a total skill of 7.
 * The chemistry of the team is 3 * 4 = 12.
 * 
 * Example 3:
 * Input: skill = [1,1,2,3]
 * Output: -1
 * Explanation:
 * There is no way to divide the players into teams such that the total skill of
 * each team is equal.
 * 
 * Constraints:
 * 2 <= skill.length <= 10^5
 * skill.length is even.
 * 1 <= skill[i] <= 1000
 */

// My approach:
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        Arrays.sort(skill);

        int left = 0;
        int right = n - 1;
        int skillSum = skill[left] + skill[right];
        long result = 0;

        while (left < right) {
            if (skill[left] + skill[right] != skillSum) {
                return -1; // If we find any team that doesn't have the target skill sum, return -1.
            }
            result += skill[left] * skill[right]; // Calculate chemistry as the product of team members
            left++;
            right--;
        }

        return result;
    }
}

// Approach-2 (Using frequency of skills similar to counting sort)
// T.C : O(n)
// S.C : O(1000) ~= O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;

        // Frequency array to count occurrences of each skill value
        int[] freq = new int[1001];
        int totalSum = 0;

        for (int s : skill) {
            totalSum += s;
            freq[s]++; // Update frequency
        }

        int teams = n / 2;

        // Check if total sum is divisible by the number of teams
        if (totalSum % teams != 0) {
            return -1;
        }

        int targetSum = totalSum / teams;
        long chemistry = 0;

        for (int currSkill : skill) {
            int remainingSkill = targetSum - currSkill;

            // If the complementary skill is not available, return -1
            if (freq[remainingSkill] <= 0) {
                return -1;
            }

            chemistry += (long) currSkill * (long) remainingSkill;
            freq[remainingSkill]--; // Reduce the frequency of used skill
        }

        return chemistry / 2;
    }
}