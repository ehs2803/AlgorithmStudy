#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int map[25][25]; // map  
bool visited[25][25]; // �湮 ����  
int n;


// dfs
void dfs(int x, int y, int cnt){
	// �־��� ������ ����� ��쿡�� ��� ����
    if (x <= -1 || x >=n || y <= -1 || y >= n)  return;
    if(map[x][y]==0) { // ���� ������ ��  
    	visited[x][y]=true; // �湮ó�� 
    	return; // ����  
	}
    if(visited[x][y]==true) return; // �̹� �湮�� ���̶�� ����  
    
    visited[x][y]=true; // �湮ó�� �ϱ� 
	 
    // ���� ��ǥ�� ���� �������� ���� ���̶��   
    if(map[x][y]==1) map[x][y]=cnt;
    
	// ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
    dfs(x - 1, y, cnt);
    dfs(x, y - 1, cnt);
    dfs(x + 1, y, cnt);
    dfs(x, y + 1, cnt); 

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
				dfs(i,j,cnt); // bfs + �� ������ ������ ���� ����  
				 
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
	sort(houseCnts.begin(), houseCnts.end()); // ������ ���� �� �������� ����  
	cout<<cnt<<'\n'; // ���� �� ���  
	for(int i=0;i<houseCnts.size();i++){ // ���� �� ���� �� ���  
		cout<<houseCnts[i]<<'\n';
	}
}
