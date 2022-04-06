#include <iostream>
#include<vector>
using namespace std;

int N, K;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> N >> K;
    vector<int> schedule(K);
    vector<int> plug(N);

    for (int i = 0; i < K; i++)
        cin >> schedule[i];

    int result = 0;
    for (int i = 0; i < K; i++)
    {
        bool check = false;
        //해당 기기가 있는지 확인 -> 처음에 연속으로 22 나올수 있어 먼저해야함
        for (int j = 0; j < N; j++)
            if (plug[j] == schedule[i])
            {
                check = true;
                break;
            }
        if (check) continue;

        //비어있는 구멍 확인후에 넣기
        for (int j = 0; j < N; j++)
            if (!plug[j])
            {
                plug[j] = schedule[i];
                check = true;
                break;
            }
        if (check) continue;

        //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾고
        int out = 0, device = -1; // 남은게 같을경우 최소=0
        for (int j = 0; j < N; j++)
        {
            int cnt = 0; // 높을수록 다른 기기니까 바꾸어줘야함
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == schedule[k]) break;
                cnt++;
            }

            if (cnt > device)
            {
                out = j;
                device = cnt;
            }
        }
        //기기를 꽂음
        plug[out] = schedule[i];
        result++;
    }

    cout << result;
}
