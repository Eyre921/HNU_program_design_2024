#include <iostream>

using namespace std;

// �ݹ������ĸ���
void mergeSort(int arr[], int left, int right) {
	if (left >= right) {
		// ���������ֻ��һ������û�������Ѿ��������
		return;
	}

	int mid = left + (right - left) / 2;

	// �ݹ�ض���ߺ��ұߵ��������������
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	// �ϲ������������������
	int temp[right - left + 1];
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	// ����ʣ���Ԫ��
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	// ��������Ԫ�ظ��ƻ�ԭ����
	for (i = left, k = 0; i <= right; ++i, ++k) {
		arr[i] = temp[k];
	}
}

int main() {
	int numbers[4];
	for (int i = 0; i < 4; i++) {
		cin >> numbers[i];
	}

	// ʹ�ù鲢������ĸ�����������
	mergeSort(numbers, 0, 3);

	// ��������Ľ��
	for (int i = 0; i < 4; i++) {
		cout << numbers[4 - i - 1] << " ";
	}
	cout << endl;

	return 0;
}