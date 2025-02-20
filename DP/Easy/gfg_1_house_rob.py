# House Robber
# Link: https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

def max_loot(hval):
    n = len(hval)
    dp = [0] * (n+1)
    dp[1] = hval[0]
    for i in range(2, n+1):
        dp[i] = max(dp[i-1], dp[i-2]+hval[i-1])
    return dp[-1]        

print(max_loot([5, 3, 4, 11, 2]))        # Thief will steal from house 1 and 4, total money = 5 + 11 = 16.
print(max_loot([6, 7, 1, 3, 8, 2, 4]))   # Thief will steal from house 1, 3, 5 and 7, total money = 6 + 1 + 8 + 4 = 19.