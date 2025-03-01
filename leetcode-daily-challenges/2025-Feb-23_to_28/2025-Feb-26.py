# 1749. Maximum Absolute Sum of Any Subarray (Medium)
# Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/?envType=daily-question&envId=2025-02-26
# Solved Status: Required Hint


def maxAbsoluteSum(nums):
    n = len(nums)
    dp_max = [0] * n
    dp_min = [0] * n
    dp_max[0] = dp_min[0] = nums[0]
    for i in range(1, n):
        dp_max[i] = max(dp_max[i - 1] + nums[i], nums[i])
        dp_min[i] = min(dp_min[i - 1] + nums[i], nums[i])
    return max(max(dp_max), abs(min(dp_min)))


# Optimized
def maxAbsoluteSum_optimized(nums):
    n = len(nums)
    max_sum = min_sum = nums[0]
    curr_max = curr_min = nums[0]
    for i in range(1, n):
        curr_max = max(curr_max + nums[i], nums[i])
        curr_min = min(curr_min + nums[i], nums[i])

        max_sum = max(max_sum, curr_max)
        min_sum = min(min_sum, curr_min)
    return max(max_sum, abs(min_sum))


test_cases = [[1, -3, 2, 3, -4], [2, -5, 1, -4, 3, -2]]
for nums in test_cases:
    print(nums, "\t->", maxAbsoluteSum(nums), "|", maxAbsoluteSum_optimized(nums))

# Hint
# Use Kadane's algo twice
# max absolute sum will be either the max sum or the min sum.
