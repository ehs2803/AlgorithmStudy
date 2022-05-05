#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, result = 0;
int map[8][8];
int temp[8][8];
vector<pair<int, int>> poison;

// 방향 이동
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    if (temp[x][y] == 1) return;
   
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                dfs(nx, ny);
            }
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < poison.size(); i++)
        q.push(poison[i]);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (temp[nx][ny] == 0) {
                    temp[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int counter() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0)
                cnt += 1;
        }
    }
    return cnt;
}

void wall(int x, int depth) {
    if (depth == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = map[i][j];
            }
        }

        //bfs();
        for (int i = 0; i < poison.size(); i++) {
            dfs(poison[i].first, poison[i].second);
        }

        result = max(result, counter());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1; // 벽 세우기 
                wall(i, depth + 1); // 벽 수 증가 
                map[i][j] = 0; // 초기화 
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2)
                poison.push_back(make_pair(i, j));
        }
    }

    wall(0, 0);
    cout << result;
}
