/* -------------------------------------------------------
 * Detailed MST Approach with Full Visuals and Explanations
 * -------------------------------------------------------
 *
 * The following is a complete, line-by-line detailed explanation of the MST construction process, preserving all visual parts exactly as provided.
 *
 * -------------------------------------------------------
 * Graph Definition:
 * -------------------------------------------------------
 *
 * G(V,E)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 * Explanation:
 * - This is our original weighted graph represented as G(V,E).
 * - Vertices: 0, 1, 2, 3, 4, 5, 6.
 * - Edge weights are labeled on each edge.
 *   • For example, the edge between 0 and 3 has a weight of 20.
 *   • The edge between 3 and 4 has a weight of 1.
 *   • Other edge weights: 5 (between 0 and 1), 5 (between 3 and 2), 2 (between 4 and 5), 4 (between 4 and 6), and 2 (between 5 and 6).
 *
 * -------------------------------------------------------
 * Spanning Tree (ST) Visual Example:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |
 *   5 |         | 5     2 |        total = 35 (ST)
 *     |         |         |
 *     1         2         5---6
 *                           2
 *
 * Explanation:
 * - This diagram represents one possible spanning tree (ST) of the given graph.
 * - A spanning tree includes all vertices but only V - 1 edges.
 * - Here, the selected edges form a tree with a total weight of 35.
 * - Notice that some edges have been "dropped" compared to the full graph to avoid cycles.
 *
 * -------------------------------------------------------
 * Minimum Spanning Tree (MST) Visual Example:
 * -------------------------------------------------------
 *
 *                    1
 *     0         3---------4
 *     |         |         |        total = 20 (MST)
 *   5 |         | 5     2 |
 *     |         |         |
 *     1---------2         5---6
 *         5                 2
 *
 * Explanation:
 * - This diagram shows the Minimum Spanning Tree (MST) of the graph.
 * - The MST is a special spanning tree where the sum of the edge weights is minimized.
 * - In this case, the MST has a total weight of 20.
 * - The edge from 3 to 4 with weight 1 is crucial, as well as other low-weight edges chosen.
 *
 * -------------------------------------------------------
 * Intuition:
 * -------------------------------------------------------
 *
 * Intuition
 *
 * Which data structure ?
 * What to put in that data structure ?
 *
 * Explanation:
 * - We now ponder which data structure helps us select the smallest weighted edge efficiently.
 * - The question “Which data structure?” prompts the answer: a min heap.
 * - “What to put in that data structure?” implies we need to store relevant information for each candidate edge (edge weight, node, and parent).
 *
 * -------------------------------------------------------
 * Detailing the Next Steps to Reach a Specific Node:
 * -------------------------------------------------------
 *
 * Ok so now to reach 3
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 * weight, node, parent
 * {20,      3,      0}
 *
 * {5,        3,     2}  will choose this because i want less weight
 *
 * so which data structure is best ???
 *
 * in O(1) time that is min heap
 *
 *     |            |
 *     |            |
 *     | {5, 3, 2}  |
 *     |------------|
 *     | {20, 3, 0} |
 *     |____________|
 *
 * Explanation:
 * - To decide which edge to choose for connecting a new vertex (here reaching vertex 3), we compare candidate edges.
 * - One candidate edge is {20, 3, 0}, meaning an edge from 0 to 3 with weight 20.
 * - Another candidate is {5, 3, 2} coming from vertex 2 with weight 5.
 * - Since 5 is less than 20, the edge with weight 5 is chosen.
 * - A min heap (or priority queue) is the ideal structure since it gives O(1) access to the smallest element.
 *
 * -------------------------------------------------------
 * Using a Visited Array and Parent Array:
 * -------------------------------------------------------
 *
 * Which data structure ? min heap
 * What to put in that data structure ? (wt, node, parent)
 *
 * The goal of MST was to find the edge with minimum weight
 * now once we used like to visit 3 from 2 there is a edge 5
 * so sum = 5
 * and mark 3 as visited
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {20, 3, 0} |
 * |____________|
 *
 * so now if 20 comes we see oh 3 is there i don't need you because i have less weight 5 for node 3
 *
 * hence from here we got to know we need visited array
 *
 * Explanation:
 * - When building the MST, once an edge is chosen, its corresponding node is marked as visited.
 * - This prevents reprocessing a vertex that already belongs to the MST.
 * - The parent array keeps track of which vertex provided the minimum connection for each node.
 * - In the min heap, if an edge with a higher weight for an already visited node appears, it is ignored.
 *
 * -------------------------------------------------------
 * Initializing Data Structures:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *         |            |
 *         |            |
 *         |            |
 *         |            |
 *         |            |
 *         |____________|
 *           min_heap
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  F  |  F  |  F  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *      Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  | -1  | -1  | -1  | -1  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - The min heap is initially empty.
 * - The visited array is set to all False (F), meaning no vertex has been added to the MST.
 * - The parent array is initialized to -1, indicating no parent for any vertex initially.
 *
 * -------------------------------------------------------
 * Starting the MST Construction from Vertex 0:
 * -------------------------------------------------------
 *
 * Now lets start with 0
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {0, 0, -1} |
 * |____________|           (min_heap)
 *
 * now pop it {0, 0, -1}
 *
 * |            |
 * |            |
 * |            |
 * |            |
 * |            |
 * |____________|           (min_heap)
 *
 * pop = {0, 0, -1}
 * wt = 0
 * node = 0
 * parent = -1
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  F  |  F  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *      sum = 0
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  | -1  | -1  | -1  | -1  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - We start by inserting the source vertex 0 into the min heap with an edge weight of 0.
 * - We pop {0, 0, -1} from the heap, meaning we now process vertex 0.
 * - Vertex 0 is marked as visited.
 * - The current sum of the MST is 0.
 * - The parent of vertex 0 remains -1 because it is the starting point.
 *
 * -------------------------------------------------------
 * Expanding MST from Vertex 0:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 0, I can go to 3, 1
 * -----------------------------------------------------
 * |            |
 * |            |
 * | {5, 1, 0}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {5, 1, 0}
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     pop = {5, 1, 0}
 *     wt =  5
 *     node = 1
 *     parent = 0
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  F  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  | -1  | -1  | -1  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 0, we can expand the MST to its neighbors: vertices 1 and 3.
 * - We insert the edge {5, 1, 0} (from 0 to 1, weight 5) and {20, 3, 0} (from 0 to 3, weight 20) into the min heap.
 * - The min heap now prioritizes the smallest weight edge.
 * - We pop {5, 1, 0} since 5 is less than 20.
 * - Vertex 1 is now visited, and we add 5 to the running sum.
 * - Update the parent of vertex 1 to 0.
 *
 * -------------------------------------------------------
 * Processing from Vertex 1:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 1, I can go to 0, 2
 *     now check visited array
 *
 *          Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  F  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     so 0 is already visited, but 2 is not visited
 *
 *     let's visit 2
 * --------------------------------------------------------
 * |            |
 * |            |
 * | {5, 2, 1}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {5, 2, 1}
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *     pop = {5, 2, 1}
 *     wt =  5
 *     node = 2
 *     parent = 1
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5 + 5
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  |  1  | -1  | -1  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 1, the only unvisited neighbor is vertex 2.
 * - We add the candidate edge {5, 2, 1} into the min heap.
 * - We then pop this edge and process vertex 2.
 * - Mark vertex 2 as visited, add its weight (5) to the sum (now 10), and update its parent to 1.
 *
 * -------------------------------------------------------
 * Processing from Vertex 2:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 2, I can go to 1, 3
 *     now check visited array
 *
 *              Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  F  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     so 1 is already visited, but 3 is not visited
 *
 *     let's visit 3
 * -----------------------------------------------
 * |            |
 * |            |
 * | {5, 3, 2}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {5, 3, 2}
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *     pop = {5, 3, 2}
 *     wt =  5
 *     node = 3
 *     parent = 2
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5 + 5 + 5
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  |  1  |  2  | -1  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 2, among its neighbors, vertex 3 is unvisited.
 * - The candidate edge {5, 3, 2} is added to the min heap.
 * - When we pop it, we process vertex 3, mark it as visited, add 5 to the sum, and update its parent to 2.
 * - Current running sum becomes 15.
 *
 * -------------------------------------------------------
 * Processing from Vertex 3:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 3, I can go to 0, 2, 4
 *     now check visited array
 *
 *              Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  F  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     so 0, 2 are already visited, but 4 is not visited
 *
 *     let's visit 4
 * -------------------------------------------------------------------
 * |            |
 * |            |
 * | {1, 4, 3}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {1, 4, 3}
 *
 * |            |
 * |            |
 * |            |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *     pop = {1, 4, 3}
 *     wt =  1
 *     node = 4
 *     parent = 3
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5 + 5 + 5 + 1
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  |  1  |  2  |  3  | -1  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 3, only vertex 4 is unvisited.
 * - We insert the candidate edge {1, 4, 3} with weight 1.
 * - It is popped, vertex 4 becomes visited, the weight 1 is added to the total sum (becoming 16), and parent of 4 is set to 3.
 *
 * -------------------------------------------------------
 * Processing from Vertex 4:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 4, I can go to 3, 5, 6
 *     now check visited array
 *
 *          Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  F  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     so 3 is already visited, but 5, 6 are not visited
 *
 *     let's visit 5, 6
 * ----------------------------------------------------------------
 *
 * |            |
 * | {2, 5, 4}  |
 * |------------|
 * | {4, 6, 4}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {2, 5, 4}
 *
 * |            |
 * |            |
 * |------------|
 * | {4, 6, 4}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *     pop = {2, 5, 4}
 *     wt =  2
 *     node = 5
 *     parent = 4
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  T  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5 + 5 + 5 + 1 + 2
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  |  1  |  2  |  3  |  4  | -1  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 4, we can go to vertices 5 and 6.
 * - We insert {2, 5, 4} (edge from 4 to 5, weight 2) and {4, 6, 4} (edge from 4 to 6, weight 4) into the min heap.
 * - The smaller edge {2, 5, 4} is chosen next.
 * - After processing, vertex 5 becomes visited, and the sum updates accordingly.
 *
 * -------------------------------------------------------
 * Processing from Vertex 5:
 * -------------------------------------------------------
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *
 *     now from 5, I can go to 4, 6
 *     now check visited array
 *
 *           Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  T  |  F  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     so 4 is already visited, but 6 is not visited
 *
 *     let's visit 6
 * ----------------------------------------------------------
 * |            |
 * | {2, 6, 5}  |
 * |------------|
 * | {4, 6, 4}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 * Now pop it {2, 6, 5}
 *
 * |            |
 * |            |
 * |------------|
 * | {4, 6, 4}  |
 * |------------|
 * | {20, 3, 0} |
 * |____________|         (min_heap)
 *
 *         20         1
 *     0---------3---------4
 *     |         |         |\
 *   5 |         | 5     2 | \  4
 *     |         |         |  \
 *     1---------2         5---6
 *         5                 2
 *     pop = {2, 6, 5}
 *     wt =  2
 *     node = 6
 *     parent = 5
 *
 *      Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  T  |  T  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     sum = 0 + 5 + 5 + 5 + 1 + 2 + 2
 *
 *         Parent Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     | -1  |  0  |  1  |  2  |  3  |  4  |  5  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 * Explanation:
 * - From vertex 5, the only unvisited adjacent vertex is 6.
 * - The candidate edge {2, 6, 5} is chosen, processing vertex 6.
 * - After processing, vertex 6 is marked as visited, and the total sum of the MST becomes 20.
 *
 * -------------------------------------------------------
 * Final Check:
 * -------------------------------------------------------
 *
 *     now from 6, I can go to 5, 4
 *     now check visited array
 *
 *          Visited Array
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  0  |  1  |  2  |  3  |  4  |  5  |  6  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *     |  T  |  T  |  T  |  T  |  T  |  T  |  T  |
 *     +-----+-----+-----+-----+-----+-----+-----+
 *
 *     here 5 and 4 are already visited
 *
 *     check priority queue
 *     |            |
 *     |            |
 *     |------------|
 *     | {4, 6, 4}  |
 *     |------------|
 *     | {20, 3, 0} |
 *     |____________|         (min_heap)
 *
 *     empty this as node 6, 3 are already visited
 *     |            |
 *     |            |
 *     |            |
 *     |            |
 *     |------------|
 *     | {20, 3, 0} |
 *     |____________|         (min_heap)
 *
 *     |            |
 *     |            |
 *     |            |
 *     |            |
 *     |            |
 *     |            |
 *     |____________|         (min_heap)
 *
 *     now check sum
 *
 *     sum = 0 + 5 + 5 + 5 + 1 + 2 + 2
 *     sum = 20 (Answer)
 *
 * -------------------------------------------------------
 * Visual of the Final MST:
 * -------------------------------------------------------
 *
 *                   1
 *     0         3---------4
 *     |         |         |        total = 20 (MST)
 *   5 |         | 5     2 |
 *     |         |         |
 *     1---------2         5---6
 *         5                 2
 *
 * This visual represents the MST where the selected edges yield the minimum total weight of 20.
 *
 * -------------------------------------------------------
 * Overall Explanation Recap:
 * -------------------------------------------------------
 * - We began with the full weighted graph G(V,E) with all vertices and edge weights.
 * - A spanning tree (ST) contains all vertices with V - 1 edges; multiple STs exist.
 * - The Minimum Spanning Tree (MST) is the ST with the smallest total edge weight.
 * - To construct the MST (using Prim’s algorithm), we use:
 *     • A min heap (priority queue) to always select the edge with the smallest weight.
 *     • A visited array to mark which vertices have been added to the MST.
 *     • A parent array to remember the MST's tree structure.
 * - The detailed simulation shows adding edges one by one,
 *   updating the min heap, the visited array, the parent array, and accumulating the total MST weight.
 * - The final total weight of the MST is 20.
 *
 */

