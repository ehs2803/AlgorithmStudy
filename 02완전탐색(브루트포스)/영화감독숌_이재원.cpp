#include<iostream>

using namespace

int main(){
	int n, num;
    cin >> n; // n��° ��ȭ�� ���� �� ���� ã�� ����
    
    int name = 0;
    int index = 0;

    while (index != n) {
        name++;
        num = name;

        while (num != 0) {
            if (num % 1000 == 666) {
                index++;
                break;
            }
            else num /= 10;
        }
    }
    cout << name;
    return 0;
}
