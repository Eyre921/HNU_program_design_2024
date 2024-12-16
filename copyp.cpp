#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

// StringWrapper 类定义
// 用于包装一个字符串，并提供基本的字符串操作
class StringWrapper
{
private:
    char *str; // 动态分配的字符数组，用来存储字符串内容

public:
    // 构造函数
    // 默认构造函数，如果没有传入参数，则初始化为空字符串
    // 如果传入参数 s，则根据 s 的长度动态分配内存并复制字符串
    StringWrapper(const char *s = "")
    {
        if (s)
        {
            // 根据 s 的长度分配内存，+1 是为了存储字符串的结束符 '\0'
            str = new char[strlen(s) + 1];
            // 将传入的字符串复制到新分配的内存中
            strcpy(str, s);
        } else
        {
            // 如果传入的 s 是空字符串或者 nullptr
            // 分配一字节空间，并设置为 '\0'，表示空字符串
            str = new char[1];
            *str = '\0';
        }
    }

    // 拷贝构造函数
    // 用于创建一个 StringWrapper 的副本，确保进行深拷贝
    // 新的对象将拥有自己独立的内存，不会与原对象共享内存
    StringWrapper(const StringWrapper &other)
    {
        // 根据 other.str 的长度分配内存，并复制其内容
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str); // 将 other 的字符串内容复制到新分配的内存中
    }

    // 析构函数
    // 当对象销毁时，释放动态分配的内存
    ~StringWrapper()
    {
        delete[] str; // 释放 str 所指向的内存
    }

    // 获取字符串内容
    // 返回当前对象中的字符串内容
    const char *getStr() const
    {
        return str; // 返回 str 字符指针，指向当前对象的字符串内容
    }
};

// 测试深拷贝的函数
void testDeepCopy()
{
    // 创建 StringWrapper 对象 sw1，并初始化为 "Hello, World!"
    StringWrapper sw1("Hello, World!");
    // 使用拷贝构造函数创建 sw2，sw2 将是 sw1 的深拷贝
    StringWrapper sw2 = sw1; // 使用拷贝构造函数

    char ch;
    cin >> ch; // 让用户输入一个字符，修改 sw1 中的字符串内容

    // 通过 const_cast 修改 sw1 中的字符串（不推荐直接这么做，实际中最好避免修改常量数据）
    const char *temp = sw1.getStr();
    const_cast<char *>(temp)[7] = ch; // 修改 sw1 的字符串内容，字符位置 7 改为用户输入的字符

    // 打印 sw1 和 sw2 的字符串内容，验证深拷贝的效果
    cout << "sw1: " << sw1.getStr() << endl; // 输出修改后的 sw1 字符串
    cout << "sw2: " << sw2.getStr() << endl; // 输出未修改的 sw2 字符串，应该保持原样

    // 验证两个 StringWrapper 对象是否独立
    // 修改 sw1 不应影响 sw2 的内容，证明深拷贝成功
    // 由于深拷贝，sw2 的内容应保持不变
}

// 主函数
int main()
{
    testDeepCopy(); // 调用 testDeepCopy 函数进行测试
    return 0; // 程序结束
}


/*
 *#include <iostream>

#include <cstring>
#include <cassert>
using namespace std;

// StringWrapper 类定义
class StringWrapper
{
private:
    char *str; // 字符串内容，通过指针 str 动态分配内存存储字符串

public:
    // 构造函数
    // 该构造函数可以接受一个字符串参数 s，若没有提供参数，则默认为空字符串
    StringWrapper(const char *s = "")
    {
        // 如果传入的字符串 s 非空（即不是 nullptr 或 ""）
        if (s)
        {
            // 动态分配内存来存储传入的字符串，+1 是为了存储字符串结束符 '\0'
            str = new char[strlen(s) + 1];
            // 使用 strcpy 将字符串 s 复制到刚分配的内存中
            strcpy(str, s);
        } else
        {
            // 如果传入的字符串是空字符串 "" 或 nullptr
            // 则为 str 分配一个字符长度为 1 的内存，用来存储结束符 '\0'
            str = new char[1];
            *str = '\0'; // 将该内存位置设置为 '\0'，表示空字符串
        }
    }

    // 析构函数
    // 析构函数用于释放由构造函数分配的内存，避免内存泄漏
    ~StringWrapper()
    {
        delete[] str; // 释放动态分配的内存
    }

    // 获取字符串内容
    // 返回保存的字符串内容，const char* 类型，不能修改返回的字符串
    const char *getStr() const
    {
        return str;
    }

    // 拷贝构造函数
    // 用于深拷贝，确保每个对象拥有独立的内存空间
    StringWrapper(const StringWrapper &other)
    {
        // 为新对象分配内存，并将原对象的字符串内容复制过来
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // 赋值运算符重载
    // 用于确保赋值时进行深拷贝，避免原对象和赋值对象共享内存
    StringWrapper &operator=(const StringWrapper &other)
    {
        if (this != &other)
        {
            // 防止自我赋值
            // 先释放当前对象的内存
            delete[] str;
            // 为当前对象分配新的内存，并复制字符串内容
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
};

// 主函数：用于测试 StringWrapper 类的功能
int main()
{
    // 创建 StringWrapper 对象 str1，并初始化为 "Hello, World!"
    StringWrapper str1("Hello, World!");
    // 输出 str1 中保存的字符串内容
    cout << "str1: " << str1.getStr() << endl;

    // 创建 StringWrapper 对象 str2，初始化为空字符串
    StringWrapper str2("");
    // 输出 str2 中保存的字符串内容
    cout << "str2: " << str2.getStr() << endl;

    // 创建一个 StringWrapper 对象 str3，使用默认构造函数（空字符串）
    StringWrapper str3;
    // 输出 str3 中保存的字符串内容
    cout << "str3: " << str3.getStr() << endl;

    // 使用拷贝构造函数创建 str4，它是 str1 的一个副本
    StringWrapper str4 = str1;
    // 输出 str4 中保存的字符串内容
    cout << "str4 (copy of str1): " << str4.getStr() << endl;

    // 使用赋值运算符重载将 str2 赋值为 str1 的内容
    str2 = str1;
    // 输出 str2 中保存的字符串内容
    cout << "str2 (assigned from str1): " << str2.getStr() << endl;

    return 0;
}
*/
