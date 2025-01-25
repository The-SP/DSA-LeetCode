# 2661. First Completely Painted Row or Column (Medium)
# Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

from typing import *

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        row_count, col_count = [0] * m, [0] * n
        pos_map = {mat[i][j]: (i, j) for i in range(m) for j in range(n)}
        for k in range(len(arr)):
            i, j = pos_map[arr[k]]
            row_count[i] += 1
            col_count[j] += 1
            if row_count[i] == n or col_count[j] == m:
                return k
