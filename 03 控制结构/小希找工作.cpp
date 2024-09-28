#include <iostream>
using namespace std;

int suanfen (int qian, char jia, int juli);

struct Company {
	char order;
	int score;
};

int main() {
	Company companies[3] = {{'A', 0}, {'B', 0}, {'C', 0}};
	int qian = 0, juli = 0;
	char jia = 0;

	for (int i = 0; i < 3; i++) {
		cin >> qian >> jia >> juli;
		companies[i].score = suanfen(qian, jia, juli);
	}

	int max_score = companies[0].score;

	for (int i = 1; i < 3; i++) {
		if (companies[i].score > max_score)
			max_score = companies[i].score;
	}

	for (int i = 0; i < 3; i++) {
		if (companies[i].score == max_score)
			cout << companies[i].order;
	}
	return 0;
}




int suanfen (int qian, char jia, int juli) {
	int sum = 0, juli_score = 100;
	sum += qian / 50;
	if (jia == 'y')
		sum += 20;
	while ((juli - 2000) > 0) {
		juli_score -= 10;
		juli -= 200;
		if (juli_score < 0)
			juli_score = 0;
	}
	sum += juli_score;
	return sum;
}