#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int findParent(int x) {
  if (x == parent[x]) return x;
  else return parent[x] =  findParent(parent[x]);
}

void unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);

  if (a < b) parent[b] = a;
  else parent[a] = b;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op==0) { // a가 포함되어 있는 집합과 b가 포함되어 있는 집합을 합침 
      unionParent(a, b);
    }
    else if (op==1) { // 두 원소가 같은 집합에 포함되어 있는지를 확인 
      if (findParent(a) == findParent(b)) cout<<"YES" << '\n';
      else cout<<"NO" << '\n';
    }
  }
}
