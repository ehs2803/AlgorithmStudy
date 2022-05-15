#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int arr[101];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) arr[i] = i;

    for (int i = 0; i < n; i++) { // 정점 좌표
        double a, b;
        cin >> a >> b;
        star.push_back({ a, b });
    }
  
    // 간선 만들기
    for (int i = 0; i < n -1; i++) {
        for (int j = i+1; j < n; j++) {
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
    // 소수점 아래 6자리 cout설정(반올림) = fixed
    // 소수점 아래 X자리까지 보임 = setprecision(X)
    // printf("%.2f", cost) 와 같음
    // 버림 = floor() 올림 = ceil()
}
