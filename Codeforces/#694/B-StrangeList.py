"""
https://codeforces.com/contest/1471/problem/A
Date: Jan 5 2021
Div: 2
Status: Wrong Answer
Remarks: No proper solution in mind. Less Time left for the problem.
"""

import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n, x = get_ints()
    num = get_list()

    twoD = []
    twoD.append(num)

    i = 0
    summation = 0
    while True:
        twoD.append([])
        for j in range(len(twoD[i])):
            if twoD[i][j] % x == 0:
                twoD[i+1].append(twoD[i][j] // x)
            else:
                break
        if len(twoD[i+1]) == 0:
            break
        i += 1

    for i in range(len(twoD)):
        for j in range(len(twoD[i])):
            summation += pow(x ,i)*twoD[i][j]

    print(summation)
