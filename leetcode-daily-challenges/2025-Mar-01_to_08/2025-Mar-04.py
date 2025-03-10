# 1780. Check if Number is a Sum of Powers of Three (medium)
# Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04
# Solved status: Not solved

from typing import *

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 0:
            if n % 3 == 2:
                return False 
            n //= 3
        return True
        