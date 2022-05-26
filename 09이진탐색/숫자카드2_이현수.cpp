#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    sort(a.begin(), a.end());

    int m;
    cin>>m;

    for (int i=0; i<m; i++) {
        int number;
        cin>>number;
        auto l = lower_bound(a.begin(), a.end(), number);
        auto r = upper_bound(a.begin(), a.end(), number);
        cout<<r-l<<' ';
        //cout<<upper_bound(a.begin(), a.end(), number)-lower_bound(a.begin(), a.end(), number)<<' ';
    }

    return 0;
}
