#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF 99999999
using namespace std;

int map[50][50];

vector<pair<int,int> > house;    // �� ��ġ��ǥ 
vector<pair<int,int> > chicken;  // ġŲ�� ��ġ��ǥ   

// 0�� �� ĭ, 1�� ��, 2�� ġŲ��
int main(){
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp; cin>>temp;
			if(temp==1) house.push_back({i,j}); // ���̶�� house vector�� ��ǥ ���� 
			else if(temp==2) chicken.push_back({i,j}); // ġŲ���̶�� chicken vector�� ��ǥ ����  
		}
	}
	
	int ans=INF; // �� ���� = ������ ġŲ �Ÿ��� �ּڰ�. 
	
	vector<pair<int,int> > selectedChicken; // Ư�� ���տ��� ���õ� m���� ġŲ�� ��ǥ�� ����  
	
	vector<bool> temp(chicken.size(), false); // ������ ����ϱ� ���� vector  
	for(int i=0;i<m;i++) temp[i]=true; // ������ ����ϱ�  ���� �ʱ�ȭ  
	do{
		// n���� ġŲ�� �� m���� ����. (����)  
		for(int i=0;i<chicken.size();i++){
			if(temp[i]){
				selectedChicken.push_back(chicken[i]);						
			}
		}
		int chickenDist=0; // ������ ġŲ �Ÿ�  
		for(int i=0;i<house.size();i++){ // ��� ���� ���ؼ�  
			int minDist=INF; // �� ���� ġŲ�Ÿ� ���� ����  
			for(int j=0;j<selectedChicken.size();j++){
				int dist = abs(house[i].first-selectedChicken[j].first)+abs(house[i].second-selectedChicken[j].second);
				if(dist<minDist) minDist = dist; // ���� ���� ġŲ�Ÿ� ���� 
			}
			chickenDist += minDist; // ���� ���� ġŲ �Ÿ��� ������ ġŲ�Ÿ� ������ ����  
		}
		if(chickenDist<ans) ans = chickenDist;  // �� ���� ����ġŲ�Ÿ��� ������ ����.  
		selectedChicken.clear(); // ���� ���� ġŲ�� �����ϱ� ���� �ʱ�ȭ. 
	}while(prev_permutation(temp.begin(), temp.end()));
	
	
	cout<<ans<<'\n'; // �� ���  
}
