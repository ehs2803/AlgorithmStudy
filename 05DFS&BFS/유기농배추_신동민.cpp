#include<iostream>
#include<queue>
using namespace std;

int t, m, n, k;
int cnt;
int map[50][50];
bool check[50][50];
// 방향 이동
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (map[x][y] == 0 || check[x][y] == true) return; 
    check[x][y] = true;

    // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);
}
void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push({ x, y });
    check[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == 1 && check[nx][ny] == false) {             
                    q.push({ nx,ny });
                    check[nx][ny] = true;
                }
            }  
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k; // 가로y 세로x 배추

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            map[y][x]=1;
        }

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (check[j][l] == false && map[j][l] == 1) {
                    bfs(j, l);
                    //dfs(j, l);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                check[i][j] = false;
                map[i][j] = 0;
            }
        }
        cnt = 0;
    }
}
