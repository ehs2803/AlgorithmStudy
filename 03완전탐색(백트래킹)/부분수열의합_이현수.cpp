#include<iostream>
#include<vector>
using namespace std;

int n,s;
vector<int> v;
int cnt=0;

void dfs(int index, int sum){
	// ��� ���ҿ� ���� ����� ������ �� ����. 
	if(index==n) return;
	
	// ��ǥ�� �ϴ� �� s��� ����Ǽ� cnt 1 ����. 
	if(sum+v[index]==s) cnt++;
	
	// �ΰ����� ���  
	// ���� index�� ���� ���Ҵ� ���� �ϴ� ��� 
	dfs(index+1, sum);
	// ���� index�� ���� ���Ҹ� ����ϴ� ��� 
	dfs(index+1, sum+v[index]);
}

int main(){
	// �Է�  
	cin>>n>>s;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	// ��Ʈ��ŷ  
	dfs(0,0);
	
	// �� ���  
	cout<<cnt;
}
