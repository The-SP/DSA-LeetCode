# 684. Redundant Connection
# Medium
# Link: https://leetcode.com/problems/redundant-connection/submissions/1524595037/?envType=daily-question&envId=2025-01-29
# Solved Status: Not Solved (Copied Solution)


def findRedundantConnection(edges):
    n = len(edges)
    parent = list(range(n + 1))  # Initialize each node as its own parent

    # Function to find the root of a node using path compression
    def find_parent(x):
        if parent[x] != x:
            parent[x] = find_parent(parent[x])
        return parent[x]

    # Function to union two sets
    def union(x, y):
        root_x = find_parent(x)
        root_y = find_parent(y)
        if root_x == root_y:
            return False
        parent[root_y] = root_x
        return True

    for u, v in edges:
        if not union(u, v):  # If union fails, it means adding this edge creates a cycle
            return [u, v]  # Return the redundant edge
    return []


# edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
edges = [[1, 2], [1, 3], [2, 3]]
result = findRedundantConnection(edges)
print(result)
