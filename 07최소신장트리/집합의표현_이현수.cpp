#include<iostream>
using namespace std;

int parent[1000001];

// Ư�� ���Ұ� ���� ���� ã��  
int find_parent(int x){
    if(parent[x]!=x) parent[x]=find_parent(parent[x]);
    return parent[x];
}

// �� ���Ұ� ���� ���� ��ġ��  
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL); // �ð� �ʰ� ����  
	
    int n,m;
    cin>>n>>m;
    
    // �θ����̺� �ڱ��ڽ����� �ʱ�ȭ  
    for(int i=1;i<=n;i++) parent[i]=i;
    
    for(int i=0;i<m;i++){
        int o,a,b;
        cin>>o>>a>>b;
        if(o==0){
            union_parent(a,b);
        }
        else if(o==1){
            if(find_parent(a)==find_parent(b)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
