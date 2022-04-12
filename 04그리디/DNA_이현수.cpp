#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// int �������� ��������, char �������� ��������  
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
	// �Է�  
	int n,m; // ���� m�� n���� dna 
	cin>>n>>m;
	
	vector<string> dna(n); // n���� dna ���� ����  
	for(int i=0;i<n;i++) cin>>dna[i]; // n���� dna �Է�  
	
	string s="";  // Hamming Distance�� ���� ���� ���� DNA s
	int hammingDistance=0; // Hamming Distance�� ���� �ּҰ� ����  ����  
	for(int i=0;i<m;i++){ // dna ���� m��ŭ �ݺ��ϸ鼭 �� �ڸ��� üũ  
		int a=0, t=0, g=0, c=0; // ����Ŭ����Ƽ�� ����  
		for(int j=0;j<n;j++){ // n���� dna�� ���ؼ� i��° �ڸ����� �ִ�... 
			if(dna[j][i]=='A') a++;
			else if(dna[j][i]=='T') t++;
			else if(dna[j][i]=='G') g++;
			else c++;
		}
		vector<pair<int, char> > sorting; // �����ϱ� ���� ���� 
		sorting.push_back({a,'A'});
		sorting.push_back({t,'T'});
		sorting.push_back({g,'G'});
		sorting.push_back({c,'C'});
		//int �������� ��������, char �������� ��������
		sort(sorting.begin(), sorting.end(), cmp); // ����  
		
		hammingDistance += (n-sorting[0].first); // Hamming Distance �����ֱ�  
		s += sorting[0].second; // dna s �߰��ϱ�  
	}
	
	// �� ��� 
	cout<<s<<'\n';
	cout<<hammingDistance; 
}
