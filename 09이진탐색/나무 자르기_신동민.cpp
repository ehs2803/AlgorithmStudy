#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int res, n, m;
vector<int> arr;

void Binary_Search() {
    int st = 0;
    int end = arr[n-1];

    while (st <= end) {
        int mid = (st + end) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)
                sum += (arr[i] - mid);
        }
        if (sum >= m) {
            if (res < mid) res = mid;
            st = mid + 1;
        }
        else end = mid - 1;
    }
}

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

    Binary_Search();
    cout << res;
}
