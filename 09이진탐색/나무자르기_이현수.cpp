#include<iostream>
#include<vector>
using namespace std;

// 절단기 위치를 heigth로 했을 때 target 이상 나무를 가져갈 수 있는지 여부  
bool isPossible(vector<long long> & trees, unsigned int heigth, int target){
	long long taken = 0;
	for(int i=0;i<trees.size();i++){
		if(trees[i]>heigth) taken+=(trees[i]-heigth);
		if(taken>=target) return true;
	}	
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<long long> trees(n);
	// 입력  
	for(int i=0;i<n;i++) cin>>trees[i];
	
	// 이분 탐색  
	unsigned int left = 0;
	unsigned int right = 1000000000;
	unsigned int mid, ans;
	while(left<=right){
		mid = (left+right)/2;
		if(isPossible(trees, mid, m)){
			ans=mid;
			left=mid+1;
		}
		else{
			right = mid-1;
		}
	}
	// 답 출력  
	cout<<ans;
}
