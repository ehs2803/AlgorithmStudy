#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

//pair vector
// 입력 p값들의 크기순 번호(인덱스)로 줄을 서야함 
//     [1 2 3 4 5]
// 입력 3 1 4 3 2
// 줄   2 5 1 4 3 

bool compare(const pair<int, int>&a, const pair<int, int>&b){
	return a.first < b.first;  // first 기준 정렬
	// return a.second < b.second -> second 기준 정렬 
		
}

int n; 
pair<int, int> arr[1000];
int P[1000];
int result = 0, s = 0;

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		//cin >> inp;
		cin >> arr[i].first;
		P[i] = arr[i].first;
		arr[i].second = i+1;
	}
	
	sort(arr, arr + n, compare); 
	
//    for (int i = 0; i < n; i++) {
//    	cout << arr[i].first << " " << arr[i].second << "\n";
//    }
//    cout<<endl;

//    for (int i = 0; i < n; i++) {
//    	cout << P[i] << "\n";
//    }
//    cout<<endl;

    
    for (int i=0;i<n;i++){
		s += P[arr[i].second-1];
		result += s;
	}
	cout<<result;
}
