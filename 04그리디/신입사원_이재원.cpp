#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int> > grade;

int main(){
	int T; // �׽�Ʈ ���̽��� ����
	cin >> T;
	
	while(T>0){
		int N; // �������� �� 
		cin >> N;
		
		for(int i=0;i<N;i++){
			
			int paper, interview;
			cin >> paper >> interview;
			grade.push_back(make_pair(paper,interview));
		}
		sort(grade.begin(), grade.end());
		
		int answer=1;
		int rank = grade.front().second;
		for(int i=1;i<N;i++){
			if(grade[i].second<rank){
				answer++;
				rank=grade[i].second;
			}
		}
		cout << answer << '\n';
		grade.clear();
	T--;
	}
	return 0;
}
