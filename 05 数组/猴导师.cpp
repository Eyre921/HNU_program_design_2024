#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n , k;
	cin >> n >> k;
	int power[n], be_tutor[n] = {0};
	set<pair<int, int>> conf;
	for (int i = 0; i < n; i++) cin >> power[i];
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		conf.insert({min(a, b), max(a, b)});
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pair<int, int> inputPair = {min(i+1, j+1), max(i+1, j+1)};
			if (!conf.count(inputPair) && power[i] > power[j])
			{
				be_tutor[i]++;
			}
		}
		cout << be_tutor[i] << " ";
	}
}
