# 1726. Tuple with Same Product (Medium)
# Link: https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06

from typing import *

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        freq = {}
        combinations = 0
        for i in range(n-1):
            for j in range(i+1, n):
                product = nums[i]*nums[j]
                combinations += freq.get(product, 0)
                freq[product] = freq.get(product, 0) + 1
        return combinations*8