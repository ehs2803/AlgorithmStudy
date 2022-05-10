#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

int v, e;
vector<pair<int, int>> Graph[20001];
int Dist[20001];

// 다익스트라  
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0,start });
	Dist[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (Dist[now] < dist) continue;
		for (int i = 0; i < Graph[now].size(); i++) {
			int cost = dist + Graph[now][i].second;
			if (cost < Dist[Graph[now][i].first]) {
				Dist[Graph[now][i].first] = cost;
				pq.push({ cost, Graph[now][i].first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cout.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) Dist[i] = INF;
	int start; cin >> start;

	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		Graph[from].push_back({ to, dist });
	}
	dijkstra(start);

	for (int i = 1; i <= v; i++) {
		if(Dist[i] == INF) 	cout << "INF" << "\n";
		else cout << Dist[i] << "\n";
	}
}
