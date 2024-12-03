#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int sum = 0, n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
		if (v[i] % 4 == 0 || v[i] % 7 == 0)
			sum += v[i];
	}
	cout << sum;
}

