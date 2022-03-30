#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> movie;
	int num = 666;
	string check;
	while (movie.size() < n)
	{
		check = to_string(num); // stoi, atoi
		if (check.find("666") != string::npos) {
			movie.push_back(num);
		}
		num++;
	}
	cout << movie.back();
}
