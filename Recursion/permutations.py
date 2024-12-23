# Permutations of an array/string
# https://leetcode.com/problems/permutations/

def permute(nums):
    def backtrack(start):
        if start == len(nums):
            result.append(nums[:])
            return 
        
        for i in range(start, len(nums)):
            nums[i], nums[start] = nums[start], nums[i] # swap current element with the first element
            backtrack(start+1)        # recursively find permutations for remaining elements
            nums[i], nums[start] = nums[start], nums[i] # swap back to restore order
    
    result = []
    backtrack(0)
    return result
        
result = permute([1, 2, 3])
print(result)

# TC: O(n! * n)
# SC: O(n! + n) ~ O(n!)