#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include <numeric>
#include<queue>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0,0 };


void bfs(int **graph ,int x , int y ,int n, int m) {
    queue<pair<int,int >> q;
    
    q.push(make_pair(x,y));
    graph[y][x] = 0;
    
    while (!q.empty()) {
        // 큐에 값이 있을경우 계속 반복 실행
        // 큐에 값이 있다. => 아직 방문하지 않은 노드가 존재 한다. 
        auto tmp = q.front();
        q.pop();

        x = tmp.first;
        y = tmp.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }

            if (graph[ny][nx] == 0)
                continue;

            if (graph[ny][nx] == 1)
            {
                //cout << nx << " " << ny << "\n";
                graph[ny][nx] = 0;
                q.push(make_pair(nx, ny));
            }
        }
    }
}


int main(void)
{
	queue<int> q;
	int T,M,N,K;
    int m, n;

	cin >> T;

    int* res = new int[T+1];

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        
        int **graph = new int*[N];
        for (int t = 0; t < N; t++)
            graph[t] = new int[M] {0};

       

        for (int k = 0; k < K; k++) {

            cin >> m >> n;
            graph[n][m] = 1;
        }

        int cnt = 0;
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < M; c++)
            {
                if (graph[r][c] == 1)
                {
                    bfs(graph, c, r, N, M);
                    cnt += 1;
                }
            }
        }
        res[i] = cnt;
        

    }
    for (int t = 0; t < T; t++)
    {
        cout << res[t] << "\n";
    }

	return 0;
}
