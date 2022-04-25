#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
vector<int> poket;
vector<pair<int, int>> arr;
priority_queue <int> heap;
long long ans = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> N >> K;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr.push_back({ a, b });
    }
    for (int i = 0; i < K; i++) {
        cin >> a;
        poket.push_back(a);
    }
    sort(arr.begin(), arr.end()); // 99 2 / 65 1 / 23 5
    sort(poket.begin(), poket.end()); // 10 2 => 2 10

    int idx = 0;
    for (auto bag_w : poket)
    {
        while (idx < N && arr[idx].first <= bag_w)
            heap.push(arr[idx++].second);
        if (!heap.empty())
        {
            ans += heap.top();
            heap.pop();
        }
    }
    cout << ans << "\n";
}
