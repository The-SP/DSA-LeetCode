# 3223. Minimum Length of String After Operations
# Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

from typing import *

class Solution:
    def minimumLength(self, s: str) -> int:
        operations = get_operations(s)
        return len(s)-operations

def get_operations(word):
        operations = 0
        letter_count = {}
        for i, letter in enumerate(word):
            count = letter_count.get(letter, 0)
            if count == 2:
                operations += 2
                letter_count[letter] = 1
            letter_count[letter] = count + 1
        return operations 
    