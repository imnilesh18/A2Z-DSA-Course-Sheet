/*
 * 1514. Path with Maximum Probability
 * 
 * You are given an undirected weighted graph of n nodes (0-indexed),
 * represented by an edge list where edges[i] = [a, b] is an undirected edge
 * connecting the nodes a and b with a probability of success of traversing that
 * edge succProb[i].
 * 
 * Given two nodes start and end, find the path with the maximum probability of
 * success to go from start to end and return its success probability.
 * 
 * If there is no path from start to end, return 0. Your answer will be accepted
 * if it differs from the correct answer by at most 1e-5.
 * 
 * Example 1:
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
 * 0, end = 2
 * Output: 0.25000
 * Explanation: There are two paths from start to end, one having a probability
 * of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
 * 
 * Example 2:
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
 * 0, end = 2
 * Output: 0.30000
 * 
 * Example 3:
 * Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * Output: 0.00000
 * Explanation: There is no path between 0 and 2.
 * 
 * Constraints:
 * 
 * 2 <= n <= 10^4
 * 0 <= start, end < n
 * start != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * There is at most one edge between every two nodes.
 */

//Using Dijkstra's Algorithm
//T.C : O(E*log(V))
//S.C : O(V + E)
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        // Build the graph
        Map<Integer, List<Pair<Integer, Double>>> graph = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph.computeIfAbsent(u, k -> new ArrayList<>()).add(new Pair<>(v, pathProb));
            graph.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair<>(u, pathProb));
        }

        // Array to store the maximum probability to reach each node
        double[] maxProb = new double[n];
        maxProb[start] = 1d;

        // Max-heap priority queue to explore the highest probability first
        PriorityQueue<Pair<Double, Integer>> pq = new PriorityQueue<>(
                (a, b) -> -Double.compare(a.getKey(), b.getKey()));
        pq.add(new Pair<>(1.0, start));

        while (!pq.isEmpty()) {
            Pair<Double, Integer> cur = pq.poll();
            double curProb = cur.getKey();
            int curNode = cur.getValue();

            // If the current node is the end node, return the probability
            if (curNode == end) {
                return curProb;
            }

            // Explore the neighbors
            for (Pair<Integer, Double> nxt : graph.getOrDefault(curNode, new ArrayList<>())) {
                int nxtNode = nxt.getKey();
                double pathProb = nxt.getValue();

                // Update the probability if a higher one is found
                if (curProb * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = curProb * pathProb;
                    pq.add(new Pair<>(maxProb[nxtNode], nxtNode));
                }
            }
        }

        // If the end node is not reachable, return 0
        return 0d;
    }
}