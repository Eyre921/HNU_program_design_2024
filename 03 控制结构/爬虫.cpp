#include <iostream>
using namespace std;

int main() {
	int target[3], up[3], down[3];

	// ����Ŀ��ֵ��������
	cin >> target[0] >> up[0] >> down[0]
	    >> target[1] >> up[1] >> down[1]
	    >> target[2] >> up[2] >> down[2];

	for (int q = 0; q < 3; q++) {
		int time = 0; // ��ʼ��ʱ��
		for (int i = 1;; i++) {
			if (i * up[q] - (i - 1) * down[q] >= target[q]) {
				time = 2 * i - 1;
				break;
			}
		}

		if (target[q] != 0)
			cout << time << endl; // ������
	}

	return 0;
}



