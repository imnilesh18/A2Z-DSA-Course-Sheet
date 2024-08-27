import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        // Example usage
        int[][] prerequisites = {{1, 0}, {2, 1}, {3, 2}}; // Example prerequisites
        Map<Integer, List<Integer>> adj = new HashMap<>();
        
        for (int[] vec : prerequisites) {
            int v = vec[1]; // prerequisite course
            int u = vec[0]; // course to take
            adj.putIfAbsent(v, new ArrayList<>());
            adj.get(v).add(u); // v -> u
        }

        // Assuming solve() is a function that takes the adjacency list and processes it
        // Here, you should implement or call the solve function
        solve(adj);
    }

    public static void solve(Map<Integer, List<Integer>> adj) {
        // Implementation for solving the problem based on the adjacency list
        // For example, you can check for cycles, find the order of courses, etc.
        // This is just a placeholder for the actual logic
        System.out.println("Adjacency list: " + adj);
    }
}
