#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[10001];
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
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; i++) arr[i] = i;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({ c, { a, b } });
    }
    sort(vec.begin(), vec.end());

    // 크루스칼 알고리즘 = 간선값이 낮은 것부터 정점을 집합화
    int cost = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (find(vec[i].second.first) != find(vec[i].second.second)) {
            Union(vec[i].second.first, vec[i].second.second);
            cost += vec[i].first;
        }
    }
    cout << cost;
}
