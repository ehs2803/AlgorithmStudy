// 다익스트라로도 풀 수 있음.  
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, K, X;
 
bool visited[300001]; // 노드 방문 여부  
int dist[300001];     // 출발노드에서 각 노드에 걸리는 거리  
vector<int> graph[300001];  

// BFS 함수 정의
void bfs(int start) {
    queue<pair<int, int> > q;
    q.push({start,0});
    
    // 현재 노드를 방문 처리
    visited[start] = true;
    
    // 큐가 빌 때까지 반복
    while(!q.empty()) {
    	// 큐에서 하나의 원소를 뽑아 출력
        int x = q.front().first;
        int cnt = q.front().second+1;
        q.pop();
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
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
	// 입출력 빨라지게 해줌. 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력  
    cin>>N>>M>>K>>X;
	
	// 그래프 노드, 간선 연결 입력  
    for(int i=0; i<M; i++){
    	int x, y;
    	cin>>x>>y;
    	graph[x].push_back(y);
	}
	
	// bfs 
	bfs(X);
	
	// 거리가 K인 노드 출력
	// 출력 않했다면 -1 출력  
	bool check=false;
	for(int i=1;i<=N;i++){
		if(dist[i]==K) {
			check=true;
			cout<<i<<'\n';
		}
	}
	if(check==false) cout<<-1;
}
