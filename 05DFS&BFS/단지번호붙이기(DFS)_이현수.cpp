#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[25][25]; // map  
bool visited[25][25]; // 방문 여부  
int n;


// dfs
void dfs(int x, int y, int cnt){
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >=n || y <= -1 || y >= n)  return;
    if(map[x][y]==0) { // 벽을 만났을 때  
    	visited[x][y]=true; // 방문처리 
    	return; // 종료  
	}
    if(visited[x][y]==true) return; // 이미 방문한 곳이라면 종료  
    
    visited[x][y]=true; // 방문처리 하기 
	 
    // 현재 좌표가 아직 오염되지 않은 곳이라면   
    if(map[x][y]==1) map[x][y]=cnt;
    
	// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
    dfs(x - 1, y, cnt);
    dfs(x, y - 1, cnt);
    dfs(x + 1, y, cnt);
    dfs(x, y + 1, cnt); 

}

int main(){
	cin>>n;
    string str;
    
    // 입력  
    for(int i = 0; i<n; i++){
        cin >> str;
        for(int j = 0; j<str.length(); j++){             
            if(str[j] == '1'){
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }
	
	int cnt=0; // 단지 수 저장 변수  
	vector<int> houseCnts; // 단지내 가구 수 저장 벡터  
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==1 && visited[i][j]==false){ // map이 1이면서 방문하지 않은경우 
				cnt++; // 단지 수 1 증가  
				dfs(i,j,cnt); // bfs + 그 단지내 가구수 리턴 받음  
				 
			}
		}
	}	
	
	for(int k=1;k<=cnt;k++){
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==k) count++;
			}
		}
		houseCnts.push_back(count);
	}
	sort(houseCnts.begin(), houseCnts.end()); // 단지내 가구 수 오름차순 정렬  
	cout<<cnt<<'\n'; // 단지 수 출력  
	for(int i=0;i<houseCnts.size();i++){ // 단지 내 가구 수 출력  
		cout<<houseCnts[i]<<'\n';
	}
}
