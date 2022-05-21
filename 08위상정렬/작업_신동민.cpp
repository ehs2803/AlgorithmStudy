#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 각 선작업 수, 작업 비용, 작업결과
int cnt[10001], cost[10001], result[10001];
// 인접행렬
vector<int> vec[10001];
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
            result[nxt] = max(result[nxt], result[cur] + cost[nxt]); // 여러 작업중 가장 늦게 끝나는 시간으로 설정
            if (cnt[nxt] == 0) { // 다음 지점 추가
                q.push(nxt);
            }
        }
    }
    int ans = *max_element(result, result+(n+1));
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < b; j++) {
            int c;  cin >> c;
            vec[c].push_back(i);
            cnt[i]++;
        }
        cost[i] = a;
    }
    topology_sort();
}
