#include <iostream>

using namespace std;

// 递归排序四个数
void mergeSort(int arr[], int left, int right) {
	if (left >= right) {
		// 基本情况：只有一个数或没有数，已经是有序的
		return;
	}

	int mid = left + (right - left) / 2;

	// 递归地对左边和右边的子数组进行排序
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	// 合并两个已排序的子数组
	int temp[right - left + 1];
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}

	// 处理剩余的元素
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	// 将排序后的元素复制回原数组
	for (i = left, k = 0; i <= right; ++i, ++k) {
		arr[i] = temp[k];
	}
}

int main() {
	int numbers[4];
	for (int i = 0; i < 4; i++) {
		cin >> numbers[i];
	}

	// 使用归并排序对四个数进行排序
	mergeSort(numbers, 0, 3);

	// 输出排序后的结果
	for (int i = 0; i < 4; i++) {
		cout << numbers[4 - i - 1] << " ";
	}
	cout << endl;

	return 0;
}