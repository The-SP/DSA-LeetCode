# 1765. Map of Highest Peak
# Medium
# Link: https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
# Help Needed: Yes

from typing import *

def highestPeak(isWater: List[List[int]]) -> List[List[int]]:
    m, n = len(isWater), len(isWater[0])
    height = [[-1 for _ in range(n)] for _ in range(m)]
    queue = []

    # Initialize queue with water cells
    for i in range(m):
        for j in range(n):
            if isWater[i][j] == 1:
                height[i][j] = 0
                queue.append((i, j))          
                
    # BFS
    while queue:
        i, j = queue.pop(0)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] # North, South, West, East
        for x, y in directions:
            r, c = i+x, j+y 
            if 0 <= r < m and 0 <= c < n and height[r][c] == -1:
                height[r][c] = height[i][j] + 1
                queue.append((r, c))  
                        
    return height


isWater = [
    [0, 0, 0, 0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 0],
    [0, 0, 1, 0, 0, 0, 0, 0],
]


result = highestPeak(isWater)
print(result)
