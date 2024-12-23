# Subsets
# https://leetcode.com/problems/subsets/

def subsets(arr):
    def backtrack(i, path):
        if i == len(arr):
            result.append(path[:])
            return
        
        # Include
        path.append(arr[i])
        backtrack(i+1, path)
        # Exclude
        path.pop()
        backtrack(i+1, path)
        
    result = []    
    backtrack(0, [])
    return result


if __name__ == '__main__':
    arr = [1,2,3]
    result = subsets(arr)
    print(result)


# TC = total calls * work done in each call = O(2^n)
# SC = O(n)