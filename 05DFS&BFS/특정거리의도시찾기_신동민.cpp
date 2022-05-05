#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[300001];
int dist[300001];

void bfs(int st) {
    queue<int> q;

    dist[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][i];
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v); //인접행렬
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    bfs(x); // 너비우선
    bool check = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            check = true;
            cout << i << "\n";
        }
    }
    if (!check)
        cout << "-1";
}
