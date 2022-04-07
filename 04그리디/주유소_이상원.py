n=int(input())


dis = list(map(int,input().split()))
dis_sum = sum(dis)

city=list(map(int,input().split()))
city.pop()
city_min =min(city)

city_min_idx = city.index(city_min)

val=0
tmp=city[0]
for i,data in enumerate(city):
    if(i==city_min_idx):
        val+=sum(dis[i:])*city_min
        break

    if i+1 != n-1:
        if tmp>=city[i+1]:
            val+=tmp*dis[i]
            tmp = city[i+1]
        else:
            val+=tmp*dis[i]


# print(city)
print(val)
