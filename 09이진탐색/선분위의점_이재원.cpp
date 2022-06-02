#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 주어진 선분마다 선분 위에 입력으로 주어진 점이 몇 개 있는지 출력 
vector<int> vc;
int main() {
	int n, m; // 점의 개수 n, 선분의 개수 m 
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n;i++) { 
		int val;
		scanf("%d", &val); // 점의 좌표 
		vc.push_back(val); // vector에 입력 
	}
	sort(vc.begin(), vc.end()); // 순서대로 오름차순 정리 
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e); // 선분의 시작점, 끝점 
		
		// 시작점 이상이 존재하는 인덱스를 찾음 
		auto lo = lower_bound(vc.begin(), vc.end(), s); 
		// 끝점 이상이 존재하는 인덱스를 찾음 
		auto hi = lower_bound(vc.begin(), vc.end(), e);
	
		//시작점 이상이 존재하는 인덱스 값이 점의 개수와 동일하다면 
		if(lo == vc.end()) { 
			printf("0\n"); // 선분상에 점이 없음 
			continue;
		}
		
		// 끝점 이상이 존재하는 인덱스 값이 점의 개수와 동일하다면 
		if(hi == vc.end())
			//벡터 size - (시작점 이상 인덱스 값 - 가장 작은 값) 
			printf("%d\n", vc.size() - (lo - vc.begin()));
		
		// 현재 인덱스 값이 끝점보다 더 크다면 
		else if (vc[hi - vc.begin()] > e) { 
			hi--; // hi를 -1 해준다 
			printf("%d\n", (hi - vc.begin()) - (lo - vc.begin()) + 1); 
			}
		
		// 나머지 
		else
			printf("%d\n", (hi - vc.begin()) - (lo - vc.begin()) + 1); 
	} 
	return 0;
}
