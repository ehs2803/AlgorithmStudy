#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 행성정보 입력 구조체  
struct Plant{
	int idx;
	int x;
	int y;
	int z;
};

int n;

int parent[100001];

// (행성간 거리, 행성1, 행성2) 저장  
vector<pair<int, pair<int, int> > > edges;

bool cmpx (struct Plant a, struct Plant b){ return a.x < b.x; }
bool cmpy (struct Plant a, struct Plant b){ return a.y < b.y; }
bool cmpz (struct Plant a, struct Plant b){ return a.z < b.z; }

// 특정 원소가 속한 집합을 찾기  
int find_parent(int x){
	if(parent[x]!=x) return find_parent(parent[x]);
	return x;
}

// 두 원소가 속한 집합을 합치기  
void union_parent(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if(a<b) parent[b]=a;
	else parent[a]=b;
}

int main(){
	// 입력  
	cin>>n;
	
	// 구조체 동적 할당  
	struct Plant * p = new Plant[n+1];
	
	// 입력  
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[i].idx=i;
		p[i].x=x;
		p[i].y=y;
		p[i].z=z;
	}
	
	// 부모테이블 초기화  
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	
	// x 기준 오름차순  
	sort(p+1, p+n+1, cmpx);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].x-p[i+1].x);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// y기준 오름차순  
	sort(p+1, p+n+1, cmpy);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].y-p[i+1].y);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// z기준 오름차순  
	sort(p+1, p+n+1, cmpz);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].z-p[i+1].z);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// 비용 오름차순으로 정렬  
    sort(edges.begin(), edges.end());
	
	int ans=0;
    // 간선을 하나씩 확인하며
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
	
	// 답 출력  
    cout << ans;
    
    // 동적 구조체에 할당된 메모리 해제  
	delete[] p;
}
