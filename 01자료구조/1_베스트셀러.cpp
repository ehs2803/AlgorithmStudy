#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

// int 기준으로 내림차순, string 기준으로 오름차순 
bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if(a.second==b.second){
        if(a.first<b.first)return true;
        else return false;
    }
    else if(a.second<b.second) return false;
    else return true;
}

int main(){
    map<string, int> m;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string temp; cin>>temp;
        if(m.find(temp)!=m.end()){
            m[temp]+=1;
        }
        else{
            m[temp]=1;
        }
    }
    
    vector<pair<string,int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), cmp);
    
    cout<<v[0].first;
}
