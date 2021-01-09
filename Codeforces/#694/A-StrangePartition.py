"""
https://codeforces.com/contest/1471/problem/A
Date: Jan 5 2021
Div: 2
Status: Accepted
"""

import sys, math
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n, x = get_ints()
    num = get_list()

    max = 0
    for i in range(len(num)):
        max += int(math.ceil(num[i] / x))

    min = int(math.ceil(sum(num) / x))

    print(min, max)