#include<iostream>
#include<queue>
#define INF 1e9
using namespace std;

int n;

int map[125][125];
int Dist[125][125];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// 다익스트라  
void bfs(int sx, int sy){
    queue<pair<int,int> > q;  
    q.push({sx, sy});
    Dist[sx][sy]= map[sx][sy];
 
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (0<=nx && nx<n && 0<=ny && ny<n){
                if (Dist[nx][ny] > Dist[x][y] + map[nx][ny]){
                    Dist[nx][ny] = Dist[x][y] + map[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
	int cnt=0;
	while(true){
		cnt++; // 테스트 케이스 개수 1 증가  
		
		cin>>n;
		if(n==0) break; // n이 0이면 종료  
		
		// 입력  
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j]; // 입력  
				Dist[i][j]=INF; // Dist 배열 초기화  
			}
		}
		
		bfs(0,0); // 다익스트라 알고리즘  
		
		int ans = Dist[n-1][n-1]; // 답 
		cout<<"Problem "<<cnt<<": "<<ans<<'\n'; // 답 출력  
	}
}
