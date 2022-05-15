#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;

        int a, b;
        for (int j = 1; j <= m; j++) {
            cin >> a >> b;
        }
        cout << n-1 << "\n";
    }
}
