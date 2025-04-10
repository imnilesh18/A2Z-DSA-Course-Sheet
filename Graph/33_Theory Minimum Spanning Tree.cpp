----------------------------------------------
Minimum Spanning Tree | Easy Theory Full Detail
----------------------------------------------

1. Graph Basics:
----------------
A graph is denoted by G(V, E) where:
  - V is the set of vertices (nodes).
  - E is the set of edges (connections between nodes).

For example, consider the graph:

         a ------- b
         |         |
         |         |
         c ------- d

Here:
  - V = 4 (vertices: a, b, c, d)
  - E = 4 (edges: a-b, a-c, c-d, b-d)

----------------------------------------------
2. Spanning Tree:
-----------------
A spanning tree of a graph is a subgraph that:
  - Contains all the vertices of the original graph.
  - Has exactly V - 1 edges.
  - Contains no cycles (i.e., it is a tree).

Since our example graph has V = 4, any spanning tree must have:
  - E = V - 1 = 4 - 1 = 3 edges.

Some possible spanning trees for our graph are:

Example A:
         a ------- b
         |         
         |         
         c ------- d
         
Example C:
         a         b
         |         |
         |         |
         c ------- d

Example C:
         a ------- b
                   |
                   |
         c ------- d

Example D:
         a ------- b
         |         |
         |         |
         c         d
         
Example E:
         a         
         |         
         |         
         c ------- d
         |
         |
         b

Note:
  - The structure of a spanning tree can vary, but every spanning tree for a graph with 4 vertices must have exactly 3 edges and be acyclic.

----------------------------------------------
3. Minimum Spanning Tree (MST):
----------------------------------------------
A Minimum Spanning Tree (MST) is a special type of spanning tree where:
  - The sum of the weights of the edges included in the tree is the smallest possible compared to any other spanning tree of the graph.
  - It is also referred to as the Minimum Weight Spanning Tree.

Consider the same graph with weights on the edges:

             5
        a ------- b    
     2  |         |  3     
        |         |
        c---------d  
              8

Here, the graph has:
  - Edge a-b with weight 5.
  - Edge a-c with weight 2.
  - Edge b-d with weight 3.
  - Edge c-d with weight 8.

Let’s visualize some possible spanning trees (ST) along with their total weights:

Spanning Tree Example 1:

        a         b    
     2  |         |  3    Total Weight = 2 (a-c) + 3 (b-d) + 8 (c-d) = 13
        |         |
        c ------- d  
             8

Spanning Tree Example 2:
             5
        a ------- b    
     2  |                 Total Weight = 5 (a-b) + 2 (a-c) + 8 (c-d) = 15 
        |         
        c ------- d  
             8

Spanning Tree Example 3 (Minimum Spanning Tree):
             5
        a ------- b    
     2  |         |  3    Total Weight = 5 (a-b) + 2 (a-c) + 3 (b-d) = 10 
        |         |
        c         d  

Spanning Tree Example 4:
             5
        a -------- b    
                   |  3    Total Weight = 5 (a-b) + 8 (c-d) + 3 (b-d) = 16
                   |
        c -------- d 
             8


Explanation:
  - Out of these, the spanning tree with total weight = 10 is the Minimum Spanning Tree because the edge weight sum is the lowest.
  - Thus, the MST is the one where selecting the set of edges gives the minimum possible total weight.

----------------------------------------------
4. Important Properties:
----------------------------------------------
- **Spanning Tree**: Must include every vertex and have exactly V - 1 edges.
- **No Cycles**: Since a tree is an acyclic connected graph.
- **MST (Minimum Spanning Tree)**: 
    - It is a spanning tree with an additional condition: the sum of the weights of the edges is minimized.
    - In our example, although several spanning trees may connect the vertices, the one with total weight 10 is chosen as the MST because it minimizes the overall cost of connecting the graph.
  
----------------------------------------------
5. Algorithms to Find MST:
----------------------------------------------
There are two well-known algorithms to find the MST:
  - **Kruskal's Algorithm**: 
      - Sorts all edges based on weight and includes the smallest edge that does not form a cycle.
  - **Prim's Algorithm**:
      - Starts with a single vertex and repeatedly adds the smallest edge from the tree being built to a new vertex.

----------------------------------------------
Summary:
----------------------------------------------
- A Spanning Tree connects all vertices with no cycles and exactly V - 1 edges.
- The Minimum Spanning Tree (MST) is the Spanning Tree with the smallest total edge weight.
- In our example, even though multiple spanning trees exist, the MST has a weight sum of 10, making it the optimal selection.
- Algorithms like Kruskal's and Prim's can efficiently compute the MST for a given weighted graph.
