#include<iostream>
#include<algorithm> // fill
using namespace std;

int w,h;

int map[50][50]; // map 
bool check[50][50]; // 방문 여부  

// dfs
void dfs(int x, int y){
    // 주어진 범위를 벗어나는 경우에는 즉시 종료 
    if(x<0 || y<0 || x>=h || y>=w) return;
    if(map[x][y]==0) { // 벽을 만났을 때  
    	check[x][y]=true; // 방문처리 
    	return; // 종료  
	}
    if(check[x][y]==true) return; // 이미 방문한 곳이라면 종료  
    
    map[x][y]=0;
    check[x][y]=true; // 방문처리 하기 
	 
    // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
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
        fill(&map[0][0], &map[49][50], 0); // 2차원 배열 0으로 초기화  
        fill(&check[0][0], &check[49][50], false); // 2차원 배열 false로 초기화  
        int k; cin>>w>>h>>k;
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            map[y][x]=1;
        }
        int cnt=0; // 배추 흰 지렁이 수  
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(check[i][j]== false && map[i][j]==1){ // map이 1이고 방문하지 않은경우 
                    dfs(i,j); // dfs
                    cnt++; // 배추 흰 지렁이 수  
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
