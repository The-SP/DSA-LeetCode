# 916. Word Subsets
# Link: https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10

from typing import *

class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words1_count = [get_count(word) for word in words1]
        
        words2_max_count = get_max_counts(words2)

        subsets = []

        for i, word1 in enumerate(words1):
            is_subset = True
            for letter, count in words2_max_count.items():
                if words1_count[i].get(letter, 0) < count:
                    is_subset = False 
                    break 

            if is_subset:
                subsets.append(word1)
        
        return subsets


def get_count(word):
    count = {}
    for letter in word:
        if letter in count:
            count[letter] += 1
        else:
            count[letter] = 1
    return count 


def get_max_counts(words2):
    max_count = {}
    for word in words2:
        word_count = get_count(word)
        for letter, count in word_count.items():
            if max_count.get(letter, 0) < count:
                max_count[letter] = count 
    return max_count   