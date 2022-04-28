#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int n,m;

char map[100][100]; // map - bfs, dfs
bool check[100][100]; // 방문여부 - bfs, dfs 
 
// 4가지 방향 이동 - bfs, dfs 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 정답 배열, 변수  
int dist[100][100]; // 거리 - bfs 
int dfs_ans= 99999; // 거리 - dfs 

void bfs(int x, int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    check[x][y]=true;
    dist[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == '1' && check[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    check[nx][ny]=true;
                    dist[nx][ny]=dist[x][y]+1;
                }
            }
        }
    }
}

void dfs(int x, int y, int depth){
	if (x <= -1 || x >=n || y <= -1 || y >= m)  return; // 맵 범위 벗어난 경우 
	if(x==n-1 && y==m-1){
		if(depth < dfs_ans){
			dfs_ans = depth;
		}
		return;
	}
	
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
        int ny = y+dy[i];
        
        if (map[nx][ny] == '1' && check[nx][ny] == false){
        	check[nx][ny]=true;
        	dfs(nx,ny,depth+1);
        	check[nx][ny]=false;
		}	
	}
}

int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string str; 
        cin>>str;
        for(int j=0;j<str.size();j++){
        	map[i][j]=str[j];
		}
    }
    bfs(0,0);
    cout<<dist[n-1][m-1];
    //dfs(0,0,1);
    //cout<<dfs_ans;
}
