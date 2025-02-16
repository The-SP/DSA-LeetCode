# 2364. Count Number of Bad Pairs (Medium)
# Link: https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09
# Solved Status: Not Solved (Copied Solution)

from typing import *

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        diff_dic = {}
        good_pairs = 0
        for i in range(n):
            diff = nums[i]-i
            if diff not in diff_dic:
                diff_dic[diff] = 1
            else:
                good_pairs += diff_dic[diff]
                diff_dic[diff] += 1
        
        total_pairs = n*(n-1)//2
        return total_pairs-good_pairs
