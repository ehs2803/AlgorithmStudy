#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
#define INF 1e9
using namespace std;

int n, e;
vector<pair<int, int>> Graph[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int Dist[801];

void dijkstra(int start) {
	fill(Dist, Dist + n + 1, INF);
    Dist[start] = 0;
	//첫 번째 길이, 두 번째 정점
	pq.push({ Dist[start],start });

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (Dist[cur.second] < cur.first) continue;
        for (auto nxt : Graph[cur.second]) {
            if (Dist[nxt.first] > Dist[cur.second] + nxt.second) {
                Dist[nxt.first] = Dist[cur.second] + nxt.second;
                pq.push({ Dist[nxt.first], nxt.first });
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        Graph[from].push_back({ to, dist});
        Graph[to].push_back({ from, dist});

    }

    int v1, v2;
    cin >> v1 >> v2;

    dijkstra(1); //1 ->v1 또는 1->v2 
    int d1_v1 = Dist[v1];
    int d1_v2 = Dist[v2];

    dijkstra(v1); //v1 -> v2 또는 v1 -> N
    int dv1_v2 = Dist[v2];
    int dv1_n = Dist[n];

    dijkstra(v2); //v2 -> v1 또는 v2 -> N
    int dv2_n = Dist[n];
    int dv2_v1 = Dist[v1];

    int sum1 = d1_v1 + dv1_v2 + dv2_n;
    int sum2 = d1_v2 + dv2_v1 + dv1_n;

    int ans = min(sum1, sum2);
    if (ans >= INF) cout << -1;
    else cout << ans;
}
