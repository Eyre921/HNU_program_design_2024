#include <iostream>
using namespace std;
int main()
{
	int a =0,ft=0,yd=0,mi=0;
	cin>>a;
	ft=a/12;//��Ӣ������ 
	a=a%12;//ȡӢ���λ���ֵ 
	//�м���� 
	yd=ft/3;//ȡ������� 
	ft=ft%3;//ȡӢ�߽�λ���ֵ
	
	mi=yd/1760;
	yd=yd%1760;//ȡ��Ľ�λֵ
	
	if (mi!=0)
	cout<<mi<<" mi ";
	if(yd!=0)
	cout<<yd<<" yd ";
	if(ft!=0)
	cout<<ft<<" ft ";
	if(a!=0)
	cout<<a<<" in ";
	
	
}

