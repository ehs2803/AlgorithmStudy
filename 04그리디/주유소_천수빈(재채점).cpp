#include<iostream>
using namespace std;

int n; // ���� ����
long road[100000]; // ���� ������ ���� 
int city[100000]; // ����

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
	long long result = now * road[1];
		
	for(i=1;i<n-1;i++){  // i=1
		if(now < city[i]){
			result += 1L * now * road[i+1];
		}
		else{
			now = city[i];
			result += 1L * now * road[i+1];
		}
	}
		
	cout << result;
} 
