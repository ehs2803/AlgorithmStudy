#include<iostream>
#include<string> 
using namespace std;

int main(){
	int n; cin>>n;
	
	int cnt=0;
	int title=0;
	
	while(1){
		string s = to_string(title);
		
		if(s.find("666")!=-1) cnt++;
		
		if(cnt==n){
			cout<<title<<'\n';
			break;
		}
		
		title++;
	}
}
