#include <iostream>
#include <string>
using namespace std;

int main(){
	int inp; cin>>inp;
	int cnt = 0;
	string itos;
	
	int some = 666;
	
	if (inp ==1){
		cout << 666;
		return 0;
	}
	
	for(int i=666; i<10000000; i++){
		itos = to_string(i);
		if(itos.find("666") != string::npos){
			cnt+=1;		
		}
	
		if (cnt == inp) break;
	}
	
	cout<<itos;
}
