size = int(input())

data =[]

for i in range(size):
    tmp = list(map(int,input()))
    data.append(tmp)

def dfs(x,y):
    #범위를 벗어나면 완전 끝~
    if x<=-1 or x>=size or y<=-1 or y>=size:
        return 0
    res=0
    if data[x][y] ==1:
        res+=1

        data[x][y] =0
        # 상하좌우 체크
        res+=dfs(x-1,y)
        res+=dfs(x,y-1)
        res+=dfs(x+1,y)
        res+=dfs(x,y+1)
        return res
    return 0


result=[]

for i in range(size):
    for j in range(size):
        res =dfs(i, j)
        if res>=1:
            result.append(res)
print(len(result))
for i in sorted(result):
    print(i)
