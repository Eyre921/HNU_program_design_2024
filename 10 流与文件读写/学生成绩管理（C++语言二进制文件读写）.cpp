#include <iostream>
#include <fstream>
using namespace std;

/*
    定义结构体student用于表示学生的基本信息，采用链表结构。
    每个学生包括学号、姓名、性别、年龄和两门课程的成绩，以及指向下一个学生的指针。
*/
struct student
{
    int no;                       // 学号
    char name[20], sex;           // 姓名以及性别
    int age;                      // 年龄
    float chinese, computer;      // 两门课程的成绩（语文和计算机）
    student *next;                // 指向下一个学生的指针

    // 重载小于运算符，用于比较两个学生的总成绩（语文+计算机成绩）
    bool operator<(const student &another) const
    {
        return ((chinese + computer) < (another.chinese + another.computer));
    }
};

// 函数声明
student* ReadFile(ifstream& infile, student *head, int &n);  // 从二进制文件中读取学生数据，存储到链表中
void display(student *head);                                 // 显示链表中的所有学生信息
void WriteFile(ofstream& outfile, student *head);            // 将链表中的学生信息写入二进制文件
student* input(student *head, int &n);                       // 输入新的学生数据，并连接到链表末尾
student* LinkSort(student *head, const int &n);              // 链表排序，按总成绩从大到小排序
void swapNode(student *s, student *q);                       // 交换两个学生节点的数据，用于排序

int main()
{
    int n = 0;
    student *head = NULL;   // 初始化链表头指针为空

    // 打开并读取学生成绩文件
    ifstream getf;
    getf.open("grade.bin", ios::in | ios::binary);
    head = ReadFile(getf, head, n);  // 从文件中读取学生信息并存储到链表中
    display(head);                    // 显示所有学生信息
    getf.close();                     // 关闭输入文件流

    // 输入新的学生信息，并将其添加到链表中
    head = input(head, n);

    // 对链表进行排序，按总成绩从大到小排序
    head = LinkSort(head, n);

    // 打开并将排序后的学生信息写入文件
    ofstream putf;
    putf.open("grade.bin", ios::out | ios::binary);
    WriteFile(putf, head);  // 将链表中的数据写入文件
    putf.close();           // 关闭输出文件流

    return 0;
}

// 从文件中读取学生数据，返回链表头指针
student* ReadFile(ifstream& infile, student* head, int &n)
{
    student *q = head;
    // 如果链表非空，找到最后一个节点
    if (head)
        while(q->next) q = q->next;

    // 从文件中读取学生数据，直到文件结束
    while(!infile.eof())
    {
        student *p = new student;  // 创建新的学生节点
        if (!infile.read((char*)p, sizeof(student)))  // 读取数据
        {
            delete p;
            break;
        }
        p->next = NULL;

        // 如果链表为空，设置head为当前学生节点
        if (!head)
            head = p;
        else
            q->next = p;  // 将当前学生节点添加到链表末尾

        q = p;
        n++;  // 增加学生数量
    }
    return head;  // 返回链表头指针
}

// 显示链表中的所有学生信息
void display(student* head)
{
    student *p = head;
    while(p)
    {
        // 输出学生的各项信息
        printf("No: %d\n", p->no);
        printf("Name: %s\n", p->name);
        printf("Sex: %c\n", p->sex);
        printf("Age: %d\n", p->age);
        printf("Scores: %f %f\n\n", p->chinese, p->computer);
        p = p->next;  // 移动到下一个学生
    }
}

// 输入新的学生数据，并连接到链表末尾
student* input(student* head, int &n)
{
    student *q = head;

    // 如果链表非空，找到最后一个节点
    if (head)
        while(q->next) q = q->next;

    while(1)
    {
        printf("Input continue(y/n)?");
        if (getchar() != 'y')  // 判断是否继续输入
            break;

        student *p = new student;  // 创建新的学生节点

        // 输入学生信息
        printf("No: ");
        scanf("%d", &p->no);
        getchar();  // 清空输入缓冲区
        printf("Name: ");
        cin.getline(p->name, 20);
        printf("Sex(M/F): ");
        p->sex = getchar();
        printf("Age: ");
        scanf("%d", &p->age);
        printf("Chinese score: ");
        scanf("%f", &p->chinese);
        printf("Computer score: ");
        scanf("%f", &p->computer);
        p->next = NULL;  // 新节点的next指针为空
        getchar();  // 清空输入缓冲区

        // 如果链表为空，将当前学生作为链表头
        if (!head)
            head = p;
        else
            q->next = p;  // 将新节点添加到链表末尾

        q = p;
        n++;  // 增加学生数量
    }

    return head;  // 返回更新后的链表头指针
}

