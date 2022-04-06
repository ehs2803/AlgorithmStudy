#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n - 1; i++) {
		cin >> num;
		dist.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	long long sum = 0;
	long long min = 1000000000;
	for (int i = 0; i < n - 1; i++) {
		if (min > arr[i])
			min = arr[i];
		sum += min * dist[i];
	}
	cout << sum;
}