/*
 * GfG link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
 *
 * Minimum Spanning Tree
 *
 * Difficulty: Medium Accuracy: 47.82% Submissions: 158K+ Points: 4 Average Time: 25m
 *
 * Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
 *
 * Input:
 * 3 3
 * 0 1 5
 * 1 2 3
 * 0 2 1
 * Output: 4
 * Explanation:
 * The Spanning Tree resulting in a weight
 * of 4 is shown above.
 *
 * Input:
 * 2 1
 * 0 1 5
 * Output: 5
 * Explanation: Only one Spanning Tree is possible which has a weight of 5.
 *
 * Constraints:
 * 2 ≤ V ≤ 1000
 * V-1 ≤ E ≤ (V*(V-1))/2
 * 1 ≤ w ≤ 1000
 * The graph is connected and doesn't contain self-loops & multiple edges.
 */

// Approach: We use Prim's algorithm with a min heap (priority queue) to repeatedly add the minimum weighted edge that connects a new vertex to the growing MST.
// Time Complexity: O(E log E) as each edge is inserted and processed in the priority queue.
// Space Complexity: O(V + E) for storing the graph, the visited array, and the priority queue.
class Solution {
    typedef pair<int, int> P; // Pair of {edge weight, node}

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to store the next edge candidate as {wt, node} in ascending order of weight.
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from vertex 0 with weight 0.
        pq.push({ 0, 0 });

        // Vector to track which vertex has already been included in the MST.
        vector<bool> inMST(V, false);
        int          sum = 0; // To store the sum of weights in the MST.

        // E
        // Process the priority queue until it's empty.
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();            // Remove the edge with the smallest weight.  // logE

            int wt   = p.first;  // The weight of the current edge.
            int node = p.second; // The current node to be included.

            // If the node is already in the MST, skip it.
            if (inMST[node]) {
                continue;
            }

            // Mark the node as included in the MST and add the weight.
            inMST[node] = true;
            sum        += wt;

            // Traverse the adjacency list for the current node.
            for (auto& tmp : adj[node]) {
                int neighbor    = tmp[0];    // Adjacent vertex.
                int neighbor_wt = tmp[1];    // Weight of the edge to the neighbor.

                // If the neighbor is not yet in the MST, push it into the priority queue.
                if (!inMST[neighbor]) {
                    pq.push({ neighbor_wt, neighbor }); // logE
                }
            }
        }
        // Return the total sum of weights in the Minimum Spanning Tree.
        return sum;
    }
};
