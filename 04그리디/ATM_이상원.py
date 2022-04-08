n=int(input())

data= list(map(int, input().split()))
data.sort()
res =0
tmp =0
for idx, d in enumerate(data):
  tmp += d
  res +=tmp

print(res)
