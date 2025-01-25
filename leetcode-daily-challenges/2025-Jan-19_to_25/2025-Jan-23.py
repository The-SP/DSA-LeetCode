# 1267. Count Servers that Communicate
# Medium
# Link: https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

from typing import *


def countServers(grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    row_servers = [0] * m
    col_servers = [0] * n
    # Count the no of servers in each row and column
    for i in range(m):
        for j in range(n):
            if grid[i][j]:
                row_servers[i] += 1
                col_servers[j] += 1

    # count the number of servers that communicate with at least one other server
    count = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] and (row_servers[i] > 1 or col_servers[j] > 1):
                count += 1

    return count


grid = [[1, 0, 0, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 1, 0]]
print(countServers(grid))
