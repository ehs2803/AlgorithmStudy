#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> key;
int n, m;

bool Binary_Search(int key) {
    int st = 0;
    int end = arr.size();

    while (st <= end) {
        int mid = (st + end) / 2;
        if (arr[mid] == key) {
            return true;
        }
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> n;
    // vector<int> arr(n);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        key.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        // if (binary_search(arr.begin(), arr.end(), key[i]))
        if (Binary_Search(key[i]))
            cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}
