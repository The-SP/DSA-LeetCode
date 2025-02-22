# 1980. Find Unique Binary String (Medium)
# Link: https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20

from typing import *


def findDifferentBinaryString(nums: List[str]) -> str:
    nums_set = set(nums)
    n = len(nums[0])
    for i in range(2**n):
        bin_str = bin(i)[2:].zfill(n)
        if bin_str not in nums_set:
            return bin_str


nums = ["00", "01"]
bin_str = findDifferentBinaryString(nums)
print(bin_str)

nums = ["111", "011", "001"]
bin_str = findDifferentBinaryString(nums)
print(bin_str)
