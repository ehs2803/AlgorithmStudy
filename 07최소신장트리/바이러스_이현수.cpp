#include<iostream>
#include<vector>
using namespace std;

int parent[101];

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

int main(){
	int v,e;
	cin>>v>>e;
	
	// 부모 테이블을 자시자신으로 초기화  
	for(int i=1;i<=v;i++) parent[i]=i;
	// 입력  
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		union_parent(a,b); 
	}	
	
	int ans=0;
	int oneParent = find_parent(1); // 1번컴퓨터속한 집합 알아내기  
	// 1번 집합과 같은 노드 발견시 ans 1증가  
	for(int i=2;i<=v;i++){
		if(find_parent(i)==oneParent) ans++;
	}
	
	// 정답 출력  
	cout<<ans;
}
