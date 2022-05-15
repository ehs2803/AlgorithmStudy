#include<iostream>
using namespace std;
int n, m;
int arr[1000001];

// 원소가 속한 집합 찾기
int find(int x) {
    //if (arr[x] != x) return find(arr[x]); // 경로압축X
    //return x;
    if (arr[x] != x) arr[x] = find(arr[x]); // 경로압축 = 찾을때 정보를 갱신함
    return arr[x];
}

// 두 원소 집합 합치기
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    // 집합을 대표하는 숫자만 일단 보냄
    if (a < b) arr[b] = a;
    else arr[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) arr[i] = i;

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            Union(a, b);
        }
        else if (op == 1) {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
