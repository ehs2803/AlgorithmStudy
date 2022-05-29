#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
int n, m;

// key 값 초과인 위치
int UpperBound(int key) {
    int mid = 0;
    int st = 0;
    int end = arr.size();
    while (st < end) {
        mid = (st + end) / 2;

        if (arr[mid] > key) {
            end = mid;
        }
        else {
            st = mid + 1;
        }
    }
    return st;
}

// key 값 이상인 위치
int LowerBound(int key) {
    int mid = 0;
    int st = 0;
    int end = arr.size();
    while (st < end) {
        mid = (st + end) / 2;

        if (arr[mid] >= key) {
            end = mid;
        }
        else {
            st = mid + 1;
        }
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        //auto l = lower_bound(arr.begin(), arr.end(), key);
        //auto r = upper_bound(arr.begin(), arr.end(), key);
        cout << UpperBound(key) - LowerBound(key) << ' ';
    }
}
