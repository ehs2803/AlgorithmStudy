#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> arr[1001];
bool visit[1001];

void dfs(int st) { 
    visit[st] = true;
    cout << st << ' ';
    for (int i = 0; i < arr[st].size(); i++) {
        int next = arr[st][i];
        if (visit[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int st) {
    queue<int> q;

    visit[st] = true;
    q.push(st);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (int i = 0; i < arr[node].size(); i++) {
            int next = arr[node][i];
            if (visit[next] == false) {
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    int n, m, st;
    cin >> n >> m >> st;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v); //인접행렬
        arr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) { // 각 정점마다 최소
        sort(arr[i].begin(), arr[i].end());
    }
    dfs(st); // 깊이우선
    cout << '\n';
    for (int i = 1; i <= 1000; i++) // 초기화
        visit[i] = false;
    bfs(st); // 너비우선
}
