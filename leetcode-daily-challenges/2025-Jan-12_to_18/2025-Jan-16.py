# 2425. Bitwise XOR of All Pairings
# Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

from typing import *

class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        xor = 0
        if len(nums1) % 2:
            xor ^= xor_list(nums2)
        if len(nums2) % 2:
            xor ^= xor_list(nums1)
        return xor 
        
def xor_list(nums):
    xor = 0
    for num in nums:
        xor ^= num
    return xor 