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
		// �̹� tab�� ���� �ִ��� ���� Ȯ��  
		bool check = false;
		for(int j=0;j<multiTab.size();j++){ // multiTab ���۰��� n���� ���Ͽ�  
			if(multiTab[j]==schedule[i]){
				check=true;
				break;
			}
		}
		if(check) continue;
		
		// ��ĭ�� �����ִ��� Ȯ�� 
		if(multiTab.size()<n){
			multiTab.push_back(schedule[i]); // multiTab�� �ű�  
			continue;
		}
		
		// �� �����ǰ ���ϱ� - ���� �������� ��� ���ϴ� �� or ������ �ʾ��� ��  ã��  
		// �׸���  
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
		ans++; // multiTab���� �̰�  
		multiTab.push_back(schedule[i]); // ����� �����ǰ �ű�  
		
	}
	
	cout<<ans; // ���� ���  
}
