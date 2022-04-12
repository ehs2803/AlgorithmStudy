#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t; cin>>t; // test 케이스 개수 입력  
	
	while(t--){
		int n; cin>>n; // 지원자수 입력  
		vector<pair<int,int> > v(n); // 서류심사 성적, 면접 성적 순위 입력 벡터  
		
		for(int i=0;i<n;i++){ // 입력  
			cin>>v[i].first>>v[i].second;
		}
		
		sort(v.begin(), v.end()); // v[i].first 기준으로 오름차순 정렬.  
		
		int ans=1; // 정렬 후 1등은 무조건 합격  
        int highRank=v[0].second;
        for(int i=1;i<n;i++){ // n-1명 지원자 합격 여부 확인  
            if(v[i].second<highRank) { // 숫자가 작을 수록 highRank 
                ans++;
                highRank = v[i].second; // highRank 갱신  
            }
        }

        cout<<ans<<'\n'; // 답 출력  
	}
}
