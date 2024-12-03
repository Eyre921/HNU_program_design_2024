#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 变量 sum 用于计算激光穿越过的空心单元格数量
int sum = 0;
int n, m, k; // n 表示网格行数，m 表示网格列数，k 表示实心单元格的数量
vector<vector<short int>> grid;
vector<unsigned short int> visited;

// 函数声明
bool checkVisited(int row, int col, int rowDir, int colDir);
void tracePath(int row, int col, int rowDir, int colDir);

int main() {
    // 输入网格的大小和实心单元的数量
    cin >> n >> m >> k;

    // 使用 STL vector 初始化网格
    grid = vector<vector<short int>>(n + 2, vector<short int>(m + 2, 0));

    // 设置边界的单元格为实心单元
    for (int j = 0; j < m + 2; j++) {
        grid[0][j] = grid[n + 1][j] = 1;
    }
    for (int i = 0; i < n + 2; i++) {
        grid[i][0] = grid[i][m + 1] = 1;
    }

    // 使用 STL vector 初始化访问标记数组
    visited = vector<unsigned short int>((n + 2) * (m + 2), 0);

    // 输入每个实心单元格的位置并将其标记在网格中
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    // 输入激光的起始位置和方向
    string direction;
    int startX, startY, rowDir, colDir;
    cin >> startX >> startY >> direction;

    // 根据输入的方向设置激光的行和列移动方向
    if (direction == "NE") {
        rowDir = -1;
        colDir = 1;
    } else if (direction == "NW") {
        rowDir = -1;
        colDir = -1;
    } else if (direction == "SE") {
        rowDir = 1;
        colDir = 1;
    } else { // SW
        rowDir = 1;
        colDir = -1;
    }

    // 追踪激光的路径
    tracePath(startX, startY, rowDir, colDir);

    // 输出激光穿越的空心单元格总数
    cout << sum << endl;
}

// 追踪激光路径的函数
void tracePath(int row, int col, int rowDir, int colDir) {
    int newRowDir, newColDir;

    // 如果当前位置已访问过，直接返回
    if (checkVisited(row, col, rowDir, colDir))
        return;

    // 根据当前位置的邻居情况计算激光新的方向
    int reflectCond = grid[row][col + colDir] * 4 + grid[row + rowDir][col + colDir] * 2 + grid[row + rowDir][col];
    if (reflectCond == 3) {
        newColDir = 1;
        newRowDir = -1;
    } else if (reflectCond == 7 || reflectCond == 2) {
        newColDir = -1;
        newRowDir = -1;
    } else if (reflectCond == 6) {
        newColDir = -1;
        newRowDir = 1;
    } else {
        newColDir = 1;
        newRowDir = 1;
    }

    // 更新行和列的移动方向
    rowDir = rowDir * newRowDir;
    colDir = colDir * newColDir;

    // 如果行方向是向下移动，更新行坐标
    if (newRowDir == 1)
        row = row + rowDir;

    // 如果列方向是向右移动，更新列坐标
    if (newColDir == 1)
        col = col + colDir;

    // 递归调用函数，继续追踪路径
    tracePath(row, col, rowDir, colDir);
}

// 检查某个位置是否已经访问过的函数
bool checkVisited(int row, int col, int rowDir, int colDir) {
    unsigned short int dirFlag;

    // 根据激光的移动方向设置访问标志
    if (rowDir == -1 && colDir == 1)
        dirFlag = 8;
    else if (rowDir == -1 && colDir == -1)
        dirFlag = 4;
    else if (rowDir == 1 && colDir == 1)
        dirFlag = 2;
    else
        dirFlag = 1;

    // 如果当前单元格未被访问，增加穿越空心单元格的计数
    if (visited[row * (m + 2) + col] == 0)
        sum++;

    // 如果当前方向已经访问过，返回 true
    if ((visited[row * (m + 2) + col] & dirFlag) == dirFlag)
        return true;
    else
        // 标记该方向为已访问
        visited[row * (m + 2) + col] |= dirFlag;

    return false;
}

