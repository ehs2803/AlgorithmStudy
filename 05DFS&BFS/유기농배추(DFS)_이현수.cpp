#include<iostream>
#include<algorithm> // fill
using namespace std;

int w,h;

int map[50][50]; // map 
bool check[50][50]; // �湮 ����  

// dfs
void dfs(int x, int y){
    // �־��� ������ ����� ��쿡�� ��� ���� 
    if(x<0 || y<0 || x>=h || y>=w) return;
    if(map[x][y]==0) { // ���� ������ ��  
    	check[x][y]=true; // �湮ó�� 
    	return; // ����  
	}
    if(check[x][y]==true) return; // �̹� �湮�� ���̶�� ����  
    
    map[x][y]=0;
    check[x][y]=true; // �湮ó�� �ϱ� 
	 
    // ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x, y + 1);

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        fill(&map[0][0], &map[49][50], 0); // 2���� �迭 0���� �ʱ�ȭ  
        fill(&check[0][0], &check[49][50], false); // 2���� �迭 false�� �ʱ�ȭ  
        int k; cin>>w>>h>>k;
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            map[y][x]=1;
        }
        int cnt=0; // ���� �� ������ ��  
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(check[i][j]== false && map[i][j]==1){ // map�� 1�̰� �湮���� ������� 
                    dfs(i,j); // dfs
                    cnt++; // ���� �� ������ ��  
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
