# 2161. Partition Array According to Given Pivot (Medium)
# Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

from typing import *

class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        left, mid, right = [], [], []
        for num in nums:
            if num < pivot:
                left.append(num)
            elif num > pivot:
                right.append(num)
            else:
                mid.append(num)
        return left + mid + right   