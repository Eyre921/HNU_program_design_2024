/*
1. 代码风格和结构化程度
原代码（网格和激光方向）：使用了STL中的vector，通过现代C++标准实现网格和访问记录的初始化，使得代码更加简洁和易于管理。代码结构清晰，通过多个函数分解任务，每个函数有明确的责任，如tracePath()处理激光的追踪，checkVisited()处理是否访问过，代码模块化程度高。
对比代码（char grid[200][200]版本）：采用了传统的二维数组，这种方法简单直接，但难以动态适配任意大小的网格。此外，激光传播的过程直接放在main()函数中，未进行函数抽象，导致代码臃肿，模块化不够，难以复用或维护。
2. 逻辑复杂性和维护性
原代码：逻辑实现复杂度较低，代码的功能被分离到多个函数中，这使得每个函数的复杂度较低，代码容易理解和调试。此外，使用了vector可以避免内存管理的复杂性，减少了潜在的内存泄漏问题。
对比代码：激光传播的逻辑嵌套在main()中，包含多个条件判断和状态转换，逻辑较为复杂，维护性较差。任何对激光传播逻辑的修改都必须在main()中进行，可能导致函数过于庞大而难以理解。
3. 性能分析
原代码：使用vector容器的实现相比于静态数组稍微会有一点性能开销，但在现代C++中vector的实现是非常高效的，其动态扩展能力使得它更具通用性。在复杂网格环境中，vector可以更加方便地处理不同尺寸的输入。
对比代码：二维数组char grid[200][200]的实现对性能要求较低，适合较小规模的网格，内存开销是固定的。但对于更大规模的输入，硬编码200的限制可能导致输入受限，难以适应规模变化。此外，直接对数组进行操作，虽然效率上略有提升，但灵活性不足。
4. 内存管理
原代码：使用STL容器vector可以自动管理内存的分配和释放，降低了内存管理的复杂性，这对于程序员来说减少了内存泄漏的可能性。特别是在动态分配和释放的场景下，vector可以确保资源的有效利用。
对比代码：直接使用静态数组，无需动态分配和释放内存，这样实现比较直观，但对内存的灵活性不高。无法有效应对大规模数据输入，固定大小的数组可能导致内存浪费或输入受限。
5. 激光传播逻辑
原代码：激光传播通过tracePath()函数递归调用来模拟激光的反射和传播，激光的方向改变通过反射条件计算出来，清晰易懂。使用了反射条件变量reflectCond来确定激光的折射方向，并通过多个条件分支进行激光路径的更新。代码更具可扩展性。
对比代码：激光传播的逻辑直接写在main()函数中，使用了多个嵌套条件分支来判断激光的反射和传播路径。各个分支之间的判断逻辑复杂且容易出错，特别是在激光的多次反射和折射中逻辑可能变得混乱。激光方向用字符q、e、z、c表示，虽然减少了一些变量，但降低了代码的直观性。
6. 可读性和可维护性
原代码：使用vector，且变量命名清晰（如rowDir、colDir），每个函数负责特定的功能，便于理解和后续维护。同时，通过分离逻辑实现使得激光路径跟踪与访问判断分开，代码的复用性和扩展性较好。
对比代码：代码集中在一个大函数中，激光传播逻辑直接嵌套其中，导致代码的复杂性增加。字符变量表示方向，虽然简洁但对于代码可读性影响较大。条件判断的复杂性也增加了维护的难度，稍有改动可能影响整个逻辑。
7. 边界处理
原代码：通过在vector数组的四周添加一圈实心单元（grid的大小设为n + 2和m + 2），使得边界的处理变得直观简洁。在路径追踪函数中，不需要单独处理边界越界的问题，只需考虑反射条件。
对比代码：直接对边界单元进行标记，但二维数组本身的边界处理更加复杂，可能需要多次手动判断边界是否越界。处理大规模数据时，使用静态数组且手动维护边界逻辑容易导致潜在的错误。
结论
原代码更适合扩展到更大的网格规模或需要频繁修改逻辑的情况。它的模块化设计、使用STL的高效数据管理和较为清晰的逻辑实现，使得代码更易于阅读、扩展和维护。
对比代码适用于较小规模、简单应用的场景，其静态内存管理和直接的逻辑实现对性能较为友好，但不易适应复杂的逻辑变化和较大规模的数据输入。
如果希望代码更适合于大规模场景，并保持良好的可读性和维护性，建议继续使用模块化和STL库的实现方式。如果对于性能极为敏感，并且可以确保输入规模较小，对比代码的静态数组实现也不失为一个选择。
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    char grid[200][200];  // 网格表示
    int n, m, k, startX, startY;  // 网格尺寸、实心单元数和起始坐标
    char laserDirection;  // 激光的当前方向 (q = NW, e = NE, z = SW, c = SE)
    cin >> n >> m >> k;

    // 初始化网格，默认为空心单元（'0'）
    memset(grid, '0', sizeof(grid));

    // 设置边界为 '1'，表示实心单元
    for (int i = 0; i <= n + 1; i++) {
        grid[i][0] = '1';
        grid[i][m + 1] = '1';
    }
    for (int i = 0; i <= m + 1; i++) {
        grid[0][i] = '1';
        grid[n + 1][i] = '1';
    }

    // 设置实心单元的位置
    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;
        grid[xi][yi] = '1';  // 实心单元标记为 '1'
    }

    string direction;
    int crossedCount = 0;  // 穿越的空单元格数量
    cin >> startX >> startY >> direction;  // 读取起始坐标和方向

    // 初始化激光方向
    if (direction == "SW") laserDirection = 'z';
    else if (direction == "SE") laserDirection = 'c';
    else if (direction == "NW") laserDirection = 'q';
    else if (direction == "NE") laserDirection = 'e';
    else laserDirection = '0'; // 防止未初始化的情况

    // 激光传播过程
    while (true) {
        // 如果到达目标点或遇到实心单元，结束循环
        if (grid[startX][startY] == laserDirection) {
            break;
        } else if (grid[startX][startY] == '0') { // 如果是空心单元
            crossedCount++;
            grid[startX][startY] = laserDirection;  // 激光穿越并标记
        }

        // 处理不同方向的激光反射和折射
        if (laserDirection == 'q') {  // NW
            if (grid[startX-1][startY-1] != '1') {
                startX--; startY--;  // 激光继续向NW传播
            } else {
                if (grid[startX][startY-1] == '1' && grid[startX-1][startY] == '1') {
                    laserDirection = 'c';  // 激光发生折射，改变方向为SE
                } else if (grid[startX-1][startY] == '1') {
                    startY--;
                    laserDirection = 'e';  // 激光反射，方向变为NE
                } else if (grid[startX][startY-1] == '1') {
                    startX--;
                    laserDirection = 'z';  // 激光反射，方向变为SW
                }
            }
        } else if (laserDirection == 'e') {  // NE
            if (grid[startX+1][startY-1] != '1') {
                startX++; startY--;  // 激光继续向NE传播
            } else {
                if (grid[startX+1][startY] == '1' && grid[startX][startY-1] == '1') {
                    laserDirection = 'z';  // 激光发生折射，方向变为SW
                } else if (grid[startX][startY-1] == '1') {
                    startX++;
                    laserDirection = 'c';  // 激光反射，方向变为SE
                } else if (grid[startX+1][startY] == '1') {
                    startY--;
                    laserDirection = 'q';  // 激光反射，方向变为NW
                }
            }
        } else if (laserDirection == 'z') {  // SW
            if (grid[startX-1][startY+1] != '1') {
                startX--; startY++;  // 激光继续向SW传播
            } else {
                if (grid[startX-1][startY] == '1' && grid[startX][startY+1] == '1') {
                    laserDirection = 'e';  // 激光发生折射，方向变为NE
                } else if (grid[startX][startY+1] == '1') {
                    startX--;
                    laserDirection = 'q';  // 激光反射，方向变为NW
                } else if (grid[startX-1][startY] == '1') {
                    startY++;
                    laserDirection = 'c';  // 激光反射，方向变为SE
                }
            }
        } else if (laserDirection == 'c') {  // SE
            if (grid[startX+1][startY+1] != '1') {
                startX++; startY++;  // 激光继续向SE传播
            } else {
                if (grid[startX][startY+1] == '1' && grid[startX+1][startY] == '1') {
                    laserDirection = 'q';  // 激光发生折射，方向变为NW
                } else if (grid[startX][startY+1] == '1') {
                    startX++;
                    laserDirection = 'e';  // 激光反射，方向变为NE
                } else if (grid[startX+1][startY] == '1') {
                    startY++;
                    laserDirection = 'z';  // 激光反射，方向变为SW
                }
            }
        }
    }

    // 输出穿越的空单元格数
    cout << crossedCount;
    return 0;
}