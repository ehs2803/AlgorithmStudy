#include<iostream>
using namespace std;

int col[15];
int n; // 체스판 크기  
int cnt=0; // 답 저장 변수  

bool check(int level){
	for(int i = 0; i < level; i++){
		if(col[i] == col[level] || abs(col[level] - col[i]) == level - i){
			return false;
		}
	}
	return true;
}

void nqueen(int index){
	if(index==n) cnt++;
	else{
		for(int i=0;i<n;i++){
			col[index]=i;
			if(check(index)) nqueen(index+1); // 조건이 맞을 경우에만  
		}
	} 
}

int main(){
	// 입력  
	cin>>n;
	
	// 백트래킹  
	nqueen(0);
	
	// 답 출력  
	cout<<cnt;
	
}
