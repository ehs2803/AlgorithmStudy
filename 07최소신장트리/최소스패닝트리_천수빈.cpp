#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
int v, e, result=0; 

// 재귀로 구성
// 최종 부모 노드를를 찾기 위한 작업 
int getParent(int parent[], int x){
	if(parent[x] == x) return x; // 최종 부모에 도달했을때(재귀종료조건) 
	return parent[x] = getParent(parent, parent[x]); 
}

// 정점 추가 ->  getParent로 최종 부모 노드까지 찾 
void unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a<b) parent[b] = a;
	else parent[a] = b;
	
} 

int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a==b) return 1; // 부모가 같으면연결되어 있음 
	return 0;           // 부모가 다르므로 연결되어 있지 않음 
}

int main(){
	vector<pair<int, pair<int, int> > > vec; 
	cin >> v >> e;
	for(int i=0;i<e;i++){
		int from, to, c;
		cin >> from >> to >> c;
		vec.push_back({c, {from, to}});
	}
	sort(vec.begin(), vec.end()); // 최소 트리를 구하기 위한 정렬 
	for (int i=0;i<v;i++) parent[i] = i;
	for (int i=0;i<vec.size();i++){
		if (!findParent(parent, vec[i].second.first, vec[i].second.second)){
			unionParent(parent , vec[i].second.first, vec[i].second.second);
			result += vec[i].first;
		}
	}
	
	cout << result;
}
