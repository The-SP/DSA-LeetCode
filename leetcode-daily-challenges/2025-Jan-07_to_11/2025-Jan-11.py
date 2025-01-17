# 1400. Construct K Palindrome Strings
# Link: https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11

from typing import *

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        letter_count = {}
        for letter in s:
            if letter not in letter_count:
                letter_count[letter] = 1
            else:
                letter_count[letter] += 1

        odd_count = 0
        for val in letter_count.values():
            odd_count += val % 2
        
        return k >= odd_count and k <= len(s)
