#include<iostream>
using namespace std;

// 定义 Point 类
class Point
{
public:
    // 默认构造函数，将 X 和 Y 初始化为 0
    Point()
    {
        X = Y = 0;
        cout << "默认构造函数被调用。" << endl;
    }

    // 带参数的构造函数，用于初始化 X 和 Y
    Point(int xx, int yy)
    {
        X = xx;
        Y = yy;
        cout << "构造函数被调用。" << endl;
    }

    // 析构函数，在对象销毁时调用
    ~Point()
    {
        cout << "析构函数被调用。" << endl;
    }

    // 返回 X 的值
    int GetX() { return X; }

    // 返回 Y 的值
    int GetY() { return Y; }

    // 将点的位置移动到指定的 (x, y) 位置
    void Move(int x, int y)
    {
        X = x;
        Y = y;
    }

private:
    int X, Y; // 坐标 X 和 Y
};

// 定义 ArrayOfPoints 类，表示一组 Point 对象
class ArrayOfPoints
{
public:
    // 带参数的构造函数，用于动态分配 Point 对象数组
    ArrayOfPoints(int n)
    {
        cout << "正在构造点数组..." << endl;
        numberOfPoints = n;
        points = new Point[n]; // 动态分配 Point 对象数组
    }

    // 自定义拷贝构造函数，进行深拷贝
    ArrayOfPoints(const ArrayOfPoints &other)
    {
        cout << "正在复制点数组..." << endl;
        numberOfPoints = other.numberOfPoints;
        points = new Point[numberOfPoints]; // 为新对象分配内存
        for (int i = 0; i < numberOfPoints; i++)
        {
            points[i] = other.points[i]; // 深拷贝每一个 Point 对象
        }
    }

    // 析构函数，释放动态分配的内存
    ~ArrayOfPoints()
    {
        cout << "正在删除..." << endl;
        delete[] points; // 删除动态分配的 Point 对象数组
    }

    // 返回指定位置的 Point 对象的引用
    Point &Element(int n)
    {
        return points[n];
    }

private:
    Point *points; // 指向动态分配的 Point 对象数组的指针
    int numberOfPoints; // 数组中的点的数量
};

// 主函数
int main()
{
    int number;
    cout << "请输入点的数量：";
    cin >> number;

    // 创建一个点数组对象 pointsArray1
    ArrayOfPoints pointsArray1(number);

    // 通过 Element 方法访问数组中的点并移动它们
    pointsArray1.Element(0).Move(5, 10);
    pointsArray1.Element(1).Move(15, 20);

    // 使用拷贝构造函数创建 pointsArray2，复制 pointsArray1
    ArrayOfPoints pointsArray2(pointsArray1);

    // 输出 pointsArray2 中的点的坐标
    cout << "pointsArray1 的副本：" << endl;
    cout << "array2 中的点_0: "
            << pointsArray2.Element(0).GetX()
            << ", " << pointsArray2.Element(0).GetY() << endl;
    cout << "array2 中的点_1: "
            << pointsArray2.Element(1).GetX()
            << ", " << pointsArray2.Element(1).GetY() << endl;

    // 修改 pointsArray1 中的点的坐标
    pointsArray1.Element(0).Move(25, 30);
    pointsArray1.Element(1).Move(35, 40);

    // 输出修改后的 pointsArray2 中的点的坐标，检查是否受影响
    cout << "修改 pointsArray1 之后：" << endl;
    cout << "array2 中的点_0: "
            << pointsArray2.Element(0).GetX()
            << ", " << pointsArray2.Element(0).GetY() << endl;
    cout << "array2 中的点_1: "
            << pointsArray2.Element(1).GetX()
            << ", " << pointsArray2.Element(1).GetY() << endl;

    system("pause"); // 暂停程序，方便查看输出结果
    return 0;
}
