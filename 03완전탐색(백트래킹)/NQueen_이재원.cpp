#include <iostream>
#include<math.h>
#define MAX 15
using namespace std;

int col[MAX];
int N, cnt = 0;

bool promising(int num) // ���� �ڸ� ���� 
{
    for(int i = 0; i < num; i++)
        if(col[i] == col[num] || abs(col[num] - col[i]) == num - i)
        // ���� �ڸ��� ���� ������ �� �ְ� ������ ��� 
            return false; // false�� ȣ�� 
    return true; // ������ �� ���� ������ ��� 
}

void nqueen(int x) 
{
    if(x == N) // �� ��ġ ����� N�� ���� ��쿡�� 
        cnt++; // �������  1 ���δ�
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[x] = i; // �� ��ġ�� �� ��ġ 
            if(promising(x)) // ��ȿ�ϴٸ� ���������� �� ��ġ
			// ��ȿ���� �ʴٸ� �ٸ� ��ġ�� �� ��ġ ���� 
                nqueen(x+1);
        }
    }
}
int main() {
    cin >> N;
    nqueen(0);
    cout << cnt<<'\n';
}
