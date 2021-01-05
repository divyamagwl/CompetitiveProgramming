"""
https://codeforces.com/contest/1472/problem/E
Date: Jan 4 2021
Div: 3
Status: TLE 
Remarks: Incorrect Order, Less Time left for the problem.
"""

import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n = int(input())
    w = []
    h = []
    for i in range(n):
        height, width = get_ints()
        h.append(height)
        w.append(width)
    answers = [-1]*n
    for i in range(n):
        answer = -1
        for j in range(n):
            if i == j:
                continue
            if h[j] < h[i] and w[j] < w[i]:
                answer = j + 1
                break
            elif w[j] < h[i] and h[j] < w[i]:
                answer = j + 1
                break
        answers[i] = answer
    
    for i in answers:
        print(i, end=' ')
    print()