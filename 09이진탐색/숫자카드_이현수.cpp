#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int> & a, int num) {
    int l = 0;
    int r = a.size()-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (a[mid] == num) {
            return 1;
        } else if (a[mid] > num) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return 0;
}
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
       if(binary_search(vn, vm[i])) cout<<1<<' ';
        else cout<<0<<' ';
    }
}
