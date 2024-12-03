#include <iostream>
using namespace std;

// 快速排序函数声明
void qsort(int arr[], int low, int high);

// 交换两个元素的函数声明
void Swap(int *a, int *b);

// 调整数组，奇数在前，偶数在后，并分别排序
void arrange(int a[], int n);

int main()
{
    int n;
    cin >> n;  // 输入数组的长度n

    int *a = new int[n];  // 动态分配内存存储数组a
    for (int i = 0; i < n; i++)  // 输入n个整数
    {
        cin >> a[i];
    }

    arrange(a, n);  // 调用函数调整数组奇偶顺序并排序

    for (int i = 0; i < n; i++)  // 输出调整后的数组
        cout << a[i] << " ";

    delete[] a;  // 释放动态分配的内存
    return 0;
}

// 调整数组，使奇数在前，偶数在后，并分别对奇偶部分排序
void arrange(int a[], int n)
{
    int *p = a, *q = a + n - 1;  // 指针p指向数组的第一个元素，指针q指向数组的最后一个元素

    while (p < q)  // 当p指针小于q指针时，继续交换
    {
        // 找到第一个偶数
        while (*p % 2 != 0)
        {
            p++;
        }

        // 找到第一个奇数
        while (*q % 2 == 0)
        {
            q--;
        }

        // 如果p小于q，则交换p和q所指向的元素，并更新指针
        if (p < q)
        {
            swap(*p, *q);  // 交换p和q所指向的元素
            p++;  // p指针向右移动
            q--;  // q指针向左移动
        }
    }

    int m;
    if (p == q)  // 如果p和q相遇
        m = (*p % 2 ? (p - a) : (p - a - 1));  // 如果p指向奇数，返回奇数部分的长度，否则返回偶数部分的起始位置
    else
        m = q - a;  // m是奇数部分的末尾位置

    qsort(a, 0, m);  // 调用快速排序对奇数部分排序
    qsort(a, m + 1, n - 1);  // 调用快速排序对偶数部分排序
}

// 快速排序的实现
void qsort(int *p, int low, int high)
{
    if (high <= low) return;  // 递归终止条件

    int key = p[low];  // 选取基准元素
    int i = low, j = high + 1;

    // 进行分区操作
    while (1)
    {
        // 从左侧找到大于等于key的元素
        while (p[++i] < key)
        {
            if (i == high) break;  // 如果i越界，退出
        }

        // 从右侧找到小于等于key的元素
        while (p[--j] > key)
        {
            if (j == low) break;  // 如果j越界，退出
        }

        if (i >= j) break;  // 如果i和j交错，退出循环

        Swap(&p[i], &p[j]);  // 交换p[i]和p[j]的值
    }

    Swap(&p[low], &p[j]);  // 将基准元素放到正确位置

    qsort(p, low, j - 1);  // 递归对基准元素左侧部分排序
    qsort(p, j + 1, high);  // 递归对基准元素右侧部分排序
}

// 交换两个元素的值
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
