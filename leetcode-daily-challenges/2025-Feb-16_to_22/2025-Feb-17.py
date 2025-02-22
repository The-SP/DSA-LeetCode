# 1079. Letter Tile Possibilities (Medium)
# Link: https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17
# Solved status: Hint required

from typing import *


def possibilities(tiles):
    n = len(tiles)
    result = set()
    used = [False] * n
    
    def backtrack(path):
        if path:
            result.add(path)
        
        for i in range(n):
            if not used[i]:
                used[i] = True
                backtrack(path + tiles[i])
                used[i] = False
    
    backtrack('')
    print(result)
    return len(result)

tiles = "AAB"
print(possibilities(tiles))