#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
	char name;
	int age;
};

int main() {
	int year[3][3];
	Person people[] = {{'A', 0}, {'B', 0}, {'C', 0}};

	// 获取并计算大小
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> year[i][j];
			if (j == 0)
				people[i].age += year[i][j] * 10000;
			else if (j == 1)
				people[i].age += year[i][j] * 100;
			else
				people[i].age += year[i][j] * 1;
		}
	}

	// 按照年龄升序排序
	sort(people, people + 3, [](const Person & a, const Person & b) {
		return a.age < b.age;
	});

	for (const auto &person : people) {
		cout << person.name;
	}
	return 0;
}


