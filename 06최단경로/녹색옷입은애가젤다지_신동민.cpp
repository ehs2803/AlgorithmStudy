#include<iostream>
#include<queue>
#define INF 1e9
using namespace std;

int n, cnt = 0;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int Dist[125][125];
int arr[125][125];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dijkstra() {
    Dist[0][0] = arr[0][0];
    pq.push({ Dist[0][0], {0, 0} });

    while (!pq.empty()) {
        int dist = pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                int ndist = dist + arr[nx][ny];
                if (ndist < Dist[nx][ny]) {
                    Dist[nx][ny] = ndist;
                    pq.push({ ndist, {nx, ny} });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    while (true) {
        cin >> n;
        if (n == 0) break; 

        // 입력  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                Dist[i][j] = INF;  
            }
        }
        dijkstra(); 

        int ans = Dist[n - 1][n - 1];
        cout << "Problem " << ++cnt << ": " << ans << '\n';
    }
}
