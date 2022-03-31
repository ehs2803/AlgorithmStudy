#include <iostream>
#include <vector>
using namespace std;

vector<int> arr1; // 세로
vector<int> arr2; // 대각선1
vector<int> arr3; // 대각선2
int cnt = 0;
int n;

void N_Queen(int row) {

	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr1[i] == 0 && arr2[row+i] == 0 && arr3[n-1+row-i] == 0) {
			arr1[i] = 1; arr2[row + i] = 1; arr3[n - 1 + row - i] = 1;
			N_Queen(row + 1);
			arr1[i] = 0; arr2[row + i] = 0; arr3[n - 1 + row - i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr1.push_back(0);
	}

	for (int i = 0; i < 2 * n - 1; i++) {
		arr2.push_back(0);
		arr3.push_back(0);
	}
	N_Queen(0);
	cout << cnt;
}
