#include <iostream>
using namespace std;
int main()
{
	int a =0,ft=0,yd=0,mi=0;
	cin>>a;
	ft=a/12;//求英尺总数 
	a=a%12;//取英寸进位后的值 
	//中间变量 
	yd=ft/3;//取码的总数 
	ft=ft%3;//取英尺进位后的值
	
	mi=yd/1760;
	yd=yd%1760;//取码的进位值
	
	if (mi!=0)
	cout<<mi<<" mi ";
	if(yd!=0)
	cout<<yd<<" yd ";
	if(ft!=0)
	cout<<ft<<" ft ";
	if(a!=0)
	cout<<a<<" in ";
	
	
}

