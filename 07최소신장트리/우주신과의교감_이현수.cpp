#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[1001];

vector<pair<int,int> > coordinate;
vector<pair<double, pair<int, int> > > edges;

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

// 두점 사이 거리 구하기  
double getDistance(int x1, int x2, int y1, int y2){
	double dx = pow((x1 - x2),2);
    double dy = pow((y1 - y2),2);
    double Dist = sqrt(dx + dy);
 
    return Dist;
} 

int main(){
	int n, m;
	cin>>n>>m;
	
	// 부모테이블 자기 자신으로 초기화  
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// 입력  
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		coordinate.push_back({x,y});
	}
	// 입력  
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		union_parent(a,b); // 합치기  
	}
	
	// 모든 간선의 경우에 대해 구하기  
    for (int i = 0; i < n - 1; i++){
        int x1 = coordinate[i].first;
        int y1 = coordinate[i].second;
        for (int j = i + 1; j < n; j++)
        {
            int x2 = coordinate[j].first;
            int y2 = coordinate[j].second;
 
            double Dist = getDistance(x1, x2, y1, y2);
            edges.push_back({Dist, {i+1, j+1}});
        }
    }
    
    // 노드  사이 거리 오름차순 정렬  
    sort(edges.begin(), edges.end());

	// 크루스칼 알고리즘  
	double ans=0;
	for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 두 노드가 같은 집합에 속하지 않은 경우 합치기 및 cost 더하기  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
    
    // 답 출력
    cout << fixed;
	cout.precision(2);
	cout<<ans; 
}