// 链表排序，按总成绩从大到小排序（冒泡排序）
student* LinkSort(student* head, const int &n)
{
    student *p;
    // 冒泡排序
    for(int i = 1; i <= n - 1; i++)
    {
        p = head;
        for(int j = 1; j <= n - i; j++)
        {
            // 比较相邻的两个学生节点，按总成绩排序
            if (*p < *p->next)
            {
                swapNode(p, p->next);  // 交换节点数据
            }
            p = p->next;
        }
    }

    return head;  // 返回排序后的链表头指针
}

// 交换两个学生节点的数据
void swapNode(student* s, student* q)
{
    student *snext = s->next, *qnext = q->next, tmp;
    tmp = *s;  // 交换数据
    *s = *q;
    *q = tmp;
    s->next = snext;  // 修复链表中的指向关系
    q->next = qnext;
}

// 将链表中的学生信息写入文件
void WriteFile(ofstream& outfile, student* head)
{
    while(head)
    {
        // 将每个学生数据写入文件
        outfile.write((char*)head, sizeof(student));
        head = head->next;  // 移动到下一个学生
    }
}


/*
#include <iostream>
#include <fstream>
using namespace std;


    定义结构体student用于表示学生的基本信息，采用链表结构

struct student
{
    int no;                       // 学号
    char name[20], sex;           // 姓名以及性别, 请思考如果将name[20]修改为*name，结果将会怎样，还适合本题的处理方式吗？
    int age;                      // 年龄
    float chinese, computer;      // 表示两门课程的成绩
    student *next;
    bool operator<(const student &another) const      // 重载运算符 < (小于)，用于结构体对象之间的比较，在LinkSort中比较链表的两个节点大小
    {
        return ((chinese + computer) < (another.chinese + another.computer));
    }
};

student* ReadFile(ifstream& infile, student *head, int &n);  // 从二进制文件(文件指针为fp)中将所有数据读入，存储于以head为头指针的链表中
void display(student *head);                         // 用于显示链表的内容
void WriteFile(ofstream& outfile, student *head);             // 将以head为头指针的链表中的数据写入二进制文件(文件指针为fp)
student* input(student *head, int &n);               // 输入新的数据，将新数据连接到链表末尾
student* LinkSort(student *head, const int &n);      // 实现对链表的排序，按总成绩从大到小排列，冒泡排序
void swapNode(student *s, student *q);               // 实现对链表节点的数据交换，用于排序, 在函数LinkSort中调用

int main()
{
    int n = 0;
    student *head = NULL;

    ifstream getf;
getf.open("grade.bin",ios::in|ios::binary);
    head = ReadFile(getf, head, n);
    display(head);
    getf.close();

    head = input(head, n);
    head = LinkSort(head, n);

    ofstream putf;
putf.open("grade.bin",ios::in|ios::binary);
    WriteFile(putf, head);
    putf.close();

    return 0;
}

student* ReadFile(ifstream& infile, student* head, int &n)
{
student *q = head;
    if (head)
        while(q->next) q = q->next;
    while(!infile.eof())
    {
        student *p = new student;                                     
        if (!infile.read((char*)p,sizeof(student))) 
        {
             delete p;
            break;
        }   
        p->next = NULL;
        if (!head)
            head = p;
        else
            q->next = p;
 
        q = p;
        n++;
    }
    return head;
}

void display(student* head)
{
    student *p = head;
    while(p)
    {
        printf("No: %d\n", p->no);
        printf("Name: %s\n", p->name);
        printf("Sex: %c\n", p->sex);
        printf("Age: %d\n", p->age);
        printf("Scores: %f %f\n\n", p->chinese, p->computer);
        p = p->next;
    }
}

student* input(student* head, int &n)
{

    student *q = head;

    if (head)
        while(q->next) q = q->next;

    while(1)
    {
        printf("Input continue(y/n)?");
        if (getchar() != 'y')
            break;

        student *p = new student;

        printf("No: ");
        scanf("%d", &p->no);
        getchar();
        printf("Name: ");
   //     gets(p->name);
        cin.getline(p->name, 20);
        printf("Sex(M/F): ");
        p->sex = getchar();
        printf("Age: ");
        scanf("%d", &p->age);
        printf("Chinese score: ");
        scanf("%f", &p->chinese);
        printf("Computer score: ");
        scanf("%f", &p->computer);
        p->next = NULL;
        getchar();

        if (!head)
            head = p;
        else
            q->next = p;

        q = p;
        n++;
    }

    return head;
}

student* LinkSort(student* head, const int &n)
{
    student *p;
    for(int i = 1; i <= n - 1; i++)
    {
        p = head;
        for(int j = 1; j <= n - i; j++)
        {
            if (*p < *p->next)
            {
                swapNode(p,p->next);
            }
            p = p->next;
        }
    }

    return head;
}

void swapNode(student* s, student* q)
{
    student *snext = s->next, *qnext = q->next, tmp;
    tmp = *s;
    *s = *q;
    *q = tmp;
    s->next = snext;
    q->next = qnext;
}

void WriteFile(ofstream& outfile, student* head)
{
while(head)
    {
        outfile.write((char*)head,sizeof(student)); 
        head = head->next;
    }
}


*/