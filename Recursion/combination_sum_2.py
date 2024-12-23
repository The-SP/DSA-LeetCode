# Combination Sum II
# https://leetcode.com/problems/combination-sum-ii/description/

def combination_sum_2(arr, target):
    result = []
    
    def backtrack(start, path, sum):
        if sum == target:
            result.append(path[:])
            return 
        if sum > target or start == len(arr):
            return 
        
        for i in range(start, len(arr)):
            if i>start and arr[i] == arr[i-1]: # Skip duplicates
                continue
            path.append(arr[i])
            backtrack(i+1, path, sum + arr[i])
            path.pop()
            
    arr.sort()  
    backtrack(0, [], 0)
    return result 


candidates = [2, 5, 2, 1, 2]
target = 5
print(combination_sum_2(candidates, target))