# 1790. Check if One String Swap Can Make Strings Equal (Easy)
# Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

from typing import *

def areAlmostEqual(s1, s2):
    n = len(s1)
    diff = []
    for i in range(n):
        if s1[i] != s2[i]:
            diff.append(i)
    
    if len(diff) == 2:
        i, j = diff
        return s1[i] == s2[j] and s1[j] == s2[i]
    
    return len(diff) == 0

s1 = "bank"
s2 = "kanb"
print(areAlmostEqual(s1, s2))