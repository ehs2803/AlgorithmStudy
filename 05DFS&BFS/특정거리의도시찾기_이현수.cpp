// ���ͽ�Ʈ��ε� Ǯ �� ����.  
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, K, X;
 
bool visited[300001]; // ��� �湮 ����  
int dist[300001];     // ��߳�忡�� �� ��忡 �ɸ��� �Ÿ�  
vector<int> graph[300001];  

// BFS �Լ� ����
void bfs(int start) {
    queue<pair<int, int> > q;
    q.push({start,0});
    
    // ���� ��带 �湮 ó��
    visited[start] = true;
    
    // ť�� �� ������ �ݺ�
    while(!q.empty()) {
    	// ť���� �ϳ��� ���Ҹ� �̾� ���
        int x = q.front().first;
        int cnt = q.front().second+1;
        q.pop();
        // �ش� ���ҿ� �����, ���� �湮���� ���� ���ҵ��� ť�� ����
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(visited[y]==false) {
            	dist[y]=cnt;
            	visited[y] = true;
                q.push({y,cnt});
            }
        }
    }
}

int main(){
	// ����� �������� ����. 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // �Է�  
    cin>>N>>M>>K>>X;
	
	// �׷��� ���, ���� ���� �Է�  
    for(int i=0; i<M; i++){
    	int x, y;
    	cin>>x>>y;
    	graph[x].push_back(y);
	}
	
	// bfs 
	bfs(X);
	
	// �Ÿ��� K�� ��� ���
	// ��� ���ߴٸ� -1 ���  
	bool check=false;
	for(int i=1;i<=N;i++){
		if(dist[i]==K) {
			check=true;
			cout<<i<<'\n';
		}
	}
	if(check==false) cout<<-1;
}
