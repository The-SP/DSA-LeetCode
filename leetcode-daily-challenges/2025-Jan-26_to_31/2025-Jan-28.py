# 2658. Maximum Number of Fish in a Grid
# Medium
# Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28
# Help needed: Yes

from typing import *


class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        max_score = 0
        count = 0

        m, n = len(grid), len(grid[0])
        is_visited = [[False for _ in range(n)] for _ in range(m)]

        def dfs(i, j):
            if i < 0 or i == m or j < 0 or j == n:
                return 0
            if grid[i][j] == 0 or is_visited[i][j]:
                return 0
            is_visited[i][j] = True
            fish_count = grid[i][j]
            fish_count += dfs(i - 1, j)
            fish_count += dfs(i + 1, j)
            fish_count += dfs(i, j - 1)
            fish_count += dfs(i, j + 1)
            return fish_count

        for i in range(m):
            for j in range(n):
                if not is_visited[i][j] and grid[i][j] > 0:
                    count = dfs(i, j)
                    max_score = max(max_score, count)

        return max_score
