s=input()
k=int(input())

def returnUnique(s):
    st=set()
    newS=""
    for c in s:
        if c in st:
            continue
        newS+=c[0]
        st.add(c)
    return newS

for i in range(0,len(s),k):
    subS=s[i:i+k]
    print(returnUnique(subS))