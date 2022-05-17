#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int parent[101];

vector<pair<double, double> > starLocation;
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
double getDistance(double x1, double x2, double y1, double y2){
	double dx = pow((x1 - x2),2);
    double dy = pow((y1 - y2),2);
    double Dist = sqrt(dx + dy);
 
    return Dist;
} 

int main(){
	int n; 
	cin>>n;

	// �Է�  
	for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		starLocation.push_back({x,y});
	}	
	
	// ��� ����� ���� ���� �� �� ���� �Ÿ� ���ϱ�  
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
	
	// MST�� ���� �θ����̺� �θ� �ڱ� �ڽ����� �ʱ�ȭ 
	for(int i=1;i<=n;i++) parent[i]=i;
	
	// ���� ����� ���� ������ �������� 
	sort(edges.begin(), edges.end());
	
	double answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // �� ��尡 ���� ���տ� ������ ���� ��� ��ġ�� �� cost ���ϱ�  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            answer += cost;
        }
    }
	
	// �� ���  
	cout << fixed;
	cout.precision(2);
    cout<<answer;
	
}
