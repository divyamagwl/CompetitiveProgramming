"""
https://codeforces.com/contest/1472/problem/D
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

    array.sort(reverse=True)
    Alice = 0
    Bob = 0

    length = len(array)

    for i in range(length):
        if i % 2 == 0:
            if array[i] % 2 == 0:
                Alice += array[i]
        else:
            if array[i] % 2 != 0:
                Bob += array[i]
        
    if Alice > Bob:
        print("Alice")
    elif Alice < Bob:
        print("Bob")
    else:
        print("Tie")
        