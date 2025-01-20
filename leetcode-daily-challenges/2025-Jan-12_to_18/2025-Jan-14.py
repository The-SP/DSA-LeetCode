# 2657. Find the Prefix Common Array of Two Arrays
# Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

from typing import *

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        N = len(A)
        set_A = set()
        count = 0
        arr = []
        for i in range(N):
            if A[i] in set_A:
                count += 1
            else:
                set_A.add(A[i])
            if B[i] in set_A:
                count += 1
            else:
                set_A.add(B[i])
            arr.append(count)
        return arr

