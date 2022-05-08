#include<iostream>
#include<queue>
#define INF 1e9
using namespace std;

int n;

int map[125][125];
int Dist[125][125];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// ���ͽ�Ʈ��  
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
		cnt++; // �׽�Ʈ ���̽� ���� 1 ����  
		
		cin>>n;
		if(n==0) break; // n�� 0�̸� ����  
		
		// �Է�  
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j]; // �Է�  
				Dist[i][j]=INF; // Dist �迭 �ʱ�ȭ  
			}
		}
		
		bfs(0,0); // ���ͽ�Ʈ�� �˰���  
		
		int ans = Dist[n-1][n-1]; // �� 
		cout<<"Problem "<<cnt<<": "<<ans<<'\n'; // �� ���  
	}
}
