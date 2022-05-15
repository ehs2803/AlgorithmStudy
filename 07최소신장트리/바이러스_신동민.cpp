#include<iostream>
using namespace std;

int arr[101];

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
    int c, m;
    cin >> c >> m;

    for (int i = 1; i <= c; i++) arr[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    // 컴퓨터에서 걸린 바이러스 수
    int ans = 0;
    for (int i = 2; i <= c; i++) {
        if (find(i) == find(1)) ans++;
    }
    cout << ans;
}
