from itertools import combinations
import math

def union_parent(parent, a, b):
    a= find_parent(parent,a)
    b=find_parent(parent,b)
    if a<b:
        parent[b] =a
    else:
        parent[a] =b

# 경로 압축 기법 소스코드
def find_parent(parent, x):
    if parent[x] !=x:
        parent[x] = find_parent(parent,parent[x])
    return parent[x]

def distance(a,b):
    return math.sqrt((b[1]-a[1])**2 +(b[0]-a[0])**2) 


# 모든 간선을 담을 리스트와 최종 비용을 담을 변수
edges = []
result = float(0)


n =int(input())

parent=[0]*(n+1) # cycle 체크를 위해서 필요할 수 밖에 없네
# 부모 테이블상에서,부모를 자기 자신으로 초기화
for i in range(1,n+1):
    parent[i] =i

comb= [i for i in range(1,n+1)]
comb = list(combinations(comb,2))

space= dict()


for i in range(1,n+1):
    x ,y = map(float, input().split())
    space[i] =(x,y)

for c in comb:
    a, b = c
    cost = distance(space[a], space[b])
    edges.append((cost,a,b))



# 간선을 비용순으로 정렬하기
edges.sort()
# print(edges)
# print(parent)
# 간선을 하나씩 확인하며
for edge in edges:
    cost, a, b= edge

    #사이클이 발생하지 않는 경우에만 집합에 포함
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent,a,b)
        #print(cost)
        result +=cost
        
       
 
print(format(result,".2f"))

