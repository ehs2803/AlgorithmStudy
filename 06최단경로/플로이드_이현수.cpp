#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

int graph[101][101];

int main(){
    int v; cin>>v;
    int e; cin>>e;
    
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INF;
        }
    }
    
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(graph[u][v]>w) graph[u][v]=w;
    }
    
    // 플로이드 워셜 알고리즘
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(graph[i][j]==INF) cout<<0<<' ';
            else cout<<graph[i][j]<<' ';
        }
        cout<<'\n';
    }
}
