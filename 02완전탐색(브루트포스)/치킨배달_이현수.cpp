#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF 99999999
using namespace std;

int map[50][50];

vector<pair<int,int> > house;    // 집 위치좌표 
vector<pair<int,int> > chicken;  // 치킨집 위치좌표   

// 0은 빈 칸, 1은 집, 2는 치킨집
int main(){
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp; cin>>temp;
			if(temp==1) house.push_back({i,j}); // 집이라면 house vector에 좌표 저장 
			else if(temp==2) chicken.push_back({i,j}); // 치킨집이라면 chicken vector에 좌표 저장  
		}
	}
	
	int ans=INF; // 답 변수 = 도시의 치킨 거리의 최솟값. 
	
	vector<pair<int,int> > selectedChicken; // 특정 조합에서 선택된 m개의 치킨집 좌표값 저장  
	
	vector<bool> temp(chicken.size(), false); // 조합을 사용하기 위한 vector  
	for(int i=0;i<m;i++) temp[i]=true; // 조합을 사용하기  위한 초기화  
	do{
		// n개의 치킨집 중 m개를 선택. (조합)  
		for(int i=0;i<chicken.size();i++){
			if(temp[i]){
				selectedChicken.push_back(chicken[i]);						
			}
		}
		int chickenDist=0; // 도시의 치킨 거리  
		for(int i=0;i<house.size();i++){ // 모든 집에 대해서  
			int minDist=INF; // 각 집의 치킨거리 저장 변수  
			for(int j=0;j<selectedChicken.size();j++){
				int dist = abs(house[i].first-selectedChicken[j].first)+abs(house[i].second-selectedChicken[j].second);
				if(dist<minDist) minDist = dist; // 가장 작은 치킨거리 저장 
			}
			chickenDist += minDist; // 가장 작은 치킨 거리를 도시의 치킨거리 변수에 저장  
		}
		if(chickenDist<ans) ans = chickenDist;  // 더 작은 도시치킨거리가 나오면 갱신.  
		selectedChicken.clear(); // 다음 조합 치킨집 저장하기 위해 초기화. 
	}while(prev_permutation(temp.begin(), temp.end()));
	
	
	cout<<ans<<'\n'; // 답 출력  
}
