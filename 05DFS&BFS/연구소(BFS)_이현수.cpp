#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int N,M;

int lab[8][8]; // 연구소   
int tmp[8][8]; // 연구소 복사  

bool check[8][8]; // 방문 여부  

vector<pair<int,int> > zero; // lab좌표 중 0인 좌표 저장  

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// 연구소 복사  : 여러 조합에 대해 테스트 해봐야 되기 때문에  
void copyLab(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) tmp[i][j]=lab[i][j];
	}
}

// bfs
void bfs(int x, int y) {
	queue<pair<int,int> > q;
	q.push({x,y});
	check[x][y]=true;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(0 <= nx && nx < N && 0 <= ny && ny < M){
				if(tmp[nx][ny]==1) {
					check[nx][ny]=true;
					continue;	
				}
				if(check[nx][ny]) continue;
				tmp[nx][ny]=2;
				q.push({nx,ny});
				check[nx][ny]=true;
			}
		}
	}
}

// 안전 구역 세기 -  안전구역 : 0인 곳 
int countVirus(){
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
	    	if(tmp[i][j]==0) cnt++;
		}
	}
	return cnt;
}

int main(){
	// 입출력 빨라지게 해줌. 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>lab[i][j];
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(lab[i][j]==0) zero.push_back({i,j});	// 안전 구역인 좌표 벡터에 저장  
		}
	}
	
	// 조합을 위한 코드들 ... 
	vector<int> ind;
	int k=3;
	for(int i=0; i<k; i++){
		ind.push_back(1);
	}
	for(int i=0; i<zero.size()-k; i++){
		ind.push_back(0);
	}
	
	sort(ind.begin(), ind.end());
	
	int ans=0;	
	do{
		copyLab(); // 연구소 복사  
		for(int i=0;i<N;i++){ // 방문 여부 확인 배열 모두 false로 초기화  
			for(int j=0;j<M;j++) check[i][j]=false; 
		}
		
		// 조합을 이용해서 벽(1) 세우기  
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				tmp[zero[i].first][zero[i].second]=1;
			}
		}
		// 바이러스(2)이면서 방문하지 않은 좌표라면 dfs로 바이러스 감염시키기  
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(tmp[i][j]==2 && check[i][j]==false) bfs(i,j);
			}
		}
		// 안전구역 크기 최대치로 갱신  
		ans = max(ans, countVirus());
	}while(next_permutation(ind.begin(), ind.end()));		
	
	// 답 출력  
	cout<<ans;
}
