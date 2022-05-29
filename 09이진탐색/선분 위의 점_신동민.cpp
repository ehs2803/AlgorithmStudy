#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        arr.push_back(h);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        auto l = lower_bound(arr.begin(), arr.end(), a);
        auto r = upper_bound(arr.begin(), arr.end(), b);
        cout << r-l << '\n';
    }
}
