#include<iostream>
#include<queue>
#include<algorithm> // fill
using namespace std;

int map[50][50]; // map 
bool check[50][50]; // �湮 ����  

int dx[] ={-1,1,0,0};
int dy[] = {0,0,1,-1};

// bfs 
void bfs(int x, int y, int w, int h){
    queue<pair<int,int> > q;
    q.push({x,y});
    check[x][y]= true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){ // ��, ��, ��, �� ���⿡ ���ؼ�  
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(map[nx][ny]==0) continue; // 0�̸� �н�  
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue; // �� �������� ����� �н�  
            if(check[nx][ny]) continue; // �̹� �湮�� ��ǥ��� �н�  

            q.push({nx,ny});
            check[nx][ny]= true; // �湮 ó��  
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        fill(&map[0][0], &map[49][50], 0); // 2���� �迭 0���� �ʱ�ȭ  
        fill(&check[0][0], &check[49][50], false); // 2���� �迭 false�� �ʱ�ȭ  
        int w,h,k; cin>>w>>h>>k;
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            map[y][x]=1;
        }
        int cnt=0; // ���� �� ������ ��  
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(check[i][j]== false && map[i][j]==1){ // map�� 1�̰� �湮���� �������  
                    bfs(i,j,w,h); // bfs
                    cnt++; // ���� �� ������ ��  
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
