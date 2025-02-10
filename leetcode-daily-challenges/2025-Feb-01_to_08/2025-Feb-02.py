# 1752. Check if Array Is Sorted and Rotated (Easy)
# Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

from typing import *

class Solution:
    def check(self, nums: List[int]) -> bool:
        break_points = 0
        for i in range(len(nums)):
            if nums[i] > nums[(i+1)%len(nums)]:
                break_points += 1
        return break_points < 2
