#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
int v, e, result=0; 

// ��ͷ� ����
// ���� �θ� ��带�� ã�� ���� �۾� 
int getParent(int parent[], int x){
	if(parent[x] == x) return x; // ���� �θ� ����������(�����������) 
	return parent[x] = getParent(parent, parent[x]); 
}

// ���� �߰� ->  getParent�� ���� �θ� ������ ã 
void unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a<b) parent[b] = a;
	else parent[a] = b;
	
} 

int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a==b) return 1; // �θ� �����鿬��Ǿ� ���� 
	return 0;           // �θ� �ٸ��Ƿ� ����Ǿ� ���� ���� 
}

int main(){
	vector<pair<int, pair<int, int> > > vec; 
	cin >> v >> e;
	for(int i=0;i<e;i++){
		int from, to, c;
		cin >> from >> to >> c;
		vec.push_back({c, {from, to}});
	}
	sort(vec.begin(), vec.end()); // �ּ� Ʈ���� ���ϱ� ���� ���� 
	for (int i=0;i<v;i++) parent[i] = i;
	for (int i=0;i<vec.size();i++){
		if (!findParent(parent, vec[i].second.first, vec[i].second.second)){
			unionParent(parent , vec[i].second.first, vec[i].second.second);
			result += vec[i].first;
		}
	}
	
	cout << result;
}
