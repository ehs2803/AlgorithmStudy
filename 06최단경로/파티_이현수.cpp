#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

vector<pair<int,int> > graph[1001];
int Dist[1001];

// ���ͽ�Ʈ��  
void dijkstra(int start){
    priority_queue<pair<int , int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // �ּ���  
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
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	 
	int n,m,x;
	cin>>n>>m>>x;
	
	// �Է�  
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
	}	
	
	int ans=0; // ���� ���� ����  
	
	// ��� �л��� ����  
	for(int i=1;i<=n;i++){
		int temp=0;
		// ��Ƽ�� x���� ���� �Ÿ�  
		for (int i = 1; i <= n; i++) Dist[i] = INF;
		dijkstra(i);
		temp+=Dist[x];
		
		// ��Ƽ�� x���� ������ ���ƿ��� �Ÿ�  
		for (int i = 1; i <= n; i++) Dist[i] = INF;
		dijkstra(x);
		temp+=Dist[i];
		
		// �ִ����� ����  
		if(ans<temp) ans=temp;
	}
	
	// �� ���
	cout<<ans; 
}
