#include<iostream>
#include<queue>
#include<algorithm> // fill
using namespace std;

int map[50][50]; // map 
bool check[50][50]; // 방문 여부  

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

        for(int i=0;i<4;i++){ // 상, 하, 좌, 우 방향에 대해서  
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(map[nx][ny]==0) continue; // 0이면 패스  
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue; // 맵 범위에서 벗어나면 패스  
            if(check[nx][ny]) continue; // 이미 방문한 좌표라면 패스  

            q.push({nx,ny});
            check[nx][ny]= true; // 방문 처리  
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        fill(&map[0][0], &map[49][50], 0); // 2차원 배열 0으로 초기화  
        fill(&check[0][0], &check[49][50], false); // 2차원 배열 false로 초기화  
        int w,h,k; cin>>w>>h>>k;
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            map[y][x]=1;
        }
        int cnt=0; // 배추 흰 지렁이 수  
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(check[i][j]== false && map[i][j]==1){ // map이 1이고 방문하지 않은경우  
                    bfs(i,j,w,h); // bfs
                    cnt++; // 배추 흰 지렁이 수  
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
