#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t; cin>>t; // test ���̽� ���� �Է�  
	
	while(t--){
		int n; cin>>n; // �����ڼ� �Է�  
		vector<pair<int,int> > v(n); // �����ɻ� ����, ���� ���� ���� �Է� ����  
		
		for(int i=0;i<n;i++){ // �Է�  
			cin>>v[i].first>>v[i].second;
		}
		
		sort(v.begin(), v.end()); // v[i].first �������� �������� ����.  
		
		int ans=1; // ���� �� 1���� ������ �հ�  
        int highRank=v[0].second;
        for(int i=1;i<n;i++){ // n-1�� ������ �հ� ���� Ȯ��  
            if(v[i].second<highRank) { // ���ڰ� ���� ���� highRank 
                ans++;
                highRank = v[i].second; // highRank ����  
            }
        }

        cout<<ans<<'\n'; // �� ���  
	}
}