/*
#include <iostream>

#include <cstring>
using namespace std;

// 变量 sum 用于计算激光穿越过的空心单元格数量
int sum = 0;
int n, m, k; // n 表示网格行数，m 表示网格列数，k 表示实心单元格的数量
short int **grid;
unsigned short int *visited;

// 函数声明
bool checkVisited(int row, int col, int rowDir, int colDir);
void tracePath(int row, int col, int rowDir, int colDir);

int main() {
	// 输入网格的大小和实心单元的数量
	cin >> n >> m >> k;

	// 动态分配存储网格的二维数组
	grid = new short int *[n + 2];
	for (int i = 0; i < n + 2; i++) {
		grid[i] = new short int[m + 2];
	}

	// 初始化整个网格，设置所有位置为空心单元
	for (int i = 0; i < n + 2; i++)
		memset(grid[i], 0, sizeof(short int) * (m + 2));

	// 设置边界的单元格为实心单元
	for (int j = 0; j < m + 2; j++)
		grid[0][j] = grid[n + 1][j] = 1;

	for (int i = 0; i < n + 2; i++)
		grid[i][0] = grid[i][m + 1] = 1;

	// 动态分配存储访问标记的数组
	visited = new unsigned short int[(n + 2) * (m + 2)];
	memset(visited, 0, sizeof(unsigned short int) * (n + 2) * (m + 2));

	// 输入每个实心单元格的位置并将其标记在网格中
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		grid[x][y] = 1;
	}

	// 输入激光的起始位置和方向
	string direction;
	int startX, startY, rowDir, colDir;
	cin >> startX >> startY >> direction;

	// 根据输入的方向设置激光的行和列移动方向
	if (direction == "NE") {
		rowDir = -1;
		colDir = 1;
	} else if (direction == "NW") {
		rowDir = -1;
		colDir = -1;
	} else if (direction == "SE") {
		rowDir = 1;
		colDir = 1;
	} else { // SW
		rowDir = 1;
		colDir = -1;
	}

	// 追踪激光的路径
	tracePath(startX, startY, rowDir, colDir);

	// 输出激光穿越的空心单元格总数
	cout << sum << endl;
}

// 追踪激光路径的函数
void tracePath(int row, int col, int rowDir, int colDir) {
	int newRowDir, newColDir;

	// 如果当前位置已访问过，直接返回
	if (checkVisited(row, col, rowDir, colDir))
		return;

	// 根据当前位置的邻居情况计算激光新的方向
	int reflectCond = grid[row][col + colDir] * 4 + grid[row + rowDir][col + colDir] * 2 + grid[row + rowDir][col];
	if (reflectCond == 3) {
		newColDir = 1;
		newRowDir = -1;
	} else if (reflectCond == 7 || reflectCond == 2) {
		newColDir = -1;
		newRowDir = -1;
	} else if (reflectCond == 6) {
		newColDir = -1;
		newRowDir = 1;
	} else {
		newColDir = 1;
		newRowDir = 1;
	}

	// 更新行和列的移动方向
	rowDir = rowDir * newRowDir;
	colDir = colDir * newColDir;

	// 如果行方向是向下移动，更新行坐标
	if (newRowDir == 1)
		row = row + rowDir;

	// 如果列方向是向右移动，更新列坐标
	if (newColDir == 1)
		col = col + colDir;

	// 递归调用函数，继续追踪路径
	tracePath(row, col, rowDir, colDir);
}

// 检查某个位置是否已经访问过的函数
bool checkVisited(int row, int col, int rowDir, int colDir) {
	unsigned short int dirFlag;

	// 根据激光的移动方向设置访问标志
	if (rowDir == -1 && colDir == 1)
		dirFlag = 8;
	else if (rowDir == -1 && colDir == -1)
		dirFlag = 4;
	else if (rowDir == 1 && colDir == 1)
		dirFlag = 2;
	else
		dirFlag = 1;

	// 如果当前单元格未被访问，增加穿越空心单元格的计数
	if ((visited[row * (m + 2) + col] == 0))
		sum++;

	// 如果当前方向已经访问过，返回 true
	if ((visited[row * (m + 2) + col] & dirFlag) == dirFlag)
		return true;
	else
		// 标记该方向为已访问
		visited[row * (m + 2) + col] |= dirFlag;

	return false;
}
*/
