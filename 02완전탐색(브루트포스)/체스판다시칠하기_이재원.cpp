#include<iostream>
#include<algorithm>

using namespace std;

int chess[50][50];

int check(int x, int y) {
    int num1 = 0;
    int num2 = 0;

    for (int i = x;i < x + 8;i++) {
        for (int j = y;j < y + 8;j++) {
            if ((i + j) % 2 == chess[i][j])num1++;
            if ((i + j + 1) % 2 == chess[i][j])num2++;
        }
    }
    return min(num1, num2);
}

int main()
{
    int n, m;
    int mini = 2500;
    char c;

    cin >> n >> m;
    int j = 0;

    for (int i = 0;i < n;i++) {
        for(int j=0 ;j<m;j++) {
            cin >> c;
            if (c == 'B') chess[i][j] = 0;
            else chess[i][j] = 1;
        }
    }

    for (int i = 0;i <= n - 8;i++) {
        for (int j = 0;j <= m - 8;j++) {
            if (mini > check(i, j))
                mini = check(i, j);//가장 작은 값 구하기
        }
    }
    cout << mini;
    return 0;
}
