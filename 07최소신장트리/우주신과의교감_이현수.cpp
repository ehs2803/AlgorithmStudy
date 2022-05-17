#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[1001];

vector<pair<int,int> > coordinate;
vector<pair<double, pair<int, int> > > edges;

// Ư�� ���Ұ� ���� ���� ã��  
int find_parent(int x){
    if(parent[x]!=x) return find_parent(parent[x]);
    return x;
}

// �� ���Ұ� ���� ���� ��ġ��  
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

// ���� ���� �Ÿ� ���ϱ�  
double getDistance(int x1, int x2, int y1, int y2){
	double dx = pow((x1 - x2),2);
    double dy = pow((y1 - y2),2);
    double Dist = sqrt(dx + dy);
 
    return Dist;
} 

int main(){
	int n, m;
	cin>>n>>m;
	
	// �θ����̺� �ڱ� �ڽ����� �ʱ�ȭ  
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// �Է�  
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		coordinate.push_back({x,y});
	}
	// �Է�  
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		union_parent(a,b); // ��ġ��  
	}
	
	// ��� ������ ��쿡 ���� ���ϱ�  
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
    
    // ���  ���� �Ÿ� �������� ����  
    sort(edges.begin(), edges.end());

	// ũ�罺Į �˰���  
	double ans=0;
	for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // �� ��尡 ���� ���տ� ������ ���� ��� ��ġ�� �� cost ���ϱ�  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
    
    // �� ���
    cout << fixed;
	cout.precision(2);
	cout<<ans; 
}
