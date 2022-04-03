#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	int n; cin>>n; // 도시 수 입력  
	
	vector<int> road(n-1); // 도시 사이 간 도로 길이 입력 벡터  
	vector<int> oilPrice(n); // 기름 가격 입력 벡터  
	
	for(int i=0;i<n-1;i++) cin>>road[i]; // 도시 사이 간 도로 길이 입력 
	for(int i=0;i<n;i++) cin>>oilPrice[i]; // 기름 가격 입력 
	
	ll ans=0;
	int minPrice=oilPrice[0];
	for(int i=0;i<oilPrice.size()-1;i++){
		if(oilPrice[i]<minPrice) minPrice=oilPrice[i];
				
		ans = ans + 1L*minPrice*road[i];
	}
	
	cout<<ans; // 답 출력  
}
