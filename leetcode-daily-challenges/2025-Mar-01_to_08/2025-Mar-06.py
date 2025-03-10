# 2965. Find Missing and Repeated Values
# Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

from typing import *

class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        freq = [0]*(n**2+1)
        for row in grid:
            for num in row:
                freq[num] = freq[num] + 1
                            
        res = [0, 0]
        for i in range(1, n**2+1):
            if freq[i] == 2:
                res[0] = i 
            elif freq[i] == 0:
                res[1] = i
        return res 