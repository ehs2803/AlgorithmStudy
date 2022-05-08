#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int,int> > graph[1001];
int Dist[1001];

// 다익스트라  
void dijkstra(int start){
    priority_queue<pair<int , int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // 최소힙  
    pq.push({0,start});
    Dist[start]=0;

    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(Dist[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost< Dist[graph[now][i].first]){
                Dist[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	 
	int n,m,x;
	cin>>n>>m>>x;
	
	// 입력  
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
	}	
	
	int ans=0; // 정답 저장 변수  
	
	// 모든 학생에 대해  
	for(int i=1;i<=n;i++){
		int temp=0;
		// 파티장 x까지 가는 거리  
		for (int i = 1; i <= n; i++) Dist[i] = INF;
		dijkstra(i);
		temp+=Dist[x];
		
		// 파티장 x에서 집까지 돌아오는 거리  
		for (int i = 1; i <= n; i++) Dist[i] = INF;
		dijkstra(x);
		temp+=Dist[i];
		
		// 최댓값으로 갱신  
		if(ans<temp) ans=temp;
	}
	
	// 답 출력
	cout<<ans; 
}
