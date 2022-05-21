#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 각 선수강 수, 학기결과
int cnt[1001], result[1001];
// 인접행렬
vector<int> vec[1001];
int n, m;

void topology_sort() {
    queue<int> q;
    // 처음 지점 추가
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            result[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        // 다음 지점 탐색
        for (int i = 0; i < vec[cur].size(); i++) {
            int nxt = vec[cur][i];
            cnt[nxt]--;
            if (cnt[nxt] == 0) {
                result[nxt] = result[cur] + 1;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << result[i] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        cnt[b]++;
    }
    topology_sort();
}
