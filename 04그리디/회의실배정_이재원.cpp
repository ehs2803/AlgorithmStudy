#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, end, begin;

	vector<pair<int, int>> schedule; // ������ vector������ <����, ����>

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin)); // ������ �����Ѵ�. (����, ����)
	}

	sort(schedule.begin(), schedule.end()); // ������ ������� ���� ������������ �����Ѵ�
	// �Է°� (1, 3)�� (2, 3)�� ���� ��� (3, 1) (3, 2) ������� �����

	int time = schedule[0].first;
	// �ð� = ���۽ð��� ����ð��� ���� ���� ����(�������� ��������)�� ����
	
	int count = 1; // count���� 1���� �����Ѵ�(�����ִ� ȸ�ǽ��� �ּ� 1���̱� ����)
	for (int i = 1;i < N; i++)
	{
		if (time <= schedule[i].second) // �ð� <= �ι�° ������ ����
		{
			count++; // count���� �ø���
			time = schedule[i].first; // �ð� ������ ���� �������� �����Ѵ�
		}
	}

	cout << count << '\n'; // count���� ����Ѵ�
	return 0;
}
