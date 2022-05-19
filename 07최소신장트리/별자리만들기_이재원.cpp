#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N;

vector<int> parent; // �θ� ��� 
vector<pair<float,float>> pos; // ��ġ 
vector<pair<double, pair<int, int>>> dist; // �Ÿ� 

//�ʱ�ȭ 
void Make_Set()
{
	parent.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
		parent[i] = i;
}

//����Ŭ�� �߻����� �ʴ��� 
int Find(int _x)
{
	if (parent[_x] != _x)
		parent[_x] = Find(parent[_x]);

	return parent[_x];
}

//���� 
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

	Make_Set(); //�ʱ�ȭ 

	for (int i = 0; i < N; i++)
	{
		float x, y;
		cin >> x >> y; // �� ���� x, y��ǥ 
		pos.push_back({ x, y }); //��ġ vector�� ���� 
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double r = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			dist.push_back({ r, {i + 1, j + 1} }); // �Ÿ� vector�� ���� 
		}
	}
	sort(dist.begin(), dist.end()); // �������� ���� 
	double res = 0;

//vector<pair<double, pair<int, int>>> dist; // �Ÿ� 

	for (int i = 0; i < dist.size(); i++)
	{
		double w = dist[i].first;
		int v = dist[i].second.first;
		int u = dist[i].second.second;

		if (Find(v) != Find(u)) // ���� �ٸ� �� ��, ����Ŭ �߻� ���� Ȯ�� 
		{
			Union(v, u);
			res += w; //�Ÿ���ŭ ��� �߰� 
		}
	}

	printf("%.2f", res); // ���ڸ��� ����� �ּ� ��� ���(�Ҽ� ��°�ڸ�����) 
	return 0;
}
