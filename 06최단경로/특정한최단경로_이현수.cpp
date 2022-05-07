#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int,int> > graph[801];
int Dist[801];

// 다익스트라  
void dijkstra(int start){
    priority_queue<pair<int , int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
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
	int n, e; 
	cin>>n>>e;
	
	// 입력  
	for(int i=0;i<e;i++){
		int u,v,w; 
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	
	int v1, v2;
	cin>>v1>>v2;
	
	int ans1=0, ans2=0; // 정답 저장 변수  
	
	// 1번 경우 ( 1 -> v1 -> v2 -> n ) 
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(1);
	int d1_1 = Dist[v1];
	
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(v1);
	int d1_2 = Dist[v2];
	
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(v2);
	int d1_3 = Dist[n];
	
	if(d1_1==INF || d1_2==INF || d1_3==INF) ans1 = INF;
	else ans1 = d1_1+d1_2+d1_3;
	
	
	// 2번 경우 ( 1 -> v2 -> v1 -> n ) 
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(1);
	int d2_1 = Dist[v2];
	
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(v2);
	int d2_2 = Dist[v1];
	
	for (int i = 1; i <= n; i++) Dist[i] = INF;
	dijkstra(v1);
	int d2_3 = Dist[n];
	
	if(d2_1==INF || d2_2==INF || d2_3==INF) ans2 = INF;
	else ans2 = d2_1+d2_2+d2_3;
	
	// 답 출력  
	if(ans1==INF && ans2==INF) cout<<-1;
	else if(ans1!=INF && ans2!=INF) cout<<min(ans1,ans2);
	else if(ans1!=INF) cout<<ans1;
	else cout<<ans2;
	
}
