//작업
#include <vector>
#include <iostream>
#include <queue>
#define MAX 10001  // 최대 노드 개수 
using namespace std;


int n, inDegree[MAX]; 
vector<int> a[MAX];
int result;
int t[MAX];
int dp[MAX];

void topologySort(){
   queue<int> q;
   
   // 진입차수가 0이면 q에 삽입 
   for (int i=1;i<=n;i++){
      if (inDegree[i] == 0) q.push(i);
   }
   
   for (int i=1;i<=n;i++){
      int x = q.front();  // now
      q.pop();
      for (int j=0;j<a[x].size();j++){
         int next = a[x][j];
         dp[next] = max(dp[next], dp[x]+t[next]);
         inDegree[next]--; // 진입차수-- 
         if(inDegree[next] == 0) q.push(next); // 진입차수 0일때 
      }
      
//      for (int k=0;k<n;k++){
//      	cout << "dp array : " << dp[k] << " ";
//	  }
//	  cout << endl;
      
   }
   
   for (int i=1;i<=n;i++) 
      result = max(result, dp[i]);
   cout << result;
}

int main(){
   cin >> n;
   for (int i=1;i<=n;i++){
		int dist, m;
		cin >> dist >> m ;
		t[i]=dist;
		dp[i] = dist;

		for (int j=0;j<m;j++){
			int x; cin >> x;
			a[x].push_back(i);
			inDegree[i]++;
      }
   }
   
   topologySort();
}