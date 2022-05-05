#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

int map_copy[8][8];
int N, M;
int answer = 0;
vector<pair<int, int>> virus;

void bfs(int row, int col) {
	queue<pair<int, int>> q;
	q.push({ row, col });

	while (!q.empty()) {
		int now_r = q.front().first;
		int now_c = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int next_r = now_r + dy[i];
			int next_c = now_c + dx[i];

			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M && map_copy[next_r][next_c] == 0) {
				q.push({ next_r, next_c });
				map_copy[next_r][next_c] = 2;
			}
		}
	}
}

void combination(int index, int start, int end, int map[][8]) {
	if (start == end) {
		copy(&map[0][0], &map[0][0] + 64, &map_copy[0][0]);

		int count = 0;
		for (int i = 0;i < virus.size();i++)
			bfs(virus[i].first, virus[i].second);

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (map_copy[i][j] == 0)
					count++;
			}
		}

		answer = max(answer, count);
		return;
	}

	for (int i = index;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (map[i][j] != 0) // 바이러스나 벽일 때
				continue;

			map[i][j] = 1;
			combination(i, start + 1, end, map);
			map[i][j] = 0;
		}
	}
}
int main() {
	int map[8][8];

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) // 바이러스의 좌표 저장
				virus.push_back({ i,j });
		}
	}

	combination(0, 0, 3, map);
	cout << answer;
	return 0;
}
