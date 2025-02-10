# 3151. Special Array I (Easy)
# Link: https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01

from typing import *


class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        prev = nums[0] % 2
        for num in nums[1:]:
            curr = num % 2
            if prev == curr:
                return False
            prev = curr
        return True
