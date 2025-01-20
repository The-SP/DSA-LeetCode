# 2683. Neighboring Bitwise XOR
# Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17

from typing import *

class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        xor = 0
        for bit in derived:
            xor ^= bit
        return xor == 0