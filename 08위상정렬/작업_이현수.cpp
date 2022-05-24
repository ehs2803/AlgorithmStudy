#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[10001];
int time[10001];
int indegree[10001];
int totalTime[10001];
int ans;

void topology_sort(int n){
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0) {
        	q.push(i);
        	totalTime[i]=time[i];
        	ans = max(ans, totalTime[i]);
		}
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans = max(ans, totalTime[now]);

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
			indegree[next]-=1;
            totalTime[next]=max(totalTime[next], totalTime[now]+time[next]);
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
}

int main(){
	int n;
	cin>>n;
	// 입력  
	for(int i=1;i<=n;i++){
		int t; 
		cin>>t;
		time[i]=t;
		int cnt;
		cin>>cnt;
		for(int j=0;j<cnt;j++){
			int temp;
			cin>>temp;
			graph[temp].push_back(i);
			indegree[i]+=1;
		}
	}
	
	topology_sort(n);
	
	// 답 출력  
	cout<<ans;
}
