#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int city[101][101];
int INF = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, m; // 도시의 개수, 버스의 개수
	cin >> n >> m;
	
	vector<vector<int> > city(n+1, vector<int>(n+1,INF));
	
	int a, b, c; 
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		city[a][b]= min(city[a][b], c);
	}
	
	for(int i=1;i<=n;i++)
		city[i][i] = 0;
		
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(city[i][k] + city[k][j] < city[i][j])
				city[i][j] = city[i][k] + city[k][j];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(city[i][j] == INF)
			cout << 0 << " ";
			else
			cout << city[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
