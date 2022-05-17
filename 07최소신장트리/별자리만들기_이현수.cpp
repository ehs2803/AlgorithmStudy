#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[101];

vector<pair<double, double> > starLocation;
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
double getDistance(double x1, double x2, double y1, double y2){
	double dx = pow((x1 - x2),2);
    double dy = pow((y1 - y2),2);
    double Dist = sqrt(dx + dy);
 
    return Dist;
} 

int main(){
	int n; 
	cin>>n;

	// 입력  
	for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		starLocation.push_back({x,y});
	}	
	
	// 모든 경우의 수에 대해 두 별 사이 거리 구하기  
	for(int i=0;i<starLocation.size();i++){
		double x1 = starLocation[i].first;
		double y1 = starLocation[i].second;
		
		for(int j=i+1;j<starLocation.size();j++){
			double x2 = starLocation[j].first;
			double y2 = starLocation[j].second;
			
			double Dist = getDistance(x1,x2,y1,y2);
			edges.push_back({Dist, {i,j}});
		}
	}
	
	// MST를 위한 부모테이블 부모를 자기 자신으로 초기화 
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// 간선 비용이 적은 순으로 오름차순 
	sort(edges.begin(), edges.end());
	
	double answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 두 노드가 같은 집합에 속하지 않은 경우 합치기 및 cost 더하기  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            answer += cost;
        }
    }
	
	// 답 출력  
	cout << fixed;
	cout.precision(2);
    cout<<answer;
	
}
