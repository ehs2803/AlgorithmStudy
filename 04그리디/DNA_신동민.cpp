#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상

	string s = "";
	int count = 0;
	map<char, int> nucleotide = { { 'A', 0 },{ 'C', 0 },{ 'G', 0 }, { 'T', 0 } };

	int n, m;
	cin >> n >> m;
	vector<string> dna;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		dna.push_back(tmp);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			nucleotide[dna[j][i]]++;
		}

		int max = 0;
		char max_char = ' ';
		for (auto& tmp : nucleotide) {
			if (tmp.second > max) {
				max = tmp.second;
				max_char = tmp.first;
			}
			tmp.second = 0;
		}
		count += n - max;
		s += max_char;
	}
	cout << s << "\n" << count << "\n";
}
