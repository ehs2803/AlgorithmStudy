#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//               검은색 먼저   흰색 먼저 
int arr[55][55], board1[8][8], board2[8][8];

int main(){
	int n,m, result = 64;
	int chk1=0, chk2=0;
	cin >> n>> m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if (s[j] == 'B') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	
	for(int i=0;i<8;i++) for(int j=0;j<8;j++){
		board1[i][j] = (i+j+1)%2;
		board2[i][j] = (i+j)%2; 
	}
	
	for(int i=0;i+8<=n;i++){
		for(int j=0;j+8<=m;j++){
			chk1 = 0; chk2 = 0;
			// board1,2 비교
			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					if(arr[i+k][j+l] != board1[k][l]) chk1++;
					if(arr[i+k][j+l] != board2[k][l]) chk2++;
				}
			}
			result = min(min(chk1, chk2), result);
		}
	}
	
	cout<<result;
	
}
