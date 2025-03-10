# 2460. Apply Operations to an Array (Easy)
# Link: https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=daily-question&envId=2025-03-01

from typing import *

class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = 0
        while i < n-1:
            if nums[i] == nums[i+1]:
                nums[i] *= 2
                nums[i+1] = 0
                i += 2
            else:
                i += 1
        
        write_idx = 0
        for i in range(n):
            if nums[i] != 0:
                if write_idx != i:
                    nums[write_idx], nums[i] = nums[i], nums[write_idx]
                write_idx += 1

        return nums

        