#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;

bool find_sudoku = false;
vector<pair<int, int>> num;
vector<vector<int>> arr(9, vector<int>(9));

bool check(pair<int, int> p) {
	int row = p.x / 3;
	int col = p.y / 3;

	for (int i = 0; i < 9; i++) {
		if (arr[i][p.y] == arr[p.x][p.y] && i != p.x)	return false;
		if (arr[p.x][i] == arr[p.x][p.y] && i != p.y)	return false;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(arr[(row*3)+i][(col*3)+j] == arr[p.x][p.y] && (row * 3) + i != p.x && (col * 3) + j != p.y)	return false;
		}
	}
	return true;
}

void sudoku(int n) {
	if (n == num.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)	cout << arr[i][j] << " ";
			cout << "\n";
		}
		find_sudoku = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		arr[num[n].x][num[n].y] = i;

		if (check(num[n]))	sudoku(n + 1);
		if (find_sudoku)	return;
	}
	arr[num[n].x][num[n].y] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)	num.push_back({ i, j });
		}
	}
	sudoku(0);
}
