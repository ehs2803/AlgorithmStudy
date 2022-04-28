n,m = list(map(int,input().split()))

a=[[] for i in range(m)]

for i in range(n):
    tmp = input()
    for idx,s in enumerate(tmp):
        a[idx].append(s)

s=''
cnt=0
for data in a:
    tmp={}
    for d in data:
        if tmp.get(d):
            tmp[d]+=1
        else:
            tmp[d]=1
    
    tmp =sorted(tmp.items(),key= lambda x:x[1],reverse=True)
    # print(tmp)
    if len(tmp) == 1:
        s+=tmp[0][0]
    else:
        tmp1=[]
        for idx,t in enumerate(tmp):
            if idx !=0:
                cnt+=t[1]
            if tmp[0][1] ==t[1]:
                tmp1.append(t[0])
        tmp1.sort()
        s+=tmp1[0]
    

print(s)
print(cnt)
