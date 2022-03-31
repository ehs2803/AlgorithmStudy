#include <iostream>
#include <vector>
using namespace std;

int n, s; // 원하는 값=s
int cnt = 0;
vector<int> arr;

void subsequence(int index, int sum) {
	if (index == n) {
		return;
	}
	if (sum + arr[index] == s) {
		cnt++;
	}
	subsequence(index + 1, sum + arr[index]);
	subsequence(index + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	//부분수열의 합
	subsequence(0, 0);
	cout << cnt;
}
