#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
char c[1000][50];
char dna[4]={'A','C','G','T'};
int tmp[4];
int result = 0;

int main(){
	cin >> n >> m;
	
	for (int i=0;i<n;i++){
		for (int j=0; j<m; j++){
			cin >> c[i][j];
		}
	}
	
	for (int j=0; j<m; j++){
		memset(tmp , 0, sizeof(tmp));
		int max = 0, check = 0;
		for (int i=0;i<n;i++){
			for (int k=0;k<4;k++){  // A,C,G,T 빈도수 체크 
				if (c[i][j] == dna[k]){  
					tmp[k] ++;
				}
			}
		}
		
		for (int i=0;i<4;i++){
			int t = tmp[i];
			if (max < t){
				max = t; check = i;
			}
		}
		
		result += n-max;    // 최종 result 카운트업 
		cout << dna[check]; // 문자 출력 
	}
	cout <<"\n" << result; 
}
