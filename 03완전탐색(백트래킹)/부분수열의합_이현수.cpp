#include<iostream>
#include<vector>
using namespace std;

int n,s;
vector<int> v;
int cnt=0;

void dfs(int index, int sum){
	// 모든 원소에 대한 고려가 끝났을 때 종료. 
	if(index==n) return;
	
	// 목표로 하는 값 s라면 경우의수 cnt 1 증가. 
	if(sum+v[index]==s) cnt++;
	
	// 두가지의 경우  
	// 현재 index에 대한 원소는 제외 하는 경우 
	dfs(index+1, sum);
	// 현재 index에 대한 원소를 고려하는 경우 
	dfs(index+1, sum+v[index]);
}

int main(){
	// 입력  
	cin>>n>>s;

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	// 백트래킹  
	dfs(0,0);
	
	// 답 출력  
	cout<<cnt;
}
