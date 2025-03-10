# 2570. Merge Two 2D Arrays by Summing Values (Easy)
# Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

from typing import *

class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        nums = []
        m, n = len(nums1), len(nums2)
        i = j = 0
        while i < m and j < n:
            if nums1[i][0] == nums2[j][0]:
                nums.append([nums1[i][0], nums1[i][1]+nums2[j][1]])
                i += 1
                j += 1
            elif nums1[i][0] < nums2[j][0]:
                nums.append(nums1[i])
                i += 1
            else:
                nums.append(nums2[j])
                j += 1
        if i < m:
            nums.extend(nums1[i:])
        if j < n:
            nums.extend(nums2[j:])
        return nums