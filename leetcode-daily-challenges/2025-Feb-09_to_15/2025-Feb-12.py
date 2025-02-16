# 2342. Max Sum of a Pair With Equal Sum of Digits (Medium)
# Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12

from typing import *

def maximumSum(nums):
    nums_sum = {}

    for num in nums:
        digit_sum = sum(int(digit) for digit in str(num))

        if digit_sum not in nums_sum:
            nums_sum[digit_sum] = [num]
        else:
            nums_sum[digit_sum].append(num)
            if len(nums_sum[digit_sum]) > 2:
                nums_sum[digit_sum].remove(min(nums_sum[digit_sum]))

    max_sum = -1
    for values in nums_sum.values():
        if len(values) == 2:
            max_sum = max(max_sum, sum(values))

    return max_sum

nums = [18,43,36,13,7]
print(maximumSum(nums)) # 54