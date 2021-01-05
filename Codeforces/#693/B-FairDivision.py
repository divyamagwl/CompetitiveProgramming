"""
https://codeforces.com/contest/1472/problem/B
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
    N = int(input())
    candies = get_list()

    candies.sort(reverse=True)

    length = len(candies)

    i = 0
    while i < length:
        if candies[i] == 2:
            if i + 1 < length and candies[i] == candies[i+1]:
                i += 2
                continue
            elif i + 1 < length and candies[i] != candies[i+1]:
                if i + 2 < length and candies[i+2] == 1:
                    i += 3
                    continue
                else:
                    break
            else:
                break
        else:
            if i + 1 < length and candies[i] == candies[i+1]:
                i += 2
                continue
            else:
                break
        i += 1


    if i == length:
        print("YES")
    else:
        print("NO")