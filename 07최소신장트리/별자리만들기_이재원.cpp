#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N;

vector<int> parent; // 부모 노드 
vector<pair<float,float>> pos; // 위치 
vector<pair<double, pair<int, int>>> dist; // 거리 

//초기화 
void Make_Set()
{
	parent.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
		parent[i] = i;
}

//사이클이 발생하지 않는지 
int Find(int _x)
{
	if (parent[_x] != _x)
		parent[_x] = Find(parent[_x]);

	return parent[_x];
}

//병합 
void Union(int _x, int _y)
{
	int root1 = Find(_x);
	int root2 = Find(_y);

	parent[root1] = root2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	Make_Set(); //초기화 

	for (int i = 0; i < N; i++)
	{
		float x, y;
		cin >> x >> y; // 각 별의 x, y좌표 
		pos.push_back({ x, y }); //위치 vector에 저장 
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double r = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			dist.push_back({ r, {i + 1, j + 1} }); // 거리 vector에 저장 
		}
	}
	sort(dist.begin(), dist.end()); // 오름차순 정렬 
	double res = 0;

//vector<pair<double, pair<int, int>>> dist; // 거리 

	for (int i = 0; i < dist.size(); i++)
	{
		double w = dist[i].first;
		int v = dist[i].second.first;
		int u = dist[i].second.second;

		if (Find(v) != Find(u)) // 서로 다른 두 별, 사이클 발생 유무 확인 
		{
			Union(v, u);
			res += w; //거리만큼 비용 추가 
		}
	}

	printf("%.2f", res); // 별자리를 만드는 최소 비용 출력(소수 둘째자리까지) 
	return 0;
}
