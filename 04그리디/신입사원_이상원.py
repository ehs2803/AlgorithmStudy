from sys import stdin
test=int(stdin.readline())

for t in range(test):
    n = int(stdin.readline())
    data ={}
    for i in range(n):
        doc , speak = list(map(int,stdin.readline().split()))
        data[doc] = speak
    data= sorted(data.items())
    min_val = data[0][1]
    cnt=1
    for d in data:
        tmp=min(min_val, d[1])
        if min_val>tmp:
            cnt+=1
            min_val = tmp
        
    print(cnt)
