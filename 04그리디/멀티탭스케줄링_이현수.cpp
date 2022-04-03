#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	
	vector<int> schedule(k);
	vector<int> multiTab;
	
	for(int i=0;i<k;i++) cin>>schedule[i];
	
	int ans = 0;
	
	for(int i=0;i<k;i++){
		// 이미 tab에 꽂혀 있는지 여부 확인  
		bool check = false;
		for(int j=0;j<multiTab.size();j++){ // multiTab 구멍개수 n개에 대하여  
			if(multiTab[j]==schedule[i]){
				check=true;
				break;
			}
		}
		if(check) continue;
		
		// 빈칸이 남아있는지 확인 
		if(multiTab.size()<n){
			multiTab.push_back(schedule[i]); // multiTab에 꼽기  
			continue;
		}
		
		// 뺄 전기용품 정하기 - 가장 오랫동안 사용 안하는 것 or 앞으로 않쓰일 것  찾기  
		// 그리디  
		int out_index=0; 
		int last_use_index=0; 
		for(int j=0;j<multiTab.size();j++){
			int cnt=0;
			for(int m=i+1; m<k; m++){
				if(multiTab[j]==schedule[m]){
					break;
				}
				cnt++;
			}
			if(cnt>last_use_index){
				out_index=j;
				last_use_index = cnt;
			}
		}
		multiTab.erase(multiTab.begin()+out_index);
		ans++; // multiTab에서 뽑고  
		multiTab.push_back(schedule[i]); // 사용할 전기용품 꼽기  
		
	}
	
	cout<<ans; // 정답 출력  
}
