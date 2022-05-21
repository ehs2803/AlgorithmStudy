#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 각 선작업 수
int cnt[32001];
// 인접행렬
vector<int> vec[32001];
int n, m;

void topology_sort() {
    queue<int> q;
    // 처음 지점 추가
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        // 다음 지점 탐색
        for (int i = 0; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i];
            cnt[nxt]--;
            if (cnt[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        cnt[b]++;
    }
    topology_sort();
}
