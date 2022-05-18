#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
using namespace std;

int n;  //(1 ≤ n ≤ 100)
int parent[101] ={0,};  // 부모 노드 
double answer = 0;
vector<pair<double, double> > star;
vector<pair<double, pair<int,int> > > v;

double caldist(double x1, double y1, double x2, double y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int findParent(int a){
	if (a==parent[a]) return a;
	
	return parent[a] = findParent(parent[a]);
}

int main(){
	cin >> n;
	double x, y;

	for (int i=0;i<n;i++){
		parent[i] = i;
	}

	for (int i=0;i<n;i++){
		cin >> x >> y;
		star.push_back(make_pair(x,y));
	}
	
	for (int i=0;i<star.size();i++){
		for (int j=i+1;j<star.size();j++){
			double r = caldist(star[i].first, star[i].second, star[j].first, star[j].second);
			v.push_back(make_pair(r, make_pair(i,j)));
		}
	} 
	
	sort (v.begin(), v.end());
	
	for (int i=0;i<v.size();i++){
		double r = v[i].first;
		int x = v[i].second.first;
		int y = v[i].second.second;
		
		int a = findParent(x); int b = findParent(y);
		
		if (a!=b){ 
			parent[a] = b;
			answer+=r;
		}
	}
	
	cout.precision(3); // 소수점 자리 설정 
	cout << answer;
	
}
