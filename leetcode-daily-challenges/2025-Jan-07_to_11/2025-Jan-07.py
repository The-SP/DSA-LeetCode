# 1408. String Matching in an Array
# Link: https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

from typing import *

class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        result = set()
        for word in words:
            for word2 in words:
                if word2 != word and word2 in word:
                    result.add(word2)
        return list(result)
