# 3160. Find the Number of Distinct Colors Among the Balls (Medium)
# Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/?envType=daily-question&envId=2025-02-07
# Solved Status: Required Hint


from typing import List

class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        colors = []
        ball_hash = {}
        colors_hash = {}
        for ball, color in queries:
            if ball in ball_hash:
                prev_color = ball_hash[ball]
                colors_hash[prev_color] -= 1
                if colors_hash[prev_color] == 0:
                    colors_hash.pop(prev_color)
                
            if color not in colors_hash:
                colors_hash[color] = 1
            else:
                colors_hash[color] += 1
            
            ball_hash[ball] = color
            colors.append(len(colors_hash))
        return colors
