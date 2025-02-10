# 1800. Maximum Ascending Subarray Sum (Easy)
# Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

from typing import *

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        curr = max_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                curr += nums[i]
                max_sum = max(max_sum, curr)
            else:
                curr = nums[i]
        return max_sum

        