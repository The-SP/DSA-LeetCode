from pprint import pprint
import copy


def is_safe(board, i, j):
    # Check column conflicts
    for row in range(i):
        if board[row][j] == 'Q':
            return False 
        
    # Check upper left diagonal
    row, left_diag = i-1, j-1
    while row >= 0 and left_diag >= 0:
        if board[row][left_diag] == 'Q':
            return False 
        row -= 1
        left_diag -= 1
        
    # # Check upper right diagonal
    row, right_diag = i-1, j+1 
    while row >= 0 and right_diag < len(board):
        if board[row][right_diag] == 'Q':
            return False 
        row -= 1
        right_diag += 1
        
    return True


def solve_n_queens(n):
    board = [['.' for _ in range(n)] for _ in range(n)]
    result = []
    
    def solve(row):
        # Base case: all queens are placed
        if row == n:
            result.append(copy.deepcopy(board))
            return
        
        # Try placing queen in each column of the current row
        for col in range(n):
            if is_safe(board, row, col):
                board[row][col] = 'Q'
                
                # Recurse to place queens in the next row
                solve(row+1)
                
                # Backtrack if solution not found 
                board[row][col] = '.'
        
    solve(0)
    return result
        
        
result = solve_n_queens(3)
print(len(result), result)

result = solve_n_queens(4)
for board in result:
    pprint(board)
    

# TC: n*(n-1)*(n-2)*...*1 = O(n!)