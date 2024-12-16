#include <iostream>
#include <fstream> // 文件输入输出库
#include <string>
using namespace std;

int main()
{
	// 打开输入文件 "listin.txt" 进行读取
	ifstream ifs("listin.txt", ios::in);
	if (!ifs.is_open())  // 检查文件是否成功打开
	{
		cout << "文件打开失败" << endl;
		return 0;
	}

	size_t n;
	cin >> n;  // 输入要求的宽度（假设是列宽度）

	// 打开输出文件 "listout.txt" 进行写入
	ofstream ofs("listout.txt", ios::out | ios::trunc);

	string line, formatted_line;

	// 逐行读取输入文件内容
	while (getline(ifs, line))
	{
		formatted_line.clear();  // 清空 formatted_line

		// 查找冒号的位置
		size_t pos = line.find(":");

		// 处理冒号前面的部分，去掉多余的空格和制表符
		for (size_t i = 0; i < pos; i++)
		{
			// 跳过空格和制表符
			if (line[i] != ' ' && line[i] != '\t')
			{
				formatted_line += line[i];
			}
			else if (i > 0 && (line[i] == ' ' || line[i] == '\t') && (line[i - 1] != ' ' && line[i - 1] != '\t'))
			{
				formatted_line += " ";  // 只保留一个空格
			}
		}

		// 计算冒号前内容的长度
		size_t num_spaces = formatted_line.size();

		// 填充不足的空格，以达到宽度 n - 1
		for (size_t i = 0; i < n - num_spaces - 1; i++)
		{
			formatted_line += " ";
		}

		// 添加冒号及空格 ": "
		formatted_line += ": ";

		// 处理冒号后的部分，去掉多余的空格和制表符
		for (size_t i = pos + 1; i < line.length(); i++)
		{
			if (line[i] != ' ' && line[i] != '\t')
			{
				formatted_line += line[i];
			}
			else if (i > pos + 1 && (line[i] == ' ' || line[i] == '\t') && (line[i - 1] != ' ' && line[i - 1] != '\t'))
			{
				formatted_line += " ";  // 只保留一个空格
			}
		}

		// 将格式化后的行写入输出文件
		ofs << formatted_line << " " << endl;
	}

	// 关闭文件流
	ifs.close();
	ofs.close();

	return 0;
}
