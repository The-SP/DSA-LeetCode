# Min Cost Path
# Link: https://www.geeksforgeeks.org/min-cost-path-dp-6/


def min_cost(cost):
    m, n = len(cost), len(cost[0])
    dp = [[0] * n for _ in range(m)]

    # Initialize the first cell
    dp[0][0] = cost[0][0]

    # Fill the first row
    for j in range(1, n):
        dp[0][j] = cost[0][j] + dp[0][j - 1]

    # Fill the first column
    for i in range(1, m):
        dp[i][0] = cost[i][0] + dp[i - 1][0]

    for i in range(1, m):
        for j in range(1, n):
            mini = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
            dp[i][j] = cost[i][j] + mini
    return dp[m - 1][n - 1]


cost = [[1, 2, 3], [4, 8, 2], [1, 5, 3]]
print(min_cost(cost))
