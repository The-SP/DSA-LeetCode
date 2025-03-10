# 2579. Count Total Number of Colored Cells (Medium)
# Link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

from typing import *

class Solution:
    def coloredCells(self, n: int) -> int:
        count = 0
        for i in range(1, 2*n, 2):
            count += i 
        return 2*count-i