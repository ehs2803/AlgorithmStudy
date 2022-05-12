#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, pair<int, int> > > edges;

int parent[10001];

// 특정 원소가 속한 집합 찾기  
int find_parent(int x){
    if(parent[x]!=x) return find_parent(parent[x]);
    return x;
}

// 두 원소가 속한 집합 합치기  
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main() {

    int v,e;
    cin>>v>>e;

	// 부모테이블 부모를 자기 자신으로 초기화  
    for(int i=1;i<=v;i++){
        parent[i]=i;
    }
	
	// 입력  
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({c,{a,b}});
	}

	// 간선 비용이 적은 순으로 오름차순  
    sort(edges.begin(), edges.end());

    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 두 노드가 같은 집합에 속하지 않은 경우 합치기 및 cost 더하기  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            answer += cost;
        }
    }
	
	// 답 출력  
    cout<<answer;
}
