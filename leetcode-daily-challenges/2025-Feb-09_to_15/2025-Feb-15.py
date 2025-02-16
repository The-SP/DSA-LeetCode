# 2698. Find the Punishment Number of an Integer (Medium)
# Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/?envType=daily-question&envId=2025-02-15
# Solved status: Required PseudoCode
# Time taken: 40 min

from typing import *


def punishmentNumber(n):
    punishment_num = 0
    for i in range(1, n + 1):
        i2 = i * i
        if is_punishment_number(i, str(i2)):
            punishment_num += i2
    return punishment_num


def is_punishment_number(n, s):
    length = len(s)
    result = []

    def backtrack(start, path):
        if start == length:
            result.append(path[:])
            path_sum = 0
            for num in path:
                path_sum += int(num)
            if path_sum == n:
                return True

        for i in range(start, length):
            left = s[start : i + 1]
            path.append(left)
            if backtrack(i + 1, path):
                return True
            path.pop()

        return False

    return backtrack(0, [])


n = 37
ans = punishmentNumber(n)
print(n, ans)

n = 10
ans = punishmentNumber(n)
print(n, ans)
