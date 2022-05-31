#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,m;
	cin>>n>>m;
	// input
	vector<int> dot(n);
	for(int i=0;i<n;i++) cin>>dot[i];
	// input
	vector<pair<int,int> > line(m);
	for(int i=0;i<m;i++){
		cin>>line[i].first>>line[i].second;
	}
	
	sort(dot.begin(), dot.end());
	for(int i=0;i<m;i++){
		cout << upper_bound(dot.begin(), dot.end(), line[i].second) - 
		lower_bound(dot.begin(), dot.end(), line[i].first) << "\n";
	}
}

