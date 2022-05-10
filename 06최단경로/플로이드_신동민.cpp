#include<iostream>
#define INF 987654321
using namespace std;

int n, m;
int graph[101][101];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c) graph[a][b] = c;
    }

    // 플로이드 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) cout << 0 << ' ';
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}
