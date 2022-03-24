from itertools import combinations


def chicken__distance(house,chicken):
    return abs((house[0]+1)-(chicken[0]+1))+abs((house[1]+1)-(chicken[1]+1))
    
def house_min_chicken(house, chicken_all):
    tmp=[]
    for c in chicken_all:
        tmp.append(chicken__distance(house,c))
        # print("in_house_min",house,c," ",tmp)
    if tmp:
        return min(tmp)


def calculate_case(house_all, chicken_all, case):
    
    
    li=[]
    com=list(combinations(chicken_all, case))

    for c in com:# 치킨집의 경우의 수
        chicken_tmp= []
        
        for liv in c: #폐업 X 치킨집
            chicken_tmp.append(liv)
        # print("ct",chicken_tmp)
        if chicken_tmp:
            tmp=[]
            for h in house_all:
                tmp.append(house_min_chicken(h, chicken_tmp) )# 한 집의 최소 치킨거리 반환
            # print("l",li)
            li.append(sum(tmp))
    if li:
        return min(li)
    else:
        return 999999

n, m = list(map(int,input().split()))

house=[]

chicken=[]

data=[]

for i in range(n):
    tmp = list(map(int,input().split()))
    data.append(tmp)
    for j,val in enumerate(tmp):
        in_val=i,j
        if val==2:
            chicken.append(in_val)
        elif val==1:
            house.append(in_val)

    
size=[]
for i in range(1,m+1):
   size.append(calculate_case(house,chicken,i))

print(min(size))
