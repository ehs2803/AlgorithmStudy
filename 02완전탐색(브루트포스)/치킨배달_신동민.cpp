#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, temp, value;
int result = 99999999;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<bool> arr;

	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1)
				house.push_back({ i, j });
			else if (num == 2) {
				chicken.push_back({ i, j });
				arr.push_back(false);
			}
		}
	}

	for (int i = 0; i < m; i++)
		arr[i] = true;

	do {
		temp = 0;
		for (int i = 0; i < house.size(); i++) {
			int value = 99999999;
			for (int j = 0; j < chicken.size(); j++) {
				if (arr[j])
					value = min(value, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
			}
			temp += value; // 모든 집당 최소값 = 도시 거리
		}
		result = min(result, temp);
	} while (prev_permutation(arr.begin(), arr.end()));
	//prev 내림차순 next 오름차순
	cout << result;
}
