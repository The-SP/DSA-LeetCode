# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray (Easy)
# Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

from typing import *

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        inc_len = dec_len = max_len = 1
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                inc_len += 1
                dec_len = 1
            elif nums[i] < nums[i-1]:
                dec_len += 1
                inc_len = 1
            else:
                inc_len = dec_len = 1
            max_len = max(max_len, inc_len, dec_len)
        return max_len