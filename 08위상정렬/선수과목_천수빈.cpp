#include <vector>
#include <iostream>
#include <queue>
#define MAX 1001  // 최대 노드 개수 
using namespace std;

int n, m, inDegree[MAX]; 
vector<int> a[MAX];
int result[MAX];

void topologySort(){
   queue<int> q;
   
   // 진입차수가 0인 노드들 큐에 추가 
   for (int i=1;i<=n;i++){
      if(inDegree[i] == 0){
      	q.push(i) ;
	  } 
	  result[i] = 1;
   }
   
   for(int i=1;i<=n;i++){
	   	if(q.empty()){
				cout << "cycle !!"; // 싸이클 발생 
				return;
		}
	   
	   int x = q.front();   
	   q.pop();              
	    
	   for (int i=0;i<a[x].size();i++){
	   	
	   		int y = a[x][i];
	   		
	   		// 진입차수--, 이때 진입차수가  0이되면 q에 삽입 
	   		if(--inDegree[y] == 0) {
	   			q.push(y);
	   			result[y] = max(result[y], result[x] + 1);
			}
	   }
	
   }
   
   for (int i=1;i<=n;i++){
   		cout << result[i] << " ";
   }
   
}
 
 
int main(){
   cin >> n >> m;

   for (int i=0;i<m;i++){
   		int x, y;
   		cin >> x >> y;
   		a[x].push_back(y);
   		inDegree[y]++; // 진입차수 증가 
   }
   
   topologySort();

   
}
