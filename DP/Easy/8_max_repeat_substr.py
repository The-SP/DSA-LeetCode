# 1668. Maximum Repeating Substring
# Link: https://leetcode.com/problems/maximum-repeating-substring/description/?envType=problem-list-v2&envId=dynamic-programming


def max_repeating_substring(sequence, word):
    n = len(word)
    dp = [0] * (len(sequence) + 1)
    max_k = 0
    i = len(sequence) - n
    while i >= 0:
        sub_str = sequence[i : i + n]
        if sub_str == word:
            dp[i] = dp[i + n] + 1
            max_k = max(max_k, dp[i])
        i -= 1
    return max_k


sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba"
word = "aaaba"
print(max_repeating_substring(sequence, word))  # 5

sequence = "ababc"
word = "ab"
print(max_repeating_substring(sequence, word))  # 2

sequence = "a"
word = "a"
print(max_repeating_substring(sequence, word))  # 1
