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
void dijkstra(int sx, int sy){
    priority_queue<pair<int , pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq; // �ּ���  
    pq.push({map[sx][sy], {sx, sy}});
    Dist[sx][sy]= map[sx][sy];

    while(!pq.empty()){
        int dist = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();
		
        //if(Dist[cx][cy]<dist) continue;
        for(int i=0; i<4; i++){
        	int nx = cx + dx[i];
        	int ny = cy + dy[i];
        	
        	if(0<=nx && nx<n && 0<=ny && ny<n){
        		int ndist = dist + map[nx][ny];
        		if(ndist<Dist[nx][ny]){
        			Dist[nx][ny] = ndist;
        			pq.push({ndist, {nx, ny}});
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
		
		dijkstra(0,0); // ���ͽ�Ʈ�� �˰���  
		
		int ans = Dist[n-1][n-1]; // �� 
		cout<<"Problem "<<cnt<<": "<<ans<<'\n'; // �� ���  
	}
}
