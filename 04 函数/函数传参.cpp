#include <iostream>
using namespace std;
void swap1(int a, int b);
void swap2(int *a, int *b);
void swap3(int &a, int &b);
int main()
{
    int a, b;
    cin >> a >> b;
    swap1(a, b);
    printf("%d %d\n",  a, b);
    swap2(&a,&b);
    printf("%d %d\n",  a, b);
    swap3(a,b);
    printf("%d %d\n",  a, b);
    return 0;
}

void swap1(int a, int b)
{
int q=a;
a=b;
b=q;
}

void swap2(int *a, int *b)
{
int q=*a;
*a=*b;
*b=q;
}

void swap3(int &a, int &b)
{
int q=a;
a=b;
b=q;
}


