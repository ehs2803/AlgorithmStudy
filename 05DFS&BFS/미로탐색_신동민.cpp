#include<iostream>
#include<queue>
using namespace std;

int n, m;
char map[100][100];
bool check[100][100];

int dist[100][100]; // 거리 - bfs 
int dfs_ans = INT_MAX; // 거리 - dfs 

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int depth) {
    // 스택 이용가능 = 재귀
    if (x <= -1 || x >= n || y <= -1 || y >= m)  return; // 맵 범위 벗어난 경우 
    if (x == n - 1 && y == m - 1) {
        if (depth < dfs_ans) {
            dfs_ans = depth;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (map[nx][ny] == '1' && check[nx][ny] == false) {
            check[nx][ny] = true;
            dfs(nx, ny, depth + 1);
            check[nx][ny] = false;
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    dist[x][y] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == '1' && check[nx][ny] == false) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    //bfs(0, 0);
    //cout << dist[n - 1][m - 1];
    dfs(0,0,1);
    cout<<dfs_ans;
}
