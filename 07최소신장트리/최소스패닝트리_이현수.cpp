#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, pair<int, int> > > edges;

int parent[10001];

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

int main() {

    int v,e;
    cin>>v>>e;

	// �θ����̺� �θ� �ڱ� �ڽ����� �ʱ�ȭ  
    for(int i=1;i<=v;i++){
        parent[i]=i;
    }
	
	// �Է�  
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({c,{a,b}});
	}

	// ���� ����� ���� ������ ��������  
    sort(edges.begin(), edges.end());

    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // �� ��尡 ���� ���տ� ������ ���� ��� ��ġ�� �� cost ���ϱ�  
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            answer += cost;
        }
    }
	
	// �� ���  
    cout<<answer;
}
