#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
#define INF 1e9
using namespace std;

int n, m, x;
vector<pair<int, int>> Graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int Dist[1001];
int arr[1001];

void dijkstra(int start) {
    fill(Dist, Dist + n + 1, INF);
    Dist[start] = 0;
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

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        Graph[from].push_back({ to, dist });
    }

    // 각 지점에서 X까지 가는 길  
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        dijkstra(i);
        arr[i] = Dist[x];
    }
    // X에서 지점까지 가는 길
    dijkstra(x);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < Dist[i] + arr[i])
            ans = Dist[i] + arr[i];
    }
    cout << ans << "\n";
}
