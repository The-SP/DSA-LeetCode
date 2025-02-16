# 3174. Clear Digits (Easy)
# Link: https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10

from typing import *

class Solution:
    def clearDigits(self, s: str) -> str:
        ans = ''
        for ch in s:
            if 48 <= ord(ch) <= 57:
                ans = ans[:-1]
            else:
                ans = ans + ch
        return ans