# 1462. Course Schedule IV
# Link: https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27
# Help needed: Yes

from typing import *


def checkIfPrerequisite(
    numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]
) -> List[bool]:
    # Build the graph containing direct prerequisite
    graph = {i: [] for i in range(numCourses)}
    for i, j in prerequisites:
        graph[j].append(i)

    # Build graph containing both direct and indirect prerequisite
    for course in graph.keys():
        graph[course] = find_all_prerequisites(graph, course)

    result = []
    for u, v in queries:
        result.append(u in graph[v])
    return result


def find_all_prerequisites(graph, course):
    children = set()

    def dfs(node):
        for child in graph[node]:
            if child not in children:
                children.add(child)
                dfs(child)

    dfs(course)
    return children


numCourses = 3
prerequisites = [[1, 2], [1, 0], [2, 0]]
queries = [[1, 0], [1, 2]]

result = checkIfPrerequisite(numCourses, prerequisites, queries)
print(result)
