#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int N,M;

int lab[8][8]; // ������   
int tmp[8][8]; // ������ ����  

bool check[8][8]; // �湮 ����  

vector<pair<int,int> > zero; // lab��ǥ �� 0�� ��ǥ ����  

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// ������ ����  : ���� ���տ� ���� �׽�Ʈ �غ��� �Ǳ� ������  
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

// ���� ���� ���� -  �������� : 0�� �� 
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
	// ����� �������� ����. 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>lab[i][j];
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(lab[i][j]==0) zero.push_back({i,j});	// ���� ������ ��ǥ ���Ϳ� ����  
		}
	}
	
	// ������ ���� �ڵ�� ... 
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
		copyLab(); // ������ ����  
		for(int i=0;i<N;i++){ // �湮 ���� Ȯ�� �迭 ��� false�� �ʱ�ȭ  
			for(int j=0;j<M;j++) check[i][j]=false; 
		}
		
		// ������ �̿��ؼ� ��(1) �����  
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				tmp[zero[i].first][zero[i].second]=1;
			}
		}
		// ���̷���(2)�̸鼭 �湮���� ���� ��ǥ��� dfs�� ���̷��� ������Ű��  
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(tmp[i][j]==2 && check[i][j]==false) bfs(i,j);
			}
		}
		// �������� ũ�� �ִ�ġ�� ����  
		ans = max(ans, countVirus());
	}while(next_permutation(ind.begin(), ind.end()));		
	
	// �� ���  
	cout<<ans;
}
