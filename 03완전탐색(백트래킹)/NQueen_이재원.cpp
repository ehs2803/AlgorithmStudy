#include <iostream>
#include<math.h>
#define MAX 15
using namespace std;

int col[MAX];
int N, cnt = 0;

bool promising(int num) // 퀸의 자리 증명 
{
    for(int i = 0; i < num; i++)
        if(col[i] == col[num] || abs(col[num] - col[i]) == num - i)
        // 퀸의 자리가 서로 공격할 수 있게 놓였을 경우 
            return false; // false를 호출 
    return true; // 공격할 수 없게 놓였을 경우 
}

void nqueen(int x) 
{
    if(x == N) // 총 배치 행수가 N과 같은 경우에는 
        cnt++; // 결과값을  1 높인다
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[x] = i; // 이 위치에 퀸 배치 
            if(promising(x)) // 유효하다면 다음행으로 퀸 배치
			// 유효하지 않다면 다른 위치로 퀸 위치 변경 
                nqueen(x+1);
        }
    }
}
int main() {
    cin >> N;
    nqueen(0);
    cout << cnt<<'\n';
}
