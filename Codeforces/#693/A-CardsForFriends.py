"""
https://codeforces.com/contest/1472/problem/A
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
    w, h, n = get_ints()
    W = w
    H = h

    papers = 1
    while W % 2 == 0 or H % 2 == 0:
        if W % 2 == 0:
            W = W //2
            papers *= 2
        elif H % 2 == 0:
            H = H // 2
            papers *= 2

    if papers >= n:
        print("YES")
    else:
        print("NO")