#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	//vector<vector<char>> arr(n, vector<char>(m));
	vector<vector<int>> arr(n, vector<int>(m));
	char color;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> color;
			//arr[i][j] = color;
			if (color == 'B') arr[i][j] = 0; // 블랙 = 처음
			else arr[i][j] = 1;				 // 화이트 = 나중
		}
	}

	int row = n-8, col = m-8;
	int indr = 0, indc = 0;
	int result = 999999;
	while (true)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = indr; i < 8 + indr; i++) {
			for (int j = indc; j < 8 + indc; j++) {
				//if ((i + j) % 2 == 0)	   // 처음
				//{
				//	if (arr[i][j] != 'B')  // 블랙/화이트
				//		cnt1++;
				//	else                   // 화이트/블랙
				//		cnt2++; 
				//}  
				//else {			       // 나중
				//	if (arr[i][j] != 'W') 
				//		cnt1++;	
				//	else
				//		cnt2++;
				//}					
				if ((i + j) % 2 == arr[i][j]) // 블랙(0)/화이트(1)
					cnt1++;
				else						 // 화이트(0)/블랙(1)
					cnt2++;
			}
		}
		result = min(result, min(cnt1, cnt2));
		indc++;
		if (indc > col) {
			indr++;
			indc = 0;
		}
		if (indr > row)
			break;
	}
	cout << result;
}
