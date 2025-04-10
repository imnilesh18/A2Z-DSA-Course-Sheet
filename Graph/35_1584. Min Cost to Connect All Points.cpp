/*
 * 1584. Min Cost to Connect All Points
 *
 * Medium
 *
 * You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
 * The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
 *
 * Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
 *
 * Example 1:
 * Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output: 20
 * Explanation:
 * We can connect the points as shown above to get the minimum cost of 20.
 * Notice that there is a unique path between every pair of points.
 *
 * Example 2:
 * Input: points = [[3,12],[-2,5],[-4,1]]
 * Output: 18
 *
 * Constraints:
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * All pairs (xi, yi) are distinct.
 */

// Approach: Use Prim's algorithm to compute the Minimum Spanning Tree (MST) over points
// by first creating a complete graph based on Manhattan distances.
// Time Complexity: O(V^2 log V) due to complete graph generation and MST extraction using a priority queue, where V is the number of points.
// Space Complexity: O(V^2) for the complete graph storage and O(V) for auxiliary data structures.
class Solution {
public:
    typedef pair<int, int> P;     // P holds {edge_weight, node_index}

    // Prim's algorithm on a graph represented by an adjacency list
    int PrimsAlgo(vector<vector<P>>& adj, int V) {
        // Min-heap (priority queue) to choose edge with the smallest weight
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from point 0 with weight 0
        pq.push({ 0, 0 });

        vector<bool> inMST(V, false);     // Tracks if a point is already included in MST
        int          sum = 0;             // Sum of weights in the MST

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();            // Get edge with minimum weight

            int wt   = p.first;  // Weight of the edge
            int node = p.second; // Current point index

            if (inMST[node]) {
                continue;            // Skip if point already included
            }
            inMST[node] = true;      // Mark point as included
            sum        += wt;        // Add weight to total MST cost

            // Traverse neighbors of the current point
            for (auto& tmp : adj[node]) {
                int neighbor    = tmp.first;       // Adjacent point
                int neighbor_wt = tmp.second;      // Distance to adjacent point

                if (!inMST[neighbor]) {
                    pq.push({ neighbor_wt, neighbor });   // Add to min-heap
                }
            }
        }

        return sum;     // Total cost to connect all points
    }
    // Main function to calculate the minimum cost to connect all points
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();     // Number of points

        // Create adjacency list for complete graph where each point is a vertex
        vector<vector<P>> adj(V);

        // Build complete graph with Manhattan distances between every pair of points
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Compute Manhattan distance
                int d = abs(x1 - x2) + abs(y1 - y2);

                // Add undirected (bidirectional) edges between points i and j
                adj[i].push_back({ j, d });
                adj[j].push_back({ i, d });
            }
        }

        // Run Prim's algorithm to find MST and return the total minimum cost
        return PrimsAlgo(adj, V);
    }
};

/*
 *
 * Dry Run
 *
 * Example: points = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
 *
 * Step 1: Graph Construction (Complete Graph via Manhattan Distance)
 *  - Number of points, V = 5.
 *
 *  Compute distances between each pair:
 *     Between point 0: (0,7) and point 1: (0,9) → d = |0-0| + |7-9| = 2
 *     Between point 0: (0,7) and point 2: (20,7) → d = 20
 *     Between point 0: (0,7) and point 3: (30,7) → d = 30
 *     Between point 0: (0,7) and point 4: (40,70) → d = 103
 *     Between point 1: (0,9) and point 2: (20,7) → d = 22
 *     Between point 1: (0,9) and point 3: (30,7) → d = 32
 *     Between point 1: (0,9) and point 4: (40,70) → d = 101
 *     Between point 2: (20,7) and point 3: (30,7) → d = 10
 *     Between point 2: (20,7) and point 4: (40,70) → d = 83
 *     Between point 3: (30,7) and point 4: (40,70) → d = 73
 *
 * Step 2: Running Prim's Algorithm to Find MST
 *
 *  Initialization:
 *     - Start with vertex 0.
 *     - Min Heap initially: { {0, 0} }
 *     - Visited array: [F, F, F, F, F]
 *     - Sum = 0
 *
 *  Iteration 1:
 *     - Pop {0, 0}, visit point 0, add 0 → sum = 0
 *     - Push neighbors of point 0: {2,1}, {20,2}, {30,3}, {103,4}
 *
 *  Iteration 2:
 *     - Pop {2,1}, visit point 1, add 2 → sum = 2
 *     - Push {22,2}, {32,3}, {101,4}
 *
 *  Iteration 3:
 *     - Pop {20,2}, visit point 2, add 20 → sum = 22
 *     - Push {10,3}, {83,4}
 *
 *  Iteration 4:
 *     - Pop {10,3}, visit point 3, add 10 → sum = 32
 *     - Push {73,4}
 *
 *  Iteration 5:
 *     - Pop {73,4}, visit point 4, add 73 → sum = 105
 *     - All visited.
 *
 * Final MST Cost: 105
 */
