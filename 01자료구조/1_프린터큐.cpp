#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(int i, int j){
	if(i>j) return true;
	else return false;
}

int main(){
    int t; cin>>t;
    
    while(t--){
        queue<pair<int,int> > q;
        vector<int> importance;
        int n,m; cin>>n>>m;
        // input
        for(int i=0;i<n;i++){
            int temp; cin>>temp;
            importance.push_back(temp);
            if(i==m){
                q.push({temp,1});
            }
            else q.push({temp,0});
        }
        
        // sort
        sort(importance.begin(), importance.end(), cmp);
        
        int printIndex=0;
        int cnt=0;
        while(true){
            if(q.front().first==importance[printIndex]){
                if(q.front().second==1){
                	cnt++;
                    cout<<cnt<<'\n';
                    break;
                }
                else{
                    q.pop();
                    printIndex++;
                    cnt++;
                }
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }
}
