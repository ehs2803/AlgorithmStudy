#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int testcase, m, n, k;
bool a[51][51];
bool check[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool dfs(int y, int x){
	if (check[y][x]) return false;
	check[y][x] = true;
	
	for(int i=0;i<4;i++){
		int xx = x+dx[i]; int yy = y+dy[i];
		if(xx >= 0 && yy >= 0 && xx < m && yy < n && a[yy][xx]) dfs(yy, xx);
	}
	return true;
}

int main(){
	cin >> testcase;
	for (int i=0;i<testcase;i++){
		scanf("%d %d %d" ,&m ,&n ,&k);
		memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));  // 변수 초기화 

		
		for (int j=0;j<k;j++){
			int x=0, y=0;
			scanf("%d %d",&x,&y);
			a[y][x] = 1;
		}
		
		int cnt = 0;
		
		for (int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				if (a[j][k] && !check[j][k]){
					if (dfs(j, k)) cnt ++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
