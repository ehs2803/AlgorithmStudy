#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, end, begin;

	vector<pair<int, int>> schedule; // 일정을 vector값으로 <시작, 종료>

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin)); // 일정에 저장한다. (종료, 시작)
	}

	sort(schedule.begin(), schedule.end()); // 일정을 종료시점 기준 오름차순으로 정렬한다
	// 입력값 (1, 3)과 (2, 3)이 있을 경우 (3, 1) (3, 2) 순서대로 저장됨

	int time = schedule[0].first;
	// 시간 = 시작시간과 종료시간이 가장 빠른 벡터(오름차순 기준으로)의 종료
	
	int count = 1; // count값은 1부터 시작한다(열려있는 회의실은 최소 1개이기 때문)
	for (int i = 1;i < N; i++)
	{
		if (time <= schedule[i].second) // 시간 <= 두번째 일정의 시작
		{
			count++; // count값을 올린다
			time = schedule[i].first; // 시간 변수를 종료 시점으로 저장한다
		}
	}

	cout << count << '\n'; // count값을 출력한다
	return 0;
}
