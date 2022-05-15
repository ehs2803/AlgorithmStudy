#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100001];
vector<pair<int, int>> dx;
vector<pair<int, int>> dy;
vector<pair<int, int>> dz;
vector<pair<int, pair<int, int>>> vec;

// 원소가 속한 집합 찾기  
int find(int x) {
    if (arr[x] != x) arr[x] = find(arr[x]);
    return arr[x];
}

// 두 원소 집합 합치기  
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) arr[b] = a;
    else arr[a] = b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) arr[i] = i;

    // 정점 좌표 + 번호
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dx.push_back({ a, i });
        dy.push_back({ b, i });
        dz.push_back({ c, i });
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    sort(dz.begin(), dz.end());

    // 간선 만들기
    for (int i = 0; i < n - 1; i++) {
        vec.push_back({ dx[i+1].first - dx[i].first, {dx[i].second, dx[i+1].second} });
        vec.push_back({ dy[i + 1].first - dy[i].first, {dy[i].second, dy[i + 1].second} });
        vec.push_back({ dz[i + 1].first - dz[i].first, {dz[i].second, dz[i + 1].second} });
    }
    sort(vec.begin(), vec.end());

    // 크루스칼 알고리즘
    int cost = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (find(vec[i].second.first) != find(vec[i].second.second)) {
            Union(vec[i].second.first, vec[i].second.second);
            cost += vec[i].first;
        }
    }
    cout << cost;
}
