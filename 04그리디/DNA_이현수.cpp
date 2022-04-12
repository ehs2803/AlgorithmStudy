#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// int 기준으로 내림차순, char 기준으로 오름차순  
bool cmp(const pair<int, char> & a, const pair<int, char> & b){
	if(a.first==b.first){
		if(a.second<b.second) return true;
		else return false;
	}
	else if(a.first>b.first) return true;
	else return false;
}

// (Adenine, Thymine, Guanine, Cytosine)
int main(){
	// 입력  
	int n,m; // 길이 m인 n개의 dna 
	cin>>n>>m;
	
	vector<string> dna(n); // n개의 dna 저장 벡터  
	for(int i=0;i<n;i++) cin>>dna[i]; // n개의 dna 입력  
	
	string s="";  // Hamming Distance의 합이 가장 작은 DNA s
	int hammingDistance=0; // Hamming Distance의 합의 최소값 저장  변수  
	for(int i=0;i<m;i++){ // dna 길이 m만큼 반복하면서 각 자리수 체크  
		int a=0, t=0, g=0, c=0; // 각뉴클레오티드 개수  
		for(int j=0;j<n;j++){ // n개의 dna에 대해서 i번째 자리수에 있는... 
			if(dna[j][i]=='A') a++;
			else if(dna[j][i]=='T') t++;
			else if(dna[j][i]=='G') g++;
			else c++;
		}
		vector<pair<int, char> > sorting; // 정렬하기 위한 벡터 
		sorting.push_back({a,'A'});
		sorting.push_back({t,'T'});
		sorting.push_back({g,'G'});
		sorting.push_back({c,'C'});
		//int 기준으로 내림차순, char 기준으로 오름차순
		sort(sorting.begin(), sorting.end(), cmp); // 정렬  
		
		hammingDistance += (n-sorting[0].first); // Hamming Distance 더해주기  
		s += sorting[0].second; // dna s 추가하기  
	}
	
	// 답 출력 
	cout<<s<<'\n';
	cout<<hammingDistance; 
}
