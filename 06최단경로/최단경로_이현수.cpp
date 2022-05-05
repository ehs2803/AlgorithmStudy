#include <iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int,int> > graph[20001];
int Dist[20001];

void dijkstra(int start){
    priority_queue<pair<int , int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,start});
    Dist[start]=0;

    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(Dist[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost< Dist[graph[now][i].first]){
                Dist[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int V,E; cin>>V>>E;
    //fill(Dist, Dist+V+1, INF);
    for (int i = 1; i <= V; i++) Dist[i] = INF;
    int start; cin>>start;
    for(int i=0;i<E;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    dijkstra(start);
    for(int i=1;i<=V;i++) {
        if(Dist[i]==INF) cout<<"INF"<<'\n';
        else cout<<Dist[i]<<'\n';
    }
}

/*
#include <iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int,int>> graph[20001];
int Dist[20001];

void dijkstra(int start){
    priority_queue<pair<int , int>> pq;
    pq.push({0,start});
    Dist[start]=0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(Dist[now]<dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost< Dist[graph[now][i].first]){
                Dist[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int V,E; cin>>V>>E;
    //fill(Dist, Dist+V+1, INF);
    for (int i = 1; i <= V; i++) Dist[i] = INF;
    int start; cin>>start;
    for(int i=0;i<E;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    dijkstra(start);
    for(int i=1;i<=V;i++) {
        if(Dist[i]==INF) cout<<"INF"<<'\n';
        else cout<<Dist[i]<<'\n';
    }
}
*/
