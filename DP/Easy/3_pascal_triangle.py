# 118. Pascal's Triangle

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[1 for _ in range(i + 1)] for i in range(numRows)]
        for i in range(1, numRows):
            for j in range(1, i):
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        return dp
