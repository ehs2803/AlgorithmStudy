#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std; 

vector <int> a[101];
int com, net;
bool check[101];
int cnt=0;

void dfs(int node){
	check[node] = true;
	cnt++;
	for (int i=0;i<a[node].size();i++){
		int next = a[node][i];
		if (check[next]!=true)
			dfs(next);
	}
}


int main(){
	cin >> com >> net;
	int x, y;
	for (int i=0;i<net;i++){
		cin >> x >> y ;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i=1;i<x;i++){
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(1);
	
	cout << cnt-1;
}
