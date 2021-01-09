"""
https://codeforces.com/contest/1467/problem/A
Date: Jan 8 2021
Div: 2
Status: Accepted
"""


import sys, math
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n = int(input())

    string = ""

    num = 9
    decrease = True
    for i in range(n):
        if i < 3:
            string += str(num)
            num -= 1
            if i == 1:
                num = 9
            elif i == 2:
                num = 0
        else:
            string += str(num)
            num += 1
            if num > 9:
                num = 0

    print(string)
