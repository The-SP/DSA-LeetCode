# Subsets II
# https://leetcode.com/problems/subsets-ii/description/

def subsets(arr):
    def backtrack(i, path):
        if i == len(arr):
            result.append(path[:])            
            return
   
        # Include current element
        path.append(arr[i])
        backtrack(i+1, path)
        path.pop()
        
        # Skip duplicates
        while (i+1 < len(arr) and arr[i] == arr[i+1]):
            i += 1
            
        # Exclude current element
        backtrack(i+1, path)
    
    arr.sort()  # Sort to handle duplicates
    result = []
    backtrack(0, [])
    return result


if __name__ == '__main__':
    arr = [1,2,2]
    result = subsets(arr)
    print(result)
    