#include<iostream>

using namespace std;

int main(){
	int T, N, M;
	cin >> T; // �׽�Ʈ ���̽��� �� 
	int* ans = new int[T];
	
	for(int i=0;i<T;i++){
		cin >> N >> M; // N : ����, M : ������� ���� 
		ans[i] = N -1;
		for(int j=0;j<M;j++){
			int a, b;
			cin >> a >> b; // a�� b �պ� 
		}
	}
	for(int i=0;i<T;i++)
		cout << ans[i] << '\n';
	
	return 0;
}

/*
#include<iostream>
using namespace std;

int T, N, M, a, b;

int main(){
	cin >> T;
	while(T--){
	cin >> N >> M;
	for(int i=0;i<M;i++)
		cin >> a >> b;
	cout << N-1 << '\n';
	}
}
*/
