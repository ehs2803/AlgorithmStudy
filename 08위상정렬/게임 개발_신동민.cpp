#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 각 선개발 수, 개발 시간, 개발결과
int cnt[501], cost[501], result[501];
// 인접행렬
vector<int> vec[501];
int n;

void topology_sort() {
    queue<int> q;
    // 처음 지점 추가
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            result[i] = cost[i];
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
            result[nxt] = max(result[nxt], result[cur] + cost[nxt]);
            if (cnt[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a;
        cost[i] = a;

        while (true)
        {
            cin >> b;
            if (b == -1)
                break;
            vec[b].push_back(i);
            cnt[i]++;
        }
    }
    topology_sort();
}
