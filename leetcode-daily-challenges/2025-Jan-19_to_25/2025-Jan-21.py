# 2017. Grid Game (Medium)
# Link: https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21

from typing import *

class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        
        # Calculate prefix sums for both rows
        prefix_row1, prefix_row2 = [0]*n, [0]*n 
        prefix_row1[0] = grid[0][0]
        prefix_row2[0] = grid[1][0]
        for i in range(1, n):
            prefix_row1[i] = prefix_row1[i-1] + grid[0][i]
            prefix_row2[i] = prefix_row2[i-1] + grid[1][i]
            
        min_points_robot2 = float('inf')
        for i in range(n):
            top_sum = prefix_row1[-1] - prefix_row1[i]
            bottom_sum = prefix_row2[i-1] if i > 0 else 0 
            
            # robot 2 will maximize its points
            robot2_choice = max(top_sum, bottom_sum)
            
            # robot 1 will minimize robot2's points
            min_points_robot2 = min(min_points_robot2, robot2_choice)
            
        return min_points_robot2