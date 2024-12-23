# Combination Sum 
# https://leetcode.com/problems/combination-sum/description/

def combination_sum(arr, target):
    result = []
    
    def backtrack(start, path, sum):
        if sum == target:
            result.append(path[:])
            return 
        if sum > target or start == len(arr):
            return 
        
        for i in range(start, len(arr)):
            path.append(arr[i])
            backtrack(i, path, sum + arr[i])
            path.pop()
        
    backtrack(0, [], 0)
    return result 


arr = [2, 3, 5]
target = 8
result = combination_sum(arr, target)
print(result)