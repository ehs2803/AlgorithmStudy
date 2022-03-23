#include<iostream>
#define INF 99999999
using namespace std;

char map[50][50];

char ex1[8][8]={ // ù��° ���  
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char ex2[8][8]={ // �ι�° ���  
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int main(){
	int n,m; cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	
	int ans=INF;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+8<=n && j+8<=m){
				int ex1Cnt=0, ex2Cnt=0;
				for(int m=i;m<i+8;m++){
					for(int n=j;n<j+8;n++){
						if(map[m][n]!=ex1[m-i][n-j]) ex1Cnt++; // �ٸ� ���  
						if(map[m][n]!=ex2[m-i][n-j]) ex2Cnt++; // �ٸ� ���  
					}
				}
				int temp = min(ex1Cnt, ex2Cnt);
				if(temp<ans) ans = temp; // �ּҰ� ����  
				
			}
		}
	}
	
	cout<<ans; // �� ���  
}
