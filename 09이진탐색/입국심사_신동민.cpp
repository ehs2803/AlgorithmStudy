#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<long long> arr; // long long안하면 틀림

long long Binary_Search() {
    long long st = 0;
    long long end = arr[n - 1] * m;
    long long res = arr[n - 1] * m;

    while (st <= end) {
        int temp = m;
        long long mid = (st + end) / 2;
        
        for (int i : arr) {
            temp -= (mid) / i;
        }
   
        if (temp <= 0) { // 시간이 남음 사람이 부족
            if (res > mid) res = mid;
            end = mid - 1;
        }
        else st = mid + 1; // 시간이 부족 사람이 완
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        arr.push_back(time);
    }
    sort(arr.begin(), arr.end());

    cout << Binary_Search();
}
