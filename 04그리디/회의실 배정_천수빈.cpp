#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int> > arr;
int result = 0;
int maxresult = 0;

bool compare (const pair<int, int>&a, const pair<int, int>&b){
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main(){
	cin >> n;
	int i, first, second;
	for(i=0;i<n;i++){
		cin >> first >> second;
		arr.push_back({first, second});
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	int now = 0;
	for (i=0;i<arr.size();i++){ 
		if (now <= arr[i].first){ // 회의끝나는시간보다 같거나 크다면  
			now = arr[i].second;  // 회의 끝나는시간으로 값 변경 
			result++; 
		}
		maxresult = max(maxresult, result);	
	}
	
	result = 0;
	cout << maxresult;
}
