#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int arr[1001];
vector<pair<int, int>> star;
vector<pair<double, pair<int, int>>> vec;

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
    int n , m;
    cin >> n >> m;
    // 1~N까지 사용
    for (int i = 1; i <= n; i++) arr[i] = i;

    // 정점 좌표
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        star.push_back({ a, b });
    }

    // 연결된 간선 갯수
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec.push_back({ 0,{ a, b} });
    }

    // 간선 만들기
    for (int i = 0; i < n-1; i++) { // 벡터로 접근해서 0부터 시작해야함 마지막 정점은 이미 간선 다 있음
        for (int j = i + 1; j < n; j++) {
            double e = sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2));
            vec.push_back({ e, {i+1,j+1} }); 
        }
    }
    sort(vec.begin(), vec.end());

    // 크루스칼 알고리즘
    double cost = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (find(vec[i].second.first) != find(vec[i].second.second)) {
            Union(vec[i].second.first, vec[i].second.second);
            cost += vec[i].first;
        }
    }
    cout << fixed << setprecision(2) << cost;
}
