#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<pair<int, int>> ranking;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> T;
    for (int i = 0; i < T; i++) {
        int ans = 1;
        cin >> N;
        ranking.clear();
        int a, b;
        for (int j = 0; j < N; j++) {
            cin >> a >> b;
            ranking.push_back({ a, b });
        }

        sort(ranking.begin(), ranking.end());
        int check = ranking[0].second; // 1차 1위의 2차성적

        for (int j = 1; j < N; j++) {
            if (ranking[j].second < check) {
                check = ranking[j].second;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
