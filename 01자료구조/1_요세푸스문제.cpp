#include<iostream>
#include<queue>
using namespace std;

int main(void){
    int n,k; cin>>n>>k;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);

    int i=0;
    cout<<"<";
    while(true){
        if(!q.empty()){
            i++;
            if(i==k){
                cout<<q.front();
                q.pop();
                if(!q.empty())cout<<", "; 
                i=0;
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
        else break;
    }
    cout<<">";
}
