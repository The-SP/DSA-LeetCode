# 2523. Closest Prime Numbers in Range (medium)
# Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
# Solved status: Required help for optimization

from typing import *

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        primes = sieve_of_eratosthenes(left, right)
        
        if len(primes) < 2:
            return [-1, -1]
        
        closest_prime = [primes[0], primes[1]]
        min_diff = primes[1] - primes[0]
        for i in range(1, len(primes)-1):
            diff = primes[i+1] - primes[i]
            if diff < min_diff:
                min_diff = diff
                closest_prime = [primes[i], primes[i+1]]
        return closest_prime


def sieve_of_eratosthenes(left, right):
    is_prime = [True] * (right+1)
    is_prime[0] = is_prime[1] = False
    p = 2
    while p <= right:
        if is_prime[p]:
            for i in range(p*p, right+1, p):
                is_prime[i] = False
        p += 1
    primes = [i for i in range(left, right+1) if is_prime[i]]
    return primes