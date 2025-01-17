# 3042. Count Prefix and Suffix Pairs I
# Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08 

from typing import *

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if isPrefixAndSuffix(words[i], words[j]):
                    count += 1
        return count

def isPrefixAndSuffix(word1, word2):
    n = len(word1)
    return word1 == word2[:n] and word1 == word2[-n:]