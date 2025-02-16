# 3066. Minimum Operations to Exceed Threshold Value II (Medium)
# Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
# Solved Status: (Time Limit Exceeded)

from typing import *


# Solution 1 (Time limit exceeded)
def minOperations(nums, k):
    nums = sorted(nums, reverse=True)
    count = 0
    while len(nums) > 1:
        x = nums.pop()
        y = nums.pop()
        if x >= k and y >= k:
            return count
        new_num = min(x, y) * 2 + max(x, y)
        insert(nums, new_num)
        count += 1
    return count

def insert(arr, val):
    for i in range(len(arr)):
        if val > arr[i]:
            arr.insert(i, val)
            return
    arr.append(val) # Insert for the first element or minimum element
    
    
nums = [1,1,2,4,9]
k = 10
min_operations = minOperations(nums, k)
print(min_operations)


# Solution 2 (Copied solution)
import heapq

def minOperations(nums, k):
    # Convert the list into a min-heap
    heapq.heapify(nums)
    count = 0

    # Continue until there are at least two elements in the heap
    while len(nums) > 1:
        # Get the two smallest elements
        x = heapq.heappop(nums)
        y = heapq.heappop(nums)

        # If both elements are already >= k, we can stop
        if x >= k and y >= k:
            return count

        # Calculate the new element to add
        new_num = min(x, y) * 2 + max(x, y)

        # Add the new element back to the heap
        heapq.heappush(nums, new_num)

        # Increment the operation count
        count += 1

    return count

nums = [1,1,2,4,9]
k = 10
min_operations = minOperations(nums, k)
print(min_operations)