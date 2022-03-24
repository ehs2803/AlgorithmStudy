a="WBWBWBWB"
b="BWBWBWBW"

#0,1
w_first=[a,b,a,b,a,b,a,b]
b_first=[b,a,b,a,b,a,b,a]


def check(val):
    sum=[0,0]
     # black
    for i in range(8):
        for j in range(8):
            if val[i][j]!=b_first[i][j]:
                sum[0]+=1
    for i in range(8):
        for j in range(8):
            if val[i][j]!=w_first[i][j]:
                sum[1]+=1  
    return sum

n,m =list(map(int,input().split()))

# print(n,m)

li=[]
for _ in range(n):
    tmp=input()
    li.append(tmp)

num=0
check_sum=[]
for i in range(n-7):
    for j in range(m-7):
        tmp=li[i:i+8]
        for idx, k in enumerate(tmp):
            tmp[idx]=k[j:j+8]
        # print(len(tmp)," ", len(tmp[0]))
        check_sum.extend(check(tmp))
        num+=1
   


# print(check_sum)
print(min(check_sum))
