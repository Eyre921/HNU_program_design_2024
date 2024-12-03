#include <iostream>
#include <cstring>
#include <string> // 引入头文件
using namespace std;

// 函数声明：将字符串进行反转
void reverseStr(char *s);

int main()
{
    char str[201]; // 定义一个长度为201的字符数组，存储输入的字符串
    cin.getline(str, 200); // 使用getline方法读取一行输入，最多读取200个字符
    reverseStr(str); // 调用reverseStr函数，反转输入的字符串
    puts(str); // 输出反转后的字符串
    return 0;
}

// 反转字符串的函数实现
void reverseStr(char *s)
{
    char *p = s, *q = s; // 定义两个指针，初始化都指向字符串的起始位置
    while (*q) // 遍历字符串，直到q指向字符串的结束符'\0'
        q++; // 将指针q移动到字符串末尾

    q--; // 指针q指向字符串的最后一个字符

    // 循环交换p和q指向的字符，直到p和q交叉或相遇
    while (p < q)
    {
        char t = *p; // 临时保存p指向的字符
        *p = *q; // 将q指向的字符赋值给p指向的位置
        *q = t; // 将临时保存的字符赋值给q指向的位置
        p++; // 指针p向右移动
        q--; // 指针q向左移动
    }
}
