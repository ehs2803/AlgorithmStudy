#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, cnt = 0;
int map[25][25];
bool check[25][25];
vector<int> result;

// 방향 이동
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int cnt){
    if (x <= -1 || x >=n || y <= -1 || y >= n)  return;
    if(map[x][y]==0 || check[x][y] == true) return;

    check[x][y] = true;
    if(map[x][y]==1) map[x][y]=cnt;
    
    dfs(x - 1, y, cnt);
    dfs(x, y - 1, cnt);
    dfs(x + 1, y, cnt);
    dfs(x, y + 1, cnt); 

}

void bfs() {
    queue<pair<int, int> > q;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && check[i][j] == false) {
                int house = 1; // 단지내 가구 수  
                q.push(make_pair(i, j));
                check[i][j] = true;
                cnt++;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (map[nx][ny] == 1 && check[nx][ny] == false) {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                                house++;
                            }
                        }
                    }
                }
                result.push_back(house);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }

    //bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && check[i][j] == false) {
                cnt++; // 단지 수 
                dfs(i, j, cnt); 
            }
        }
    }
    for (int k = 1; k <= cnt; k++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == k) count++;
            }
        }
        result.push_back(count);
    }
    sort(result.begin(), result.end());
    cout << cnt << "\n";
    for (int i = 0; i < result.size(); i++) {
  		cout << result[i] << "\n";
    }
}
