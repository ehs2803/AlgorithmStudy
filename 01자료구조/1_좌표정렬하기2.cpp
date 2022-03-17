#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// y오름차순, x 오름차순  
bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
        if (a.first < b.first)
            return true;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << "\n";
}
