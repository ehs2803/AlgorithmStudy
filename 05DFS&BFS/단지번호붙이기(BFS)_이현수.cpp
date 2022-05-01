#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[25][25]; // map  
bool visited[25][25]; // �湮 ����  
int n;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

// bfs 
int bfs(int sx, int sy){
	int housecnt=0; // ������ ���� �� ���� ����  
	queue<pair<int,int> > q;
	q.push({sx, sy});
	visited[sx][sy]=true; // �湮 ó�� 
	housecnt++; // ���� �� ������ 1 ����  
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){ // ��, ��, ��, �� ���⿡ ���Ͽ�  
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < n){ // ���ο� ��ǥ�� �־��� map���� ���� ������쿡�� 
				if(map[nx][ny]==1 && visited[nx][ny]==false){ // map�� 1�̰� �湮���� ���� ���  
					visited[nx][ny]=true; // �湮ó��  
					housecnt++; // ���� �� ������ 1 ����  
					q.push({nx,ny});
				}
			}
		}
			
	}
	
	return housecnt; // ������ ���� �� ����  
}

int main(){
	cin>>n;
    string str;
    
    // �Է�  
    for(int i = 0; i<n; i++){
        cin >> str;
        for(int j = 0; j<str.length(); j++){             
            if(str[j] == '1'){
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }
	
	int cnt=0; // ���� �� ���� ����  
	vector<int> houseCnts; // ������ ���� �� ���� ����  
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==1 && visited[i][j]==false){ // map�� 1�̸鼭 �湮���� ������� 
				cnt++; // ���� �� 1 ����  
				int houseCnt = bfs(i,j); // bfs + �� ������ ������ ���� ����  
				houseCnts.push_back(houseCnt); // ������ ���� �� ���Ϳ� ����  
			}
		}
	}	
	
	sort(houseCnts.begin(), houseCnts.end()); // ������ ���� �� �������� ����  
	cout<<cnt<<'\n'; // ���� �� ���  
	for(int i=0;i<houseCnts.size();i++){ // ���� �� ���� �� ���  
		cout<<houseCnts[i]<<'\n';
	}
}
