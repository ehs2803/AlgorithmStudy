// 참고 
// https://hyeo-noo.tistory.com/161 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9+7//1001

//typedef pair<int, int> p;
#define p pair<int, int>
int N, E; // (2 ≤정점N ≤ 800, 0 ≤간선E ≤ 200,000) 
int v1, v2; // 꼭 거쳐야 하는 정점 
vector<p> graph[801];
vector<int> dist;


int dijkstra(int st, int ed){
	dist = vector<int>(N+1, INF);
	priority_queue<p, vector<p > , greater<p > >pq; 
	// 최소값부터 pop하기 위한 작업 
	pq.push(make_pair(0, st));
	
	dist[st] = 0; 
	
	while(!pq.empty()){
		int now = pq.top().second; // 최소값 
		int w = pq.top().first; 
		pq.pop();
		
		if(w > dist[now]) continue;
		
		for(int i=0;i<graph[now].size(); i++){
			int next = graph[now][i].second;
			int next_w = graph[now][i].first + w;
			
			if (next_w < dist[next]){
				dist[next] = next_w;
				pq.push(make_pair(next_w, next));
			}
		}
	}
	
	return dist[ed];
}

int main(){
	cin >> N >> E;
	int a, b, c;
	int gov1, gov2;
	for (int i=0;i<E;i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	cin >> v1 >> v2; 
	
	int a1 = dijkstra(1, v1);
	int a2 = dijkstra(v1, v2);
	int a3 = dijkstra(v2, N);
	if (a1 == INF || a2 == INF || a3 == INF) gov1 = INF;
	else gov1 = a1 + a2 + a3;
	
	int b1 = dijkstra(1, v2);
	int b2 = dijkstra(v2, v1);
	int b3 = dijkstra(v1, N);
	if (b1 == INF || b2 == INF || b3 == INF) gov2 = INF;
	else gov2 = b1 + b2 + b3;
	
	if (gov1 == INF && gov2 == INF) cout << -1;
	else cout << min(gov1, gov2);
}
