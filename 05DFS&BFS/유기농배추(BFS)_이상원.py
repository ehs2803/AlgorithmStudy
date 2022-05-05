from collections import deque
T = int(input())

dx = [0, 0, -1, 1]
dy =[-1, 1, 0,0]

def bfs(x, y, n, m) -> bool:
    
    # 12시 방향 기준 상, 하, 좌, 우
    
    queue = deque()
    queue.append((x,y))
    graph[x][y]=0

    while queue:

        x,y = queue.popleft()


        
        for i in range(4):  
            nx = x+dx[i]
            ny = y+dy[i]
            if nx <0 or ny<0 or nx>=n or ny>=m:
                continue
            if graph[nx][ny] ==0:
                continue 
            if graph[nx][ny] ==1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
    
    return 

result =[0]*T
for t in range(T):
    M, N, K = map(int ,input().split())
    # M : 가로(열) y , N : 세로(행) x
    graph=[ [0]*M for i in range(N)]

    for k in range(K):
        m,n = map(int,input().split())
        graph[n][m] =1
    #print(data)
    for i in range(N):
        for j in range(M):
           if graph[i][j]==1:
               bfs(i,j,N,M)
               result[t]+=1

    
 
     
for i in result:
    print(i)
