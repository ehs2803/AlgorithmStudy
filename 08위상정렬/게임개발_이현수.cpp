#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[501];
int indegree[501];
int time[501];
int totalTime[501];

void topology_sort(int n){
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0) {
        	q.push(i);
        	totalTime[i]=time[i];
		}
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

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
		cin>>time[i];
		while(true){
			int temp;
			cin>>temp;
			if(temp==-1) break;
			graph[temp].push_back(i);
			indegree[i]+=1;
		}
	}
	
	// 위상정렬  
	topology_sort(n);
	
	// 답 출력  
	for(int i=1;i<=n;i++) cout<<totalTime[i]<<'\n';
}
