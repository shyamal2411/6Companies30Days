#include <bits/stdc++.h>
using namespace std;

void findMax(
	string s, int k, string& max)
{
	if (k == 0)	return;
	int n = s.size();

	for (int i = 0; i < n - 1; i++) {

		for (int j = i + 1; j < n; j++) {

			if (s[i] < s[j]) {
				swap(s[i], s[j]);

				if (s.compare(max) > 0)
					max = s;
				findMax(s, k - 1, max);

				swap(s[i], s[j]);
			}
		}
	}
}

int main()
{
	string s = "129814999";
	int k = 4;
	string max = s;
	findMax(s, k, max);
	cout << max << endl;
	return 0;
}
