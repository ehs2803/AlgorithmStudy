#include<iostream>
#include<vector>
using namespace std;

int parent[101];

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

int main(){
	int v,e;
	cin>>v>>e;
	
	// �θ� ���̺��� �ڽ��ڽ����� �ʱ�ȭ  
	for(int i=1;i<=v;i++) parent[i]=i;
	// �Է�  
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		union_parent(a,b); 
	}	
	
	int ans=0;
	int oneParent = find_parent(1); // 1����ǻ�ͼ��� ���� �˾Ƴ���  
	// 1�� ���հ� ���� ��� �߽߰� ans 1����  
	for(int i=2;i<=v;i++){
		if(find_parent(i)==oneParent) ans++;
	}
	
	// ���� ���  
	cout<<ans;
}
