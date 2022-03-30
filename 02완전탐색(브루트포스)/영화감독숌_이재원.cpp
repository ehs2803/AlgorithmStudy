#include<iostream>

using namespace

int main(){
	int n, num;
    cin >> n; // n번째 영화의 제목에 들어갈 수를 찾는 문제
    
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
