#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[25][25]; // map  
bool visited[25][25]; // 방문 여부  
int n;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// bfs 
int bfs(int sx, int sy){
	int housecnt=0; // 단지내 가구 수 저장 변수  
	queue<pair<int,int> > q;
	q.push({sx, sy});
	visited[sx][sy]=true; // 방문 처리 
	housecnt++; // 단지 내 가구수 1 증가  
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){ // 상, 하, 좌, 우 방향에 대하여  
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < n){ // 새로운 좌표가 주어진 map범위 내에 있을경우에만 
				if(map[nx][ny]==1 && visited[nx][ny]==false){ // map이 1이고 방문하지 않은 경우  
					visited[nx][ny]=true; // 방문처리  
					housecnt++; // 단지 내 가구수 1 증가  
					q.push({nx,ny});
				}
			}
		}
			
	}
	
	return housecnt; // 단지내 가구 수 리턴  
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
				int houseCnt = bfs(i,j); // bfs + 그 단지내 가구수 리턴 받음  
				houseCnts.push_back(houseCnt); // 단지내 가구 수 벡터에 저장  
			}
		}
	}	
	
	sort(houseCnts.begin(), houseCnts.end()); // 단지내 가구 수 오름차순 정렬  
	cout<<cnt<<'\n'; // 단지 수 출력  
	for(int i=0;i<houseCnts.size();i++){ // 단지 내 가구 수 출력  
		cout<<houseCnts[i]<<'\n';
	}
}
