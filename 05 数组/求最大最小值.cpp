#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int size = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + size);
	cout << arr[n - 1] << " " << arr[0] << endl;
}
