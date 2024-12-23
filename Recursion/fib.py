# Fibonacci

# TC: total no of rec calls + work in each calls
# SC: depth of rec tree * mem in each call

# TC: (2^n -1) * 1 = O(2^n)
# SC: n * 1 = O(n)
def fib(n):
    if n == 0 or n == 1:
        return n 
    return fib(n-1) + fib(n-2)

# TC: O(n)
# SC: O(n)
hash = {}
def fib2(n):
    if n in hash:
        return hash[n]
    if n == 0 or n == 1:
        return n
    result = fib2(n-1)+fib2(n-2)
    if n not in hash:
        hash[n] = result 
    return result


if __name__ == '__main__':
    for i in range(10):
        print(fib(i), end=' ')
        
    print()
    for i in range(10):
        print(fib2(i), end=' ')