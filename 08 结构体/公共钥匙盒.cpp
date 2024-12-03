#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Teacher {
    int key;  // 需要的教室钥匙编号
    int startTime;  // 开始上课的时间
    int endTime;    // 下课时间（即还钥匙时间）
    bool returned = false;  // 是否已还钥匙
};

// 函数声明
bool compareByKey(Teacher a, Teacher b);
void returnKeyToHooks(vector<int>& hooks, Teacher t);
void borrowKeyFromHooks(vector<int>& hooks, Teacher& t);

bool compareByKey(Teacher a, Teacher b) {
    return a.key < b.key;  // 按照钥匙编号升序排序
}

void returnKeyToHooks(vector<int>& hooks, Teacher t) {
    // 查找第一个空挂钩并放入钥匙
    auto it = find(hooks.begin(), hooks.end(), 0);
    if (it != hooks.end()) {
        *it = t.key;  // 将钥匙放到空挂钩上
    }
}

void borrowKeyFromHooks(vector<int>& hooks, Teacher& t) {
    // 查找钥匙并取走
    auto it = find(hooks.begin(), hooks.end(), t.key);
    if (it != hooks.end()) {
        *it = 0;  // 将钥匙从挂钩上取下
    }
}

int main() {
    int numHooks;  // 钥匙挂钩数量
    cin >> numHooks;
    vector<int> hooks(numHooks);  // 钥匙挂钩的状态
    for (int i = 0; i < numHooks; i++) {
        hooks[i] = 1 + i;  // 初始化挂钩上的钥匙编号
    }

    int numTeachers;  // 老师的数量
    cin >> numTeachers;
    vector<Teacher> teachers(numTeachers);  // 老师们的信息
    for (int i = 0; i < numTeachers; i++) {
        cin >> teachers[i].key >> teachers[i].startTime >> teachers[i].endTime;
        teachers[i].endTime += teachers[i].startTime;  // 计算下课时间，即还钥匙时间
    }

    int returnedKeys = 0;  // 记录已还钥匙的老师数量

    // 使用STL sort按照钥匙编号排序
    sort(teachers.begin(), teachers.end(), compareByKey);

    // 处理老师们的上课和还钥匙过程
    for (int currentTime = 1; returnedKeys < numTeachers; currentTime++) {
        // 先处理所有还钥匙的操作
        for (int i = 0; i < numTeachers; i++) {
            if (currentTime == teachers[i].endTime) {
                if (!teachers[i].returned) {
                    returnKeyToHooks(hooks, teachers[i]);
                    returnedKeys++;
                    teachers[i].returned = true;
                }
            }
        }

        // 然后处理所有取钥匙的操作
        for (int i = 0; i < numTeachers; i++) {
            if (currentTime == teachers[i].startTime) {
                borrowKeyFromHooks(hooks, teachers[i]);
            }
        }
    }

    // 输出最终的挂钩状态（钥匙的顺序）
    for (int i = 0; i < numHooks; i++) {
        cout << hooks[i] << " ";
    }

    return 0;
}
/*
【问题描述】

   有一个学校的老师共用N个教室，按照规定，所有的钥匙都必须放在公共钥匙盒里，老师不能带钥匙回家。每次老师上课前，都从公共钥匙盒里找到自己上课的教室的钥匙去开门，上完课后，再将钥匙放回到钥匙盒中。
  　　钥匙盒一共有N个挂钩，从左到右排成一排，用来挂N个教室的钥匙。一串钥匙没有固定的悬挂位置，但钥匙上有标识，所以老师们不会弄混钥匙。
  　　每次取钥匙的时候，老师们都会找到自己所需要的钥匙将其取走，而不会移动其他钥匙。每次还钥匙的时候，还钥匙的老师会找到最左边的空的挂钩，将钥匙挂在这个挂钩上。如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。如果同一时刻既有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出。
  　　今天开始的时候钥匙是按编号从小到大的顺序放在钥匙盒里的。有K位老师要上课，给出每位老师所需要的钥匙、开始上课的时间和上课的时长，假设下课时间就是还钥匙时间，请问最终钥匙盒里面钥匙的顺序是怎样的？

【输入形式】

   输入的第一行包含两个整数N, K。
  　　接下来K行，每行三个整数w, s, c，分别表示一位老师要使用的钥匙编号、开始上课的时间和上课的时长。可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重叠。
  　　保证输入数据满足输入格式，你不用检查数据合法性。

【输出形式】

   输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥匙编号。

【样例输入1】

5 2
4 3 3
2 2 7

【样例输出1】

1 4 3 2 5


【样例输入2】

5 7
1 1 14
3 3 12
1 15 12
2 7 20
3 18 12
4 21 19
5 30 9

【样例输出2】

1 2 3 5 4

【样例1说明】

   第一位老师从时刻3开始使用4号教室的钥匙，使用3单位时间，所以在时刻6还钥匙。第二位老师从时刻2开始使用钥匙，使用7单位时间，所以在时刻9还钥匙。
  　　每个关键时刻后的钥匙状态如下（X表示空）：
  　　时刻2后为1X345；
  　　时刻3后为1X3X5；
  　　时刻6后为143X5；
  　　时刻9后为14325。

【评分标准】
 */