#include<iostream>
using namespace std;

int n; // ���� ����
int road[10000]; // ���� ������ ���� 
int city[10000]; // ����

int main(){
	cin >> n;
	int i;
	for (i=1;i<n;i++){
		cin>>road[i];
	}
	for(i=0;i<n;i++){
		cin>>city[i];
	}

	int now = city[0];
	int result = now * road[1];
		
	for(i=1;i<n;i++){
		if(now < city[i]){
			result += now * road[i+1];
		}
		else{
			now = city[i];
			result += now * road[i+1];
		}
	}
		
	cout << result;
} 
