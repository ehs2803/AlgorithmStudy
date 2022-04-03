#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	int n; cin>>n; // ���� �� �Է�  
	
	vector<int> road(n-1); // ���� ���� �� ���� ���� �Է� ����  
	vector<int> oilPrice(n); // �⸧ ���� �Է� ����  
	
	for(int i=0;i<n-1;i++) cin>>road[i]; // ���� ���� �� ���� ���� �Է� 
	for(int i=0;i<n;i++) cin>>oilPrice[i]; // �⸧ ���� �Է� 
	
	ll ans=0;
	int minPrice=oilPrice[0];
	for(int i=0;i<oilPrice.size()-1;i++){
		if(oilPrice[i]<minPrice) minPrice=oilPrice[i];
				
		ans = ans + 1L*minPrice*road[i];
	}
	
	cout<<ans; // �� ���  
}
