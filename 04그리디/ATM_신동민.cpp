#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		result += arr[i] * (n - i);
	}
	cout << result;
}
