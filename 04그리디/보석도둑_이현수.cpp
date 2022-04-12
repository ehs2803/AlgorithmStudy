#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
// 가격으로 내림차순, 무게로 내림차순  
bool cmp(const pair<int, int> & a, const pair<int, int> & b){
	if(a.second==b.second){
		if(a.first>b.first) return true;
		else return false;
	}
	else if(a.second>b.second) return true;
	else return false;
}
*/

int main(){
	int n, k;
	cin>>n>>k; // n : 보석 종류 개수, k : 가방 개수  
	
	vector<pair<int,int> > item(n); // 보석 무게, 가격 저장 벡터  
	for(int i=0;i<n;i++){
		cin>>item[i].first>>item[i].second; // 보석 무게, 가격 입력  
	}	
	
	vector<int> bag(k); // 가방 무게 저장 벡터  
	for(int i=0;i<k;i++){
		cin>>bag[i]; // 가방 무게 입력  
	}
	
	// 정렬  
	sort(item.begin(), item.end()); // 무게로 오름차순  
	sort(bag.begin(), bag.end()); // 가방 무게 오름차순
	
	priority_queue<int> pq; // Max Heap 
	long long ans=0; // 정답 저장 변수  
	int index_item=0;  
	for(int i=0;i<bag.size();i++){
		// bag[i]에 들어갈 수 있는 모든 보석을 우선순위큐에 담아두기  
		while(index_item<n && item[index_item].first<=bag[i]){
			pq.push(item[index_item].second);
			index_item++;
		}
		
		if(!pq.empty()){ // 우선순위큐가 비어있지 않다면 = bag[i]에 보석을 담을 수 있다. 
			ans+=pq.top(); // 보석 담기  
			pq.pop(); // 훔친 보석 우선순위큐에서 제외  
		}
	}
	
	// 답 출력
	cout<<ans;
	 
	/* 시간 초과 ... 
	// 정렬  
	sort(item.begin(), item.end(), cmp); // 가격으로 내림차순, 무게로 오름차순  
	sort(bag.begin(), bag.end()); // 가방 무게 오름차순  
	
	long long ans=0;
	for(int i=0;i<bag.size();i++){
		for(int j=0;j<item.size();j++){
			if(bag[i]>=item[j].first){
				ans+=item[j].second;
				item.erase(item.begin()+j);
				break;
			}
		}
	}
	cout<<ans; // 답 출력  
	*/
}
