# Python implementation for Kruskal's
# algorithm

import numpy as np

from prettytable import PrettyTable

# Find set of vertex i


def find(i):
    while parent[i] != i and parent[i] != -1:
        i = parent[i]
    return i

# Does union of i and j. It returns
# false if i and j are already in same
# set.


def union(i, j):
    a = find(i)
    b = find(j)
    parent[b] = a

# Finds MST using Kruskal's algorithm


def kruskalMST(cost):
    mincost = 0  # Cost of min MST

    # Include minimum weight edges one by one
    edge_count = 0
    while edge_count < V - 1:
        min = INF
        a = -1
        b = -1
        for i in range(V):
            for j in range(V):
                if find(i) != find(j) and cost[i][j] < min:
                    min = cost[i][j]
                    a = i
                    b = j
        union(a, b)
        print(f'Edge {edge_count}:({alpha[a]}, {alpha[b]}) cost:{min}\\\\')
        outSolution(parent)
        edge_count += 1
        mincost += min

    print("Minimum cost= {}".format(mincost))


def outSolution(input):
    alpha = ["A", "B", "C", "D", "E", "F"]
    t = PrettyTable(alpha)
    t.add_row(input)
    print(t)
    print("\n")


# MAIN
alpha = ["A", "B", "C", "D", "E", "F"]
I = float('inf')
graph = [
    [I, 9, 2, 11, I, 3],
    [9, I, 10, 4, I, I],
    [2, 10, I, 8, 5, 6],
    [11, 4, 8, I, 12, I],
    [I, I, 5, 12, I, 1],
    [3, I, 6, I, 1, I]
]


V = len(graph)

parent = [-1 for i in range(len(graph))]
INF = float('inf')

kruskalMST(graph)


