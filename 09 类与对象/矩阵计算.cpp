#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
    int rows, cols;     // 矩阵的行数和列数
    int **elements;     // 矩阵的数据，存储在二维数组中

public:
    Matrix();                                      // 默认构造函数
    Matrix(int &numRows, int &numCols);            // 带行列数的构造函数
    Matrix(Matrix &A, int &&removeRow, int &removeCol); // 从矩阵A中删除指定的行和列，得到新的矩阵
    ~Matrix();                                     // 析构函数

    Matrix multiply(int scalar);                   // 数乘操作
    int determinant();                              // 计算行列式
    void display();                                // 输出矩阵
    void input();                                  // 输入矩阵元素

    Matrix operator+(Matrix &another);              // 重载加法运算符，实现矩阵加法
    Matrix operator*(Matrix &another);              // 重载乘法运算符，实现矩阵乘法
};

// 默认构造函数
Matrix::Matrix() : rows(0), cols(0), elements(nullptr) {}

// 带行列数的构造函数，初始化矩阵大小
Matrix::Matrix(int &numRows, int &numCols)
{
    rows = numRows;
    cols = numCols;
    elements = new int *[rows]; // 动态分配行
    for (int i = 0; i < rows; i++)
    {
        elements[i] = new int[cols]; // 动态分配每一行的列
    }
}

// 从矩阵A中删除指定行和列，创建新矩阵
Matrix::Matrix(Matrix &A, int &&removeRow, int &removeCol)
{
    rows = A.rows - 1; // 新矩阵的行数
    cols = A.cols - 1; // 新矩阵的列数
    elements = new int *[rows]; // 动态分配行
    for (int i = 0; i < rows; i++)
    {
        elements[i] = new int[cols]; // 动态分配每一行的列
    }

    // 删除指定行和列
    for (int i = 0; i < removeRow; i++)
    {
        for (int j = 0; j < removeCol; j++)
        {
            elements[i][j] = A.elements[i][j];
        }
    }

    for (int i = 0; i < removeRow; i++)
    {
        for (int j = removeCol + 1; j < A.cols; j++)
        {
            elements[i][j - 1] = A.elements[i][j];
        }
    }

    for (int i = removeRow + 1; i < A.rows; i++)
    {
        for (int j = 0; j < removeCol; j++)
        {
            elements[i - 1][j] = A.elements[i][j];
        }
    }

    for (int i = removeRow + 1; i < A.rows; i++)
    {
        for (int j = removeCol + 1; j < A.cols; j++)
        {
            elements[i - 1][j - 1] = A.elements[i][j];
        }
    }
}

// 析构函数，释放动态分配的内存
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] elements[i];
    delete[] elements;
}

// 数乘操作
Matrix Matrix::multiply(int scalar)
{
    Matrix result(rows, cols); // 创建一个与当前矩阵同样大小的矩阵

    // 将当前矩阵的每个元素与标量相乘
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.elements[i][j] = this->elements[i][j] * scalar;
        }
    }

    return result;
}

// 输出矩阵
void Matrix::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << elements[i][j] << ' ';
        }
        cout << endl;
    }
}

// 输入矩阵元素
void Matrix::input()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> elements[i][j];
}

// 重载加法运算符，实现矩阵加法
Matrix Matrix::operator+(Matrix &another)
{
    Matrix result(rows, cols); // 创建一个与当前矩阵同样大小的矩阵

    // 矩阵对应位置的元素相加
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.elements[i][j] = this->elements[i][j] + another.elements[i][j];
        }
    }
    return result;
}

// 重载乘法运算符，实现矩阵乘法
Matrix Matrix::operator*(Matrix &another)
{
    Matrix result(rows, another.cols); // 创建一个与另一个矩阵乘积大小相同的矩阵

    // 矩阵乘法：计算第i行与第j列的点积
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < another.cols; j++)
        {
            result.elements[i][j] = 0; // 初始化该位置为0

            for (int k = 0; k < cols; k++)
            {
                result.elements[i][j] += this->elements[i][k] * another.elements[k][j];
            }
        }
    }
    return result;
}

// 计算行列式，使用递归方法
int Matrix::determinant()
{
    if (rows == 1)
        return elements[0][0]; // 1x1矩阵的行列式就是它的唯一元素
    else
    {
        int result = 0;
        int sign;
        for (int i = 0; i < cols; i++)
        {
            sign = (i % 2) ? -1 : 1;
            Matrix submatrix(*this, 0, i); // 删除第0行第i列，生成子矩阵
            result += sign * elements[0][i] * submatrix.determinant(); // 递归计算行列式
        }
        return result;
    }
}

