#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// �༺���� �Է� ����ü  
struct Plant{
	int idx;
	int x;
	int y;
	int z;
};

int n;

int parent[100001];

// (�༺�� �Ÿ�, �༺1, �༺2) ����  
vector<pair<int, pair<int, int> > > edges;

bool cmpx (struct Plant a, struct Plant b){ return a.x < b.x; }
bool cmpy (struct Plant a, struct Plant b){ return a.y < b.y; }
bool cmpz (struct Plant a, struct Plant b){ return a.z < b.z; }

// Ư�� ���Ұ� ���� ������ ã��  
int find_parent(int x){
	if(parent[x]!=x) return find_parent(parent[x]);
	return x;
}

// �� ���Ұ� ���� ������ ��ġ��  
void union_parent(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if(a<b) parent[b]=a;
	else parent[a]=b;
}

int main(){
	// �Է�  
	cin>>n;
	
	// ����ü ���� �Ҵ�  
	struct Plant * p = new Plant[n+1];
	
	// �Է�  
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		p[i].idx=i;
		p[i].x=x;
		p[i].y=y;
		p[i].z=z;
	}
	
	// �θ����̺� �ʱ�ȭ  
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	
	// x ���� ��������  
	sort(p+1, p+n+1, cmpx);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].x-p[i+1].x);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// y���� ��������  
	sort(p+1, p+n+1, cmpy);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].y-p[i+1].y);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// z���� ��������  
	sort(p+1, p+n+1, cmpz);
	for(int i=1;i<n;i++){
		int cost = abs(p[i].z-p[i+1].z);
		edges.push_back({cost, {p[i].idx, p[i+1].idx}});
	}
	
	// ��� ������������ ����  
    sort(edges.begin(), edges.end());
	
	int ans=0;
    // ������ �ϳ��� Ȯ���ϸ�
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            ans += cost;
        }
    }
	
	// �� ���  
    cout << ans;
    
    // ���� ����ü�� �Ҵ�� �޸� ����  
	delete[] p;
}
