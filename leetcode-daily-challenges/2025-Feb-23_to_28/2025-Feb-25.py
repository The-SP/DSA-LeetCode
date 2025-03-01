# 1524. Number of Sub-arrays With Odd Sum (Medium)
# Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
# Solved Status: (X) Copied Solution

from typing import List

def numOfSubarrays(arr: List[int]) -> int:
    MOD = 1e9+7
    n = len(arr)
    # dp_even[i]: number of subarrays ending at index i with even sum
    # dp_odd[i]: number of subarrays ending at index i with odd sum
    dp_even, dp_odd = [0] * n, [0] * n
    
    # Base case: first element
    if arr[0] % 2 == 1:  # if first element is odd
        dp_odd[0] = 1    # one subarray [arr[0]] with odd sum
    else:                # if first element is even
        dp_even[0] = 1   # one subarray [arr[0]] with even sum

    for i in range(1, n):
        if arr[i] % 2 == 1:  # Current element is odd
            # New odd sum = prev even sums + current element (even + odd = odd)
            # +1 for the single element subarray [arr[i]]
            dp_odd[i] = (dp_even[i-1] + 1) % MOD
            # New even sum = prev odd sums + current element (odd + odd = even)
            dp_even[i] = dp_odd[i-1]
        else:  # Current element is even
            # New odd sum = prev odd sums (even + even = even, so no new odd)
            dp_odd[i] = dp_odd[i-1]
            # New even sum = prev even sums + current element (even + even = even)
            # +1 for the single element subarray [arr[i]]
            dp_even[i] = (dp_even[i-1] + 1)%MOD
    
    # Total number of subarrays with odd sum is the sum of dp_odd
    count = 0
    for odd_count in dp_odd:
        count = (count + odd_count) % MOD
    return int(count)
        

test_cases = [[1,3,5], [2,4,6], [1,2,3,4], [1,2,3,4,5,6, 7]]
for arr in test_cases:
    print(arr, '->', numOfSubarrays(arr))
