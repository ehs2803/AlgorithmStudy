#include<iostream>
#include<string>
using namespace std;

int main(void){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        string str; cin>>str;
        int cnt=0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='(') cnt+=1;
            else cnt-=1;
            if(cnt<0){
                cout<<"NO\n";
                break;
            }
        }
        if(cnt==0) cout<<"YES\n";
        else if(cnt>0) cout<<"NO\n";
    }
}
