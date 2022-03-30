#include<iostream>
using namespace std;

int map[10][10];
bool check_row[10][10];
bool check_col[10][10];
bool check_square[10][10];

void dfs(int row, int col)
{
	// 답 출력  
    if(row==10){ // 탐색이 완료된 경우  
    	for(int i=1;i<=9;i++){
    		for(int j=1;j<=9;j++){
    			cout<<map[i][j]<<' ';
			}
			cout<<'\n';
		}
		exit(0); // 프로그램 종료.  
	}
	
    if (map[row][col] == 0){ // 빈칸인 경우  
        for (int i = 1; i <= 9; i++){ // 1~9 숫자 모두를 시도해봄.  
            if (check_row[row][i] == false && check_col[col][i] == false && check_square[((row-1) / 3) * 3 + ((col-1) / 3)][i] == false){ 
                check_row[row][i] = true;
                check_col[col][i] = true;
                check_square[((row-1) / 3) * 3 + ((col-1) / 3)][i] = true;
                map[row][col] = i;
                
                // 다음칸으로 넘어가기  
                if(col==9) dfs(row+1,1);
    			else dfs(row, col+1);
    			
                check_row[row][i] = false;
                check_col[col][i] = false;
                check_square[((row-1) / 3) * 3 + ((col-1) / 3)][i] = false;
                map[row][col] = 0;
            }
        }
    }
    else{ // 빈칸이 아닌 경우. 다음 칸으로 그냥 넘어감. 
    	if(col==9) dfs(row+1,1);
    	else dfs(row, col+1);
	}
}

int main(){
	// 입력  
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++) {
			cin>>map[i][j];	
			if (map[i][j] != 0){
                check_row[i][map[i][j]] = true;
                check_col[j][map[i][j]] = true;
                check_square[((i-1) / 3) * 3 + ((j-1) / 3)][map[i][j]] = true;
            }
		}
	}	
		
	dfs(1,1);
}
