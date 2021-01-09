"""
https://codeforces.com/contest/1467/problem/B
Date: Jan 8 2021
Div: 2
Status: Wrong Answer
Remarks: Missed edge cases. Did very complicated solution.
"""

import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()

T = int(input())
for _ in range(T):
    n = int(input())
    num = get_list()

    valleys = 0
    hills = 0

    responsible = [""]*n

    for i in range(1, n-1):
        if i == 1 or i == n - 2:
            responsible[i] += "N"
        if num[i] > num[i-1] and num[i] > num[i+1]:
            hills += 1
            responsible[i-1] += "H"
            responsible[i] += "H"
            responsible[i+1] += "H"
        elif num[i] < num[i-1] and num[i] < num[i+1]:
            valleys += 1
            responsible[i-1] += "V"
            responsible[i] += "V"
            responsible[i+1] += "V"
        else:
            responsible[i-1] += "N"
            responsible[i] += "N"
            responsible[i+1] += "N"

    total = hills + valleys

    pos3 = ["HVH", "VHV"]
    pos2 = ["NVH", "NHV", "HVN", "VHN"]
    pos1 = ["HNN", "VNN", "NHN", "NVN", "NNV", "NNH", "HNV", "VNH", "H", "V", "NH", "HN", "VN", "NV"]

    maximum = 0
    index = 0
    for i in range(1, n-1):
        # print(responsible[i])
        if responsible[i] in pos3:
            maximum = 3
        elif responsible[i] in pos2:
            if maximum < 2:
                maximum = 2
        elif responsible[i] in pos1:
            if maximum < 1:
                maximum = 1
    
    total -= maximum

    # print("#########")
    # print(hills, valleys)
    print(total)
    # print("#########")
