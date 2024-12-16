#include <iostream>
using namespace std;

// 定义人物类，用于表示每个参与游戏的人
class Person {
private:
    int number;      /* 人物编号 */
    Person *next;    /* 指向下一个人的指针 */
public:
    // 构造函数，初始化人物编号和下一个指针为空
    Person(int num) {
        number = num;
        next = NULL;
    }

    // 设置下一个人的指针
    void setNext(Person *p) {
        next = p;
    }

    // 获取当前人物的编号
    int getNumber() {
        return number;
    }

    // 获取下一个人的指针
    Person *getNext() {
        return next;
    }
};

// 定义循环类，用于模拟约瑟夫环问题
class Cycle {
private:
    Person *start;   /* 起始位置，表示开始数数的位置 */
    int out;         /* 数到几出列 */
    int inQueue;     /* 当前队列中人的数量 */
public:
    // 构造函数，初始化人数、开始数数的位置和每次出列的计数
    Cycle(int num, int from, int whoOut) {
        inQueue = num;  // 初始化队列中的人数
        out = whoOut;   // 初始化数到几出列
        Person *prev = NULL, *first = NULL;

        // 创建所有的人物对象，并将它们连接成一个循环链表
        for (int i = 1; i <= num; i++) {
            Person *p = new Person(i);  // 创建一个新的人物
            if (i == 1)
                first = p;  // 第一个人作为起始点
            if (i == from)
                start = p;  // 设置从哪位开始数
            if (i > 1)
                prev->setNext(p);  // 将前一个人指向当前的人

            prev = p;  // 更新前一个人
        }

        // 完成循环链表的连接：最后一个人指向第一个人，形成循环
        prev->setNext(first);
    }

    // 获取队列中当前的总人数
    int getInQueue() {
        return inQueue;
    }

    // 模拟数数过程，按照要求确定出列的人并将其从队列中移除
    void count() {
        Person *current = start;  // 当前从哪个人开始数

        // 如果每次都从第一人开始数，则更新出列数
        if (out == 1) {
            out += this->inQueue;
        }

        Person *toDelete = NULL;

        // 遍历链表，找到要出列的人
        for (int z = 2; z <= out - 1; z++) {
            toDelete = current->getNext();
            current = toDelete;
        }

        // 当前人的下一个人是要出列的人
        toDelete = current->getNext();
        toDelete = toDelete->getNext();  // 跳过出列的人

        current->setNext(toDelete);  // 将当前人的下一个人指向要删除的人的下一个人

        inQueue -= 1;  // 队伍中的人数减一
        toDelete = current->getNext();  // 更新当前指针
        start = toDelete;  // 更新起始位置
    }

    // 获取起始位置的指针
    Person *getStart() {
        return start;
    }

    // 析构函数，释放内存
    ~Cycle() {
        delete start;
    }
};

int main() {
    int n, k, m;  // n: 圈内人数，k: 从哪个人开始数，m: 每次数到几出列
    cin >> n >> k >> m;

    // 创建循环链表对象，并初始化
    Cycle *p = new Cycle(n, k, m);

    // 通过循环进行计数，直到只剩一个人
    while (p->getInQueue() > 1) {
        p->count();
    }

    // 输出最后剩下的人的编号
    Person *winner = p->getStart();
    cout << winner->getNumber() << endl;

    // 释放内存
    delete p;

    return 0;
}
