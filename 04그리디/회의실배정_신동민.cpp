#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
int n, cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int st, end;
	for (int i = 0; i < n; i++) {
		cin >> st >> end;
		arr.push_back({ end, st });
	}
	sort(arr.begin(), arr.end());

	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur <= arr[i].second) {
			cnt++;
			cur = arr[i].first;
		}
	}
	cout << cnt;
}
