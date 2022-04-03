#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<int,int> &u, const pair<int,int> &v) {
    if (u.second == v.second) {
        return u.first < v.first;
    } else {
        return u.second < v.second;
    }
}

int main(){
	int n; cin>>n;
	
	vector<pair<int,int> > schedule;
	
	for(int i=0;i<n;i++){
		int start, end;
		cin>>start>>end;
		schedule.push_back({start,end});
	}
	
	// 정렬 
	sort(schedule.begin(), schedule.end(), cmp);
	
	int ans=0;
	int now=0;
	for(int i=0;i<schedule.size();i++){
		if(now<=schedule[i].first){
			now = schedule[i].second;
			ans++;
		}
	}
	
	// 정답 출력
	cout<<ans; 
	
}
