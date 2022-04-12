#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
// �������� ��������, ���Է� ��������  
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
	cin>>n>>k; // n : ���� ���� ����, k : ���� ����  
	
	vector<pair<int,int> > item(n); // ���� ����, ���� ���� ����  
	for(int i=0;i<n;i++){
		cin>>item[i].first>>item[i].second; // ���� ����, ���� �Է�  
	}	
	
	vector<int> bag(k); // ���� ���� ���� ����  
	for(int i=0;i<k;i++){
		cin>>bag[i]; // ���� ���� �Է�  
	}
	
	// ����  
	sort(item.begin(), item.end()); // ���Է� ��������  
	sort(bag.begin(), bag.end()); // ���� ���� ��������
	
	priority_queue<int> pq; // Max Heap 
	long long ans=0; // ���� ���� ����  
	int index_item=0;  
	for(int i=0;i<bag.size();i++){
		// bag[i]�� �� �� �ִ� ��� ������ �켱����ť�� ��Ƶα�  
		while(index_item<n && item[index_item].first<=bag[i]){
			pq.push(item[index_item].second);
			index_item++;
		}
		
		if(!pq.empty()){ // �켱����ť�� ������� �ʴٸ� = bag[i]�� ������ ���� �� �ִ�. 
			ans+=pq.top(); // ���� ���  
			pq.pop(); // ��ģ ���� �켱����ť���� ����  
		}
	}
	
	// �� ���
	cout<<ans;
	 
	/* �ð� �ʰ� ... 
	// ����  
	sort(item.begin(), item.end(), cmp); // �������� ��������, ���Է� ��������  
	sort(bag.begin(), bag.end()); // ���� ���� ��������  
	
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
	cout<<ans; // �� ���  
	*/
}
