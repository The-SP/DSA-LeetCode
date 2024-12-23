# Unique-Paths III
# Leetcode Hard
# https://leetcode.com/problems/unique-paths-iii/description/

# Time taken: 1hour 10 minutes (40 minute whiteboard + 30 min coding)

def find_start_square_and_obstacle_count(grid):
    start = (0, 0)
    obstacle = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                start = (i, j)
            elif grid[i][j] == -1:
                obstacle += 1
    return start, obstacle


def uniquePaths(grid):
    m, n = len(grid), len(grid[0])
    (i, j), obstacle_count = find_start_square_and_obstacle_count(grid)
    goal_path_count = m*n-1-obstacle_count

    path = []
    result = []
    visited = [[False for j in range(n)] for i in range(m)]

    def backtrack(i, j, path, visited):
        # check out of boundary
        if i < 0 or i >= m or j < 0 or j >= n:
            return 

        # check if already visited
        if visited[i][j] == True:
            return 

        # Check if obstacle
        if grid[i][j] == -1:
            return 

        # Check if goal square
        if grid[i][j] == 2:
            # Check if all non-obstacle square visited
            if len(path) == goal_path_count:
                result.append(path[:])
            return 

        visited[i][j] = True 
        path.append((i, j))

        backtrack(i-1, j, path, visited)
        backtrack(i+1, j, path, visited)
        backtrack(i, j-1, path, visited)
        backtrack(i, j+1, path, visited)

        visited[i][j] = False 
        path.pop()

    backtrack(i, j, path, visited)
    return result 


grid = [
    [1, 0, 0, 0], 
    [0, 0, 0, 0], 
    [0, 0, 2, -1]
]

# grid = [
#     [1,0,0,0],
#     [0,0,0,0],
#     [0,0,0,2]
# ]

# grid = [[0,1],[2,0]]

result = uniquePaths(grid)
print(f'Unique paths: {len(result)}')
for ans in result:
    print(ans)
