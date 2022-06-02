#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vc;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n;i++) { 
		int val;
		scanf("%d", &val);
		vc.push_back(val);
	}
	sort(vc.begin(), vc.end());
	while (m--) { int s, e;
	scanf("%d %d", &s, &e);
	auto lo = lower_bound(vc.begin(), vc.end(), s);
	auto hi = lower_bound(vc.begin(), vc.end(), e);
	if(lo == vc.end()) { 
		printf("0\n");
		continue;
	}
	if(hi == vc.end())
		printf("%d\n", vc.size() - (lo - vc.begin()));
	else if (vc[hi - vc.begin()] > e) { 
		hi--;
		printf("%d\n", (hi - vc.begin())-(lo - vc.begin()) + 1); }
	else
		printf("%d\n", (hi - vc.begin()) - (lo - vc.begin()) + 1); }
	return 0;
}
