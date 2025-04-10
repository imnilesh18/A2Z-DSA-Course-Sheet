/*
 * Dijkstra 's Algorithm
 *
 * input:
 *              0
 *             /  \
 *          1 /    \  6
 *           /      \
 *          1--------2   source
 *              3
 *
 * Explanation:
 * - This is the graph on which we run Dijkstra's algorithm.
 *-The nodes are labeled 0, 1, and 2. The source node is marked as "source".
 *-The edge weights are given on the edges.
 *
 * output: { 4, 3, 0 }
 *
 * Explanation:
 *-Dijkstra 's Algorithm gives the minimum distance from the source node to all the other nodes.
 * - For node 2, the resulting minimum distances to nodes 0, 1, and 3 are {4, 3, 0}.
 *
 * For node 2 to:  0, 1, 3
 *                {4, 3, 0}
 *
 * (Reiterated diagram for clarity)
 *
 *              0
 *             /  \
 *          1 /    \  6
 *           /      \
 *          1--------2   source
 *              3
 *
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * Explanation:
 * - The above adjacency list represents the graph:
 *   • For node 2, the neighbors are node 0 with edge weight 6 and node 1 with edge weight 3.
 *   • For node 1, the neighbors are node 2 with edge weight 3 and node 0 with edge weight 1.
 *   • For node 0, the neighbors are node 1 with edge weight 1 and node 2 with edge weight 6.
 *
 * For node 2 to:  0, 1, 3
 *                {4, 3, 0}
 *
 * Explanation:
 * - This line reiterates that from the source (node 2 in this case) the computed minimum distances
 *   are 4, 3, and 0, respectively.
 *
 * _______________________________________________________
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 *    adj:
 *    2 -> {0, 6}, {1, 3}
 *    1 -> {2, 3}, {0, 1}
 *    0 -> {1, 1}, {2, 6}
 *
 * Explanation:
 * - The graph is depicted again along with its adjacency list.
 *
 *  Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  ∞  |  ∞  |  ∞  |
 *  +-----+-----+-----+
 *
 * Explanation:
 * - Initially, the distance (result) array is set to infinity (∞) for all nodes, meaning the minimum
 *   distance from the source to each node is unknown and assumed infinitely large.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - The min heap (or priority queue) is shown here as empty at the beginning.
 *
 * Now, we know result[source] = 0.
 * So,
 *
 *  Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  ∞  |  ∞  |  0  |
 *  +-----+-----+-----+
 *
 * Explanation:
 * - We update the distance for the source node (node 2) to 0.
 *
 * So, push {0, 2}.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |------------|         {0, 2} -> {distance, node}
 *    |   {0, 2}   |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - We push the tuple {0, 2} into the min heap, meaning node 2 has a current distance of 0.
 *
 * ----------------------------------------------
 * Now, pop it {0, 2}.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - We now pop the smallest element from the min heap, which is {0, 2}.
 *
 * Pop = {0, 2}
 * dist = 0
 * node = 2
 *
 * Explanation:
 * - The popped element indicates that the distance to node 2 is 0.
 *
 * Now check from 2 where we can go.
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * Explanation:
 * - For node 2, based on the adjacency list, its neighbors are:
 *   • Node 0 with weight 6.
 *   • Node 1 with weight 3.
 *
 * Neighbor = 0
 * dist = 6
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * So,
 * - From node 2 to itself is 0.
 * - Then from node 2 to node 0, the total distance would be 0 + 6 = 6.
 *
 * It is better than ∞, so update the result array for node 0 to 6,
 * and push it into the min heap {6, 0}.
 *
 *  Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  6  |  ∞  |  0  |
 *  +-----+-----+-----+
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - The result array is updated with a distance of 6 for node 0.
 * - We push {6, 0} into the min heap as a candidate path.
 *
 * (Note: At this point, we again observe the popped element {0, 2} with dist = 0, node = 2.)
 *
 * Pop = {0, 2}
 * dist = 0
 * node = 2
 *
 * Now check from 2 for other neighbors.
 *    adj:
 *    2 -> {0, 6}, {1, 3}
 *    1 -> {2, 3}, {0, 1}
 *    0 -> {1, 1}, {2, 6}
 *
 * From 2, neighbor = 1 with dist = 3.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * So,
 * - From node 2 to itself is 0.
 * - Then from node 2 to node 1, the total distance is 0 + 3 = 3.
 *
 * It is better than ∞, so update the result array for node 1 to 3,
 * and push it into the min heap {3, 1}.
 *
 *  Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  6  |  3  |  0  |
 *  +-----+-----+-----+
 *
 *    |            |
 *    |            |
 *    |------------|
 *    |   {3, 1}   |         {3, 1} -> {distance, node}
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - The result array now has updated distances: node 0 → 6, node 1 → 3, node 2 → 0.
 * - The min heap now contains {3, 1} and {6, 0}.
 *
 * Again, checking the adjacencies from node 2, we have explored all its neighbors.
 *    adj:
 *    2 -> {0, 6}, {1, 3}
 *    1 -> {2, 3}, {0, 1}
 *    0 -> {1, 1}, {2, 6}
 *
 * --------------------------------------------------------
 *
 * Now, pop the next element {3, 1} from the min heap.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * Pop = {3, 1}
 * dist = 3
 * node = 1
 *
 * Now check from node 1 where we can go.
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * Explanation:
 * - For node 1, its neighbors are node 2 with weight 3 and node 0 with weight 1.
 *
 * For neighbor = 2, dist = 3.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * So,
 * - From node 2 to node 1 the distance is 3.
 * - Then from node 1 to node 2 the total would be 3 + 3 = 6.
 *
 * It is not better than the current best for node 2 (which is 0), so do not update.
 *
 * Result Array remains:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  6  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * And min heap still contains {6, 0}.
 *
 * Now, from node 1 check the other neighbor.
 *
 * Pop = {3, 1}
 * dist = 3
 * node = 1
 *
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * For neighbor = 0, dist = 1.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * So,
 * - From node 2 to node 1 is 3.
 * - Then from node 1 to node 0 is 3 + 1 = 4.
 *
 * It is better than the current best for node 0 (6), so update the result array for node 0 to 4.
 * And push {4, 0} into the min heap.
 *
 *  Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 *    |            |
 *    |            |
 *    |------------|
 *    |   {4, 0}   |         {4, 0} -> {distance, node}
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * Explanation:
 * - The result array is now updated with node 0 having distance 4.
 * - The min heap now has both {4, 0} and the older {6, 0}; when {6, 0} is later popped, it will be ignored if node 0 is already settled.
 *
 * Again, checking adjacencies from node 1, we have explored all its neighbors.
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * --------------------------------------------------------
 *
 * Now, pop the next element {4, 0} from the min heap.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * Pop = {4, 0}
 * dist = 4
 * node = 0
 *
 * Now check from node 0 where we can go.
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * For neighbor = 1, dist = 1.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * So,
 * - From node 2 to node 0 we have 4,
 * - Then from node 0 to node 1 is 4 + 1 = 5.
 *
 * It is not better than the current best for node 1 (3), so do not update.
 *
 * Result Array remains:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * Pop = {4, 0}
 * dist = 4
 * node = 0
 *
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * Also check neighbor = 2, dist = 6.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * Total from node 0: 4 + 6 = 10, not better than the current best for node 2 (0).
 *
 * Result Array remains unchanged.
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * The min heap still holds {6, 0} from earlier.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |------------|         {6, 0} -> {distance, node}
 *    |   {6, 0}   |
 *    |____________|
 *      min_heap
 *
 * -------------------------------------------------
 *
 * Now, pop {6, 0} from the min heap.
 *
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |____________|
 *      min_heap
 *
 * Pop = {6, 0}
 * dist = 6
 * node = 0
 *
 * Check from node 0:
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 * For neighbor = 1, dist = 1.
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * Total from node 0: 6 + 1 = 7, not better than current best for node 1 (3).
 *
 * So, do not update.
 *
 * Result Array remains:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * Pop = {6, 0}
 * dist = 6
 * node = 0
 *
 * Also, check neighbor = 2, dist = 6.
 * adj:
 * 2 -> {0, 6}, {1, 3}
 * 1 -> {2, 3}, {0, 1}
 * 0 -> {1, 1}, {2, 6}
 *
 *                0
 *               /  \
 *            1 /    \  6
 *             /      \
 *            1--------2   source
 *                3
 *
 * Total: 6 + 6 = 12, not better than current best for node 2 (0).
 *
 * Result Array remains unchanged.
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * The min heap is now empty.
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |            |
 *    |____________|
 *      min_heap
 *
 * ----------------------------------------------------
 *
 * Final Result Array:
 *  +-----+-----+-----+
 *  |  0  |  1  |  2  |
 *  +-----+-----+-----+
 *  |  4  |  3  |  0  |
 *  +-----+-----+-----+
 *
 * Hence, this is the final answer.
 *
 * Explanation:
 * - The priority queue (min heap) ensures that at each step we get the node with the smallest temporary distance.
 * - We update the result array (which holds the minimum distances from the source) only if a shorter path is found.
 * - In this example, the final minimum distances from the source (node 2) to nodes 0, 1, 3 are {4, 3, 0} respectively.
 *
 * Why use a priority queue?
 * - The priority queue (min heap) gives the shortest path at the top.
 * - This allows us to always process the node with the current smallest known distance,
 *   ensuring an efficient and optimal solution as outlined by Dijkstra's algorithm.
 */
