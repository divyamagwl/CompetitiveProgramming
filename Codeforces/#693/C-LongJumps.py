"""
https://codeforces.com/contest/1472/problem/C
Date: Jan 4 2021
Div: 3
Status: Accepted
"""

import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n = int(input())
    array = get_list()

    maxScore = 0
    length = len(array)
    storage = [0]*length
    for i in range(length-1, -1, -1):
        sum = array[i]
        storage[i] += array[i]

        j = i + array[i]

        while j < length:
            if storage[j] != 0:
                sum += storage[j]
                storage[i] = sum
                break
            else:
                sum += array[j]
                storage[i] = sum
                j += array[j]
        if sum > maxScore:
            maxScore = sum

    print(maxScore)

