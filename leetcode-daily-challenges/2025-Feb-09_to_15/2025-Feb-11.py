# 1910. Remove All Occurrences of a Substring (Medium)
# Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11

from typing import *

class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n, p = len(s), len(part)
        i = 0
        while i < n:
            substr = s[i:i+p]
            if substr == part:
                s = s[:i] + s[i+p:]
                n = len(s)
                i = i - p 
            i += 1
        return s
                
        