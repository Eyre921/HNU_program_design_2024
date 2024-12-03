#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, d, new_house = 2;
	cin >> n >> d;
	vector<int> house(n);
	for (int i = 0; i < n; i++) cin >> house[i];

	for (int i = 0; i < n - 1; i++)
	{
		if (house[i+1] - house[i] == 2*d)
		{
			new_house++;
		}
		else if (house[i+1] - house[i] > 2*d)
		{
			new_house += 2;
		}
	}
	cout << new_house;
}
