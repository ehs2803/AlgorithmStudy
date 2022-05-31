#include<iostream>
#include<algorithm>
using namespace std;

long long time[100000];

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++) cin>>time[i];
	
	sort(time, time+n);
		
	long long left=1; // 최소시간  
	long long right=time[n-1]*m; // 최대시간  
	long long mid;
	long long ans;
	while(left<=right){
		mid = (left+right)/2;
		
		long long cnt=0;
		for(int i=0;i<n;i++){
			cnt+=mid/time[i];
		}
		
		if(cnt<m){
			left = mid+1;
		}
		else{
			ans=mid;
			right = mid-1;
		}
	}	
	// 답 출력  
	cout<<ans;
	
}