// 主函数
int main()
{
    int rowsA, colsA;

    // 输入矩阵A的行数和列数
    cin >> rowsA >> colsA;

    Matrix matrixA(rowsA, colsA); // 创建矩阵A

    // 输入矩阵A的元素
    matrixA.input();

    // 输入数乘的标量
    int scalar;
    cin >> scalar;

    // 进行数乘操作
    Matrix matrixResultA = matrixA.multiply(scalar);

    // 输出数乘后的矩阵
    matrixResultA.display();

    // 输入矩阵B的行数和列数
    int rowsB, colsB;
    cin >> rowsB >> colsB;

    Matrix matrixB(rowsB, colsB); // 创建矩阵B
    matrixB.input(); // 输入矩阵B的元素

    // 矩阵A和矩阵B的和
    if (rowsA == rowsB && colsA == colsB)
    {
        Matrix matrixSum = matrixA + matrixB; // 矩阵加法
        matrixSum.display(); // 输出矩阵和
    }

    // 矩阵A和矩阵B的乘积
    if (colsA == rowsB)
    {
        Matrix matrixProduct = matrixA * matrixB; // 矩阵乘法
        matrixProduct.display(); // 输出矩阵乘积
    }

    // 计算矩阵A的行列式
    if (rowsA == colsA)
        cout << matrixA.determinant() << endl;

    // 计算矩阵B的行列式
    if (rowsB == colsB)
        cout << matrixB.determinant() << endl;

    return 0;
}
/*

#include <iostream>
#include <cstdlib>
using namespace std;

class matrix
{
private:
    int rows, cols;
    int **p;

public:
    matrix();

    matrix(int &M, int &N);

    matrix(matrix &A, int &&m, int &n);

    ~matrix();

    matrix multi(int x); // 数乘
    int det(); // 计算行列式
    void out(); //输出矩阵
    void input();

    matrix operator+(matrix &another); //重载加法运算实现矩阵相加
    matrix operator*(matrix &another); //重载乘法运算实现矩阵相乘
};

matrix::matrix(int &M, int &N)
{
    rows = M, cols = N;
    p = new int *[rows];
    for (int i = 0; i < M; i++)
    {
        p[i] = new int[cols];
    }
}

matrix::matrix(matrix &A, int &&m, int &n) //从矩阵A中删除第m行第n列后得到新的矩阵
{
    rows = A.rows - 1;
    cols = A.cols - 1;
    p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }

    // 从矩阵A中删除第m行第n列
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = A.p[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = n + 1; j < A.cols; j++)
        {
            p[i][j - 1] = A.p[i][j];
        }
    }

    for (int i = m + 1; i < A.rows; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i - 1][j] = A.p[i][j];
        }
    }

    for (int i = m + 1; i < A.rows; i++)
    {
        for (int j = n + 1; j < A.cols; j++)
        {
            p[i - 1][j - 1] = A.p[i][j];
        }
    }
}

matrix::~matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] p[i];

    delete[] p;
}

matrix matrix::multi(int x) // 数乘
{
    matrix tmp(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tmp.p[i][j] = this->p[i][j] * x;
        }
    }

    return tmp;
}

void matrix::out() //输出矩阵
{
    /* 逐行输出，数据间用空格分隔

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}

void matrix::input()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> p[i][j];
}

matrix matrix::operator+(matrix &another) //重载加法运算实现矩阵相加
{
    matrix tmp(rows, cols);
    /* 矩阵对应位置元素相加

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tmp.p[i][j] = this->p[i][j] + another.p[i][j];
        }
    }
    return tmp;

    return tmp;
}

matrix matrix::operator*(matrix &another) //重载乘法运算实现矩阵相乘
{
    matrix tmp(rows, another.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < another.cols; j++)
        {
            /* 计算A矩阵的第i行与B矩阵的第j列元素对应相乘后之和，作为新矩阵的第i行第j列元素的值

            tmp.p[i][j] = 0; // 初始化该位置为0

            // 计算A矩阵的第i行与B矩阵的第j列元素对应相乘后的累加和
            for (int k = 0; k < cols; k++)
            {
                tmp.p[i][j] += this->p[i][k] * another.p[k][j];
            }
        }
    }
    return tmp;
}

int matrix::det()
{
    if (rows == 1)
        return p[0][0];
    else
    {
        int result = 0, flag;
        for (int i = 0; i < cols; i++)
        {
            flag = (i % 2) ? -1 : 1;
            matrix tmp(*this, 0, i);
            result = result + flag * p[0][i] * tmp.det(); // 使用代数余子式求行列式的值, 递归
        }
        return result;
    }
}

int main()
{
    int M, N;

    // A矩阵的行和列
    cin >> M >> N;

    matrix mA(M, N); //生成A矩阵

    // 输入矩阵值

    mA.input();

    // 输入数乘值

    int x;
    cin >> x;

    matrix mm1 = mA.multi(x);

    mm1.out();

    //B矩阵的行和列
    int K, L;
    cin >> K >> L;

    matrix mB(K, L); //生成B矩阵
    mB.input();

    /* 求矩阵A和矩阵B的和

    if (M == K && N == L)
    {
        matrix mm2 = mA + mB;
        mm2.out();
    }

    /* 求矩阵A和矩阵B的乘积矩阵 *
    if (N == K)
    {
        matrix mm3 = mA * mB;
        mm3.out();
    }

    /* 矩阵A的行列式的值 *
    if (M == N)
        cout << mA.det() << endl;

    if (K == L)
        cout << mB.det() << endl;

    return 0;
}

 */