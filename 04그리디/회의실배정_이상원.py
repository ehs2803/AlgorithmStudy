data=[]
for i in range(n):
  data.append(tuple(map(int,input().split())))
  
#print(data)

#끝나는 시간의 오름차순 1 , 시작하는 시간의 오름차순 2.
data.sort(key=lambda x : (x[1],x[0]))
#print(data)
cnt =1
tmp = data[0]
for idx in range(1, n):
  if (data[idx][0]>=tmp[1]):
    cnt+=1
    tmp =data[idx]
  

print(cnt)
