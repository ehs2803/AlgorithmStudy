#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m; 
    cin>>n;
    vector<int> vn(n);
    for(int i=0;i<n;i++) cin>>vn[i];
    sort(vn.begin(), vn.end());
    
    cin>>m;
    vector<int> vm(m);
    for(int i=0;i<m;i++) cin>>vm[i];
    
    for(int i=0;i<m;i++){
       if(binary_search(vn.begin(), vn.end(), vm[i])) cout<<1<<' ';
        else cout<<0<<' ';
    }
}
